#include <iostream>

#include "Node.h"
#include "LinkedList.h"

int main() {
    int nArray[3] = {1,2,3};
    LinkedList * test = new LinkedList(nArray, 3);

    test->search(2);

    test->addFront(0);
    test->addEnd(5);
    test->addAtPosition(5, 4);

    test->printItems();

    test->getItem(0);
    
    test->printItems();
}