#ifndef __DYNAMICARRAY__
#define __DYNAMICARRAY__

#include <stdexcept>

template <typename T>
class DynamicArray {

    private:
        T* items;
        size_t count;

    public:
       /* DynamicArray(T* items, size_t count) : count(count), capacity(count) {
            T* array = new T[count];
            for (int i = 0; i < count; i++) {
                array[i] = items[i];
            }
        }

        DynamicArray(size_t capacity) : capacity(capacity), count(0) {
            T* array = new T[capacity];
        }

        DynamicArray(const DynamicArray<T> & dynamicArray) {
            
        }*/
    public:
        T get(size_t index) {
            if (index >= count)  {
                throw std::out_of_range("Out of the range of the array");
            } else {
                return items[index];
            }

        }

        size_t getSize() {
            return count;
        }


};

#endif