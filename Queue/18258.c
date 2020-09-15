#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct q_node{
	int data;
	struct q_node *next;
} q_node;

int N;
int size=0;
void q_pop();
void q_push(int num);
void q_size();
void q_empty();
void q_front();
void q_back();
q_node * head;
q_node * last;


void order(){
	char * command;
	command = malloc(sizeof(char)*7);
	scanf("%s",command);
	if(!strcmp(command,"push")){
		int num;
		scanf("%d", &num);
		q_push(num);
	}
	if(!strcmp(command,"pop")){
		q_pop();
	}
	if(!strcmp(command,"size")){
		q_size();
	}
	if(!strcmp(command,"empty")){
		q_empty();
	}
	if(!strcmp(command,"front")){
		q_front();
	}
	if(!strcmp(command,"back")){
		q_back();
	}
	free(command);
}

void nojam18258(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		order();
	}
}

int main(){
	nojam18258();	
}

void q_push(int num){
	size++;
	q_node * node;
	node = malloc(sizeof(q_node));
	if(head==NULL){
		head = node;
		node->data = num;
		node->next = NULL;
		last = node;
	}else{
		last->next= node;
		node->data = num;
		node->next = NULL;
		last = node;
	}
}
void q_pop(){
	if(head==NULL){
		printf("-1\n");
		return;
	}
	size--;
	q_node *trash;
	trash=head;
	if(head->next==NULL){
		head=NULL;
	}else{
		head=head->next;
	}
	printf("%d\n",trash->data);
	free(trash);
}
void q_size(){
	printf("%d\n",size);
}
void q_empty(){
	if(head==NULL){
		printf("1\n");
	}else{
		printf("0\n");
	}
}
void q_front(){
	if(head==NULL){
		printf("-1\n");
		return;
	}
	printf("%d\n",head->data);
}
void q_back(){
	if(head==NULL){
		printf("-1\n");
		return;
	}
	printf("%d\n",last->data);
}
