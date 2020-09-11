#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node * pre;
	int data;
}Node;
int N;
Node *last=NULL;

void s_push(int N);
void s_pop();

void nojam1874(){
	scanf("%d",&N);
	int *num;
	num=malloc(sizeof(int)*(N+1));
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1;i<=N;i++){
		for(int j=1;num[i]!=j;i++){
			s_push(j);
		}
	}
}

int main(){
	nojam1874();
}

void s_push(int N){
	if(last==NULL){
		Node *node;
		node = malloc(sizeof(Node));
		node->data = N;
		last=node;
		node->pre == NULL;
	}else{
		Node *node;
		node = malloc(sizeof(Node));
		node->data = N;
		node->pre = last;
		last= node;
	}
	printf("+\n");
}
void s_pop(){
	Node *trash;
	trash=last;
	last=last->pre;
	free(trash);
	printf("-\n");
}
