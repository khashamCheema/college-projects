#ifndef BST_H_
#define BST_H_
#include <iostream>
#include "node.h"


template <class T>
class bst
{
 public:
  bst():root{nullptr}{};
    ~bst();
    void insert(T d);
    bool insert_r(node* newnode, node* curr);
    void inorder();
    void inorder_r(node* n);
    void preorder();
    void preorder_r(node* n);
    void postorder();
    void postorder_r(node* n);
    T sumAllNodes();
    T sumAllNodes(node &n);
    T sumAllLeaves();
    T sumAllLeaves(node &n);
    T sumAllEven();
    T sumAllEven(node &n);
    T getHeight(node &n);
    node* find(T f);
    node* find(node &n, T f);
    void breadth();
    void depth();
    friend std::ostream& operator<<(std::ostream& out, const bst &b);
    node* max();
    node* max(node* n);
    node* min();
    node* min(node* n);
    T isComplete();
    T isComplete(node *root);
    bool isFull();
    bool isFull(node* r);
    node* findRemove(T r);
    node* findRemove(node* n, T r);
    node* getSuccessor(node **n);
    node* minValueNode(node* n);
    T inRange(T min, T max);
    T inRange(T min, T max, node &n);
    
  //  void chainsaw(node* n);
 private:
    node *root;
    

};

#include "bst.cpp"

#endif
