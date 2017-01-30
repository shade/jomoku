#include "jomoku.h"
 
void qs(uint *A, int len)
{
  if (len < 2) return;
 
  int pivot = A[len / 2];
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;
    //SWAP 1
    //int temp = A[i];
    //A[i]     = A[j];
    //A[j]     = temp;

    A[i] ^= A[j];
    A[j] ^= A[i];
    A[i] ^= A[j];
  }
 
  qs(A, i);
  qs(A + i, len - i);
}