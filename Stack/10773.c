#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node * next, *pre;
	int data;
};

int N;
int SUM;
struct Node * head;
struct Node * last;
void s_pop();
void s_push(int num);

void order(int num){
	if(num==0){
		s_pop();
		return;
	}
	s_push(num);
	return;
}

void nojam10773(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		order(num);
	}
	printf("%d\n",SUM);
}

int main(){
	nojam10773();
}

void s_pop(){
	struct Node * garbege;
	garbege=last;
	if(head==NULL){
	return;
	}else if (garbege->pre==NULL){
		head=NULL;
		last=NULL;
		SUM-=garbege->data;
		free(garbege);
		return;
	}else{
		garbege->pre->next=NULL;
		last=garbege->pre;
		SUM-=garbege->data;
		free(garbege);
		return;
	}
}

void s_push(int num){
	SUM+=num;
	struct Node * node;
	node = malloc(sizeof(struct Node));
	if(head==NULL){
		head=node;
		node->data = num;
		node->pre = NULL;
		node->next = NULL;
		last = node;
	}else{
		node->data = num;
		node->pre = last;
		node->next = NULL;
		last = node;
	}
	return;
}
