#include <stdio.h>
#include <stdlib.h>
#include "Syira.h"
#include "Agista.h"
#include "Afyar.h"


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
