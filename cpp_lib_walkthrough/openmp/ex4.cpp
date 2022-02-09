#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "omp.h"
using namespace std;
#define NUM_THREADS 4

int main(){
  // set to 4 threads
  int i;
  long num_steps = 1000000;
  double x, pi, sum = 0.0;
  double step = 1.0/(double) num_steps;

  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel for private(x) reduction (+:sum) 
  for(i = 0; i < num_steps; i++){
    x = (i+0.5)*step;
    sum += (4.0)/(1.0 + x*x);
  }
  pi = step * sum; 

  // add the sums together to get pi
  cout << "final result: " << pi << endl;
  


}
