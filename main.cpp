#include <iostream>
#include <string>

#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {
    int count = 0;
    int arr[100];

    int x;
    string command;
    for (int i = 0; i < 100; i++) {
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin >> command;
            break;
        }
        arr[i] = x;
        count++;
    }

    LinkedList * list = new LinkedList(arr, count);
    
    int param1, param2;
    cin >> param1 >> param2;
    if (command == "AF") list->addFront(param1);
    else if (command == "AE") list->addEnd(param1);
    else if (command == "AP") list->addAtPosition(param1, param2);
    else if (command == "S") list->search(param1);
    else if (command == "DF") list->deleteFront();
    else if (command == "DE") list->deleteEnd();
    else if (command == "DP") list->deletePosition(param1);
    else list->getItem(param1);

    list->printItems();
}