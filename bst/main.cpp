#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "aux.h"

using namespace std;

int main(){
  cout << "hi" << endl;
  struct node *root;
  
  root = init_node(5);
  //cout << root->left << endl;
  //cout << root->right << endl;
  //cout << root->val << endl;
  root = insert(root, 6);
  root = insert(root, 2); 
  root = insert(root, 1); 
  root = insert(root, -100); 
  root = insert(root, 25); 
  root = insert(root, 0); 
  traverse(root);
  cout << endl;

}
