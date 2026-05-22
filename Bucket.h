#pragma once
#include "LinkedList.h"

template <typename T>
class Bucket {
private:
    LinkedList<T>* buckets;
    int numBuckets;

public:
    Bucket(int n) : numBuckets(n) {
        buckets = new LinkedList<T>[n];
    }

    ~Bucket() {
        delete[] buckets;
    }

    void add(int bucketIndex, T element) {
        if (bucketIndex >= 0 && bucketIndex < numBuckets) {
            buckets[bucketIndex].append(element);
        }
    }
    LinkedList<T>& get(int bucketIndex) {
        return buckets[bucketIndex];
    }

    void clearAll() {
        for (int i = 0; i < numBuckets; i++) {
            buckets[i].clear();
        }
    }
    void printAll() {
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            buckets[i].print();
        }
    }
    int size() {
        return numBuckets;
    }
};