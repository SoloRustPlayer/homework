#include <iostream>

class String {
private:
    char* str;
    size_t length;

public:
    String() : String(80) {}

    String(size_t size) : length(size) {
        str = new char[length + 1] {};
    }

    String(const char* input) {
        length = 0;
        while (input[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (size_t i = 0; i < length; i++) {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        for (size_t i = 0; i <= length; i++) {
            str[i] = other.str[i];
        }
    }

    ~String() {
        delete[] str;
    }
};
