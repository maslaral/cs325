#ifndef BADSORTTIMED_INCLUDED
#define BADSORTTIMED_INCLUDED 1

typedef struct DynArr DynArr;

void initDynArr(DynArr *v, int capacity);
DynArr *newDynArr(int cap);
void _dynArrSetCapacity(DynArr *v, int newCap);
void writeFile();
void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);
void addDynArr(DynArr *v, int val);
void readFile(int n, float a);
void saveFile(DynArr *v);
void badSort(DynArr *v, int l, int r, float a);

#endif
