#include <iostream>

class Array {
private:
    int* data;
    size_t size;

public:
    Array(size_t n) : size(n) {
        data = new int[size] {};
    }

    Array(size_t n, int min, int max) : size(n) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = min + (i % (max - min + 1));
        }
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }
};
