#include <gtest/gtest.h>
#include "../Task2/Common/HashMap.h"
#include "../Task2/Common/HashMap.cpp"

TEST(HashMapTests, InsertTest) {
    HashMap<int, int> test;
    test.Insert(1, 2);
    EXPECT_EQ(test.GetValue(1), 2);
}

TEST(HashMapTests, GetValueTest) {
    HashMap<int, int> test;
    test.Insert(1, 2);
    int testValue = test.GetValue(1);
    EXPECT_EQ(testValue, 2);
}

TEST(HashMapTests, UpdateTest) {
    HashMap<int, int> test;
    test.Insert(1, 2);
    test.Update(1, 5);
    EXPECT_EQ(test.GetValue(1), 5);
}

TEST(HashMapTests, RemoveTest) {
    HashMap<int, int> test;
    test.Insert(1, 2);
    test.Insert(3, 4);
    test.Remove(1);
    EXPECT_THROW(test.GetValue(1), out_of_range);
}

TEST(HashMapTests, CreateTest) {
    HashMap<int, int> test;
    EXPECT_EQ(test.GetCountBuckets(), 32);
}

TEST(HashMapTests, CopyConstructorTest) {
    HashMap<int, int> test;
    test.Insert(1, 2);

    HashMap<int, int> copy = HashMap<int, int>(test);

    EXPECT_EQ(copy.GetValue(1), 2);
}

TEST(HashMapTests, OperatorTest) {
    HashMap<int, int> test;
    test.Insert(1, 2);

    HashMap<int, int> test2 = test;

    EXPECT_EQ(test2.GetValue(1), 2);
}