#ifndef SORTED_VECTOR_H
#define SORTED_VECTOR_H

/* This template class implements the sorted vector from the book.
 * This class remains sorted at all times.
 * Item type T is assumed to have order relations.
 * author\ Frank Greenhalgh
 */

const int MAX_LENGTH=10;

template <typename T>
class SortedVector
{
 int length;
 T info[MAX_LENGTH];
 int cur_pos;
 int acp;//assignment cur_pos
 public:
  SortedVector();
  // Pre: None.
  // Post: List is empty.

  void MakeEmpty();
  // Pre: List has been initialized.
  // Post: List is empty.

  bool IsEmpty() const;
  bool IsFull() const;
  // Pre: List has been initialized.
  // Post: Funnction value == (list is full ).

  int GetLength() const;
  // Pre: List has been initialized.
  // Post: Function value == (number of elements in
  // 	list ).

  T GetItem( T item, bool& found ) const;
  // Pre: Key memebr of item is initialzed.
  // PostL: If found, item's key matches an elmenet's key in the list
  // and a copy of that element is returned; otherwise,
  // original item is returned.

  T &operator[](int index_) const;

  void PutItem( T const& item );
  //void PutItem( T item );
  // Pre: List has been initialized. List is not full.
  // item is not in list.
  // List is sorted by key member using function ComparedTo.
  // Post: item is in the list. List is still sorted.

  void DeleteItem( T item );
  // Pre: List has been initialized.
  // Key member of item is initialized.
  // Exactly one element in list has a key matching item's key
  // List is sorted by key member using function ComparedTo.
  // Post: No item in list has key matching item's key.
  // List is still sorted.

  void ResetList();
  // Pre: List has been initialized.
  // Post: Current position is prior to first element in list.
  
  void ARL();
  // Pre: List has been initialized.
  // Post: Current position is prior to first element in list.
  
  T GetNextItem();
  // Pre: List has been initialized. Current position is defined.
  //  Element at current position is not last in list.
  //  Post: Current position is updated to next position.
  //  item is a copy of element at current position.

  SortedVector<T> const &operator=(SortedVector<T> const &rhs);
  SortedVector<T> &operator=(SortedVector<T> &rhs);
  // Pre: 
  // Post:
  
  T AGNI();
  // Pre: List has been initialized. Current position is defined.
  //  Element at current position is not last in list.
  //  Post: Current position is updated to next position.
  //  item is a copy of element at current position.

};//end SortedVector

template <typename T>
  SortedVector<T>::SortedVector()
  // Pre: None.
  // Post: List is empty.
  {
   length=0;
   cur_pos=-1;
  }

template <typename T>
  void SortedVector<T>::MakeEmpty()
  {
   length=0;
   cur_pos=-1;
  }

template <typename T>
  bool SortedVector<T>::IsEmpty() const
  {
   return (length==0);
  }
template <typename T>
  bool SortedVector<T>::IsFull() const
  // Pre: List has been initialized.
  // Post: Funnction value == (list is full ).
  {
   return (length==MAX_LENGTH);
  }

template <typename T>
  int SortedVector<T>::GetLength() const
  // Pre: List has been initialized.
  // Post: Function value == (number of elements in
  // 	list ).
  {
   return length;
  }

template <typename T>
  T SortedVector<T>::GetItem( T item, bool& found ) const
  // Pre: Key memebr of item is initialzed.
  // PostL: If found, item's key matches an elmenet's key in the list
  // and a copy of that element is returned; otherwise,
  // original item is returned.
  {
   int midPoint;
   int first = 0;
   int last=length-1;

   bool moreToSearch = (first<=last);
   found=false;
   
   while(moreToSearch&&!found)
   {
    midPoint=(first+last)/2;//INDEX OF MIDDLE ELEMENT
    if( item.first<info[midPoint].first )
    {
     last=midPoint-1;
     moreToSearch=(first<=last);
    }
    else if( item.first>info[midPoint].first )
    {
     first=midPoint+1;
     moreToSearch=(first<=last);
    }
    else
    {
     found=true;
     item=info[midPoint];
    }
   }//end while
   return item;
  }//end GetItem

