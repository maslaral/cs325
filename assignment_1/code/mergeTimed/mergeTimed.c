#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "mergeTimed.h"

struct DynArr
{
  int *data;
  int size;
  int capacity;
};

// Description: main organizing function, creates
// an array of random integers between 0 and 10000,
// calls the sort function, and then saves the values
// into the output file
void readFile(int n)
{
  int r;
  writeFile();
  DynArr *v;
  v = newDynArr(4);

  for (int i = 0; i < n; i++)
  {
    r = rand() % 10001;
    addDynArr(v, r);
  }

  mergeSort(v, 0, v->size - 1);
  saveFile(v);
  deleteDynArr(v);
};

// Description: Initializes the dynamic array by allocating
// space in memory, and setting the array's initial capacity
void initDynArr(DynArr *v, int capacity)
{
  assert(capacity > 0);
  assert(v != 0);

  v->data = (int *)malloc(sizeof(int) * capacity);
  assert(v->data != 0);

  v->size = 0;
  v->capacity = capacity;
};

// Description: Function to create the dynamic array, calls
// initDynArr and allocates space for struct
DynArr *newDynArr(int cap)
{
  assert(cap > 0);
  DynArr *v = (DynArr *)malloc(sizeof(DynArr));
  assert(v != 0);
  initDynArr(v, cap);
  return v;
};

// Description: Sets the capacity of the array,
// often used internally when the array needs to be
// resized
void _dynArrSetCapacity(DynArr *v, int newCap)
{
  DynArr *temp = newDynArr(newCap);
  assert(temp != 0);

  for (int i = 0; i < v->size; i++)
  {
    temp->data[i] = v->data[i];
  }

  free(v->data);
  v->data = temp->data;
  v->capacity = newCap;

  free(temp);
  temp = 0;
};

// Description: Frees the dynamic array from
// memory
void freeDynArr(DynArr *v)
{
  if (v->data != 0)
  {
    free(v->data); // free the space on the heap
    v->data = 0;   // make it point to null
  }
  v->size = 0;
  v->capacity = 0;
};

// Description: Calls freeDynArr and frees the
// pointer to the DynArr struct
void deleteDynArr(DynArr *v)
{
  freeDynArr(v);
  free(v);
};

// Description: Adds a value to the dynamic
// array. The function also checks if the capacity
// has been reached and calls the set capacity function
// to increase the memory allocated
void addDynArr(DynArr *v, int val)
{
  assert(v != 0);

  if (v->size == v->capacity)
  {
    int newCapacity = v->capacity * 2;
    _dynArrSetCapacity(v, newCapacity);
  }

  v->data[v->size] = val;
  v->size += 1;
};

// Description: Saves the values in the dynamic
// array to the output file
void saveFile(DynArr *v)
{
  FILE *fptr;

  fptr = fopen("merge.out", "a+");
  assert(fptr != NULL);

  for (int i = 0; i < v->size; i++)
  {
    fprintf(fptr, "%d ", v->data[i]);
  }
  fprintf(fptr, "\n");
};

// Description: Creates the output file, necessary
// to ensure a fresh file is written to when saving
// values to the file
void writeFile()
{
  fopen("merge.out", "w");
}

// Description: Merge operation which combines the
// two subarrays by going one by one and comparing, if
// one is less, then it gets added to the original
// array, and that array gets incremented. This continues
// until both subarrays are empty.
void _merge(DynArr *v, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1; // length of left subarray
  int n2 = r - m;     // length of right subarray

  // allocating subarrays
  int lft[n1];
  int rgt[n2];

  // copying values into subarrays from original array
  for (i = 0; i < n1; i++)
  {
    lft[i] = v->data[l + i];
  }
  for (j = 0; j < n2; j++)
  {
    rgt[j] = v->data[m + 1 + j];
  }

  i = j = 0;
  k = l;

  while (i < n1 && j < n2)
  {
    if (lft[i] <= rgt[j])
    {
      v->data[k] = lft[i];
      i++;
    }
    else
    {
      v->data[k] = rgt[j];
      j++;
    }
    k++;
  }

  // if the right subarray is empty
  while (i < n1)
  {
    v->data[k] = lft[i];
    i++;
    k++;
  }

  // if the left subarray is empty
  while (j < n2)
  {
    v->data[k] = rgt[j];
    j++;
    k++;
  }
};

// Description: Function that is called recursively
// and divides the array until the subarray is 1, then
// calls the merge function on each recursion to merge
// the array back together in sorted order
void mergeSort(DynArr *v, int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    _merge(v, l, m, r);
  }
};
