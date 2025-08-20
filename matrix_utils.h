#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

// These fcns are meant to make it easier to deal with
// matrices in C.  We use col major format since that's
// what underlies Lapack.

// returns +/-1 depending upon sign of x
#define SIGN(x) (((x) > 0) - ((x) < 0))

// Macros to extract matrix index and element.
// Matrix is NxN, i = row idx, j = col idx. 
#define MATRIX_IDX(N, I, J) (((N)*(J)) + (I))
#define MATRIX_ELEMENT(A, m, n, i, j) A[ MATRIX_IDX(n, i, j) ]

// Min and max macros for scalars.
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// Function prototypes
void print_matrix(const double* A, int m, int n);
void print_matrix_linear(const double* A, int m, int n);
int lindex(int m, int n, int i, int j);
void zeros(int m, int n, double *A);
void linspace(double x0, double x1, int N, double *v);
int maxeltf(int N, double *u);
void quickSort(double *arr, int low, int high);

#endif
