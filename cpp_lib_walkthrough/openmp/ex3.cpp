#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "omp.h"
using namespace std;
#define NUM_THREADS 4

int main(){
  // set to 4 threads
  int Nthreads;
  long num_steps = 1000000;
  double pi;
  double step = 1.0/(double) num_steps;

  double sum2;
  double y;
  for (int j = 0; j < num_steps; j++){
    y = (j+0.5)*step;
    sum2 += (4.0)/(1.0 + y*y);
  }
  pi = step*sum2;
  cout << "non parallel check: " << pi << endl;
  // reset pi
  pi = 0;

  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int ID, num_threads, i;
    double x, sum;
    // get thread ID
    ID = omp_get_thread_num();
    // get number of threads
    num_threads = omp_get_num_threads();
    // if ID is 0, update Nthreads;
    // only do this on one ID to avoid allocation conflict
    if (ID == 0) {Nthreads = num_threads;} 
    // set sum[ID] to zero, each thread will look increment by number_threads
    // to basically divide and conquer this loop by number_threads
    for (i = ID, sum = 0; i < num_steps; i+=num_threads){
      x = (i+0.5)*step;
      sum += (4.0/ (1.0 + x*x));
    }
    // ensure only one thread can update pi at any given time
    // atomic has lower overhead than critical, so use that
    // this only protect the read/update of pi. Critical creates a critical
    // region. 
    #pragma omp atomic
      pi += step*sum;
  }
  // add the sums together to get pi
  cout << "final result: " << pi << endl;
  


}
