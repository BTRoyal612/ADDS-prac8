#include <iostream>
#include <limits>

#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int * newArray, int size) {
    std::cout << "parameter constructor" << std::endl;

    Node * ptr = new Node();
    ptr->setData(newArray[0]);
    head = ptr;

    for (int i = 1; i < size; i++) {
        Node * temp = new Node();
        temp->setData(newArray[i]);
        ptr->setNext(temp);
        ptr = temp;
    }
    ptr->setNext(nullptr);
}

bool LinkedList::isEmpty() {
    if (head == nullptr) return true;
    return false;
}

void LinkedList::addFront(int newItem) {
    std::cout << "add front" << std::endl;

    Node * temp = new Node(newItem, head);
    head = temp;
}

void LinkedList::addEnd(int newItem) {
    std::cout << "add end" << std::endl;

    Node * temp = new Node(newItem, nullptr);

    if (this->isEmpty()) {
        head = temp;
        return;
    }

    Node * ptr = head;
    while (ptr->getNext() != nullptr) {
        ptr = ptr->getNext();
    }

    ptr->setNext(temp);
}

void LinkedList::addAtPosition(int position, int newItem) {
    std::cout << "add at position" << std::endl;

    if (this->isEmpty()) {
        head = new Node(newItem, nullptr);
        return;
    }

    if (position <= 1) {
        this->addFront(newItem);
        return;
    } 

    Node * add = nullptr;
    Node * ptr = head;
    int count = 0;
    while (ptr != nullptr && count <= position) {
        count++;
        if (count == position-1) {
            add = ptr;
        }
        ptr = ptr->getNext();
    }

    if (add == nullptr) {
        this->addEnd(newItem);
        return;
    }

    Node * temp = new Node(newItem, add->getNext());
    add->setNext(temp);
}

int LinkedList::search(int item) {
    std::cout << "search" << std::endl;

    int found = 0;

    int count = 1;
    Node * ptr = head;
    while (ptr != nullptr) {
        if (ptr->getData() == item) {
            found = count;
            break;
        }
        ptr = ptr->getNext();
        count++;
    }

    std::cout << found << " " << std::endl;
    return found;
}

void LinkedList::deleteFront() {
    std::cout << "delete front" << std::endl;
    
    if (this->isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node * ptr = head;
    head = head->getNext();
    delete ptr;
}

void LinkedList::deleteEnd() {
    std::cout << "delete end" << std::endl;
    
    if (this->isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node * ptr = nullptr;
    Node * end = head;
    while (end->getNext() != nullptr) {
        ptr = end;
        end = end->getNext();
    }

    ptr->setNext(nullptr);
    delete end;
}

void LinkedList::deletePosition(int position) {
    std::cout << "delete position" << std::endl;

    if (this->isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    if (position < 1) {
        std::cout << "outside range" << std::endl;
        return;
    }  

    Node * del = nullptr;
    Node * ptr = head;
    int count = 0;
    while (ptr != nullptr && count <= position) {
        count++;
        if (count == position-1) {
            del = ptr;
        }
        ptr = ptr->getNext();
    }

    if (del == nullptr || del->getNext() == nullptr) {
        std::cout << "outside range" << std::endl;
        return;
    }

    Node * temp = del->getNext();
    del->setNext(temp->getNext());
    delete(temp);
}

int LinkedList::getItem(int position) {
    std::cout << "get item" << std::endl;
    int outOfRange = std::numeric_limits < int >::max();
    if (position < 1) {
        std::cout << outOfRange << std::endl;
        return outOfRange;
    }

    Node * get = nullptr;
    Node * ptr = head;
    int count = 0;
    while (ptr != nullptr && count <= position) {
        count++;
        if (count == position) {
            get = ptr;
        }
        ptr = ptr->getNext();
    }

    if (get == nullptr) {
        std::cout << outOfRange << std::endl;
        return outOfRange;
    }

    std::cout << get->getData() << " " << std::endl;
    return get->getData();
}

void LinkedList::printItems() {
    std::cout << "print" << std::endl;
    
    if (this->isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node * ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->getData() << " ";
        ptr = ptr->getNext();
    }
    std::cout << std::endl;
}

LinkedList::~LinkedList() {}