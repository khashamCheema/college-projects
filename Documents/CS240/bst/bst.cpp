#include "bst.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;




template <class T>
bst<T>::~bst()
{
  

}

/*void bst::chainsaw(node* n)
{
    if(n == nullptr) return;
    chainsaw(n->getLeft());
    chainsaw(n->getRight());
    delete n;
    return;
        
}*/

template <class T>
void bst<T>::insert(T d)
{
    node *n = new node(d);
    if(root == nullptr) root = n;
    
    else
        insert_r(n, root);
}


template <class T>
bool bst<T>::insert_r(node* newnode, node* curr)
{
    
    if(curr == nullptr) return false;
    
    if(curr->getData() <= newnode->getData())
    {
        if(curr->getRight() == nullptr)
        {
            curr->setRight(newnode);
            return true;
        }
        else
        {
            return insert_r(newnode, curr->getRight());
        }
    }
    else
    {
        if(curr->getLeft() == nullptr)
        {
            curr->setLeft(newnode);
            return true;
        }
        else
        {
            return insert_r(newnode, curr->getLeft());
        }
    }
}

template <class T>
T bst<T>::sumAllNodes()
{
    if(root == nullptr) return 0;
    return sumAllNodes(*root);
}


template <class T>
T bst<T>::sumAllNodes(node &n)
{
    T lft = 0;
    T rht = 0;
    
    if(n.getLeft() != nullptr)
        lft = sumAllNodes(*(n.getLeft()));
    if(n.getRight() != nullptr)
        rht = sumAllNodes(*(n.getRight()));
    cout << rht <<endl;
    return n.getData() + lft + rht;

}

template <class T>
T bst<T>::sumAllLeaves()
{
    if(root == nullptr) return 0;
    return sumAllLeaves(*root);
}


template <class T>
T bst<T>::sumAllLeaves(node &n)
{
    T lft = 0;
    T rht = 0;
    if(n.getRight() == nullptr && n.getLeft() == nullptr)
    {
        return n.getData();
    }
    if(n.getRight() != nullptr)
    {
        lft =  sumAllLeaves(*(n.getRight()));
    }
    if(n.getLeft() != nullptr)
    {
        rht = sumAllLeaves(*(n.getLeft()));
    }
    cout << lft << "    "  << rht << endl;
    return lft + rht;
}


template <class T>
T bst<T>::sumAllEven()
{
    if(root == nullptr) return 0;
    return sumAllEven(*root);
}


template <class T>
T bst<T>::sumAllEven(node &n)
{
    T rht = 0;
    T lft = 0;
    
    if(n.getLeft() != nullptr)
        lft = sumAllEven(*(n.getLeft()));
    if(n.getRight() != nullptr)
        rht = sumAllEven(*(n.getRight()));
    if(T(n.getData()) % 2 == 0)
        return n.getData() + lft + rht;
    else
        return rht + lft;
        
}


template <class T>
T bst<T>::getHeight(node &n)
{
    T rht = 0;
    T lft = 0;
    if(n.getRight() == nullptr && n.getLeft() == nullptr) return 0;

    
    if(n.getLeft() != nullptr)
        lft = getHeight(*(n.getLeft()));
    if(n.getRight() != nullptr)
        rht = getHeight(*(n.getRight()));
    
    if(lft > rht)
        return 1+lft;
    else
        return 1+rht;
}


template <class T>
node* bst<T>::find(T f)
{
    if(root == nullptr) return root;
    return find(*root, f);
}


template <class T>
node* bst<T>::find(node& n, T f)
{
    if(n.getData() == f) return &n;
     
    if(n.getData() <= f && n.getRight() != nullptr)
        return find(*(n.getRight()),f);
    else if(n.getData() > f && n.getLeft() != nullptr)
      //  cout <<find(*(n.getLeft()),f) << endl;
        return find(*(n.getLeft()),f);
    else
        return nullptr;
}

template <class T>
void bst<T>::breadth()
{
    queue<node*> n;
    
    n.push(root);
    
    while(!n.empty())
    {
        node* front= n.front();
        n.pop();
        if (front->getRight()!=nullptr && front->getLeft()!=nullptr)
        {

        cout << front->getData()<<" ";
        
        if(front->getLeft() != nullptr)
        {
        n.push(front->getLeft());
        }
        if(front->getRight() != nullptr)
        {
        n.push(front->getRight());
        }
            
        }
        else
        cout<<"bnotful";
    }
    
}



template <class T>
void bst<T>::depth()
{
    stack<node*> n;
    
    n.push(root);
    
    
    cout<<root->getData();
    while(!n.empty())
    {
        node* front = n.top();
        n.pop();

        cout << front->getData() << std::endl;
        
        if(front->getRight() != nullptr)
        {
            n.push(front->getRight());
        }
        if(front->getLeft() != nullptr)
        {
            n.push(front->getLeft());
        }
        
    }
    
}