template <typename T>
  void SortedVector<T>::PutItem( T const& item )
  {
   bool moreToSearch;
   int location = 0;
   //find proper location for new element
   moreToSearch = ( location < length );
   while( moreToSearch )
   {
    if( item.first < info[location].first )
     moreToSearch=false;
    else
    {
     location++;
     moreToSearch=(location<length);
    }
   } //make room for new element in sorted list
   for( int index = length; index>location; index-- )
    info[index] = info[ index-1 ];
   info[location] = item;
   length++;
  }//end PutItem

/*
template <typename T>
  void SortedVector<T>::PutItem( T item )
  // Pre: List has been initialized. List is not full.
  // item is not in list.
  // List is sorted by key member using function ComparedTo.
  // Post: item is in the list. List is still sorted.
  {
   bool moreToSearch;
   int location = 0;
   //find proper location for new element
   moreToSearch = ( location < length );
   while( moreToSearch )
   {
    if( item < info[location] )
     moreToSearch=false;
    else
    {
     location++;
     moreToSearch=(location<length);
    }
   } //make room for new element in sorted list
   for( int index = length; index>location; index-- )
    info[index] = info[ index-1 ];
   info[location] = item;
   length++;
  }//end PutItem
*/

template <typename T>
  void SortedVector<T>::DeleteItem( T item )
  // Pre: List has been initialized.
  // Key member of item is initialized.
  // Exactly one element in list has a key matching item's key
  // List is sorted by key member using function ComparedTo.
  // Post: No item in list has key matching item's key.
  // List is still sorted.
  {
   int location = 0;
   //find location of element to be deleted

   while( item.first>info[location].first||item.first<info[location].first )
    location++;

   //move up elmeents that follow deleted item in sorted list

   for( int index = location+1; index<length; index++ )
    info[index-1]=info[index];
   
   length--;
  } //end DeleteItem

template <typename T>
  void SortedVector<T>::ResetList()
  // Pre: List has been initialized.
  // Post: Current position is prior to first element in list.
  {
   cur_pos=-1;
  }

template <typename T>
  void SortedVector<T>::ARL()
  // Pre: List has been initialized.
  // Post: Current position is prior to first element in list.
  {
   acp=-1;
  }
  
template <typename T>
  T SortedVector<T>::GetNextItem()
  // Pre: List has been initialized. Current position is defined.
  //  Element at current position is not last in list.
  //  Post: Current position is updated to next position.
  //  item is a copy of element at current position.
  {
   cur_pos++;
   return info[cur_pos];
  }

template <typename T>
  T SortedVector<T>::AGNI()
  // Pre: List has been initialized. Current position is defined.
  //  Element at current position is not last in list.
  //  Post: Current position is updated to next position.
  //  item is a copy of element at current position.
  {
   acp++;
   return info[acp];
  }
  

template <typename T>
  T &SortedVector<T>::operator[](int index_) const
  {
   return info[index_];
  }

template <typename T>
  SortedVector<T> &SortedVector<T>::operator=(SortedVector<T> &rhs) 
  // Pre: rhs is initialized. List initialized
  // Post: List is equal to rhs. rhs is reset
  {
   rhs.ARL();
   MakeEmpty();
   ARL();

   int rhs_length = rhs.GetLength();
   for(int i=0; i<rhs_length; i++ )
    PutItem(rhs.AGNI());

   rhs.ARL();
   ARL();

   return rhs;
  }

template <typename T>
  SortedVector<T> const &SortedVector<T>::operator=(SortedVector<T> const &rhs) 
  // Pre: rhs is initialized. List initialized
  // Post: List is equal to rhs. rhs is reset
  {
   MakeEmpty();
   ARL();

   int rhs_length = rhs.GetLength();
   for(int i=0; i<rhs_length; i++ )
    PutItem(rhs[i]);

   ARL();
   return rhs;
  }
#endif
