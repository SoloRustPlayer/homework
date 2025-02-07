#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() { clear(); }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void push_front(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
    }

    T front() {
        if (!head) throw std::out_of_range("List is empty");
        return head->data;
    }

    T back() {
        if (!tail) throw std::out_of_range("List is empty");
        return tail->data;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    int find(T value) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    void erase(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            pop_front();
            return;
        }
        if (index == size - 1) {
            pop_back();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
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
