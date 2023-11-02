#include <iostream>
#include "Task2/Headers/HashMap.h"

using namespace std;

int main() {
    HashMap myHashMap;

    myHashMap.Insert(1, 3);
    myHashMap.Insert(2, 10);
    myHashMap.Insert(3, 6);

    cout << "Value of 1: " << myHashMap.GetValue(1) << endl;
    cout << "Value of 2: " << myHashMap.GetValue(2) << endl;
    cout << "Value of 3: " << myHashMap.GetValue(3) << endl;

    myHashMap.Insert(4, 11);
    cout << "Value of 4: " << myHashMap.GetValue(4) << endl;

    myHashMap.Remove(2);

    cout << "Value of 4 after remove: " << myHashMap.GetValue(2) << endl;

    return 0;

}