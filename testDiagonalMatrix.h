#ifndef __TESTDIAGONALMATRIX__
#define __TESTDIAGONALMATRIX__

#include "ArrayDiagonalMatrix.hpp"
#include "ListDiagonalMatrix.hpp"

int DiagonalMatrix();
int InputData(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);
int AddNewRowOrNewColumn(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);
int MultByScalar(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);
int AddingMatrix(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);
int OutputNorm(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);
int OutputDimension(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);
int OutputMatrix(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt);

#endif