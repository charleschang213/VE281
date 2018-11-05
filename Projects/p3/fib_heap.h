#ifndef FIB_HEAP_H
#define FIB_HEAP_H

#include <algorithm>
#include <cmath>
#include "priority_queue.h"

// OVERVIEW: A specialized version of the 'heap' ADT implemented as a 
//           Fibonacci heap.
template<typename TYPE, typename COMP = std::less<TYPE> >
class fib_heap: public priority_queue<TYPE, COMP> {
public:
  typedef unsigned size_type;

  // EFFECTS: Construct an empty heap with an optional comparison functor.
  //          See test_heap.cpp for more details on functor.
  // MODIFIES: this
  // RUNTIME: O(1)
  fib_heap(COMP comp = COMP()):compare(comp),n(0),min(NULL){};

  // EFFECTS: Deconstruct the heap with no memory leak.
  // MODIFIES: this
  // RUNTIME: O(n)
  ~fib_heap();
  
  // EFFECTS: Add a new element to the heap.
  // MODIFIES: this
  // RUNTIME: O(1)
  virtual void enqueue(const TYPE &val);

  // EFFECTS: Remove and return the smallest element from the heap.
  // REQUIRES: The heap is not empty.
  // MODIFIES: this
  // RUNTIME: Amortized O(log(n))
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
  // Note: compare is a functor object
  COMP compare;

private:
  typedef struct __node__{
    TYPE val;
    struct __node__ *right;
    struct __node__ *left;
    struct __node__ *child;
    struct __node__ *parent;
    int degree;
  }node_t;
  node_t *min;
  size_type n;
  void consolidate();
  void link(node_t *y,node_t *x){
    //y->left->right = y->right;
    //y->right->left = y->left;
    if (x->child==NULL){
      y->left = y->right = y;
      y->parent = x;
      x->child = y;
    }
    else{
      y->left = x->child;
      y->right = x->child->right;
      x->child->right->left = y;
      x->child->right = y;
      y->parent = x;
    }
    x->degree++;
  }
  // Add any additional member functions or data you require here.
  // You may want to define a strcut/class to represent nodes in the heap and a
  // pointer to the min node in the heap.

};
  // EFFECTS: Deconstruct the heap with no memory leak.
  // MODIFIES: this
  // RUNTIME: O(n)
template<typename TYPE,typename COMP>
fib_heap<TYPE,COMP>::~fib_heap(){
  while (!this->empty()){
    this->dequeue_min();
  }
}

// EFFECTS: Add a new element to the heap.
// MODIFIES: this
// RUNTIME: O(1)
template<typename TYPE,typename COMP>
void fib_heap<TYPE,COMP>::enqueue(const TYPE &val){
  fib_heap<TYPE,COMP>::node_t *newnode = new fib_heap<TYPE,COMP>::node_t;
  newnode->val = val;
  newnode->child = NULL;
  newnode->parent = NULL;
  newnode->degree = 0;
  if (this->min==NULL){
    this->min = newnode;
    newnode->left = newnode;
    newnode->right = newnode;
  }
  else {
    newnode->left = this->min;
    newnode->right = this->min->right;
    this->min->right->left = newnode;
    this->min->right = newnode;
    if (this->compare(newnode->val,this->min->val)) this->min = newnode;
  }
  this->n++;
}

template<typename TYPE,typename COMP>
void fib_heap<TYPE,COMP>::consolidate(){
  fib_heap<TYPE,COMP>::node_t **A = new fib_heap<TYPE,COMP>::node_t*[this->n];
  for (int i=0;i<this->n;i++) A[i] = NULL;
  fib_heap<TYPE,COMP>::node_t *flag = this->min;
  do{
    fib_heap<TYPE,COMP>::node_t *x = flag;
    flag = flag->right;
    int d = x->degree;
    while (A[d]!=NULL){
      fib_heap<TYPE,COMP>::node_t *y = A[d];
      if (this->compare(y->val,x->val)){
        fib_heap<TYPE,COMP>::node_t *tmp = x;
        x = y;y = tmp;
      }
      this->link(y,x);
      A[d] = NULL;
      d++;
    }
    A[d] = x;
  }while (flag!=this->min);
  this->min = NULL;
  for (int i=0;i<this->n;i++){
    if (A[i]!=NULL){
      if (this->min == NULL){
        this->min = A[i];
        A[i]->left = A[i]->right = A[i];
      }
      else {
        A[i]->left = this->min;
        A[i]->right = this->min->right;
        this->min->right->left = A[i];
        this->min->right = A[i];
        if (this->compare(A[i]->val,this->min->val)) this->min = A[i];
      }
    }
  }
  delete []A;
}

// EFFECTS: Remove and return the smallest element from the heap.
// REQUIRES: The heap is not empty.
// MODIFIES: this
// RUNTIME: Amortized O(log(n))
template<typename TYPE,typename COMP>
TYPE fib_heap<TYPE,COMP>::dequeue_min(){
  fib_heap<TYPE,COMP>::node_t *z = this->min;
  while (z->child!=NULL){
    fib_heap<TYPE,COMP>::node_t *c = z->child;
    c->parent = NULL;
    c->left->right = c->right;
    c->right->left = c->left;
    z->child = c->right;
    if (z->child==c) z->child = NULL;
    c->right = this->min->right;
    c->left = this->min;
    this->min->right->left = c;
    this->min->right = c;
  }
  TYPE ans = z->val;
  this->n--;
  if (this->n==0){
    this->min = NULL;
    delete z;
    return ans;
  }
  this->min = z->right;
  z->left->right = z->right;
  z->right->left = z->left;
  delete z;
  this->consolidate();
  return ans;
}

// EFFECTS: Return the smallest element of the heap.
// REQUIRES: The heap is not empty.
// RUNTIME: O(1)
template<typename TYPE,typename COMP>
const TYPE &fib_heap<TYPE,COMP>::get_min() const{
  return this->min->val;
}

// EFFECTS: Get the number of elements in the heap.
// RUNTIME: O(1)
template<typename TYPE,typename COMP>
unsigned int fib_heap<TYPE,COMP>::size() const{
  return this->n;
}

// EFFECTS: Return true if the heap is empty.
// RUNTIME: O(1)
template<typename TYPE,typename COMP>
bool fib_heap<TYPE,COMP>::empty() const{
  return this->n==0;
}

// Add the definitions of the member functions here. Please refer to
// binary_heap.h for the syntax.

#endif //FIB_HEAP_H
