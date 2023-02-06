#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	int val;
	
	struct data *left;
	struct data *right;
} *root = NULL;

struct data *createData(int val){
	struct data *temp = (struct data*)malloc(sizeof(struct data));
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(struct data *curr, int newVal){
	if(root == NULL){
		root = createData(newVal);
	}
	else{
		if(newVal < curr->val && curr->left == NULL){
			curr->left = createData(newVal);
			
		}else if(newVal > curr->val && curr->right == NULL){
			curr->right = createData(newVal);
			
		}else if(newVal < curr->val){
			insert(curr->left , newVal);
			
		}else if(newVal > curr->val){
			insert(curr->right , newVal);
		}
	}
}

void displayInfix(struct data *curr){
	
	if(curr->left != NULL) displayInfix(curr->left);
	printf("%d " , curr->val);
	if(curr->right != NULL) displayInfix(curr->right);
}

void find(struct data *curr, int val){
	if(curr==NULL){
		printf("%d is not found\n",val);
		return;
	}
	else if(curr->val == val){
		printf("%d is found\n",val);
		return;
	}
	//jika val lebih kecil dari curr node , rekursif ke kiri
	else if(val < curr->val){
		find(curr->left , val);
	}
	//jika val lebih besar dari curr node , rekursif ke kanan
	else if(val > curr->val){
		find(curr->right, val);
	}
}

struct data *delRecursive(struct data *parent, struct data *curr){
	// jika node leaf
	if(curr->left == NULL && curr->right == NULL){
		free(curr);
		return 0 ; 
	}
	
	// jika node hanya memiliki left child
	else if(curr->left != NULL && curr->right == NULL){
		return curr->left;
		
	}
	
	//jika node hanya memiliki right child
	
	else if(curr->left == NULL && curr->right!= NULL){
		return  curr->right;
	}
	
	//jika node memiliki 2 anak
}

struct data *parent = NULL;
void del(struct data *curr, int delVal){
	if (curr == NULL){
		printf("%d is not available to delete\n",delVal);
		return;
	}
	if(curr->val == delVal){
		//no delete
		curr = delRecursive(parent,curr);
		if(delVal > parent->val) parent->right = curr;
		else parent->left = curr;
		return;
	}
	if(delVal < curr->val){
		parent =  curr;
		del(curr->left , delVal);
	}
	else if(delVal > curr->val){
		parent = curr;
		del(curr->right , delVal);
	}
}



int main(){
	
	insert(root, 20);
	insert(root, 10);
	insert(root, 50);
	insert(root, 2);
	insert(root, 100);
	insert(root, 90);
	
	displayInfix(root);
	printf("\n");

//	find(root, 5);
//	find(root, 20);
//	find(root, 101);

	del(root,10);
	del(root,11);
	displayInfix(root);
	
	
	return 0;
}