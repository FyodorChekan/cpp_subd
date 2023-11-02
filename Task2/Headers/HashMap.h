#ifndef CPP_SUBD_HASHMAP_H
#define CPP_SUBD_HASHMAP_H

#endif //CPP_SUBD_HASHMAP_H

#include <vector>
#include <iostream>

using namespace std;

class HashMap {
public:
    HashMap();
    ~HashMap();
    void Insert(const int &key, const int &value);
    int GetValue(const int &key);
    void Remove(const int &key);
private:
    int countBuckets;
    vector<vector<pair<int, int>>> buckets;
};