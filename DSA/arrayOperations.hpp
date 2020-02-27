//Insert an element at a certain index of an array

#include <iostream>
#include <limits>

using namespace std;

#define SIZE 100

class ArrayManeuverer {
    int myArray[SIZE], numElements = 0;

    public:
    bool populate(bool fill = false) {
        if(!fill) {
            cout << "Please enter less than " << SIZE << " elements into array. End with a string." << endl;
            for (;cin >> myArray[numElements]; numElements++);
        }else {
            cout << "Please enter elements " << SIZE << " elements into the array." << endl;
            for (; numElements < SIZE; numElements++) {
                cin >> myArray[numElements];
            }
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;
        return fill ? numElements == SIZE : numElements > 0;
    }
    bool insertAtPosition(int pos) {
        if (pos < numElements) {
            for (int i = numElements; i > pos; i--) {
                myArray[i] = myArray[i-1];
            }
        }
        cout << "Insert an element at index (" << pos << ") : ";
        bool isSuccess = (cin >> myArray[pos]) ? true : false;
        numElements++;

        cout << endl;
        return isSuccess;
    }
    int currentSize() {
        return numElements;
    }
    void printArray() {
        cout << "\nElements in array are : ";
        for (int i = 0; i < numElements; i++) {
            cout << myArray[i] << ' ';
        }
        cout << endl;
    }
    bool deleteElement(int pos) {
        if (pos >= numElements) return false;

        for (int i = pos; i < numElements - 1;) {
            myArray[i] = myArray[i+1];
        }
        numElements--;
        return true;
    }
    void updateElement(int pos, int newValue) {
        myArray[pos] = newValue;
    }
    bool searchElement(int value) {
        for (int i = 0; i < numElements; i++) {
            if (myArray[i] == value) {
                cout << "Element \'" << value << "\' found at position " << i << endl;
                return true;
            }
        }
        return false;
    }
};