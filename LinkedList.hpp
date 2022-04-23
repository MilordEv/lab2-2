#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <cstring>
#include <stdexcept>

template <typename T>
class LinkedList {
    private:
        class Item {
            T value;
            Item* Next;
        };

        Item* start;
        Item* end;
        size_t length;

    public:
        LinkedList(T* items, int count);
        LinkedList();
        LinkedList(const LinkedList<T> &lindedList);

        ~LinkedList(); 

        T GetFirst();
        T GetLast();
        T Get(int index);
        int GetLength();
        LinkedList<T>* GetSubList(int startIndex, int endIndex);

        void Append(T item);
        void Prepend(T item);
        void InsertAt(int index, T item);
        void Remove(int index);
        LinkedList<T>* Concat(LinkedList<T> *list);

};




template <typename T>
void LinkedList<T>::Append(T item) {
    Item* newItem = new Item;
    newItem->value = item; 
    newItem->Next = nullptr;

    if (this->end) {
        this->end->Next = newItem;
        this->end = newItem;
    } else {
        this->start = newItem;
        this->end = newItem;
        newItem->Next = nullptr;
    }

    this->length += 1;

    return;
}

template <typename T>
void LinkedList<T>::Prepend(T item) {
    Item* newItem = new Item;
    newItem->value = item;
    
    if (this->start) {
        newItem->Next = this->start;
        this->start = newItem;
    } else {
        this->start = newItem;
        this->end = newItem;
        newItem->Next = nullptr;
    }

    this->length += 1;

    return;
}

template <typename T>
void LinkedList<T>::InsertAt(int index, T item) {
    if (index >= this->length || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    }

    if (index == 0) {
        this->Append(item);
    } else {

        Item* ptr = this->start;

        for (int i = 0; i < index; i++) {
            ptr = ptr->Next;
        }

        Item* nextItem = new Item;
        nextItem->Next = ptr->Next;
        nextItem->value = ptr->value;

        ptr->Next = nextItem;
        ptr->value = item;
        this->length += 1;
    }
}

template <typename T>
void LinkedList<T>::Remove(int index) {
    if (index >= this->length || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    }
    
    Item* ptr = this->start;
    Item* previousItem = this->start;

    if (index == 0) {
        this->start = this->start->Next;
        delete ptr;  

    } else {
        for (int i = 0; i < index; i++) {
            previousItem = ptr;
            ptr = ptr->Next;
        }

        previousItem->Next = ptr->Next;
        delete ptr;
    }

    this->length -= 1;
    return;
}


#endif