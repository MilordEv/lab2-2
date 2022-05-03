#ifndef __RECTANGULARMATRIX__
#define __RECTANGULARMATRIX__

#include "ArraySequence.hpp"
#include <stdexcept>

template<typename T>
class RectangularMatrix {
    private:
        size_t numberRows;
        ArraySequence<T>* items;

    public:
        RectangularMatrix(int numberRow, int numberColumn, T** items);
        RectangularMatrix();
        RectangularMatrix(const RectangularMatrix<T> &rectangularMatrix);
        ~RectangularMatrix();

        size_t GetNumberRows(); 
        size_t GetNumberColumns(); 
        T Get(int indexRow, int indexColumn);

        void AddRow(T* newRow, int indexRow);
        void AddColumn(T* newColumn, int indexColumn);

        void MultRow(int numberRow, T scalar);
        void MultColumn(int numberColumn, T scalar);
        void AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient);
        void AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient);
        void SwapRows(int indexFirstRow, int indexSecondRow);
        void SwapColumns(int indexFirstColumn, int indexSecondColumn);

};

template<typename T>
RectangularMatrix<T>::RectangularMatrix(int numberRow, int numberColumn, T** items) {
    this->numberRows = numberRow;

    this->items = new ArraySequence<T>[numberRow];
    for (int i = 0; i < numberRow; i++) {
        for (int j = 0; j < numberColumn; j++) {
            (this->items)[i].Append(items[i][j]);
        }
    }
}

template<typename T>
RectangularMatrix<T>::RectangularMatrix() {
    this->numberRows = 0;

    this->items = nullptr;
}

template<typename T>
RectangularMatrix<T>::RectangularMatrix(const RectangularMatrix<T> &rectangularMatrix) {
    this->numberRows = rectangularMatrix.GetNumberRows();
    this->items = new ArraySequence<T>[rectangularMatrix.GetNumberRows()];

    for (int i = 0; i < rectangularMatrix.GetNumberRows(); i++) {
        for (int j = 0; j < rectangularMatrix.GetNumberColumns(); j++) {
            (this->items)[i].Append(rectangularMatrix.Get(i, j));
        }
    }
}




template<typename T>
RectangularMatrix<T>::~RectangularMatrix() {
    delete[] this->items;
}





template<typename T>
size_t RectangularMatrix<T>::GetNumberRows() {
    return this->numberRows;
}

template<typename T>
size_t RectangularMatrix<T>::GetNumberColumns() {
    return (this->items)[0].GetLength();
}

template<typename T>
T RectangularMatrix<T>::Get(int indexRow, int indexColumn) {
    if (indexRow >= this->numberRows || indexRow < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (indexColumn >= this->GetNumberColumns() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    return (this->items)[indexRow].Get(indexColumn);
}

template<typename T>
void RectangularMatrix<T>::AddRow(T* newRow, int indexRow) {
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
void RectangularMatrix<T>::AddColumn(T* newColumn, int indexColumn) {
    if (indexColumn > this->GetNumberColumns() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    for (int i = 0; i < this->numberRows; i++) {
        (this->items)[i].InsertAt(newColumn[i], indexColumn);
    }
}

template<typename T>
void RectangularMatrix<T>::MultRow(int numberRow, T scalar) {
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
void RectangularMatrix<T>::MultColumn(int numberColumn, T scalar) {
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
void RectangularMatrix<T>::AddRowByRow(int indexRowWhereAdd, int indexRowWhicheAdd, T coefficient) {
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
void RectangularMatrix<T>::AddColumnByColumn(int indexColumnWhereAdd, int indexColumnWhicheAdd, T coefficient) {
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
void RectangularMatrix<T>::SwapRows(int indexFirstRow, int indexSecondRow) {
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
void RectangularMatrix<T>::SwapColumns(int indexFirstColumn, int indexSecondColumn) {
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




#endif