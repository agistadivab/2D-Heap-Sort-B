#include <stdio.h>
#include <stdlib.h>
#include "HeadList.h"
#include "HeadTree.h"
#include "HeadTampilan.h"

int main() {
	int choice,level;
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
        	inputan(); 
        	printf("\n====== Binary Tree ======\n");
			treeprint(root, level);
            tampilTrvsl();
            printf("\nPRE-ORDER:\n");
			PreOrder(root);
            printf("\nIN-ORDER:\n");
            InOrder(root);
            printf("\nPOST-ORDER:\n");
            PostOrder(root);
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
