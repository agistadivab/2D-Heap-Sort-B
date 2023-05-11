#include <stdio.h>
#include <stdlib.h>
#include "HeadList.h"
#include "HeadTree.h"


int main(){
	int y;
	awal :
	system("cls");
	printf("1. SORT TREEE\n2. TRANVERSAL\n");
	printf("Masukan Pilihan: ");
	scanf("%d", &y);
	switch(y){
		case 1 :
			//system("cls");
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
		    system("pause");
		    goto awal;
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
			system("pause");
		    goto awal;
		case 3 :
			return;
	}
    
    return 0;
}
