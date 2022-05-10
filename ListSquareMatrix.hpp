#ifndef __LISTSQUAREMATRIX__
#define __LISTSQUAREMATRIX__

#include "ListSequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ListSquareMatrix {
    private:
        ListSequence<T>* items;

    public:
        ListSquareMatrix(int dimension, T** items);
        ListSquareMatrix();
        ListSquareMatrix(const ListSquareMatrix<T> &squarearMatrix);
        ~ListSquareMatrix();

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
        void AddMatrix(ListSquareMatrix<T>* squarearMatrix);

        T GetNorm();

        const ListSquareMatrix<T> & operator = (const ListSquareMatrix<T> & squarearMatrix);

};

template<typename T>
ListSquareMatrix<T>::ListSquareMatrix(int dimension, T** items) {
    this->items = new ListSequence<T>[dimension];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            (this->items)[i].Append(items[i][j]);
        } 
    }
}

template<typename T>
ListSquareMatrix<T>::ListSquareMatrix() {
    this->items = nullptr;
}

template<typename T>
ListSquareMatrix<T>::ListSquareMatrix(const ListSquareMatrix<T> &squarearMatrix) {
    this->items = new ListSequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = 0; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }
}


template<typename T>
const ListSquareMatrix<T> & ListSquareMatrix<T>::operator = (const ListSquareMatrix<T> & squarearMatrix) {
    this->items = new ListSequence<T>[squarearMatrix.GetDimension()];

    for (int i = 0; i < squarearMatrix.GetDimension(); i++) {
        for (int j = 0; j < squarearMatrix.GetDimension(); j++) {
            (this->items)[i].Append(squarearMatrix.Get(i, j));
        }
    }

    return *this;
}




template<typename T>
ListSquareMatrix<T>::~ListSquareMatrix() {
    delete[] this->items;
}




template<typename T>
size_t ListSquareMatrix<T>::GetDimension() const {
    if (!(this->items)) {
        return 0;
    }

    return (this->items)[0].GetLength();
}

template<typename T>
T ListSquareMatrix<T>::Get(int indexRow, int indexColumn) const {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (indexRow >= this->GetDimension() || indexRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumn >= this->GetDimension() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    return (this->items)[indexRow].Get(indexColumn);
}

template<typename T>
void ListSquareMatrix<T>::AddRowAndColumn(T* newRow, int indexRow, T* newColumn, int indexColumn) {
    if (this->items) {
        if (indexRow > this->GetDimension() || indexRow < 0) {
            throw std::out_of_range("Out of the range of the array");
        }

        if (indexColumn > this->GetDimension() || indexColumn < 0) {
            throw std::out_of_range("Out of the range of the array");
        }

        ListSequence<T>* oldItems = new ListSequence<T>[this->GetDimension()];

        for (int i = 0; i < this->GetDimension(); i++) {
            for (int j = 0; j < this->GetDimension(); j++) {
                oldItems[i].Append(this->Get(i, j));
            }
        }

        int numberColumn = this->GetDimension();
        delete[] this->items;
        this->items = new ListSequence<T>[numberColumn + 1];
        
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
    } else {
        this->items = new ListSequence<T>[1];

        this->items[0].Append(newRow[0]);
    }
}

template<typename T>
void ListSquareMatrix<T>::MultRow(int numberRow, T scalar) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
void ListSquareMatrix<T>::MultColumn(int numberColumn, T scalar) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
void ListSquareMatrix<T>::AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
void ListSquareMatrix<T>::AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
void ListSquareMatrix<T>::SwapRows(int indexFirstRow, int indexSecondRow) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (indexFirstRow >= this->GetDimension() || indexFirstRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexSecondRow >= this->GetDimension() || indexSecondRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ListSequence<T> buf;
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
void ListSquareMatrix<T>::SwapColumns(int indexFirstColumn, int indexSecondColumn) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (indexFirstColumn >= this->GetDimension() || indexFirstColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexSecondColumn >= this->GetDimension() || indexSecondColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ListSequence<T> buf;
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
void ListSquareMatrix<T>::MultScalar(T scalar) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
void ListSquareMatrix<T>::AddMatrix(ListSquareMatrix<T>* squarearMatrix) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

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
T ListSquareMatrix<T>::GetNorm() {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
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