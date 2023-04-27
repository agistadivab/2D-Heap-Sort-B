#ifndef Afyar_h
#define Afyar_h

void PreOrder(Node* node);
void InOrder(Node* node);
void PostOrder(Node* node);
void swapNodes(address node1, address node2);

void PreOrder(Node* node){
	if (root == NULL){
		printf("Silahkan membuat tree/root terlebih dahulu");
	}
	
	if(node != NULL){
		printf("%d ", node->data);
		PreOrder(node->leftson);
		PreOrder(node->rightson);
	}
	
}

void InOrder(Node* node) {
    if (root == NULL) {
        printf("Silahkan membuat tree/root terlebih dahulu");
        return;
    }

    if (node != NULL) {
        InOrder(node->leftson);
        printf("%d ", node->data);
        InOrder(node->rightson);
    }
}

void PostOrder(Node* node) {
    if (root == NULL) {
        printf("Silahkan membuat tree/root terlebih dahulu");
        return;
    }

    if (node != NULL) {
        PostOrder(node->leftson);
        PostOrder(node->rightson);
        printf("%d ", node->data);
    }
}
 
 void swapNodes(address node1, address node2) {
    infotype temp = node1->info;
    node1->info = node2->info;
    node2->info = temp;
}

#endif
