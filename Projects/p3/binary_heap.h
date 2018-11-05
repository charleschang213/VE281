#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <algorithm>
#include "priority_queue.h"

// OVERVIEW: A specialized version of the 'heap' ADT implemented as a binary
//           heap.
template<typename TYPE, typename COMP = std::less<TYPE> >
class binary_heap: public priority_queue<TYPE, COMP> {
public:
  typedef unsigned size_type;

  // EFFECTS: Construct an empty heap with an optional comparison functor.
  //          See test_heap.cpp for more details on functor.
  // MODIFIES: this
  // RUNTIME: O(1)
  binary_heap(COMP comp = COMP());

  // EFFECTS: Add a new element to the heap.
  // MODIFIES: this
  // RUNTIME: O(log(n))
  virtual void enqueue(const TYPE &val);

  // EFFECTS: Remove and return the smallest element from the heap.
  // REQUIRES: The heap is not empty.
  // MODIFIES: this
  // RUNTIME: O(log(n))
  virtual TYPE dequeue_min();

  // EFFECTS: Return the smallest element of the heap.
  // REQUIRES: The heap is not empty.
  // RUNTIME: O(1)
  virtual const TYPE &get_min() const;

  // EFFECTS: Get the number of elements in the heap.
  // RUNTIME: O(1)
  virtual size_type size() const;

  // EFFECTS: Return true if the heap is empty.
  // RUNTIME: O(1)
  virtual bool empty() const;

private:
  // Note: This vector *must* be used in your heap implementation.
  std::vector<TYPE> data;
  // Note: compare is a functor object
  COMP compare;

private:
  void percolate_up(size_type i);
  void percolate_down(size_type i);
  // Add any additional member functions or data you require here.
};

template<typename TYPE, typename COMP>
void binary_heap<TYPE,COMP>::percolate_up(binary_heap<TYPE,COMP>::size_type i){
    binary_heap<TYPE,COMP>::size_type flag = i;
    while ((flag>0)&&(this->compare(this->data[flag],this->data[(flag-1)/2]))){
        TYPE tmp = this->data[flag];
        this->data[flag] = this->data[(flag-1)/2];
        this->data[(flag-1)/2] = tmp;
        flag = (flag-1)/2;
    }
}

template<typename TYPE, typename COMP>
void binary_heap<TYPE,COMP>::percolate_down(binary_heap<TYPE,COMP>::size_type i){
    binary_heap<TYPE,COMP>::size_type flag = i;
    for (binary_heap<TYPE,COMP>::size_type j = 2*flag+1;j<this->size();j = 2*flag+1){
        if ((j<this->size()-1)&&(this->compare(this->data[j+1],this->data[j]))) j++;
        if (this->compare(this->data[flag],this->data[j])) break;
        TYPE tmp = this->data[flag];
        this->data[flag] = this->data[j];
        this->data[j] = tmp;
        j = flag;
    }
}

template<typename TYPE, typename COMP>
binary_heap<TYPE, COMP> :: binary_heap(COMP comp) {
    compare = comp;
    // Fill in the remaining lines if you need.
}

template<typename TYPE, typename COMP>
void binary_heap<TYPE, COMP> :: enqueue(const TYPE &val) {
    this->data.push_back(val);
    this->percolate_up(this->size()-1);
}

template<typename TYPE, typename COMP>
TYPE binary_heap<TYPE, COMP> :: dequeue_min() {
    TYPE val = this->data[0];
    this->data[0] = this->data[this->size()-1];
    this->data.pop_back();
    if (!this->empty()) this->percolate_down(0);
    return val;
}

template<typename TYPE, typename COMP>
const TYPE &binary_heap<TYPE, COMP> :: get_min() const {
    return this->data[0];// Fill in the body.
}

template<typename TYPE, typename COMP>
bool binary_heap<TYPE, COMP> :: empty() const {
    return this->data.size()==0;// Fill in the body.
}

template<typename TYPE, typename COMP>
unsigned binary_heap<TYPE, COMP> :: size() const { 
    return this->data.size();// Fill in the body.
}

#endif //BINARY_HEAP_H
