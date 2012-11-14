//
//  Stack.h
//  project5_hanoi_towers
//
//  Created by Taylor Mansfield on 11/6/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <cstdlib>

template<class T>
class StackNode
{
private:
    T item;
    StackNode* next;
public:
    StackNode()
    {
        next=NULL;
    }
    ~StackNode()
    {}
    T getItem()
    {
        return item;
    }
    StackNode<T>* getPtr()
    {
        return next;
    }
    void setItem(T newitem)
    {
        item = newitem;
    }
    void setPtr(StackNode* nextItm)
    {
        next=nextItm;
    }
};

template<class T>
class Stack
{
    private:
        int length;
        StackNode<T>* top;

    public:
        Stack();
        ~Stack();
        void MakeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        void Push(T item);
        T Pop();
        T Top() const;
        
};

template<class T>
Stack<T>::Stack()
{
    top=NULL;
}

template<class T>
Stack<T>::~Stack()
{
    StackNode<T>* tempptr;
    for(int i = 0; i<length; i++)
    {
        tempptr=top;
        top=top->getPtr();
        delete tempptr;
    }
}

template<class T>
void Stack<T>::MakeEmpty()
{
    StackNode<T>* tempptr;
    for(int i = 0; i<length; i++)
    {
        tempptr=top;
        top=top->next;
        delete tempptr;
    }
}

template<class T>
bool Stack<T>::isEmpty() const
{
    if (top==NULL)
        return true;
    else
        return false;
}

template<class T>
bool Stack<T>::isFull() const
{
    return false;
}

template<class T>
void Stack<T>::Push(T item)
{
    StackNode<T>* tmpPtr= new StackNode<T>();
    tmpPtr->setItem(item);
    tmpPtr->setPtr(top);
    top=tmpPtr;
}

template<class T>
T Stack<T>::Pop()
{
    T item;
    StackNode<T>* tmpPtr;
    tmpPtr=top;
    top=top->getPtr();
    item = tmpPtr->getItem();
    delete tmpPtr;
    return item;
}

template<class T>
T Stack<T>::Top() const
{
    return top->getItem();
}

#endif
