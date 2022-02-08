#include <iostream>
#include <stdlib.h>
#include <vector>
#include "aux.h"
#include <numeric>
using namespace std;

int main(){
  vector<int> A;
  cout << "populating and printing vector A" << endl;
  for (int i = 1; i < 11; i++){
    A.push_back(i);
  }
  print(A);
  cout << endl;

  vector<int> B;
  cout << "populating and printing vector B" << endl;
  for (int i = 1; i < 11; i++){
    B.push_back(i);
  }
  print(B);
  cout << endl;


  vector<int>::iterator it;
  it = A.begin();
  int pos = 3;
  A.insert(it + pos,43); 
  it = B.begin();
  B.insert(it + pos,43); 
  //B.insert(it,43); 
  cout << "inserting 43 at index 3" << endl;
  print(A);
  cout << endl;
  //B.insert(3, 43)
  //A.insert(3, 43)

  vector<int> C;
  cout << "elementwise addition" << endl;
  C = elementAdd(A,B);
  print(C);
  // deallocate C;
  C = vector<int>();
  cout << endl;


  cout << "matrix mult" << endl;
  vector<vector<int>> D;
  D = mat_mul();

  for (int i = 0; i < D.size(); i++){
    print(D[i]);
  }
}
