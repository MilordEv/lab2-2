#ifndef __ARRAYRECTANGULARMATRIX__
#define __ARRAYRECTANGULARMATRIX__

#include "ArraySequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ArrayRectangularMatrix {
    private:
        size_t numberRows;
        ArraySequence<T>* items;

    public:
        ArrayRectangularMatrix(int numberRow, int numberColumn, T** items);
        ArrayRectangularMatrix();
        ArrayRectangularMatrix(const ArrayRectangularMatrix<T> &rectangularMatrix);
        ~ArrayRectangularMatrix();

        size_t GetNumberRows() const; 
        size_t GetNumberColumns() const; 
        T Get(int indexRow, int indexColumn) const;

        void AddRow(T* newRow, int indexRow);
        void AddColumn(T* newColumn, int indexColumn);

        void MultRow(int numberRow, T scalar);
        void MultColumn(int numberColumn, T scalar);
        void AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient);
        void AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient);
        void SwapRows(int indexFirstRow, int indexSecondRow);
        void SwapColumns(int indexFirstColumn, int indexSecondColumn);

        void MultScalar(T scalar);
        void AddMatrix(ArrayRectangularMatrix<T>* rectangularMatrix);

        T GetNorm();

        const ArrayRectangularMatrix<T> & operator = (const ArrayRectangularMatrix<T> & rectangularMatrix);

};

template<typename T>
ArrayRectangularMatrix<T>::ArrayRectangularMatrix(int numberRow, int numberColumn, T** items) {
    this->numberRows = numberRow;

    this->items = new ArraySequence<T>[numberRow];
    for (int i = 0; i < numberRow; i++) {
        for (int j = 0; j < numberColumn; j++) {
            (this->items)[i].Append(items[i][j]);
        }
    }
}

template<typename T>
ArrayRectangularMatrix<T>::ArrayRectangularMatrix() {
    this->numberRows = 0;

    this->items = nullptr;
}

template<typename T>
ArrayRectangularMatrix<T>::ArrayRectangularMatrix(const ArrayRectangularMatrix<T> &rectangularMatrix) {
    this->numberRows = rectangularMatrix.GetNumberRows();
    this->items = new ArraySequence<T>[rectangularMatrix.GetNumberRows()];

    for (int i = 0; i < rectangularMatrix.GetNumberRows(); i++) {
        for (int j = 0; j < rectangularMatrix.GetNumberColumns(); j++) {
            (this->items)[i].Append(rectangularMatrix.Get(i, j));
        }
    }
}


template<typename T>
const ArrayRectangularMatrix<T> & ArrayRectangularMatrix<T>::operator = (const ArrayRectangularMatrix<T> & rectangularMatrix) {
    this->numberRows = rectangularMatrix.GetNumberRows();
    this->items = new ArraySequence<T>[rectangularMatrix.GetNumberRows()];

    for (int i = 0; i < rectangularMatrix.GetNumberRows(); i++) {
        for (int j = 0; j < rectangularMatrix.GetNumberColumns(); j++) {
            (this->items)[i].Append(rectangularMatrix.Get(i, j));
        }
    }

    return *this;
}




template<typename T>
ArrayRectangularMatrix<T>::~ArrayRectangularMatrix() {
    delete[] this->items;
}





template<typename T>
size_t ArrayRectangularMatrix<T>::GetNumberRows() const {
    return this->numberRows;
}

template<typename T>
size_t ArrayRectangularMatrix<T>::GetNumberColumns() const {
    return (this->items)[0].GetLength();
}

