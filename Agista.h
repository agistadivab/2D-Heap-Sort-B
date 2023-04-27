#ifndef Agista_h
#define Agista_h

address createBinaryTree(int data)
void deleteTree(address node)

#endif

#include <stdio.h>
#include <stdlib.h>

address createBinaryTree(int data) {
    address newNode = (address) malloc(sizeof(tree1));
    if (newNode != NULL) { 
        newNode->info = data; 
        newNode->prnt = NULL; 
        newNode->rightson = NULL; 
        newNode->leftson = NULL; 	
    }
	return newNode;
}

void deleteTree(address node) {
    if (node == NULL) { 
        return;
    }
    deleteTree(node->leftson); // hapus sub-pohon kiri
    deleteTree(node->rightson); // hapus sub-pohon kanan
    free(node); // hapus node
}


