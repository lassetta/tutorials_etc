#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "aux.h"

using namespace std;

int main(){
  cout << "hi" << endl;
  struct node *root;
  
  root = init_node(85);
  //cout << root->left << endl;
  //cout << root->right << endl;
  //cout << root->val << endl;
  root = insert(root, 75);
  root = insert(root, 3);
  root = insert(root, 18);
  root = insert(root, -2);
  root = insert(root, 0);
  root = insert(root, 10);
  root = insert(root, 12);
  root = insert(root, 4);
  root = insert(root, 2);
  traverse(root);
  cout << endl;
  cout << "root get_height: " << get_height(root) << endl;
  cout << "root left get_height: " << get_height(root->left) << endl;
  cout << "root right get_height: " << get_height(root->right) << endl;

}
