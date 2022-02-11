// Provided by Tim Mattson's OpenMP tutorial

#include <stdio.h>
#include "omp.h"
#include "random.h"

static long num_trials = 1000000;
#define NUM_THREADS 32
int main(){
  long i; long Ncirc=0;
  double pi, x, y, test;
  double r = 1.0;
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    #pragma omp single
    seed(-r, r);
    #pragma omp parallel for private (x,y) reduction (+:Ncirc) 
    for (i = 0; i < num_trials; i++){
      x = random();
      y = random();

      test = x*x + y*y;
      if (test <= r*r) Ncirc++;
    }
  }

  pi = 4.0 * ((double)Ncirc/(double)num_trials);

  printf("\n %d trials, pi is %f \n", num_trials, pi);
  return 0;

}
