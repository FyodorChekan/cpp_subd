#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename keyType, typename valueType>
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