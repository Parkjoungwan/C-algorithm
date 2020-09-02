#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
	struct Node * next;
	int data;
};
struct Node * head;
struct Node * last;
struct Node * beforelast;
int N;
bool first=true;
char *command;

void s_push(int num){
	struct Node * node;
	ndoe = malloc(sizeof(struct Node));
	if(first){
		node->data=num;
		node->next=NULL;
		head=node;
		last=node;
		beforelast=node;
		first=false;
	}else{
		node->data=num;
		node->next=NULL;
		beforelast=last;
		last->next=node;
		last=node;
	}
}

void s_pop(){
	if(s_empty()){
		return;
	}
	struct Node * garbege;
	garbege=last;
	last=beforelast;
	printf("%d\n",garbege->data);
	free(garbege);
}

void order(){
	command=malloc(sizeof(char)*7);
	scanf("%s",command);
	if(!strcmp(command,"push")){
		int num;
		scanf("%d",&num);
		s_push(num);
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
