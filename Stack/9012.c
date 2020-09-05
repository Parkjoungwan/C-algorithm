#include <stdio.h>
#include <stdlib.h>
struct Node {
	struct Node * next, *pre;
	char data;
}

int N;
struct Node * head;
struct Node * last;
void s_popcheck();
void s_push();
bool fisrt=true;

void order(char glho){
	if(glho=='('){
		s_push();
		return;
	}else{
		s_popcheck();
		return;
	}
}

void nojam9012(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char glho;
		while((glho=getchar())!=EOF){
			order(glho);
		}
	}
}

int main(){
	nojam9012();
}

void s_push(){
	struct Node * node;
	node = malloc(sizeof(struct Node));
	if(fisrt){
		node->pre = NULL;
		node->next = NULL;
		node->data = '(';
		head=node;
		last=node;
	}else{
		node->pre = last;
		node->data = '(';
		node->next = NULL;
		last = node;
	}
}
void s_popcheck(){
	if(fisrt){
		return;
	}
	if (last->data=='('){
	
	}
}
