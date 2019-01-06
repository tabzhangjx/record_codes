/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */

char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i,j,k,l,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11;/*all variables are defined here*/
/*case 1: M=32 N=32
 * 8x8 blocking is used in this case.
 */	
	if(M==32 && N==32)
	{
		for(i=0;i<N;i+=8)										/*i is the iteration of rows in A and cols in B*/
		{
			for(j=0;j<M;j+=8)									/*j is the iteration of cols in A and rows in B*/
			{				
				for(k=i;k<i+8;k++)
				{
					tmp_4=A[k][j];								/*read a whole block at one time to reduce misses*/
					tmp_5=A[k][j+1];
					tmp_6=A[k][j+2];
					tmp_7=A[k][j+3];
					tmp_8=A[k][j+4];
					tmp_9=A[k][j+5];
					tmp_10=A[k][j+6];
					tmp_11=A[k][j+7];
					
/*transfer the datas into B, in the first iteration of the 8x8 block, 8 blocks in a set of cache will be put in use, 
 * but after the 8 iterations, those blocks will be exactly filled
 */
					B[j][k]=tmp_4;					
					B[j+1][k]=tmp_5;
					B[j+2][k]=tmp_6;
					B[j+3][k]=tmp_7;
					B[j+4][k]=tmp_8;
					B[j+5][k]=tmp_9;
					B[j+6][k]=tmp_10;
					B[j+7][k]=tmp_11;
				}
			}
		}
		return;
	}
/*
 * case 2: M=64 N=64
 * 8x8 blocking is used in this case
 * divide 8x8 block into 4 parts as follow
 * |1|2|
 * |3|4|
 * the whole process of transposition is
 * A1->B1,A2->B3,A3->B2,A4->B4
 */
	if(M==64 && N==64)
	{
		for(i=0;i<N;i+=8)
		{
			for(j=0;j<M;j+=8)
			{
				for(k=i;k<i+4;k++)
				{
					/*read A1,A2 horizontally*/
					tmp_4=A[k][j];								/*read a whole block int numbers*/
					tmp_5=A[k][j+1];
					tmp_6=A[k][j+2];
					tmp_7=A[k][j+3];
					tmp_8=A[k][j+4];
					tmp_9=A[k][j+5];
					tmp_10=A[k][j+6];
					tmp_11=A[k][j+7];
					/*step 1 A1->B1*/
					B[j][k]=tmp_4;
					B[j+1][k]=tmp_5;
					B[j+2][k]=tmp_6;
					B[j+3][k]=tmp_7;
					/*step 2 A2->B2,but in reverse order*/
					B[j+3][k+4]=tmp_8;
					B[j+2][k+4]=tmp_9;
					B[j+1][k+4]=tmp_10;
					B[j][k+4]=tmp_11;
				}
				for(l=0;l<4;l++)
				{
					/*read A3,A4 vertically*/
					tmp_4=A[k][j+3-l];
					tmp_5=A[k+1][j+3-l];
					tmp_6=A[k+2][j+3-l];
					tmp_7=A[k+3][j+3-l];
					tmp_8=A[k][j+4+l];
					tmp_9=A[k+1][j+4+l];
					tmp_10=A[k+2][j+4+l];
					tmp_11=A[k+3][j+4+l];
					
					/*step 3 B2->B3 A3->B2*/
					B[j+4+l][i]=B[j+3-l][i+4];
					B[j+3-l][i+4]=tmp_4;
					B[j+4+l][i+1]=B[j+3-l][i+5];
					B[j+3-l][i+5]=tmp_5;
					B[j+4+l][i+2]=B[j+3-l][i+6];
					B[j+3-l][i+6]=tmp_6;
					B[j+4+l][i+3]=B[j+3-l][i+7];
					B[j+3-l][i+7]=tmp_7;
					
					/*step 4 A4->B4*/
					B[j+4+l][i+4]=tmp_8;
					B[j+4+l][i+5]=tmp_9;
					B[j+4+l][i+6]=tmp_10;
					B[j+4+l][i+7]=tmp_11;
				}
			}

		}
		return ;
	}
/* other cases, in Part B M=61 N=67
 * 16x4 blocking in used
 */
	else{
		for(i=0;i<N;i+=16)
		{
			for(j=0;j<M;j+=4)
			{
				
				for(k=i;k<i+16 && k<N;k++)
				{
					tmp_4=-1;
					for(l=j;l<j+4 && l<M;l++)
					{
						if(k==l)
						{
							tmp_4=k;
							tmp_5=A[k][k];						/*temprorily store the elements with k=l
																which is sure to have collisions*/
						}
						else{
							B[l][k]=A[k][l];					/*use the most recently wroten block which 
																has the smallest probability to be evicted*/
						}
					}
					if(tmp_4!=-1)
					B[tmp_4][tmp_4]=tmp_5;
				}
				
			}
		}
	}
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}



/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}