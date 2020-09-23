#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	struct Node *next, *pre;
	int data;
}Node;
int N;
Node * head, * last; 
void push_front(int num);
void push_back(int num);
void pop_front();
void pop_back();
void deq_show();
void deq_clear();
char *order;
int Reverse=0;
int fail=0;

void nojam5430(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int T;
		order=malloc(sizeof(char)*100001);
		scanf(" %s",order);
		scanf("%d",&T);
		char input;
		while(1){
			scanf(" %1c",&input);
			if(T==0){
				scanf(" %1c",&input);
				break;
			}
			if(input=='['){
				int number;
				scanf("%d", &number);
				push_back(number);
			}
			if(input==','){
				int number;
				scanf("%d", &number);
				push_back(number);
			}
			if(input==']'){
				break;
			}
		}
		int k2=0;
		while(order[k2]!='\0'){
			if(order[k2]=='R'){
				if(Reverse) Reverse=0;
				else Reverse=1;
			}
			if(order[k2]=='D'){
				if(Reverse) pop_back();
				else pop_front();
			}
			k2++;
		}
		if(fail){
			printf("error\n");
			deq_clear();
		}
		else{
			printf("[");
			deq_show();
			printf("]\n");
		}
		fail=0;
		Reverse=0;
		free(order);
	}
}


int main(){
	nojam5430();
}

void push_back(int num){
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
		fail=1;
		return;
	}
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
		fail=1;
		return;
	}
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
void deq_show(){
	while(head!=NULL){
		if(Reverse){
			if(last->pre==NULL){
				printf("%d",last->data);
			}else{
				printf("%d,",last->data);
			}
			pop_back();
		}else{
			if(head->next==NULL){
				printf("%d",head->data);
			}else{
				printf("%d,",head->data);
			}
			pop_front();
		}
	}
}
void deq_clear(){
	while(head!=NULL){
		pop_front();
	}
}
