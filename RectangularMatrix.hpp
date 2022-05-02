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

        void addRow(T* newRow, int indexRow);
        void addColumn(T* newColumn, int indexColumn);

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
void RectangularMatrix<T>::addRow(T* newRow, int indexRow) {
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
void RectangularMatrix<T>::addColumn(T* newColumn, int indexColumn) {
    if (indexColumn > this->numberRows || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    for (int i = 0; i < this->numberRows; i++) {
        (this->items)[i].InsertAt(newColumn[i], indexColumn);
    }
}

#endif