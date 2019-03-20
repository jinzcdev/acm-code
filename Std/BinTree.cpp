#include <stdio.h>
#include <stdlib.h>
typedef struct BinTree
{
	int e;
	struct BinTree* left;
	struct BinTree* right;
}BinTree;

void PreOrderTraversal(BinTree* b){
	if(b){
		printf("%d\n",b -> e );
		PreOrderTraversal(b -> left);
		PreOrderTraversal(b -> right);
	}
}

int main(){
	BinTree* b = (BinTree *) malloc(sizeof(BinTree));
	b -> e = 1;
	BinTree* b_left = (BinTree *) malloc(sizeof(BinTree));
	b_left -> e = 2;
	b_left -> left = NULL;
	b_left -> right = NULL;

	BinTree* b_right = (BinTree *) malloc(sizeof(BinTree));
	b_right -> e = 3;
	b_right -> left = NULL;
	b_right -> right = NULL;

	b -> left = b_left;
	b -> right = b_right;

	PreOrderTraversal(b);



	return 0;
}