template <class T>
void bst<T>::inorder()
{
    if(root == nullptr) return;
    inorder_r(root);
}

template <class T>
void bst<T>::inorder_r(node* n)
{
    if(n == nullptr) return;
    inorder_r(n->getLeft());
    cout << n->getData() ;
    inorder_r(n->getRight());
}

template <class T>
void bst<T>::preorder()
{
    if(root == nullptr) return;
    preorder_r(root);
}

template <class T>
void bst<T>::preorder_r(node* n)
{
    if(n == nullptr) return;
    cout << n->getData();
    preorder_r(n->getLeft());
    preorder_r(n->getRight());
}

template <class T>
void bst<T>::postorder()
{
    if(root == nullptr) return;
    preorder_r(root);
}

template <class T>
void bst<T>::postorder_r(node* n)
{
    if(n == nullptr) return;
    postorder_r(n->getLeft());
    postorder_r(n->getRight());
    cout << n->getData();
    
}

template <class T>
ostream& operator<<(ostream& out, bst<T> &b)
{
    out << b.inorder();
    
    
    return out;
}

template <class T>
node* bst<T>::max()
{
    if(root == nullptr) return root;
    return max(root);
}


template <class T>
node* bst<T>::max(node* n)
{
    if(n == nullptr) return n;
    node* tmp = n;
    while(tmp->getRight() != nullptr)
    {
        tmp = tmp->getRight();
    }
    cout << tmp->getData() << endl;
    return tmp;
}


template <class T>
node* bst<T>::min()
{
    if(root == nullptr) return root;
    return min(root);
}


template <class T>
node* bst<T>::min(node* n)
{
    if(n == nullptr) return n;
    node* tmp = n;
    while(tmp->getLeft() != nullptr)
    {
        tmp = tmp->getLeft();
    }
    
    cout << tmp->getData() << endl;
    return tmp;
}

template <class T>
T bst<T>::isComplete()
{
    if(root == nullptr) return -20;
     return isComplete(root);
}


template <class T>
T bst<T>::isComplete(node *root)
{
    T flag=0;
    node *temp;
    
    queue<node*> q;
    
    q.push(root);
    
    while (!q.empty()) {
        
        node *temp=q.front();
        q.pop();
        
        if (temp->getLeft())
            {
                if(flag)
                    return 0; // Not complete binary tree
                q.push(temp->getLeft());
            }
            else
                flag=1;
            if(temp->getRight())
            {
                if(flag)
                    return 0;
                q.push(temp->getRight());
            }
            else
                flag=1;
        }
        return 1;
    }


template <class T>
bool bst<T>::isFull()
{
    if(root == nullptr) return false;
    return isFull(root);
}
    
template <class T>
bool bst<T>::isFull(node *r)
{
    if(!r)
        return true;
    
    bool lf=isFull(r->getLeft());
    bool rf=isFull(r->getRight());
    
    if(r->getLeft() || r->getRight())
    {
        if(!r->getLeft() || !r->getRight())
            return false;
        
        else
            return (lf && rf);
    }
    
    else
        return (lf && rf);
}




template<class T>
node* bst<T>::findRemove(T r)
{
    if(root == nullptr) return root;
    return findRemove(root, r);
}


template<class T>
node* bst<T>::findRemove(node* n, T r)
{
    if(r < root->getData())
    {
        findRemove(root->getLeft(), r);
    }
    if(r > root->getData())
    {
        findRemove(root->getRight(), r);
    }
    else
    {
        if (root->getLeft() == nullptr)
        {
            node *temp = root->getRight();
            free(root);
            return temp;
        }
        else if (root->getRight() == nullptr)
        {
            struct node *temp = root->getLeft();
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->getRight());
        root->setData(temp->getData());
        root->setRight(findRemove(root->getRight(), temp->getData()));
    }
    return root;
}

template<class T>
node* bst<T>::minValueNode(node* n)
{
    node* current = n;
    
    while (current->getLeft() != nullptr)
        current = current->getLeft();
    
    return current;
}

template <class T>
T bst<T>::inRange(T min, T max)
{
    if(root == nullptr) return 0;
    return inRange(min, max, *root);
}


template <class T>
T bst<T>::inRange(T min, T max, node &n)
{
    T rht = 0;
    T lft = 0;
    
    if(n.getLeft() != nullptr)
        lft = inRange(min, max, (*(n.getLeft())));
    if(n.getRight() != nullptr)
        rht = inRange(min, max, (*(n.getRight())));
    if(T(n.getData()) > min && n.getData() < max )
        return n.getData() + lft + rht;
    else
        return rht + lft;
    
}





