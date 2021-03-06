#include <iostream>
#include <limits>

#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int * newArray, int size) {
    Node * ptr = new Node(newArray[0], nullptr);
    head = ptr;

    for (int i = 1; i < size; i++) {
        Node * temp = new Node(newArray[i], nullptr);
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
    Node * temp = new Node(newItem, head);
    head = temp;
}

void LinkedList::addEnd(int newItem) {
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
    return;
}

void LinkedList::addAtPosition(int position, int newItem) {
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
    return;
}

int LinkedList::search(int item) {
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
    if (this->isEmpty()) {
        return;
    }

    Node * ptr = head;
    head = head->getNext();
    delete ptr;
    return;
}

void LinkedList::deleteEnd() {
    if (this->isEmpty()) {
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
    return;
}

void LinkedList::deletePosition(int position) {
    if (this->isEmpty()) {
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
    return;
}

int LinkedList::getItem(int position) {
    int outOfRange = std::numeric_limits < int >::max();
    if (position < 1) {
        std::cout << outOfRange << " ";
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
        std::cout << outOfRange << " ";
        return outOfRange;
    }

    std::cout << get->getData() << " ";
    return get->getData();
}

void LinkedList::printItems() {
    if (this->isEmpty()) {
        return;
    }

    Node * ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->getData() << " ";
        ptr = ptr->getNext();
    }
    std::cout << std::endl;
}

LinkedList::~LinkedList() {
    Node * ptr = head;
    Node * temp;
    while (ptr != nullptr) {
        temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}