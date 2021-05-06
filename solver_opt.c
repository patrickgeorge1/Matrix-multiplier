/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include <stdlib.h>
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");


	// allocate additional memory
	double *m_AB = calloc(N * N, sizeof(double));
	double *m_ABBt = calloc(N * N, sizeof(double));
	double *m_AtA = calloc(N * N, sizeof(double));
	// int i, j, k;

	if(m_AB == 	NULL || m_ABBt == NULL || m_AtA == NULL) {
		exit(EXIT_FAILURE);
	}

	// m_AB = A * B, TODO
	for (register int i = 0; i < N; i++)
	{
		register double *pointer_save_a = (double *) &(A[i * N]);
		for (register int j = 0; j < N; j++)
		{
			register double *pointer_a = pointer_save_a;
			register double *pointer_b = (double *) &(B[j]);
			register double result = 0.0;
			for (register int k = 0; k < N; ++k, ++pointer_a, pointer_b += N)
			{
				result += (k >= i) ? (*pointer_a * *pointer_b) : 0;
			}
			m_AB[i * N + j] = result;
		}	
	}


	// m_ABBt = m_AB * Bt
	for (register int i = 0; i < N; i++)
	{
		register double *pointer_save_AB = (double *) &(m_AB[i * N]);

		register double result;
		for (register int j = 0; j < N; j++)
		{
			register double *pointer_AB = pointer_save_AB;
			register double *pointer_Bt = (double *) &(B[j * N]);
			result = 0.0;

			for (register int k = 0; k < N; k++, ++pointer_AB, ++pointer_Bt)
				result += *pointer_AB * *pointer_Bt;
			
			m_ABBt[i * N + j] = result;
		}
	}
	
	// m_AtA = At * A
	for (register int i = 0; i < N; i++)
	{
		register double *pointer_save_At= (double *) &(A[i]);
		for (register int j = 0; j < N; j++)
		{
			register double result = 0.0;
			register double *pointer_At = pointer_save_At; 
			register double *pointer_A = (double *) &(A[j]);
			
			for (register int k = 0; k <= i; ++k, pointer_At += N, pointer_A += N)
				// inferior triunghiulara cu superior triunghiulara
				if (k <= j) result += *pointer_At * *pointer_A;
			
			m_AtA[i * N + j] = result;
		}
	}

	// m_ABBt = A * B * B' + A' * A
	for (register int i = 0; i < N * N; i++)
	{
			*(m_ABBt + i) += *(m_AtA + i);
	}

	// free additional memory
	free(m_AB);
	free(m_AtA);

	return m_ABBt;
}