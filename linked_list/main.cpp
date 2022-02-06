#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "aux.h"
using namespace std;

int main(){
  cout << "hi" << endl;
  struct Linked_List* LL_ptr;
  LL_ptr = (struct Linked_List*) malloc(sizeof(struct Linked_List));
  init_LL(LL_ptr);
  add_node(LL_ptr, 1, 2);
  add_node(LL_ptr, 0, 3);
  add_node(LL_ptr, 3, 3);
  add_node(LL_ptr, 5, 3);
  add_node(LL_ptr, 2, 3);

}
