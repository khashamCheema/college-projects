#include "bst.h"
#include <iostream>
using namespace std;



int main(int argc,char* argv[])
{

    bst<double> maple;
    maple.insert(5);
    maple.insert(10);
    maple.insert(3);
    maple.insert(4);
    maple.insert(15);
    maple.insert(9);
    maple.insert(2);
    
   
 //   maple.findRemove(15);
    //maple.insert(15);
 // bool x=  maple.isFull();
    
 //   maple.inorder();
  //  maple.max();
    cout << x;


   // double f = maple.sumAllLeaves();
   // cout << "sum all leaves " << maple.find(3) <<  "    " << endl;
    
 //   maple.inorder();

    
 /*   std::vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); itr++)
        
    */
  return 0;
}
