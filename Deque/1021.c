//nojam 1021
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node *next,*pre;
	int data;
}Node;
Node *head,*last;
int N,M;
int size;
int result=0;
void pop_front();
void pop_back();
void push_front(int num);
void push_back(int num);
void Lmove();
void Rmove();
int find(int num);

void nojam1021(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		push_back(i);
	}
	scanf("%d",&M);
	int finding;
	int LorR;
	for(int i=0;i<M;i++){
		scanf("%d",&finding);
		LorR=find(finding);
		if((size-LorR)>LorR){
			result+=LorR;
			for(int i=0;i<LorR;i++) Lmove();
		}else{
			result+=(size-LorR);
			for(int i=0;i<(size-LorR);i++) Rmove(); 
		}
		pop_front();
	}
	printf("%d\n",result);
}

int main(){
	nojam1021();
}
void push_front(int num){
	size++;
	Node * node;
	node = malloc(sizeof(Node));
	if(head==NULL){
		head = node;
		node->data = num;
		node->pre = NULL;
		node->next = NULL;
		last = node;
	}else{
		node->data = num;
		node->next = head;
		node->pre = NULL;
		head->pre = node;
		head = node;
	}
}
void push_back(int num){
	size++;
	Node * node;
	node = malloc(sizeof(Node));
	if(head==NULL){
		head = node;
		node->data = num;
		node->pre = NULL;
		node->next = NULL;
		last = node;
	}else{
		node->data = num;
		node->next = NULL;
		node->pre = last;
		last->next = node;
		last = node;
	}
}
void pop_front(){
	if(head==NULL){
		return;
	}
	size--;
	Node * garbege;
	garbege = head;
	if(garbege->next==NULL){
		head=NULL;
		last=NULL;
	}else{
		head=garbege->next;
		head->pre=NULL;
	}
	free(garbege);
}
void pop_back(){
	if(last==NULL){
		return;
	}
	size--;
	Node * garbege;
	garbege=last;
	if(garbege->pre==NULL){
		head=NULL;
		last=NULL;
	}else{
		last=garbege->pre;
		last->next=NULL;
	}
	free(garbege);
}
int find(int num){
	int Lside=0;
	Node *tracker;
	tracker=head;
	while(tracker->data!=num){
		tracker=tracker->next;
		Lside++;
	}
	return Lside;
}
void Lmove(){
	int temp=head->data;
	pop_front();
	push_back(temp);
}
void Rmove(){
	int temp=last->data;
	pop_back();
	push_front(temp);
}
