#include <stdio.h>
#include <stdlib.h>	
#include "HeadList.h"

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
			X->next = First;
			First->prev = X;
			First = X;
		}	
	}
}

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
