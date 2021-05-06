/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "cblas.h"


/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");

	// allocate additional memory
	double *m_ABBt = calloc(N * N, sizeof(double));
	double *m_AB = calloc(N * N, sizeof(double));
	double *m_AtA = calloc(N * N, sizeof(double));

	if(m_ABBt == NULL || m_AtA == NULL || m_AB) {
		exit(EXIT_FAILURE);
	}

	// m_AB = B
	memcpy(m_AB, B, N * N * sizeof(double));

	// m_AB = A * B  ==> triangular multiply
	cblas_dtrmm(
		CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
		N, N,
		1, A, N,
		m_AB, N
	);


	// m_AtA = A
	memcpy(m_AtA, A, N * N * sizeof(double));


	// m_Ata = A' * A  ==> triangular multiply
	cblas_dtrmm(
		CblasRowMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit,
		N, N,
		1, A, N,
		m_AtA, N
	);

	// m_AtA += m_AB * B'  ==> basic matrix multiply and addition
	cblas_dgemm(
		CblasRowMajor, CblasNoTrans, CblasTrans, 
		N, N, N,
		1, m_AB, N,
		B, N, 1, m_AtA, N
	);

	free(m_ABBt);
	free(m_AB);
	
	return m_AtA;
}
