#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node *next;
	int data;
	int order;
}Node;

int N;
void q_push(int num,int order);
int q_pop();
void q_clear();
int q_check();
Node *head;
Node *last;

void printer(int page, int order){
	for(int i=0;i<page;i++){
		int importance;
		scanf("%d",&importance);
		q_push(importance,i);
	}
	int numprint=-1;
	int printed =0;
	while(numprint!=order){
		if(q_check()){
			int importance;
			int headorder = head->order;
			importance=q_pop();
			q_push(importance,headorder);
		}else{
			numprint=head->order;
			q_pop();
			printed++;
		}
	}
	printf("%d\n",printed);
	q_clear();
}

void nojam1966(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		int page, order;
		scanf("%d %d",&page,&order);
		printer(page, order);
	}
}

int main(){
	nojam1966();
}

void q_push(int num,int order){
	Node *node;
	node = malloc(sizeof(Node));
	if(head==NULL){
		head=node;
		last=node;
		node->data = num;
		node->order=order;
		node->next = NULL;
	}else{
		last->next = node;
		node->data = num;
		node->order = order;
		node->next = NULL;
		last = node;
	}
	return;
}

int q_pop(){
	if(head==NULL){
		return -1;
	}
	Node * trash;
	int returnnum;
	trash=head;
	if(head->next==NULL){
		head=NULL;
		last=NULL;
	}else{
		head = trash->next;
	}
	returnnum=trash->data;
	free(trash);
	return returnnum;
}

int q_check(){
	if(head==NULL){
		return 0;
	}
	Node *tracker = head;
	int temp = tracker->data;
	while(tracker->next!=NULL){
		if(temp<tracker->data) return 1;
		tracker= tracker->next;
	}
	return 0;
}

void q_clear(){
	if(head==NULL) return;
	while(head!=NULL){
		q_pop();
	}
	return;
}
