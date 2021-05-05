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
		register double *pointer_save_a = A + i * N;
		for (register int j = 0; j < N; j++)
		{
			register double *pointer_a = pointer_save_a;
			register double *pointer_b = B + j;
			register double result = 0.0;
			for (register double k = 0; k < N; k++)
			{
				if (k >= i) {
					result += *pointer_a * *pointer_b;
				}
				pointer_a++;
				pointer_b += N;

				m_AB[i * N + j] = result;
			}
		}	
	}


	// m_ABBt = m_AB * Bt
	for (register int i = 0; i < N; i++)
	{
		register double *pointer_save_AB = m_AB + i * N;
		for (register int j = 0; j < N; j++)
		{
			register double *pointer_AB = pointer_save_AB;
			register double *pointer_Bt = B + j * N;
			register double result = 0.0;
			for (register double k = 0; k < N; k++)
			{
				result += *pointer_AB * *pointer_Bt;
				pointer_AB++;
				pointer_Bt++;
			}
			m_ABBt[i * N + j] = result;
		}
	}
	
	// m_AtA = At * A
	for (register int i = 0; i < N; i++)
	{
		register double *pointer_save_At= A + i;
		for (register int j = 0; j < N; j++)
		{
			register double *pointer_At = pointer_save_At;
			register double *pointer_A = A + j;
			register double result = 0.0;
			for (register double k = 0; k <= i; k++)
			{
				result += *pointer_At * *pointer_A;
				pointer_At += N;
				pointer_A += N;
			}
			m_AtA[i * N + j] = result;
		}
	}

	// m_ABBt = A * B * B' + A' * A
	for (register int i = 0; i < N; i++)
	{
		for (register int j = 0; j < N; j++)
		{
			m_ABBt[i * N + j] += m_AtA[i * N + j];
		}
	}

	// free additional memory
	free(m_AB);
	free(m_AtA);

	return m_ABBt;
}