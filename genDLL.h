#include <iostream>
#include <stdexcept>

using namespace std;

////Template List node class////
template <class T>
class ListNode
{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        T data;
        ListNode *next;
        ListNode *prev;
};

////implementation////
template <class T>
ListNode<T>::ListNode()
{
    data = NULL;
    next = NULL;
    prev = NULL;
}
template <class T>
ListNode<T>::ListNode(T d)
{
    data = d;
    next = NULL;
    prev = NULL;
}
template <class T>
ListNode<T>::~ListNode()
{
    //you know
}

////Template Doubly Linked List Class////
template <class T>
class DoublyLinkedList
{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertFront(T data);
        void insertBack(T data);
        T removeFront();
        T removeBack();
        T remove(T key);

        void printList();
        T find(T val); //search()

        bool isEmpty();
        unsigned int getSize();
        T deletePos(int position);

};

////implementation////
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    size = 0;
    front = NULL;
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    ListNode<T> *current = front;
    ListNode<T> *next = front;

    while (size > 0)
    {
        next = current->next;
        next->prev = NULL;
        current->next = NULL;
        delete current;
        current = next;
        size--;
    }
}
template <class T>
void DoublyLinkedList<T>::insertFront(T data)
{
    ListNode<T> *node = new ListNode<T>(data);
    if(isEmpty())
    {
        back = node;
    }
    else //not an empty list
    {
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}
template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
    ListNode<T> *node = new ListNode<T>(data);
    if(isEmpty())
    {
        front = node;
    }
    else //not an empty list
    {
        back->next = node;
        node->prev = back;
    }
    back = node;
    size++;
}
template <class T>
T DoublyLinkedList<T>::removeFront()
{
    //check if empty
    if(isEmpty())
    {
        throw out_of_range("The List is Empty");
    }

    ListNode<T> *node = front;

    //check if there is only one element
    if(front->next == NULL) // there is only one element in the list
    {
        back = NULL;
    }
    else //more than one element
    {
        //set the prev of the next node to null
        front->next->prev = NULL;
    }
    front = front->next;
    T temp = node->data;
    node->next = NULL;

    delete node;
    size--;

    return temp;
}
template <class T>
T DoublyLinkedList<T>::removeBack()
{
    //check if empty
    if(isEmpty())
    {
        throw out_of_range("The List is Empty");
    }

    ListNode<T> *node = front;
    //check if there is only one element
    if(front->next == NULL) // there is only one element in the list
    {
        back = NULL;
    }
    else //more than one element
    {
        //set the prev of the next node to null
        front->next->prev = NULL;
    }
    front = front->next;
    T temp = node->data;
    node->next = NULL;

    delete node;
    size--;

    return temp;
}
template <class T>
T DoublyLinkedList<T>::remove(T key)
{
    //check if empty
    if(isEmpty())
    {
        throw out_of_range("The List is Empty");
    }

    ListNode<T> *current = front;

    while(current->data != key)
    {
        current=current->next;
        if(current == NULL)
            return NULL;
    }
    if(current == front)//front node
    {
        front = current->next;
    }
    else
    {
        current->prev->next = current->next;
    }
    if(current == back)
    {
        back = current->prev;
    }
    else
    {
        current->next->prev = current->prev;
    }
    current->next = NULL;
    current->prev = NULL;

    size--;

    return current->data;

}

template <class T>
void DoublyLinkedList<T>::printList()
{
    ListNode<T> *current = front;

    if(isEmpty())
    {
        cout << "There is nothing here" << endl;
    }
    else
    {
        while(current)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
}
template <class T>
T DoublyLinkedList<T>::find(T val)
{
    int idx = -1;

    ListNode<T> *current = front;
    while(current != NULL)
    {
        ++idx;
        if (current->data == val) //we found it
            break;
        else
            current = current->next;
    }

    if (current == NULL)
        idx = -1;

    return idx;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (size == 0);
}
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
    return size;
}
template <class T>
T DoublyLinkedList<T>::deletePos(int position)
{
    if (position > size)
    {
        throw out_of_range("Given position was out of range of the list");
    }

    int idx = 0;

    ListNode<T> *current = front;
    ListNode<T> *prev = front;

    while(idx =! position)
    {
        prev = current; //stay back
        current = current->next;
        ++idx;

    }

    //when we find the correct position, update pointers
    prev->next = current->next;
    current->next = NULL;
    int temp = current->data;
    delete current;
    size--;

    return temp;

}
