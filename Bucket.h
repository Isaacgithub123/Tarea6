#pragma once
#include "LinkedList.h"
#include <iostream>
using namespace std;

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

    void add(int indiceBuckets, T element) {
        if (indiceBuckets >= 0 && indiceBuckets < numBuckets) {
            buckets[indiceBuckets].append(element);
        }
    }
    LinkedList<T>& get(int indiceBuckets) {
        return buckets[indiceBuckets];
    }

    void clear() {
        for (int i = 0; i < numBuckets; i++) {
            buckets[i].clear();
        }
    }
    void print() {
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            buckets[i].print();
        }
    }
    int size() {
        return numBuckets;
    }
};