#ifndef __TESTTRIANGLEMATRIX__
#define __TESTTRIANGLEMATRIX__

#include "ArrayTriangleMatrix.hpp"
#include "ListTriangleMatrix.hpp"

int TriangleMatrix();
int InputData(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int AddNewRow(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int AddNewColumn(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int MultByScalar(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int AddingMatrix(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int OutputNorm(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int OutputDimension(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);
int OutputMatrix(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt);

#endif