#include <vector>
#include "Task2/Headers/HashMap.h"

template <typename keyType, typename valueType>
HashMap<keyType, valueType>:: HashMap() {
    countBuckets = 32;
    buckets.resize(countBuckets);
}

template <typename keyType, typename valueType>
HashMap<keyType, valueType>:: ~HashMap() {
    for (auto &bucket: buckets) {
        bucket.clear();
    }
}

template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Insert(const keyType &key, const valueType &value) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    for (auto &pair: buckets[hashIndex]) {
        if (pair.first == key) {
            cout << "Pair already exists, choose update to set new value. \n";
            return;
        }
    }
    buckets[hashIndex].push_back(make_pair(key, value));
}

template <typename keyType, typename valueType>
valueType HashMap<keyType, valueType>::GetValue(const keyType &key) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    for (auto &pair : buckets[hashIndex]) {
        if (pair.first == key) {
            return pair.second;
        }
        else {
            throw out_of_range("Pair not found");
        }
    }
}

template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Update(const keyType &key, const valueType &value) {
    int hashIndex = hash<keyType>{}(key) % countBuckets;
    for (auto &pair: buckets[hashIndex]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
        else
        {
            throw out_of_range("Pair not found");
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