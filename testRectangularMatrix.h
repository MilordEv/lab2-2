#ifndef __TESTRECTANGULARMATRIX__
#define __TESTRECTANGULARMATRIX__

#include "ArrayRectangularMatrix.hpp"
#include "ListRectangularMatrix.hpp"

int RectangularMatrix();
int InputData(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int AddNewRow(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int AddNewColumn(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int MultRowByDigit(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int MultColumnByDigit(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int AddingRows(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int AddingColumns(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int RowPermutation(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int ColumnPermutation(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int MultByScalar(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int AddingMatrix(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int OutputNorm(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int OutputDimension(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);
int OutputMatrix(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt);

#endif