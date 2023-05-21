#include <stdio.h>
#include <stdlib.h>
#include "HeadList.h"
#include "HeadTree.h"
#include "HeadTampilan.h"

int main() {
	int choice,level,rootData;
    tampilan();
    system("pause");
    awal :
	system("cls");
    menu();
    printf("Masukan pilihan: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:{
    		system("cls");
    		inputan();
			printf("\n\n");
    		maxHeapSort();
    		tampilSort();
    		printf("\nTampilan ASCENDING:\n");
    		ASC();
    		printf("\nTampilan DESCENDING:\n");
    		DESC();
    		printf("\n\n");
    		printf("tekan enter untuk ke menu utama");
    		printf("\n\n");
    		system("pause");
    		goto awal;
            break;
        }
        case 2:{
        	system("cls");
        	printf("\n====== Binary Tree ======\n");
			printf("\n");
			printf("--child yang pertama di masukkan adalah anak kiri, jika sudah ada anak kiri maka akan di masukkan ke anak kanan--");
			printf("\n");
			printf("\n");
    		printf("Masukkan nilai root: ");
    		scanf("%d", &rootData);

    		address treeRoot = createNode(rootData);
    		buildTree(treeRoot);
			
			printf("\n");
            printf("\nPRE-ORDER:\n");
			PreOrder(treeRoot);
            printf("\nIN-ORDER:\n");
            InOrder(treeRoot);
            printf("\nPOST-ORDER:\n");
            PostOrder(treeRoot);
    		printf("\n\n");
    		printf("tekan enter untuk ke menu utama");
    		printf("\n\n");
    		system("pause");
    		goto awal;
			break;
		}
        case 3:{
		    exit(0);
            break;
		}
		default:{
			printf("Pilihan tidak valid!\n");
			break;
		}	
}
	return 0;
}