template<typename T>
T ArrayRectangularMatrix<T>::Get(int indexRow, int indexColumn) const {
    if (indexRow >= this->numberRows || indexRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumn >= this->GetNumberColumns() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    return (this->items)[indexRow].Get(indexColumn);
}

template<typename T>
void ArrayRectangularMatrix<T>::AddRow(T* newRow, int indexRow) {
    if (indexRow > this->numberRows || indexRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ArraySequence<T>* oldItems = new ArraySequence<T>[this->numberRows];

    for (int i = 0; i < this->numberRows; i++) {
        for (int j = 0; j < this->GetNumberColumns(); j++) {
            oldItems[i].Append(this->Get(i, j));
        }
    }

    int numberColumn = this->GetNumberColumns();
    delete[] this->items;
    this->items = new ArraySequence<T>[this->numberRows + 1];
    
    for (int i = 0; i < indexRow; i++) {
        for (int j = 0; j < numberColumn; j++) {
            (this->items)[i].Append(oldItems[i].Get(j));
        }
    }

    for (int i = 0; i < numberColumn; i++) {
            (this->items)[indexRow].Append(newRow[i]);
    }

    for (int i = indexRow + 1; i < this->numberRows + 1; i++) {
        for (int j = 0; j < numberColumn; j++) {
            (this->items)[i].Append(oldItems[i-1].Get(j));
        }
    }

    this->numberRows += 1;

    delete[] oldItems;
}


template<typename T>
void ArrayRectangularMatrix<T>::AddColumn(T* newColumn, int indexColumn) {
    if (indexColumn > this->GetNumberColumns() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    for (int i = 0; i < this->numberRows; i++) {
        (this->items)[i].InsertAt(newColumn[i], indexColumn);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::MultRow(int numberRow, T scalar) {
    if (numberRow > this->numberRows || numberRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetNumberColumns(); i++) {
        this->items[numberRow].Set(scalar * this->Get(numberRow, i), i);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::MultColumn(int numberColumn, T scalar) {
    if (numberColumn > this->GetNumberColumns() || numberColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->numberRows; i++) {
        this->items[i].Set(scalar * this->Get(i, numberColumn), numberColumn);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient) {
    if (indexRowWhereAdd >= this->numberRows || indexRowWhereAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexRowWhicheAdd >= this->numberRows || indexRowWhicheAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(coefficient)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetNumberColumns(); i++) {
        this->items[indexRowWhereAdd].Set(coefficient * this->Get(indexRowWhicheAdd, i) + this->Get(indexRowWhereAdd, i), i);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient) {
    if (indexColumnWhereAdd >= this->GetNumberColumns() || indexColumnWhereAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumnWhicheAdd >= this->GetNumberColumns() || indexColumnWhicheAdd < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (!(coefficient)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->numberRows; i++) {
        this->items[i].Set(coefficient * this->Get(i, indexColumnWhicheAdd) + this->Get(i, indexColumnWhereAdd), indexColumnWhereAdd);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::SwapRows(int indexFirstRow, int indexSecondRow) {
    if (indexFirstRow >= this->numberRows || indexFirstRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexSecondRow >= this->numberRows || indexSecondRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ArraySequence<T> buf;
    for (int i = 0; i < this->GetNumberColumns(); i++) {
        buf.Append(this->Get(indexFirstRow, i));
    }
    for (int i = 0; i < this->GetNumberColumns(); i++) {
       this->items[indexFirstRow].Set(this->Get(indexSecondRow, i), i);
    }
    for (int i = 0; i < this->GetNumberColumns(); i++) {
       this->items[indexSecondRow].Set(buf.Get(i), i);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::SwapColumns(int indexFirstColumn, int indexSecondColumn) {
    if (indexFirstColumn >= this->numberRows || indexFirstColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexSecondColumn >= this->numberRows || indexSecondColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    ArraySequence<T> buf;
    for (int i = 0; i < this->numberRows; i++) {
        buf.Append(this->Get(i, indexFirstColumn));
    }
    for (int i = 0; i < this->numberRows; i++) {
       this->items[i].Set(this->Get(i, indexSecondColumn), indexFirstColumn);
    }
    for (int i = 0; i < this->numberRows; i++) {
       this->items[i].Set(buf.Get(i), indexSecondColumn);
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::MultScalar(T scalar) {
    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->numberRows; i++) {
        for (int j = 0; j < this->GetNumberColumns(); j++) {
            this->items[i].Set(this->Get(i, j) * scalar, j);
        }
    }
}

template<typename T>
void ArrayRectangularMatrix<T>::AddMatrix(ArrayRectangularMatrix<T>* rectangularMatrix) {
    if (this->numberRows != rectangularMatrix->numberRows) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    if (this->GetNumberColumns() != rectangularMatrix->GetNumberColumns()) {
        throw std::invalid_argument("the number of columns in the matrix does not match");
    }

    for (int i = 0; i < this->numberRows; i++) {
        for (int j = 0; j < this->GetNumberColumns(); j++) {
            this->items[i].Set(this->Get(i, j) + rectangularMatrix->Get(i, j), j);
        }
    }
} 

template<typename T>
T ArrayRectangularMatrix<T>::GetNorm() {
    if (!(this->GetNumberRows())) {
        throw std::domain_error("empty matrix");
    }

    T valueNorm = this->Get(0, 0);
    valueNorm *= valueNorm;

    for (int i = 0; i < this->GetNumberRows(); i++) {
        for (int j = 0; j < this->GetNumberColumns(); j++) {
            if (!(i == 0 && j == 0)) {
                valueNorm += this->Get(i, j) * this->Get(i, j);
            }
        }
    }

    return pow(valueNorm, 0.5);
}


#endif