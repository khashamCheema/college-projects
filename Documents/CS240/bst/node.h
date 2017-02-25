#ifndef NODE_H_
#define NODE_H_

class node
{
 public:
    node():data{0},right{nullptr},left{nullptr}{};
  node(double d):data{d},right{nullptr},left{nullptr}{};
  ~node();
    node* getRight(){return right;}
    node* getLeft(){return left;}
    void setRight(node* r){right = r;}
    void setLeft(node* l){left = l;}
    double getData(){return data;}
    void setData(double d){data = d;}
//    friend std::ostream& operator<<(ostram & out, const node &n);

 private:
  double data;
  node* right;
  node* left;

};
#endif
