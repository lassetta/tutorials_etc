#include <iostream>
#include <stdio.h>
#include "omp.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#define NUM_THREADS 32

using namespace std;

float **init_arr(int N, int M){
  float **arr = (float**)malloc(N * sizeof(float*));
  for (int i = 0; i < N; i++){
    arr[i] = (float*)malloc(M*sizeof(float));
  }
  return arr;
}

void populate_arr(float **arr, int N, int M){
  for (int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      arr[i][j] = float((rand() % 100000)/1000.);
    }
  }
}

void print_arr(float **arr, int N, int M){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

float **matmul(float **A, float **B, int N, int M, int K){
  float sum = 0;
  float **C = init_arr(N,K);
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    #pragma omp single
    {
      for (int i = 0; i < N; i++){
        for (int j = 0; j < K; j++){
          sum = 0;
          #pragma omp task firstprivate(sum)
          {
            for (int h = 0; h < M; h++){
              sum += A[i][h] + B[h][j];
            }
            C[i][j] = sum;
          }
        }
      }
    }
  }
  return C;
}

int main(){
  int N = 400;
  int M = 250;
  int K = 500;
  float **arr1;
  float **arr2;
  arr1 = init_arr(N,M);
  arr2 = init_arr(M,K);
  srand(time(NULL));
  populate_arr(arr1,N,M);
  populate_arr(arr2,M,K);

  float **dot = matmul(arr1, arr2, N, M, K);


}
