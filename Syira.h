#ifndef Syira_h
#define Syira_h
#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------------

// NAMA : Syira Khoerunisa
// NIM : 221511064
// KELAS : D3-1B

//-----------------------------------------------------------------------------------


//struct tree------------------------------------------------------------------------

typedef int infotype;
typedef struct tree *address;
typedef struct tree {
	infotype info;
	address prnt;
	address rightson;
	address leftson;
} tree1;

address root;
address NewNode;
address lastNode, parentOfLastNode;

//struct linked list-----------------------------------------------------------------

typedef struct list *pointer;
typedef struct list {
	infotype info;
	pointer next;
	pointer prev;
} ls;

pointer First;
pointer Last;

address createNode(infotype data) {
    address newNode = (address) malloc(sizeof(tree1));
    newNode->info = data;
    newNode->prnt = NULL;
    newNode->rightson = NULL;
    newNode->leftson = NULL;
    return newNode;
}

// header------------------------------------------------------------------------------------------

address createNode(infotype data);
address buildTreeFromArray(infotype arr[], int start, int end);
void heapify(address node);
void BuildMaxHeap(address node);
int height(address root);
address LastNodeDanParent(address root, int level, address parent);
address FindLastNode(address root);
void InsertLast(infotype item);
void maxHeapSort();
void ASC();
void DESC();
void inputan();

// header--------------------------------------------------------------------------------------------


// MODUL buildTreeFromArray

address buildTreeFromArray(infotype arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    
    int mid = (start + end) / 2;
    address root = createNode(arr[mid]);
    
    root->leftson = buildTreeFromArray(arr, start, mid - 1);
    if (root->leftson != NULL) {
        root->leftson->prnt = root;
    }
    
    root->rightson = buildTreeFromArray(arr, mid + 1, end);
    if (root->rightson != NULL) {
        root->rightson->prnt = root;
    }
    
    return root;
}

// MODUL heapify

void heapify(address node)
{
   if (node->prnt != NULL)
    {

        if (node->info > node->prnt->info)
        {
            swapNodes(node, node->prnt);
            heapify(node->prnt);
        }
    }
    else
    {
        return;
    }
}

//MODUL BuildMaxHeap

void BuildMaxHeap(address node){
	if (root == NULL){
		printf("silahkan membuat tree/root terlebih dahulu");
	}
	
	if(node != NULL){
		heapify(node);
		BuildMaxHeap(node->leftson);
		BuildMaxHeap(node->rightson);
	}
	
}

// MODUL height

int height(address root)
{
    if (root == NULL)
        return 0;

    int left = height(root->leftson) + 1;
    int right = height(root->rightson) + 1;

    return max(left, right);
}

// MODUL LastNodeDanParent

address LastNodeDanParent(address root, int level, address parent)
{
    address temp;
    if (root == NULL)
        return temp;

    if (level == 1)
    {
        lastNode = root;
        parentOfLastNode = parent;
    }
    temp = LastNodeDanParent(root->leftson, level - 1, root);
    temp = LastNodeDanParent(root->rightson, level - 1, root);
    return temp;
}

// MODUL FindLastNode

address FindLastNode(address root)
{
    address temp;
    int levelOfLastNode = height(root);
    temp = LastNodeDanParent(root, levelOfLastNode, NULL);

    if (lastNode!=NULL && parentOfLastNode!=NULL)
    {
        if (parentOfLastNode->rightson !=NULL )
            return parentOfLastNode->rightson;
        else
            return parentOfLastNode->leftson;
    }

    return root;
}

// MODUL InsertLast

void InsertLast(infotype item){
	pointer X,Y;
	X = (pointer) malloc (sizeof (ls));
	if(X == NULL){
		printf("alokasi gagal");
	}else{
	X->info = item;
	X->next = NULL;
	X->prev = NULL;
		if(First == NULL && Last == NULL){
			First = X;
			Last = X;
		}
		else{
			Y = First;
			while(Y->next != NULL){
			Y = Y->next;
			}
			Last->next = X;
			X->prev = Last;
			Last = X;
		}	
	}
}

// MODUL maxHeapSort

void maxHeapSort() {
	infotype maxVal;
    address x;

    while (root != NULL) {
        BuildMaxHeap(root);
        maxVal = root->info;
        x = FindLastNode(root);
        if (x != root) {
            swapNodes(root, x);
        }
        InsertLast(maxVal);
        if (root == x) {
            root = NULL;
        } else {
            if (x->prnt->leftson == x) {
                x->prnt->leftson = NULL;
            } else {
                x->prnt->rightson = NULL;
            }
            x->prnt = NULL;
            free(x);
        }
    }
}

// MODUL ASC

void ASC(){
	pointer Y;
	if (First == NULL){
		printf("List Kosong");
		return;
	}
	Y = First;
	while (Y->next != NULL){
		printf("%d ",Y->info);
		Y = Y->next;
	}
	printf("%d ",Y->info);
}

// MODUL DESC

void DESC(){
	pointer Y;
	if (First == NULL){
	printf("List Kosong");
	return;
	}
	Y = Last;
	while (Y->prev != NULL){
		printf("%d ",Y->info);
		Y = Y->prev;
	}
	printf("%d ",Y->info);
}

// MODUL INPUTAN

void inputan(){
	int n,i;
	printf("masukan jumlah indeks: ");
    scanf("%d", &n);

    infotype arr[n];
    printf("masukan angka dengan spasi: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    root = buildTreeFromArray(arr, 0, n - 1);
}

#endif









