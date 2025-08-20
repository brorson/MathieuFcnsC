#include <stdio.h>
#include <math.h>
#include "matrix_utils.h"

//===========================================================
// This file holds utility functions for dealing with vectors
// and matrices.  The idea is to be able to reuse common matrix
// operations.  I will name the utils analogously to their names
// in Matlab.
// Note that C matrices are row-major.


//-----------------------------------------------------
void print_matrix(const double* A, int m, int n) {
  // prints matrix as 2-dimensional tablei -- this is how we
  // usually think of matrices.
   int i, j;
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
          printf("% 10.4e  ", MATRIX_ELEMENT(A, m, n, i, j));
      }
      printf("\n");
   }
}


//-----------------------------------------------------
void print_matrix_linear(const double* A, int m, int n) {
  // Prints matrix as one long, linear object.
  int i;
  for (i = 0; i < m*n; i++) {
    printf("%8.4f\n", A[i]);
  }
}


//-----------------------------------------------------
int lindex(int m, int n, int i, int j) {
  // Function returning the linear index into matrix of
  // dimensions m, n.  The macro defined in the header file can
  // be buggy, particularly if used more than once
  // in an expression -- use this function
  // to be sure you're getting correct behavior.
  // Assumes row-major indexing (C-style).
  return j + i*n;
}


//-----------------------------------------------------
void zeros(int m, int n, double *A) {
  int i, j;
  for (j = 0; j < n; j++) {
    for (i = 0; i < m; i++) {
      MATRIX_ELEMENT(A, m, n, i, j) = 0.0;
    }
  }
}


//-----------------------------------------------------
void linspace(double x0, double x1, int N, double *v) {
  // Returns vector v with N values from x0 to x1
  int i;
  double dx;

  dx = (x1-x0)/(N-1);
  for (i = 0; i < N; i++) {
    v[i] = x0 + i*dx;
  }
}


//-----------------------------------------------------
int maxeltf(int N, double *u) {
  // Given double vector u with N elements, return the
  // index of the largest element.
  // This is a dumb linear search O(N).  But for small N
  // it's quick and dirty.  For large N I should write a
  // binary search.
  int i, imax;
  double umax;

  umax = -INFINITY;

  for (i = 0; i < N; i++) {
    if (u[i] > umax) {
      umax = u[i];
      imax = i;
    }
  }
  return imax;
}


//-----------------------------------------------------
// Stuff to sort a vector.
// Function to swap two elements
void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(double *arr, int low, int high) {
    double pivot = arr[high];  // Choose last element as pivot
    int i = (low - 1);      // Index of smaller element
    
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(double *arr, int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pivotIndex = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Call like this:
// quickSort(numbers, 0, size - 1);
