#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	struct Node * next;
	int data;
}Node;

int N;
int LastStanding;
Node *head;
Node *last;
void q_push(int num);
int q_pop();

void nojam2164(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		q_push(i);
	}
	while(head!=NULL){
		int repush;
		LastStanding=q_pop();
		repush=q_pop();
		if(repush==-1) break;
		q_push(repush);
	}
	printf("%d\n",LastStanding);
}

int main(){
	nojam2164();
}

void q_push(int num){
	Node *node;
	node = malloc(sizeof(Node));
	if(head==NULL){
		head=node;
		last=node;
		node->data = num;
		node->next = NULL;
	}else{
		last->next = node;
		node->data = num;
		node->next = NULL;
		last = node;
	}
}

int q_pop(){
	if(head==NULL){
		return -1;
	}
	int result;
	Node * trash;
	trash=head;
	if(head->next==NULL){
		head=NULL;
		last=NULL;
	}else{
		head = trash->next;
	}
	result=trash->data;
	free(trash);
	return result;
}
