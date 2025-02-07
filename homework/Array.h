#include <iostream>
template <typename T>
class Array {
private:
    T* data;
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
    void display() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void fill(int min, int max) {
        for (size_t i = 0; i < size; i++) {
            data[i] = min + (i % (max - min + 1));
        }
    }
    void Remove(size_t index) {
        if (index >= size) return;
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        resize(size - 1);
    }

    void Append(int value) {
        resize(size + 1);
        data[size - 1] = value;
    }

    void resize(size_t newSize) {
        int* newData = new int[newSize] {};
        size_t minSize = (newSize < size) ? newSize : size;
        for (size_t i = 0; i < minSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    void sort() {
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    int min() const {
        int minValue = data[0];
        for (size_t i = 1; i < size; i++) {
            if (data[i] < minValue) {
                minValue = data[i];
            }
        }
        return minValue;
    }

    int max() const {
        int maxValue = data[0];
        for (size_t i = 1; i < size; i++) {
            if (data[i] > maxValue) {
                maxValue = data[i];
            }
        }
        return maxValue;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Array operator+(const Array& other) const {
        Array result(size + other.size);
        for (size_t i = 0; i < size; i++) {
            result.data[i] = data[i];
        }
        for (size_t i = 0; i < other.size; i++) {
            result.data[size + i] = other.data[i];
        }
        return result;
    }

    Array& operator+=(const Array& other) {
        *this = *this + other;
        return *this;
    }

    int operator[](size_t index) const {
        return (index < size) ? data[index] : 0;
    }

    bool operator==(const Array& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; i++) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=(const Array& other) const {
        return !(*this == other);
    }

    bool operator>(const Array& other) const {
        return size > other.size;
    }

    bool operator<(const Array& other) const {
        return size < other.size;
    }
    Array(size_t n = 10) : size(0), capacity(n) {
        data = new T[capacity]{};
    }

    ~Array() {
        delete[] data;
    }

    void push(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void pop() {
        if (size > 0) {
            size--;
        }
    }

    T top() const {
        if (size > 0) {
            return data[size - 1];
        }
        return T();
    }

    void clear() {
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    size_t getSize() const {
        return size;
    }
};
