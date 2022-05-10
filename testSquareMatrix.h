#ifndef __TESTSQUAREMATRIX__
#define __TESTSQUAREMATRIX__

#include "ArraySquareMatrix.hpp"
#include "ListSquareMatrix.hpp"

int SquareMatrix();
int InputData(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int AddNewRowAndColumn(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int MultRowByDigit(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int MultColumnByDigit(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int AddingRows(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int AddingColumns(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int RowPermutation(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int ColumnPermutation(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int MultByScalar(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int AddingMatrix(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int OutputNorm(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int OutputDimension(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);
int OutputMatrix(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listRectangularMatrixInt);

#endif