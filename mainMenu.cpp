#include <iostream>
#include "testATD.h"
#include "testRectangularMatrix.h"
#include "testSquareMatrix.h"
#include "testTriangleMatrix.h"
#include "testDiagonalMatrix.h"

using namespace std;

int main() {

    int codeType = 0;

    while(1 + 1 == 2) {
        
        cout << "Enter a number for:" << endl;
        cout << "\t1 - To test ATD" << endl; 
        cout << "\t2 - To test rectangulat matrix" << endl; 
        cout << "\t3 - To test square matrix" << endl; 
        cout << "\t4 - To test triangle matrix" << endl; 
        cout << "\t5 - To test diagonal matrix" << endl; 
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

            case 3:
                SquareMatrix();
                break;

            case 4:
                TriangleMatrix();
                break;

            case 5:
                DiagonalMatrix();
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