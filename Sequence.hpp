#ifndef __SEQUENCE__
#define __SEQUENCE__

template<typename T>
class Sequence {
    public:
        virtual T GetFirst() = 0;
        virtual T GetLast() = 0;
        virtual T Get(int index) = 0;
        virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
        virtual int GetLength() = 0;

        virtual void Set(T item, int index) = 0;
        virtual void Append(T item) = 0;
        virtual void Prepend(T item) = 0;
        virtual void InsertAt(T item, int index) = 0;
        virtual void Remove(int index) = 0;
        virtual Sequence<T>* Concat(Sequence<T> *list) = 0;

        virtual Sequence<T>* Map(T func(T)) = 0;
        virtual Sequence<T>* Where(bool func(T)) = 0;
        virtual T Reduce(T func(T, T), T startValue) = 0;

        virtual ~Sequence() {};
};


#endif