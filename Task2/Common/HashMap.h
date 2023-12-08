#pragma once
#include <vector>
#include <iostream>

using namespace std;
/**
* @brief Класс HashMap.
* @tparam keyType тип данных ключа.
* @tparam valueType тип данных значения.
*/
template <typename keyType, typename valueType>
class HashMap {
public:
/**
* @brief Конструктор по умолчанию.
*/
    HashMap();
/**
* @brief Конструктор копирования.
* @param t объект HashMap.
*/
    HashMap(const HashMap &t);
/**
* @brief Деструктор.
*/
    ~HashMap();
/**
* @brief Метод вставки пары (Ключ, значение).
* @param key Ключ.
* @param value Значение.
*/
    void Insert(const keyType &key, const valueType &value);
/**
* @brief Метод обновление значения по ключу.
* @param key Ключ.
* @param value Новое значение.
*/
    void Update(const keyType &key, const valueType &value);
/**
* @brief Метод получения значения по ключу.
* @param key Ключ.
* @return Значение.
*/
    valueType GetValue(const keyType &key);
/**
* @brief Метод удаления пары (ключ, значения) по ключу.
* @param key Ключ.
*/
    void Remove(const keyType &key);
/**
* @brief Метод получения размера HashMap.
* @return размер HashMap.
*/
    int GetCountBuckets();
/**
* @brief Оператор копирования.
* @param t объект HashMap.
*/
    HashMap<keyType, valueType>& operator=(const HashMap<keyType, valueType>& t);
private:
/**
* @brief размер HashMap.
*/
    int countBuckets;
/**
* @brief Массив пар (ключ, значение).
*/
    vector<vector<pair<keyType, valueType>>> buckets;
};
