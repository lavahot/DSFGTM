#ifndef QUE_LIST_H
#define QUE_LIST_H

/* This template class implements the que list.
 * The que list is an expandable FIFO ADT.
 * Item type T is assumed to have order relations.
 * author\ Frank Greenhalgh and Taylor Mansfield
 */
#include "node.h"

template <typename T>
class QueList
{
 Node<T>* d_qFront;
 Node<T>* d_qRear;
 int length;
 int MAX_LENGTH;
 public:
  QueList();
  //Pre:  None
  //Post: Que empty
  
  QueList(int maxsize);
  //pre: maxsize is a positive integer.
  //post: Que Empty

  ~QueList();
  //Pre: Que has item
  //Post: Que memory freed

  void MakeEmpty();
  //Pre: Que has item
  //Post: Que memory freed

  bool IsEmpty() const;
  //Pre: Que is initialized
  //Post: Answers "Is empty?"

  bool IsFull() const;
  //Pre: Que is initialized
  //Post: Answers "Is full?"
  
  int GetLength() const;
  //Pre: Que is initialized
  //Post: Answers "How long?"

  void Enqueue(T newItem);
  //Pre: Que initialized
  //Post: Added member to back

  void EnqueueFront(T newItem);
  //Pre: Que initialized
  //Post: Added member to front

  void Dequeue(T &newItem);
  //Pre: Que not empty
  //Post: Get member from front
  
};//end QueList

template <typename T>
  QueList<T>::QueList()
  // Pre: None.
  // Post: List is empty.
  {
   d_qFront=NULL;
   d_qRear=NULL;
  }
  
  QueList<T>::QueList(int maxsize)
  // Pre: None.
  // Post: List is empty.
  {
   MAX_LENGTH=maxsize;
   d_qFront=NULL;
   d_qRear=NULL;
  }

template <typename T>
  QueList<T>::~QueList()
  //Pre: Que has item
  //Post: Que memory freed
  {
   MakeEmpty();
  }

template <typename T>
  void QueList<T>::MakeEmpty()
  //Pre: Que has item
  //Post: Que memory freed
  {
   Node<T>* temp;
   while(d_qFront!=NULL)
   {
    temp = d_qFront;
    d_qFront = d_qFront->next;
    delete temp;
   }
   d_qRear=NULL;
  }

template <typename T>
  bool QueList<T>::IsEmpty() const
  //Pre: Que is initialized
  //Post: Answers "Is empty?"
  {
   return (d_qRear==NULL);
  }

template <typename T>
  bool QueList<T>::IsFull() const
  //Pre: Que is initialized
  //Post: Answers "Is full?"
  {
  	if(length<MAX_LENGTH)
  		return true;
  	else
   		return false;
  }

template <typename T>
  void QueList<T>::Enqueue(T newItem)
  //Pre: Que initialized and not full
  //Post: Added member to back
  {
   length++;
   Node<T>* temp_node = new Node<T>;
   temp_node->data = newItem;
   temp_node->next = NULL;
   if( d_qRear!=NULL ){
    d_qRear->next = temp_node;
    d_qRear = temp_node;
   }
   else
    d_qRear=d_qFront=temp_node;
  }

template <typename T>
  void QueList<T>::EnqueueFront(T newItem)
  //Pre: Que initialized and not full
  //Post: Added member to front
  {
   length++;
   Node<T>* temp_node = new Node<T>;
   temp_node->data = newItem;
   temp_node->next = d_qFront;
   d_qFront = temp_node;
   if(d_qRear==NULL){
    d_qRear=d_qFront;
   }
  }

template <typename T>
  void QueList<T>::Dequeue(T &newItem)
  //Pre: Que not empty
  //Post: Get member from front
  {
   length--;
   Node<T>* temp_node;
   newItem = d_qFront->data;
   temp_node = d_qFront;
   d_qFront = d_qFront->next;
   delete temp_node;
   if(d_qFront==NULL)
    d_qRear=NULL;
  }
  
#endif
