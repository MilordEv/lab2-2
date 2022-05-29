#ifndef __TESTVECTOR__
#define __TESTVECTOR__

#include "VectorArray.hpp"
#include "VectorList.hpp"

int Vector();
int InputData(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);
int ScalarMult(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);
int MultByScalar(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);
int AddingVector(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);
int OutputNorm(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);
int OutputDimension(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);
int OutputVector(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList);

#endif