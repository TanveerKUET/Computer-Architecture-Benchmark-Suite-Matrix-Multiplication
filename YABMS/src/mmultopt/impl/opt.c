/* opt.c
 *
 * Author:
 * Date  :
 *
 *  Description
 */

/* Standard C includes */
#include <stdlib.h>

/* Include common headers */
#include "common/macros.h"
#include "common/types.h"

/* Include application-specific headers */
#include "include/types.h"

/* Alternative Implementation */
#pragma GCC push_options
#pragma GCC optimize ("O1")
void* impl_scalar_opt(void* args)
{
  /* Get the argument struct */
  args_t* parsed_args = (args_t*)args;

  /* Get all the arguments */
  register       int*   dest = (      int*)(parsed_args->output);


  register       float*   R = (      float*)(parsed_args->R);
  register const float*   A = (const float*)(parsed_args->A);
  register const float*   B = (const float*)(parsed_args->B);
  
  register       int*   M = (      int*)(parsed_args->M);
  register const int*   N = (const int*)(parsed_args->N);
  register const int*   P = (const int*)(parsed_args->P);
  
  register const int*   block_size = (const int*)(parsed_args->block_size);
 
  int m = *M; 
  int n = *N;
  int p = *P;
  
  int b = *block_size;
  /*
  printf("M: %d\n", m);
  printf("N: %d\n", n);
  printf("P: %d\n", p);
  */
  //decalre three matrix here
  float matA[m][n];
  float matB[n][p];
  float matR[m][p];
  int value = 1;
  int index = 0;
  //printf("printing A: \n");
  for (register int i = 0; i < m; i++) {
	for (register int j = 0; j < n; j++) {
		matA[i][j] = A[index];
		//printf("%10.6f ", matA[i][j]);
		index++;
	}
    //printf("\n");
  }
  index = 0;
  //printf("printing B: \n");
  for (register int i = 0; i < n; i++) {
	for (register int j = 0; j < p; j++) {
		matB[i][j] = B[index];
		//printf("%10.6f ", matB[i][j]);
		index++;
	}
    //printf("\n");
  }

    // Initialize result matrix R
    for (int i = 0; i < m; i += b) {
        for (int j = 0; j < p; j += b) {
            for (int k = i; k < i + b && k < m; ++k) {
                for (int l = j; l < j + b && l < m; ++l) {
                    matR[k][l] = 0.0;
                }
            }
        }
    }
	
//Do the matrix multiplication here */
    // Perform blocked matrix multiplication
    for (int ii = 0; ii < m; ii += b) {
        for (int jj = 0; jj < p; jj += b) {
            for (int kk = 0; kk < n; kk += b) {
                for (int i = ii; i < ii + b && i < m; ++i) {
                    for (int j = jj; j < jj + b && j < p; ++j) {
                        double val = matR[i][j];
                        for (int k = kk; k < kk + b && k < n; ++k) {
                            val += matA[i][k] * matB[k][j];
                        }
                        matR[i][j] = val;
                    }
                }
            }
        }
    }
	
    /*



  //printf("printing multiplcation result store on R: \n");
  index = 0;
  for (int i = 0; i < m; i++) {
	for (int j = 0; j < p; j++) {
		R[index] = matR[i][j];
		//printf("%10.6f ", R[index]);
		index++;
	}
    //printf("\n");
  }

//printf("Multiplication Finished\n");
  
  /* Done */
  return NULL;
}
#pragma GCC pop_options
