#include <iostream>
#include "String.h"
#include "Array.h"
#include "List.h"

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

    
    Array<int> arr1(5, 1, 5);
    std::cout << "arr1: ";
    arr1.display();

    Array<int> arr2 = arr1;
    std::cout << "arr2 (copy of arr1): ";
    arr2.display();

    arr1.Append(6);
    arr1.Append(7);
    std::cout << "arr1 after appending 6 and 7: ";
    arr1.display();

    arr1.Remove(2);
    std::cout << "arr1 after removing index 2: ";
    arr1.display();

    std::cout << "Min element in arr1: " << arr1.min() << std::endl;
    std::cout << "Max element in arr1: " << arr1.max() << std::endl;

    arr1.sort();
    std::cout << "arr1 after sorting: ";
    arr1.display();

    Array<int> arr3 = arr1 + arr2;
    std::cout << "arr3 (arr1 + arr2): ";
    arr3.display();

    std::cout << "arr1 == arr2: " << (arr1 == arr2 ? "true" : "false") << std::endl;
    std::cout << "arr1 != arr2: " << (arr1 != arr2 ? "true" : "false") << std::endl;
    std::cout << "arr1 > arr2: " << (arr1 > arr2 ? "true" : "false") << std::endl;
    std::cout << "arr1 < arr2: " << (arr1 < arr2 ? "true" : "false") << std::endl;

    Array<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top of stack: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Top of stack after pop: " << stack.top() << std::endl;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    stack.clear();
    std::cout << "After clearing, is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    List<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(0);
    lst.print();

    lst.pop_back();
    lst.print();

    lst.pop_front();
    lst.print();

    lst.push_back(4);
    lst.push_back(5);
    lst.print();

    std::cout << "Index of 4: " << lst.find(4) << std::endl;

    lst.erase(1);
    lst.print();

    lst.reverse();
    lst.print();

    lst.clear();
    lst.print();
    return 0;  
}
