
#include <iostream>
#include <cstdlib>
#include "arrayOperations.hpp"

using namespace std;

#define SIZE 100

int getNumber(int lessThan) {
    int i;
    cin >> i;
    if (i >= lessThan) {
        i = rand() % lessThan;
    }
    return i;
}

int main() {
    //Insert an element at beginning of an array
    ArrayManeuverer myOps;
    myOps.populate();
    myOps.insertAtPosition(0);
    myOps.printArray();

    //Insert at a certain index
    cout << "\nChoose a position between 0 and " << myOps.currentSize() << " to insert a new element." << endl;
    cout << ">> ";
    int pos = getNumber(myOps.currentSize());
    
    myOps.insertAtPosition(pos);
    myOps.printArray();

    //Insert before an index
    cout << "\nInserting before an index" << endl;
    myOps.insertAtPosition(pos > 0 ? pos : 0);
    myOps.printArray();

    //delete an element
    cout << "\nEnter index in array to delete: ";
    myOps.deleteElement(myOps.currentSize());
    myOps.printArray();

    //update an element
    cout << "\nEnter index of an element to update: ";
    pos = getNumber(myOps.currentSize());
    cout << "\nEnter new value: ";
    int newValue;
    cin >> newValue;
    myOps.updateElement(pos, newValue);
    myOps.printArray();

    //search for an element
    cout << "\nEnter a value to search for in array: ";
    cin >> newValue;
    if(!myOps.searchElement(newValue)) {
        cout << "\nElement no found" << endl;
    }

    return 0;
}