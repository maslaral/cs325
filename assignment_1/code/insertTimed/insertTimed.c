#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "insertTimed.h"

struct DynArr
{
  int *data;    // actual array with data
  int size;     // size of the array
  int capacity; // array's capacity to allow for dynamic allocation
};

// Description: main organizing function, creates
// an array of random integers between 0 and 10000,
// calls the sort function, and then saves the values
// into the output file
void readFile(int n)
{
  int r;
  writeFile(); // creates the output file
  DynArr *v;
  v = newDynArr(4);

  for (int i = 0; i < n; i++)
  {
    r = rand() % 10001;
    addDynArr(v, r); // adds the rand value to the array
  }

  insertSort(v);   // sorts the array
  saveFile(v);     // saves the dynamic array data to the output file
  deleteDynArr(v); // deletes the array to free memory
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
  // create a temporary new array
  DynArr *temp = newDynArr(newCap);
  assert(temp != 0);

  // copy values from old array to temp array
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

  fptr = fopen("insert.out", "a+");
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
  fopen("insert.out", "w");
}

// Description: Sorts the dynamic array using the
// insert sort algorithm
void insertSort(DynArr *v)
{
  // starting at index 1, loops through the
  // array and compares to previous value(s)
  // and swaps when appropriate
  for (int j = 1; j < v->size; j++)
  {
    int key = v->data[j];
    int i = j - 1;
    while (i >= 0 && v->data[i] > key)
    {
      v->data[i + 1] = v->data[i];
      i = i - 1;
    }
    v->data[i + 1] = key;
  }
}