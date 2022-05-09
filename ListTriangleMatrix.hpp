#ifndef __LISTTRIANGLEMATRIX__
#define __LISTTRIANGLEMATRIX__

#include "ListSequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ListTriangleMatrix {
    private:
        ListSequence<T>* items;

    public:
        ListTriangleMatrix(int dimension, T** items);
        ListTriangleMatrix();
        ListTriangleMatrix(const ListTriangleMatrix<T> &squarearMatrix);
        ~ListTriangleMatrix();

        size_t GetDimension() const; 
        T Get(int indexRow, int indexColumn) const;

        void AddRow(T* newRow);
        void AddColumn(T* newColumn);

        void MultScalar(T scalar);
        void AddMatrix(ListTriangleMatrix<T>* rectangularMatrix);

        T GetNorm();

        const ListTriangleMatrix<T> & operator = (const ListTriangleMatrix<T> & squarearMatrix);

};

template<typename T>
ListTriangleMatrix<T>::ListTriangleMatrix(int dimension, T** items) {
    this->items = new ListSequence<T>[dimension];
    for (int i = 0; i < dimension; i++) {
        for (int j = i; j < dimension; j++) {
            (this->items)[i].Append(items[i][j]);
        } 
    }
}

template<typename T>
ListTriangleMatrix<T>::ListTriangleMatrix() {
    this->items = nullptr;
}

template<typename T>
ListTriangleMatrix<T>::ListTriangleMatrix(const ListTriangleMatrix<T> &squarearMatrix) {
    this->items = new ListSequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = i; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }
}


template<typename T>
const ListTriangleMatrix<T> & ListTriangleMatrix<T>::operator = (const ListTriangleMatrix<T> & squarearMatrix) {
    this->items = new ListSequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = i; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }

    return *this;
}




template<typename T>
ListTriangleMatrix<T>::~ListTriangleMatrix() {
    delete[] this->items;
}




template<typename T>
size_t ListTriangleMatrix<T>::GetDimension() const {
    return (this->items)[0].GetLength();
}

template<typename T>
T ListTriangleMatrix<T>::Get(int indexRow, int indexColumn) const {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix")
    }

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
void ListTriangleMatrix<T>::AddRow(T* newRow) {
    ListSequence<T>* newItems = new ListSequence<T>[this->GetDimension() + 1];

    for (int i = 0; i <= this->GetDimension(); i++) {
        newItems[0].Append(newRow[i]);
    }

    for (int i = 1; i <= this->GetDimension(); i++) {
        for (int j = i; j <= this->GetDimension(); j++) {
            newItems[i].Append(this->Get(i - 1, j - 1));
        }
    }

    delete[] this->items;
    this->items = newItems;
}

template<typename T>
void ListTriangleMatrix<T>::AddColumn(T* newColumn) {
    ListSequence<T>* newItems = new ListSequence<T>[this->GetDimension() + 1];

    for (int i = 0; i <= this->GetDimension(); i++) {
        for (int j = i; j < this->GetDimension(); j++) {
            newItems[i].Append(this->Get(i, j));
        }
    }

    for (int i = 0; i <= this->GetDimension(); i++) {
        newItems[i].Append(newColumn[i]);
    }

    delete[] this->items;
    this->items = newItems;
}

template<typename T>
void ListTriangleMatrix<T>::MultScalar(T scalar) {
    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = i; j < this->GetDimension(); j++) {
            this->items[i].Set(this->Get(i, j) * scalar, j - i);
        }
    }
}

template<typename T>
void ListTriangleMatrix<T>::AddMatrix(ListTriangleMatrix<T>* rectangularMatrix) {
    if (this->GetDimension() != rectangularMatrix->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = i; j < this->GetDimension(); j++) {
            this->items[i].Set(this->Get(i, j) + rectangularMatrix->Get(i, j), j - i);
        }
    }
} 

template<typename T>
T ListTriangleMatrix<T>::GetNorm() {
    if (!(this->GetDimension())) {
        throw std::domain_error("empty matrix");
    }

    T valueNorm = this->Get(0, 0);
    valueNorm *= valueNorm;

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = i; j < this->GetDimension(); j++) {
            if (!(i == 0 && j == 0)) {
                valueNorm += this->Get(i, j) * this->Get(i, j);
            }
        }
    }

    return pow(valueNorm, 0.5);
}

#endif