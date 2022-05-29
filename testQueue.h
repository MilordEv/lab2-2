#ifndef __TESTQUEUE__
#define __TESTQUEUE__

#include "QueueArray.hpp"
#include "QueueList.hpp"

int AtdMenu();
int InputData(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
int Add(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int PopQueue(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int Map(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int Where(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int Reduce(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int GetSubQueue(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int FindSubQueue(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int Separation(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int Empty(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);
int Output(int* codeData, QueueArray<int>** arraySequenceInt, QueueArray<double>** arraySequenceDouble, QueueList<int>** listSequenceInt, QueueList<double>** listSequenceDouble);

#endif