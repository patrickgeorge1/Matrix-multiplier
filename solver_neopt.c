/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include <stdlib.h>
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");

	// allocate additional memory
	double *m_AB = calloc(N * N, sizeof(double));
	double *m_ABBt = calloc(N * N, sizeof(double));
	double *m_AtA = calloc(N * N, sizeof(double));
	int i, j, k;

	if(m_AB == 	NULL || m_ABBt == NULL || m_AtA == NULL) {
		exit(EXIT_FAILURE);
	}

	// m_AB = A * B
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = i; k < N; k++)
			{
				m_AB[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}	
	}

	// m_ABBt = m_AB * Bt
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				m_ABBt[i * N + j] += m_AB[i * N + k] * B[j * N + k];
			}
		}
	}
	
	// m_AtA = At * A
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k <= i; k++)
			{
				m_AtA[i * N + j] += A[k * N + i] * A[k * N + j];
			}
		}
	}

	// m_ABBt = A * B * B' + A' * A
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			m_ABBt[i * N + j] += m_AtA[i * N + j];
		}
	}

	// free additional memory
	free(m_AB);
	free(m_AtA);

	return m_ABBt;
}
