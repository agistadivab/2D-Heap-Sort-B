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
    		system("cls");
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


#include <stdio.h>
#include <stdlib.h>
#include "HeadList.h"
#include "HeadTree.h"


int main(){
	int y;
	printf("1. SORT TREEE\n2. TRANVERSAL\n");
	printf("Masukan Pilihan: ");
	scanf("%d", &y);
	switch(y){
		case 1 :
			inputan();
			 //melakukan heap sort
    		maxHeapSort();
    		//tampilan asc
		    printf("tampilan ASCENDING\n");
		    ASC();
		    printf("\n");
		    //tampilan desc
		    printf("tampilan DESCENDING\n");
		    DESC();
		    printf("\n");
		    break;
		case 2 :
			inputan();
			printf("PreOrder:\n");
			PreOrder(root);
			printf("\n");
			printf("InOrder:\n");
			InOrder(root);
			printf("\n");
			printf("PostOrder:\n");
			PostOrder(root);
			printf("\n");
		case 3 :
			return;
	}
    
    return 0;
}
