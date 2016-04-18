#include<iostream>
using namespace std;


void BinaryTree::insertElement(int x) {
    int currentIndex = 0;
    cout << "Adding: " << x;
    while(true) {
        if(array[currentIndex] == NULL){
            array[currentIndex] = x;
            cout << " Inserted at index: " << currentIndex << endl;
            break;
        }else if(array[currentIndex] <= x) {
            if(array[currentIndex] == x){
                cout << "ERROR!-- Repeating element" << endl;
                break;
            }else
            cout << " Right ";
            currentIndex = (2 * currentIndex + 2);
        }else if(array[currentIndex] >= x) {
             if(array[currentIndex] == x){
                cout << "ERROR!-- Repeating element" << endl;
                break;
            }else
            cout << " Left ";
            currentIndex = (2 * currentIndex + 1);
        }
    }
}

void BinaryTree::searchElement(int x){
    int currentIndex = 0;
    while (true) {
            if (array[currentIndex] == NULL) {
            cout << "Not Found" << endl;
            break;
            }
            if (array[currentIndex] == x) {
            cout << "Found at index: " << currentIndex << endl;
            break;
            }
            else if(array[currentIndex] < x) {
            currentIndex = (2 * currentIndex + 2);
        }
            else if(array[currentIndex] > x) {
            currentIndex = (2 * currentIndex + 1);
        }
    }
}

