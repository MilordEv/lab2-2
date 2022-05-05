#ifndef __ARRAYTRIANGLEMATRIX__
#define __ARRAYTRIANGLEMATRIX__

#include "ArraySequence.hpp"
#include <stdexcept>

template<typename T>
class ArrayTriangleMatrix {
    private:
        ArraySequence<T>* items;

    public:
        ArrayTriangleMatrix(int dimension, T** items);
        ArrayTriangleMatrix();
        ArrayTriangleMatrix(const ArrayTriangleMatrix<T> &squarearMatrix);
        ~ArrayTriangleMatrix();

        size_t GetDimension() const; 
        T Get(int indexRow, int indexColumn) const;

        void AddRowAndColumn(T* newRow, int indexRow, T* newColumn, int indexColumn);

        void MultScalar(T scalar);
        void AddMatrix(ArrayTriangleMatrix<T>* rectangularMatrix);

        const ArrayTriangleMatrix<T> & operator = (const ArrayTriangleMatrix<T> & squarearMatrix);

};

template<typename T>
ArrayTriangleMatrix<T>::ArrayTriangleMatrix(int dimension, T** items) {
    this->items = new ArraySequence<T>[dimension];
    for (int i = 0; i < dimension; i++) {
        for (int j = i; j < dimension; j++) {
            (this->items)[i].Append(items[i][j]);
        } 
    }
}

template<typename T>
ArrayTriangleMatrix<T>::ArrayTriangleMatrix() {
    this->items = nullptr;
}

template<typename T>
ArrayTriangleMatrix<T>::ArrayTriangleMatrix(const ArrayTriangleMatrix<T> &squarearMatrix) {
    this->items = new ArraySequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = i; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }
}


template<typename T>
const ArrayTriangleMatrix<T> & ArrayTriangleMatrix<T>::operator = (const ArrayTriangleMatrix<T> & squarearMatrix) {
    this->items = new ArraySequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = i; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }

    return *this;
}




template<typename T>
ArrayTriangleMatrix<T>::~ArrayTriangleMatrix() {
    delete[] this->items;
}




template<typename T>
size_t ArrayTriangleMatrix<T>::GetDimension() const {
    return (this->items)[0].GetLength();
}

template<typename T>
T ArrayTriangleMatrix<T>::Get(int indexRow, int indexColumn) const {
    if (indexRow >= this->GetDimension() || indexRow < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    if (indexColumn >= this->GetDimension() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    if (indexRow > indexColumn) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    return (this->items)[indexRow].Get(indexColumn-indexRow);
}

template<typename T>
void ArrayTriangleMatrix<T>::AddRowAndColumn(T* newRow, int indexRow, T* newColumn, int indexColumn) {
    if (indexRow > this->GetDimension() || indexRow < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    if (indexColumn > this->GetDimension() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    ArraySequence<T>* oldItems = new ArraySequence<T>[this->GetDimension()];

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = i; j < this->GetDimension(); j++) {
            oldItems[i].Append(this->Get(i, j));
        }
    }

    int numberColumn = this->GetDimension();
    delete[] this->items;
    this->items = new ArraySequence<T>[numberColumn + 1];
    
    for (int i = 0; i < indexRow; i++) {
        for (int j = i; j < numberColumn; j++) {
            (this->items)[i].Append(oldItems[i].Get(j - i));
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
void ArrayTriangleMatrix<T>::MultScalar(T scalar) {
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
void ArrayTriangleMatrix<T>::AddMatrix(ArrayTriangleMatrix<T>* rectangularMatrix) {
    if (this->GetDimension() != rectangularMatrix->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = 0; j < this->GetDimension(); j++) {
            this->items[i].Set(this->Get(i, j) + rectangularMatrix->Get(i, j), j);
        }
    }
} 

#endif