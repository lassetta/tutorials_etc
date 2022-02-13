#include "omp.h"
#include <malloc.h>
#include <stdio.h>

#define N        10000000
#define SEED       2531
#define RAND_MULT  1366
#define RAND_ADD   150889
#define RAND_MOD   714025
#define NUM_THREADS 6
int randy = SEED;

/* function to fill an array with random numbers */
void fill_rand(int length, double *a)
{
   int i; 
   for (i=0;i<length;i++) {
     randy = (RAND_MULT * randy + RAND_ADD) % RAND_MOD;
     *(a+i) = ((double) randy)/((double) RAND_MOD);
   }   
}
// sum array
double sum_array(int length, double *a){
   int i;  double sum = 0.0;
   for (i=0;i<length;i++)  sum += *(a+i);  
   return sum; 
}

// negative sum array
double neg_sum_array(int length, double *a){
   int i;  double sum = 0.0;
   for (i=0;i<length;i++)  sum -= *(a+i);  
   return sum; 
}


int main(){
  double *A, *B, sumA, sumB, negSumA, negSumB, runtime;
  int flagA = 0;
  int flagB = 0;

  A = (double *)malloc(N*sizeof(double));
  B = (double *)malloc(N*sizeof(double));

  omp_set_num_threads(NUM_THREADS);
  runtime = omp_get_wtime();
  fill_rand(N, A);
  fill_rand(N, B);
  sumA = sum_array(N, A);
  negSumA = neg_sum_array(N, A);
  sumB = sum_array(N, B);
  negSumB = neg_sum_array(N, B);
  runtime = omp_get_wtime() - runtime;

  printf(" In %lf seconds, The sums are: A - %lf - %lf; B - %lf - %lf\n",runtime,sumA,negSumA,sumB,negSumB);

  

}
