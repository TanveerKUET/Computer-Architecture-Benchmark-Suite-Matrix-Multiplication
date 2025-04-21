/* naive.c
 *
 * Author:
 * Date  :
 *
 *  Description
 */

/* Standard C includes */
#include <stdlib.h>
#include <stdio.h>
/* Include common headers */
#include "common/macros.h"
#include "common/types.h"

/* Include application-specific headers */
#include "include/types.h"

/* Naive Implementation */
#pragma GCC push_options
#pragma GCC optimize ("O1")
void* impl_scalar_naive(void* args)
{
  /* Get the argument struct */
  args_t* parsed_args = (args_t*)args;

  /* Get all the arguments */
  register       int*   dest = (      int*)(parsed_args->output);


  register       int*   R = (      int*)(parsed_args->R);
  register const int*   A = (const int*)(parsed_args->A);
  register const int*   B = (const int*)(parsed_args->B);
  
  register       int*   M = (      int*)(parsed_args->M);
  register const int*   N = (const int*)(parsed_args->N);
  register const int*   P = (const int*)(parsed_args->P);
 
  int m = *M; 
  int n = *N;
  int p = *P;
  
  printf("M: %d\n", m);
  printf("N: %d\n", n);
  printf("P: %d\n", p);
  
  //decalre three matrix here
  int matA[m][n];
  int matB[n][p];
  int matR[m][p];
  int value = 1;
  int index = 0;
  //printf("printing A: \n");
  for (register int i = 0; i < m; i++) {
	for (register int j = 0; j < n; j++) {
		matA[i][j] = value;
		//printf("%d ", matA[i][j]);
		value++;
	}
    //printf("\n");
  }
  value = 1;
  printf("printing B: \n");
  for (register int i = 0; i < n; i++) {
	for (register int j = 0; j < p; j++) {
		matB[i][j] = value;
		//printf("%d ", matB[i][j]);
		value++;
	}
    //printf("\n");
  }
  value = 1;
  //printf("printing blank R: \n");
  for (register int i = 0; i < m; i++) {
	for (register int j = 0; j < p; j++) {
		matR[i][j] = 0;
		//printf("%d ", matR[i][j]);
		value++;
	}
    //printf("\n");
  }
  /*
//Do the matrix multiplication here */

// Perform matrix multiplication: C = A * B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                matR[i][j] += matA[i][k] * matB[k][j];
				
            }
        }
    }
  printf("printing R: \n");
  for (register int i = 0; i < m; i++) {
	for (register int j = 0; j < p; j++) {
		R[index] = matR[i][j];
		//printf("%d ", R[index]);
		index++;
	}
    printf("\n");
	printf("Multiplication Finished\n");
  }

  /* Done */
  return NULL;
}
#pragma GCC pop_options
