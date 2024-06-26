#ifndef __ARRAYTRIANGLEMATRIX__
#define __ARRAYTRIANGLEMATRIX__

#include "ArraySequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ArrayTriangleMatrix {
    private:
        ArraySequence<T>* items;

    public:
        ArrayTriangleMatrix(int dimension, T** items);
        ArrayTriangleMatrix();
        ArrayTriangleMatrix(const ArrayTriangleMatrix<T> &triangleMatrix);
        ~ArrayTriangleMatrix();

        size_t GetDimension() const; 
        T Get(int indexRow, int indexColumn) const;

        void AddRow(T* newRow);
        void AddColumn(T* newColumn);

        void MultScalar(T scalar);
        void AddMatrix(ArrayTriangleMatrix<T>* triangleMatrix);

        T GetNorm();

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
ArrayTriangleMatrix<T>::ArrayTriangleMatrix(const ArrayTriangleMatrix<T> &triangleMatrix) {
    this->items = new ArraySequence<T>[triangleMatrix.GetDimension()];

    for (int i = 0; i < triangleMatrix.GetDimension(); i++) {
        for (int j = i; j < triangleMatrix.GetDimension(); j++) {
            (this->items)[i].Append(triangleMatrix.Get(i, j));
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
    if (!(this->items)) {
        return 0;
    }

    return (this->items)[0].GetLength();
}

template<typename T>
T ArrayTriangleMatrix<T>::Get(int indexRow, int indexColumn) const {

    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
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
void ArrayTriangleMatrix<T>::AddRow(T* newRow) {
    if (this->items) {
        ArraySequence<T>* newItems = new ArraySequence<T>[this->GetDimension() + 1];

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
    } else {
        int lengthRow = 0;
        std::cout << "Enter the length of the row: ";
        std::cin >> lengthRow;

        if (lengthRow <= 0) {
            throw std::underflow_error("invalid length value");
        }

        this->items = new ArraySequence<T>[1];

        for (int i = 0; i < lengthRow; i++) {
            this->items[0].Append(newRow[i]);
        }
    }
}

template<typename T>
void ArrayTriangleMatrix<T>::AddColumn(T* newColumn) {
    if (this->items) {
        ArraySequence<T>* newItems = new ArraySequence<T>[this->GetDimension() + 1];

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
    } else {
        this->items = new ArraySequence<T>[1];
        this->items[0].Append(newColumn[0]);
    }
}

template<typename T>
void ArrayTriangleMatrix<T>::MultScalar(T scalar) {
     if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
void ArrayTriangleMatrix<T>::AddMatrix(ArrayTriangleMatrix<T>* triangleMatrix) {
     if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }
    
    if (this->GetDimension() != triangleMatrix->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        for (int j = i; j < this->GetDimension(); j++) {
            this->items[i].Set(this->Get(i, j) + triangleMatrix->Get(i, j), j - i);
        }
    }
} 

template<typename T>
T ArrayTriangleMatrix<T>::GetNorm() {
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