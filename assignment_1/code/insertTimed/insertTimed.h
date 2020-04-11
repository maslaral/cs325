#ifndef INSERTTIMED_INCLUDED
#define INSERTTIMED_INCLUDED 1

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
void insertSort(DynArr *v);

#endif