#ifndef __ARRAYSQUAREMATRIX__
#define __ARRAYSQUAREMATRIX__

#include "ArraySequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ArraySquareMatrix {
    private:
        ArraySequence<T>* items;

    public:
        ArraySquareMatrix(int dimension, T** items);
        ArraySquareMatrix();
        ArraySquareMatrix(const ArraySquareMatrix<T> &squarearMatrix);
        ~ArraySquareMatrix();

        size_t GetDimension() const; 
        T Get(int indexRow, int indexColumn) const;

        void AddRowAndColumn(T* newRow, int indexRow, T* newColumn, int indexColumn);

        void MultRow(int numberRow, T scalar);
        void MultColumn(int numberColumn, T scalar);
        void AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient);
        void AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient);
        void SwapRows(int indexFirstRow, int indexSecondRow);
        void SwapColumns(int indexFirstColumn, int indexSecondColumn);

        void MultScalar(T scalar);
        void AddMatrix(ArraySquareMatrix<T>* squarearMatrix);

        T GetNorm();

        const ArraySquareMatrix<T> & operator = (const ArraySquareMatrix<T> & squarearMatrix);

};

template<typename T>
ArraySquareMatrix<T>::ArraySquareMatrix(int dimension, T** items) {
    this->items = new ArraySequence<T>[dimension];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            (this->items)[i].Append(items[i][j]);
        } 
    }
}

template<typename T>
ArraySquareMatrix<T>::ArraySquareMatrix() {
    this->items = nullptr;
}

template<typename T>
ArraySquareMatrix<T>::ArraySquareMatrix(const ArraySquareMatrix<T> &squarearMatrix) {
    this->items = new ArraySequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = 0; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }
}


template<typename T>
const ArraySquareMatrix<T> & ArraySquareMatrix<T>::operator = (const ArraySquareMatrix<T> & squarearMatrix) {
    this->items = new ArraySequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = 0; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }

    return *this;
}




template<typename T>
ArraySquareMatrix<T>::~ArraySquareMatrix() {
    delete[] this->items;
}




template<typename T>
size_t ArraySquareMatrix<T>::GetDimension() const {
    return (this->items)[0].GetLength();
}

template<typename T>
T ArraySquareMatrix<T>::Get(int indexRow, int indexColumn) const {
    if (indexRow >= this->GetDimension() || indexRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumn >= this->GetDimension() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    return (this->items)[indexRow].Get(indexColumn);
}

template<typename T>
void ArraySquareMatrix<T>::AddRowAndColumn(T* newRow, int indexRow, T* newColumn, int indexColumn) {
    if (indexRow > this->GetDimension() || indexRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumn > this->GetDimension() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ArraySequence<T>* oldItems = new ArraySequence<T>[this->GetDimension()];

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = 0; j < this->GetDimension(); j++) {
            oldItems[i].Append(this->Get(i, j));
        }
    }

    int numberColumn = this->GetDimension();
    delete[] this->items;
    this->items = new ArraySequence<T>[numberColumn + 1];
    
    for (int i = 0; i < indexRow; i++) {
        for (int j = 0; j < numberColumn; j++) {
            (this->items)[i].Append(oldItems[i].Get(j));
        }
    }

    for (int i = 0; i < numberColumn; i++) {
            (this->items)[indexRow].Append(newRow[i]);
    }

    for (int i = indexRow + 1; i < this->GetDimension() + 1; i++) {
        for (int j = 0; j < numberColumn; j++) {
            (this->items)[i].Append(oldItems[i-1].Get(j));
        }
    }

    delete[] oldItems;

    for (int i = 0; i < this->GetDimension(); i++) {
        (this->items)[i].InsertAt(newColumn[i], indexColumn);
    }
}


template<typename T>
void ArraySquareMatrix<T>::MultRow(int numberRow, T scalar) {
    if (numberRow > this->GetDimension() || numberRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items[numberRow].Set(scalar * this->Get(numberRow, i), i);
    }
}

template<typename T>
void ArraySquareMatrix<T>::MultColumn(int numberColumn, T scalar) {
    if (numberColumn > this->GetDimension() || numberColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items[i].Set(scalar * this->Get(i, numberColumn), numberColumn);
    }
}

template<typename T>
void ArraySquareMatrix<T>::AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient) {
    if (indexRowWhereAdd >= this->GetDimension() || indexRowWhereAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexRowWhicheAdd >= this->GetDimension() || indexRowWhicheAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(coefficient)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items[indexRowWhereAdd].Set(coefficient * this->Get(indexRowWhicheAdd, i) + this->Get(indexRowWhereAdd, i), i);
    }
}

template<typename T>
void ArraySquareMatrix<T>::AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient) {
    if (indexColumnWhereAdd >= this->GetDimension() || indexColumnWhereAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumnWhicheAdd >= this->GetDimension() || indexColumnWhicheAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(coefficient)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items[i].Set(coefficient * this->Get(i, indexColumnWhicheAdd) + this->Get(i, indexColumnWhereAdd), indexColumnWhereAdd);
    }
}

template<typename T>
void ArraySquareMatrix<T>::SwapRows(int indexFirstRow, int indexSecondRow) {
    if (indexFirstRow >= this->GetDimension() || indexFirstRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexSecondRow >= this->GetDimension() || indexSecondRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ArraySequence<T> buf;
    for (int i = 0; i < this->GetDimension(); i++) {
        buf.Append(this->Get(indexFirstRow, i));
    }
    for (int i = 0; i < this->GetDimension(); i++) {
       this->items[indexFirstRow].Set(this->Get(indexSecondRow, i), i);
    }
    for (int i = 0; i < this->GetDimension(); i++) {
       this->items[indexSecondRow].Set(buf.Get(i), i);
    }
}

template<typename T>
void ArraySquareMatrix<T>::SwapColumns(int indexFirstColumn, int indexSecondColumn) {
    if (indexFirstColumn >= this->GetDimension() || indexFirstColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexSecondColumn >= this->GetDimension() || indexSecondColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ArraySequence<T> buf;
    for (int i = 0; i < this->GetDimension(); i++) {
        buf.Append(this->Get(i, indexFirstColumn));
    }
    for (int i = 0; i < this->GetDimension(); i++) {
       this->items[i].Set(this->Get(i, indexSecondColumn), indexFirstColumn);
    }
    for (int i = 0; i < this->GetDimension(); i++) {
       this->items[i].Set(buf.Get(i), indexSecondColumn);
    }
}

template<typename T>
void ArraySquareMatrix<T>::MultScalar(T scalar) {
    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = 0; j < this->GetDimension(); j++) {
            this->items[i].Set(this->Get(i, j) * scalar, j);
        }
    }
}

template<typename T>
void ArraySquareMatrix<T>::AddMatrix(ArraySquareMatrix<T>* squarearMatrix) {
    if (this->GetDimension() != squarearMatrix->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = 0; j < this->GetDimension(); j++) {
            this->items[i].Set(this->Get(i, j) + squarearMatrix->Get(i, j), j);
        }
    }
} 

template<typename T>
T ArraySquareMatrix<T>::GetNorm() {
    if (!(this->GetDimension())) {
        throw std::domain_error("empty matrix");
    }

    T valueNorm = this->Get(0, 0);
    valueNorm *= valueNorm;

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = 0; j < this->GetDimension(); j++) {
            if (!(i == 0 && j == 0)) {
                valueNorm += this->Get(i, j) * this->Get(i, j);
            }
        }
    }

    return pow(valueNorm, 0.5);
}

#endif