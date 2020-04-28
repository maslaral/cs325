#ifndef INSERTSORT_INCLUDED
#define INSERTSORT_INCLUDED 1

typedef struct DynArr DynArr;

void initDynArr(DynArr *v, int capacity);
DynArr *newDynArr(int cap);
void _dynArrSetCapacity(DynArr *v, int newCap);
void writeFile();
void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);
void addDynArr(DynArr *v, int val);
void readFile(char *filename);
void saveFile(DynArr *v);
void insertSort(DynArr *v);

#endif