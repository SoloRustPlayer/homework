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
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            for (size_t i = 0; i <= length; i++) {
                str[i] = other.str[i];
            }
        }
        return *this;
    }

    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        for (size_t i = 0; i < length; i++) {
            newStr[i] = str[i];
        }
        for (size_t i = 0; i < other.length; i++) {
            newStr[length + i] = other.str[i];
        }
        newStr[newLength] = '\0';
        String result(newStr);
        delete[] newStr;
        return result;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    char operator[](size_t index) const {
        return (index < length) ? str[index] : '\0';
    }

    void print() const {
        for (size_t i = 0; i < length; i++) {
            std::cout << str[i];
        }
        std::cout << std::endl;
    }

    bool operator==(const String& other) const {
        if (length != other.length) return false;
        for (size_t i = 0; i < length; i++) {
            if (str[i] != other.str[i]) return false;
        }
        return true;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    bool operator>(const String& other) const {
        return length > other.length;
    }

    bool operator<(const String& other) const {
        return length < other.length;
    }
    String(String&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

};
