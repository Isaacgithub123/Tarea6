#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
using namespace std;

template <typename E>
class LinkedList {
private:
    Node<E>* head;
    Node<E>* current;
    Node<E>* tail;
    int size;

public:

    LinkedList() {
        head = current = tail = new Node<E>();
        size = 0;
    }
    ~LinkedList() {
        clear();
        delete head;
    }

    void insert(E element) {
        current->next = new Node<E>(element, current->next);
        if (current == tail)
            tail = tail->next;
        size++;
    }

    void append(E element) {
        tail = tail->next = new Node<E>(element);
        size++;
    }

    E remove() {
        if (size == 0)
            throw runtime_error("Empty list");
        if (current == tail)
            throw runtime_error("No current element");
        E result = current->next->element;
        Node<E>* temp = current->next;
        current->next = temp->next;
        if (temp == tail)
            tail = current;
        delete temp;
        size--;
        return result;
    }

    void clear() {
        current = head;
        while (head->next != nullptr) {
            current = head->next;
            head->next = current->next;
            delete current;
        }
        tail = head;
        current = head;
        size = 0;
    }

    int getSize() {
        return size;
    }

    void moveToStart() {
        current = head;
    }

    void moveToEnd() {
        current = tail;
    }

    void next() {
        if (current != tail)
            current = current->next;
    }

    E getValue() {
        if (current->next == nullptr)
            throw runtime_error("No current element");
        return current->next->element;
    }

    void print() {
        Node<E>* temp = head->next;
        cout << "[ ";
        while (temp != nullptr) {
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};