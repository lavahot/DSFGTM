#ifndef NODE_H
#define NODE_H

/* A node
 */
template <typename T>
 struct Node
 {
   T data;
   Node<T>* next;
 };

#endif
