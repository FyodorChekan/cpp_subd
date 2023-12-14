#include <vector>
#include "HashMap.h"

template <typename keyType, typename valueType>
HashMap<keyType, valueType>:: HashMap() {
    countBuckets = 32;
    buckets.resize(countBuckets);
}



template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Insert(const keyType &key, const valueType &value) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    for (auto &pair: buckets[hashIndex]) {
        if (pair.first == key) {
            throw out_of_range("Pair already exists, choose update to set new value. \n");
        }
    }
    buckets[hashIndex].push_back(make_pair(key, value));
}

template <typename keyType, typename valueType>
valueType HashMap<keyType, valueType>::GetValue(const keyType &key) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    if (buckets[hashIndex].empty())
    {
        throw out_of_range("Pair is not found");
    }
    for (auto &pair : buckets[hashIndex]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
}

template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Update(const keyType &key, const valueType &value) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    if (buckets[hashIndex].empty())
    {
        throw out_of_range("Pair is not found");
    }
    for (auto &pair: buckets[hashIndex]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
}

template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Remove(const keyType &key) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    for (auto it = buckets[hashIndex].begin(); it != buckets[hashIndex].end(); ++it){
        if (it->first == key) {
            buckets[hashIndex].erase(it);
            return;
        }
    }
}


template<typename keyType, typename valueType>
int HashMap<keyType, valueType>::GetCountBuckets() {
    return this->countBuckets;
}
