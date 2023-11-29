#ifndef CPP_SUBD_HASHMAP_H
#define CPP_SUBD_HASHMAP_H

#endif //CPP_SUBD_HASHMAP_H

#include <vector>
#include <iostream>

using namespace std;

template <typename keyType, typename valueType>
class HashMap {
public:
    HashMap();
    ~HashMap();
    void Insert(const keyType &key, const valueType &value);
    void Update(const keyType &key, const valueType &value);
    valueType GetValue(const keyType &key);
    void Remove(const keyType &key);
private:
    int countBuckets;
    vector<vector<pair<keyType, valueType>>> buckets;
};