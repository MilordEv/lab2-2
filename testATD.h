#ifndef __TESTATD__
#define __TESTATD__

#include "ArraySequence.hpp"
#include "ListSequence.hpp"

int AtdMenu();
int InputData(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int AddEnd(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int AddBeginning(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int AddElement(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int GetSub(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int ConcateSequence(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int DeleteItem(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int OutputSequence(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);
int OutputLength(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble);

#endif