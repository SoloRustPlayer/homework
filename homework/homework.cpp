#include <iostream>
#include "String.h"
#include "Array.h"

int main() {
    String str1("Hello");
    String str2(" World");
    String str3 = str1 + str2;
    str3.print();

    str1 += str2;
    str1.print();

    std::cout << "Character at index 1: " << str1[1] << std::endl;
    std::cout << "String equality: " << (str1 == str3) << std::endl;
    std::cout << "String inequality: " << (str1 != str2) << std::endl;
    std::cout << "String comparison: " << (str1 > str2) << " " << (str1 < str2) << std::endl;

    
    Array arr1(5);
    arr1.fill(1, 10);
    arr1.display();

    Array arr2(5, 5, 15);
    arr2.display();

    Array arr3 = arr1 + arr2;
    arr3.display();

    arr1 += arr2;
    arr1.display();

    std::cout << "Element at index 2: " << arr1[2] << std::endl;
    std::cout << "Array min: " << arr1.min() << ", max: " << arr1.max() << std::endl;

    arr1.sort();
    arr1.display();

    arr1.Remove(2);
    arr1.display();

    arr1.Append(99);
    arr1.display();

    std::cout << "Array equality: " << (arr1 == arr2) << std::endl;
    std::cout << "Array inequality: " << (arr1 != arr2) << std::endl;
    std::cout << "Array comparison: " << (arr1 > arr2) << " " << (arr1 < arr2) << std::endl;

    return 0;
}
