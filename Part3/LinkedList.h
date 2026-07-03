#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
public:
    struct Node {
        T     data;
        Node* next;
        explicit Node(T data) : data(data), next(nullptr) {}
    };

private:
    Node* head;
    Node* tail;
    int   sz;

public:
    LinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    LinkedList(const LinkedList&)            = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // Insert a new element at the end — O(1) via tail pointer
    void insert(T item) {
        Node* node = new Node(item);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        ++sz;
    }

    // Remove the first node whose data == item — O(n)
    // Returns true if found and removed, false if not found
    // Does NOT delete the T object itself (the caller owns it)
    bool remove(T item) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->data == item) {
                if (prev)       prev->next = curr->next;
                else            head       = curr->next;
                if (curr == tail) tail     = prev;
                delete curr;
                --sz;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    // Print every element using operator<< — requires T to support operator<<
    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << std::endl;
            curr = curr->next;
        }
    }

    Node* getHead() const { return head; }
    int   getSize() const { return sz;   }
};

#endif
