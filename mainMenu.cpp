#include <iostream>
#include "testATD.h"
#include "testRectangularMatrix.h"

using namespace std;

int main() {

    int codeType = 0;

    while(1 + 1 == 2) {
        cout << "Enter a number for:" << endl;
        cout << "\t1 - To test ATD" << endl; 
        cout << "\t2 - To test rectangulat matrix" << endl; 
        /*cout << "\t3 - Add an element to the beginning" << endl; 
        cout << "\t4 - Insert an element into the sequence" << endl; 
        cout << "\t5 - Get a subsequence" << endl; 
        cout << "\t6 - Сoncatenate sequences" << endl;
        cout << "\t7 - Delete an item" << endl;
        cout << "\t8 - Output the sequence" << endl; 
        cout << "\t9 - Output the length of the sequence" << endl; 
        cout << "\t0 - Exit the test" << endl << endl;*/
        cout << "\t0 - To exit the program" << endl; 
        cout << endl << "Enter: ";

        int code = 0;
        cin >> code;

        switch(code) {
            case 1: 
                AtdMenu();
                break;

            case 2:
                RectangularMatrix();
                break;
                
            case 0:
                cout << "Exit the program" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 

    }

    return 0;
}