#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <cstring>
#include <stdexcept>

template <typename T>
class LinkedList {
    private:
        class Item {
            T value;
            Item* next;
        };

        Item* head;
        Item* tail;
        size_t length;

    public:
        LinkedList(T* items, int count);
        LinkedList();
        LinkedList(const LinkedList<T> &linkedList);

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
LinkedList<T>::LinkedList(T* items, int count) {
    if (count == 0) {
        LinkedList();
    } else {
        for (int i = 0; i < count; i++) {
            this->Append(items[i]);
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &linkedList) {

    if (!(linkedList->head)) {
        LinkedList<T>();
    } else {
        Item* ptr = linkedList->head;
        for (int i = 0; i < linkedList->length; i++) {
            this->Append(ptr->value);
            ptr = ptr->next;
        }
    }
    
}




template <typename T>
LinkedList<T>::~LinkedList() {
    if (!(this->length)) {
        Item* ptr = this->head;
        while (ptr) {
            Item* deleteItem = ptr;
            ptr = ptr->next;
            delete deleteItem;
        }
    }
}








template <typename T>
T LinkedList<T>::GetFirst() {
    if (this->head) {
        return this->head->value;
    } else {
        throw std::out_of_range("the list is empty");
    }
}

template <typename T>
T LinkedList<T>::GetLast() {
    if (this->tail) {
        return this->tail->value;
    } else {
        throw std::out_of_range("the list is empty");
    }
}

template <typename T>
T LinkedList<T>::Get(int index) {
    if (index >= this->length || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    } 

    Item* ptr = this->head;

    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }

    return ptr->value;
}

template <typename T>
int LinkedList<T>::GetLength() {
    return this->length;
}


template <typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex >= this->length || startIndex < 0 || endIndex >= this->length || endIndex < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    LinkedList<T>* subList = new LinkedList<T>();
    Item* ptr = this->head;
    
    for (int i = 0; i < startIndex; i++) {
        ptr = ptr->next;
    }

    for (int i = startIndex; i < endIndex; i++) {
        subList->Append(ptr->value);
        ptr = ptr->next;
    }

    return subList;
}





template <typename T>
void LinkedList<T>::Append(T item) {
    Item* newItem = new Item;
    newItem->value = item; 
    newItem->next = nullptr;

    if (this->tail) {
        this->tail->next = newItem;
        this->tail = newItem;
    } else {
        this->head = newItem;
        this->tail = newItem;
        newItem->next = nullptr;
    }

    this->length += 1;

    return;
}

template <typename T>
void LinkedList<T>::Prepend(T item) {
    Item* newItem = new Item;
    newItem->value = item;
    
    if (this->head) {
        newItem->next = this->head;
        this->head = newItem;
    } else {
        this->head = newItem;
        this->tail = newItem;
        newItem->next = nullptr;
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
        this->Prepend(item);
    } else {

        Item* ptr = this->head;

        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }

        Item* nextItem = new Item;
        nextItem->next = ptr->next;
        nextItem->value = ptr->value;

        ptr->next = nextItem;
        ptr->value = item;
        this->length += 1;
    }
}

template <typename T>
void LinkedList<T>::Remove(int index) {
    if (index >= this->length || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    }
    
    Item* ptr = this->head;
    Item* previousItem = this->head;

    if (index == 0) {
        this->head = this->head->next;
        delete ptr;  

    } else {
        for (int i = 0; i < index; i++) {
            previousItem = ptr;
            ptr = ptr->next;
        }

        previousItem->next = ptr->next;
        delete ptr;
    }

    this->length -= 1;
    return;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list) {

    if (!(list->head)) {
        return this;
    }

    Item* ptr = list->head;

    while(ptr) {
        this->Append(ptr->value);
        ptr = ptr->next;
    }

    return this;

}


#endif