#ifndef HeadTree_h
#define HeadTree_h

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

int max(int a, int b);
address createNode(infotype data);
address buildTreeFromArray(infotype arr[], int start, int end);
void swapNodes(address node1, address node2);
void heapify(address node);
void BuildMaxHeap(address node);
int max(int a, int b);
int height(address root);
address LastNodeDanParent(address root, int level, address parent);
address FindLastNode(address root); 
void maxHeapSort();

void PreOrder(address node);
void InOrder(address node);
void PostOrder(address node);

void inputan();
void deleteTree(address node);

#endif
