#include <iostream>
#include "omp.h"
using namespace std;

int main(){
  //call parallel directive with 4 threads
  #pragma omp parallel num_threads(4)
  {
    // get the thread number
    int ID = omp_get_thread_num();
    cout << "hello (" << ID << ")";
    cout << "world (" << ID << ")" << endl;
  }

}
