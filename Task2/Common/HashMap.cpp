#include <vector>
#include "Task2/Headers/HashMap.h"

HashMap:: HashMap() {
    countBuckets = 32;
    buckets.resize(countBuckets);
}

HashMap:: ~HashMap() {
    for (auto &bucket: buckets) {
        bucket.clear();
    }
}

void HashMap::Insert(const int &key, const int &value) {
    int hashIndex = hash<int>{}(key) % countBuckets;
    for (auto &pair: buckets[hashIndex]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    buckets[hashIndex].push_back(make_pair(key, value));
}

int HashMap::GetValue(const int &key) {
    int hashIndex = hash<int>{}(key) % countBuckets;
    for (auto &pair : buckets[hashIndex]) {
        if (pair.first == key) {
            return pair.second;
        }
        else {
            return int();
        }
    }
}

void HashMap::Remove(const int &key) {
    int hashIndex = hash<int>{}(key) % countBuckets;
    for (auto it = buckets[hashIndex].begin(); it != buckets[hashIndex].end(); ++it){
        if (it->first == key) {
            buckets[hashIndex].erase(it);
            return;
        }
    }
}