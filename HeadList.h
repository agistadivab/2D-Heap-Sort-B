#ifndef HeadList_h
#define HeadList_h

typedef int infotype;
typedef struct list *pointer;
typedef struct list {
	infotype info;
	pointer next;
	pointer prev;
} ls;

pointer First;
pointer Last;

void InsertLast(infotype item);
void ASC();
void DESC();

#endif
