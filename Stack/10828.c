#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Node{
	struct Node * next, * pre;
	int data;
};
struct Node * head=NULL;
struct Node * last=NULL;
int N;
int size;
char *command;
void s_push(int num);
int s_empty();
void s_pop();
void s_size();
void s_top();

void order(){
	command=malloc(sizeof(char)*7);
	scanf("%s",command);
	if(!strcmp(command,"push")){
		int num;
		scanf("%d",&num);
		s_push(num);
	}
	if(!strcmp(command,"pop")){
		s_pop();
	}
	if(!strcmp(command,"size")){
		s_size();	
	}
	if(!strcmp(command,"top")){
		s_top();
	}
	if(!strcmp(command,"empty")){
		printf("%d\n", s_empty());
	}
}


void nojam10828(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		order();
	}
}

int main(){
	nojam10828();
}

void s_push(int num){
	size++;
	struct Node * node;
	node = malloc(sizeof(struct Node));
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
		last = node;
	}
}

void s_pop(){
	int empty = s_empty();
	if(empty){
		printf("-1\n");
		return;
	}
	size--;
	struct Node * garbege;
	garbege=last;
	if(garbege->pre==NULL){
		head=NULL;
		last=NULL;
		printf("%d\n",garbege->data);
		free(garbege);
		return;
	}else{
		garbege->pre->next = NULL;
		last=garbege->pre;
		printf("%d\n",garbege->data);
		free(garbege);
	}
}

int s_empty(){
	if(head==NULL){
		return 1;
	}else{
		return 0;
	}
}

void s_size(){
	printf("%d\n",size);
}
void s_top(){
	int empty = s_empty();
	if(empty){
		printf("-1\n");
		return;
	}
	printf("%d\n",last->data);
	return;
}
