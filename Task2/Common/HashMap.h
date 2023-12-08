#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename keyType, typename valueType>
/*
* @brief Класс HashMap - реализация структуры данных вида хэшмап. Реализация включает в себя конструкторы,
 * в том числе конструктор копирования, а также деструктор, основные операции, аналогичные парадигме CRUD
 * и переопределение оператора копирования (присваивания)
 *@param countBuckets - размер хэшмапа
 *@param buckets - вектор, который хранит в себе всю структуру данных (в том числе сами пары ключ-значение)
*/
class HashMap {
public:
    HashMap();
    HashMap(const HashMap &t);
    ~HashMap();
    void Insert(const keyType &key, const valueType &value);
    void Update(const keyType &key, const valueType &value);
    valueType GetValue(const keyType &key);
    void Remove(const keyType &key);
    int GetCountBuckets();
    HashMap<keyType, valueType>& operator=(const HashMap<keyType, valueType>& t);
private:
    int countBuckets;
    vector<vector<pair<keyType, valueType>>> buckets;
};