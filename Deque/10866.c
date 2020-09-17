#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	struct Node * next, * pre;
	int data;
}Node;

int N;
int size=0;
Node * head=NULL;
Node * last=NULL;
void push_front(int num);
void push_back(int num);
void pop_front();
void pop_back();

void order(){
	char *command;
	command = malloc(sizeof(char)*12);
	scanf("%s",command);
	if(!strcmp(command,"push_front")){
		int num;
		scanf("%d", &num);
		push_front(num);
	}
	if(!strcmp(command,"push_back")){
		int num;
		scanf("%d", &num);
		push_back(num);
	}
	if(!strcmp(command,"pop_front")){
		pop_front();
	}
	if(!strcmp(command,"pop_back")){
		pop_back();
	}
	if(!strcmp(command,"size")){
		printf("%d\n",size);
	}
	if(!strcmp(command,"empty")){
		if(head==NULL){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
	if(!strcmp(command,"front")){
		if(head==NULL){
			printf("-1\n");
		}else{
			printf("%d\n",head->data);
		}
	}
	if(!strcmp(command,"back")){
		if(last==NULL){
			printf("-1\n");
		}else{
			printf("%d\n",last->data);
		}
	}
}

void nojam10866(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		order();
	}	
}

int main(){
	nojam10866();
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
		printf("-1\n");
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
	}
	printf("%d\n",garbege->data);
	free(garbege);
}
void pop_back(){
	if(head==NULL){
		printf("-1\n");
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
	}
	printf("%d\n",garbege->data);
	free(garbege);
}
