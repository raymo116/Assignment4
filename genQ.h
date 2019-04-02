#include "genDLL.h"
#include <iostream>

using namespace std;

template <class T>
class GenQ
{
    public:
        GenQ(); //constructor
        GenQ(int size); //overloaded constructor
        ~GenQ();

        void insert (T d); //enqueue
        T remove(); //dequeue
        T front(); //peak

        bool isFull();
        bool isEmpty();
        int getSize();

        int mSize;
        int head; //front of queue
        int tail; //rear of queue
        int numElements; //number of elements in my queue

        DoublyLinkedList<T>  *myQueue;
};

template <class T>
GenQ<T>::GenQ()
{
    mSize = 128;
    myQueue = new DoublyLinkedList<T>;
    numElements = 0;
}

template <class T>
GenQ<T>::GenQ(int maxSize)
{
    mSize = maxSize;
    myQueue = new DoublyLinkedList<T>;
    numElements = 0;
}

template <class T>
GenQ<T>::~GenQ()
{
    delete myQueue;
}

template <class T>
void GenQ<T>::insert(T d)
{
    myQueue->insertBack(d);

    ++numElements;
}

template <class T>
T GenQ<T>::remove()
{
    if(isEmpty())
    {
        throw out_of_range("The queue is empty");
    }

    numElements--;
    return myQueue->removeFront(); //advance the head
}

template <class T>
T GenQ<T>::front()
{
    return myQueue->front->data;
}

template <class T>
bool GenQ<T>::isFull()
{
    return (numElements == mSize);
}

template <class T>
bool GenQ<T>::isEmpty()
{
    return (numElements == 0);
}

template <class T>
int GenQ<T>::getSize()
{
    return numElements;
}
