//
//  Queue.h
//  project6
//
//  Created by Taylor Mansfield on 11/10/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

template<class T>
class QueNode
{
private:
    T item;
    QueNode* next;
public:
    QueNode()
    {
        next=NULL;
    }
    ~QueNode()
    {}
    T getItem()
    {
        return item;
    }
    QueNode<T>* getPtr()
    {
        return next;
    }
    void setItem(T newitem)
    {
        item = newitem;
    }
    void setPtr(QueNode* nextItm)
    {
        next=nextItm;
    }
};

class FullQueue
{};

class EmptyQueue
{};

template<class T>
class Queue
{
private:
    QueNode<T>* front;
    QueNode<T>* rear;
    
public:
    Queue();
    ~Queue();
    void MakeEmpty();
    bool isEmpty() const;
    bool isFull() const;
    void Enqueue(T item);
    T Dequeue();
    T Front() const;
    T Rear() const;
    
};

template<class T>
Queue<T>::Queue()
{
    front=NULL;
    rear=NULL;
}

template<class T>
Queue<T>::~Queue()
{
    MakeEmpty();
}

template<class T>
void Queue<T>::MakeEmpty()
{
    QueNode<T>* tempptr;
    while(front!=NULL)
    {
        tempptr=front;
        front=front->next;
        delete tempptr;
    }
    rear = NULL;
}

template<class T>
bool Queue<T>::isEmpty() const
{
    if (front==NULL)
        return true;
    else
        return false;
}

template<class T>
bool Queue<T>::isFull() const
{
    QueNode<T>* loc;
    try
    {
        loc = new QueNode<T>;
        delete loc;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

template<class T>
void Queue<T>::Enqueue(T item)
{
    if (!isFull())
    {
        QueNode<T>* tmpPtr= new QueNode<T>();
        tmpPtr->setItem(item);
        if(isEmpty())
        {
            front=tmpPtr;
            rear=tmpPtr;
        }
        else
        {
            rear->setPtr(tmpPtr);
            rear=tmpPtr;
        }
    }
    else
    {
        throw FullQueue();
    }
}

template<class T>
T Queue<T>::Dequeue()
{
    if (isEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        T item;
        QueNode<T>* tmpPtr;
        item = front->getItem();
        tmpPtr=front;
        front=front->getPtr();

        delete tmpPtr;
        return item;
    }
}

#endif /* defined(Queue) */
