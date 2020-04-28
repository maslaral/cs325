#ifndef MERGESORT_INCLUDED
#define MERGESORT_INCLUDED 1

typedef struct DynArr DynArr;

void initDynArr(DynArr *v, int capacity);
DynArr *newDynArr(int cap);
void _dynArrSetCapacity(DynArr *v, int newCap);
void writeFile();
void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);
void addDynArr(DynArr *v, int val);
void readFile(int n);
void saveFile(DynArr *v);
void _merge(DynArr *v, int p, int q, int r);
void mergeSort(DynArr *v, int p, int r);

#endif