#include <stdio.h>
#include <stdlib.h>	
#include "HeadTree.h"

address createNode(infotype data) {
    address newNode = (address) malloc(sizeof(tree1));
    newNode->info = data;
    newNode->prnt = NULL;
    newNode->rightson = NULL;
    newNode->leftson = NULL;
    return newNode;
}

address searchNode(address node, infotype target) {
    if (node == NULL || node->info == target) {
        return node;
    }
  
    address foundNode = searchNode(node->leftson, target);
    if (foundNode != NULL) {
        return foundNode;
    }
  
    return searchNode(node->rightson, target);
}

void addChild(address parent) {
    infotype data;
    printf("Masukkan child (0 untuk berhenti): ");
    scanf("%d", &data);
    
    if (data != 0) {
        printf("Masukkan parent: ");
        infotype parentData;
        scanf("%d", &parentData);
        
        address search = searchNode(parent, parentData);
        
        if (search == NULL) {
            printf("Parent tidak ditemukan!\n");
            addChild(parent);
            return;
        }
        
        address child = createNode(data);
        child->prnt = search;
        
        if (search->leftson == NULL) {
            search->leftson = child;
        } else if (search->rightson == NULL) {
            search->rightson = child;
        } else if (search->leftson != NULL && search->rightson != NULL){
            printf("parent sudah memiliki dua anak!\n");
            return;
        }  
        addChild(parent);  // Lanjutkan menambahkan child pada parent yang sama
    }
}



void buildTree(address node) {
    addChild(root);
}

void treeprint(address node, int level)
{
	int i;

    if (node == NULL) {
        return;
    }

    treeprint(node->rightson, level + 1);

    for (i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", node->info);

    treeprint(node->leftson, level + 1);
}


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

void swapNodes(address node1, address node2) {
    infotype temp = node1->info;
    node1->info = node2->info;
    node2->info = temp;
}

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

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
    	
}

int height(address root)
{
    if (root == NULL)
        return 0;

    int left = height(root->leftson) + 1;
    int right = height(root->rightson) + 1;

    return max(left, right);
}

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

void PreOrder(address node){
	if (node == NULL){
		return;
	}
	
	if(node != NULL){
		printf("%d ",node->info);
		PreOrder(node->leftson);
		PreOrder(node->rightson);
	}
	
}

void InOrder(address node){
	if (node == NULL){
		return;
	}
	if(node != NULL){
		InOrder(node->leftson);
		printf("%d ",node->info);
		InOrder(node->rightson);
	}
}

void PostOrder(address node){
	if (node == NULL){
		return;
	}
	if(node != NULL){
		PostOrder(node->leftson);
		PostOrder(node->rightson);
		printf("%d ",node->info);
	}
}
