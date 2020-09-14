#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	struct Node * pre;
	int data;
}Node;
int N;
Node *last=NULL;

void s_push(int N);
void s_pop();

void nojam1874(){
	scanf("%d",&N);
	int *num;
	num=malloc(sizeof(int)*(N+1));
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
	}
	int target=1;
	int pushnum=1;
	for(int i=1;i<=2*N;i++){
		if(last==NULL){
			s_push(pushnum);
			printf("pushed: %d\n",pushnum);
			pushnum++;
		}else if(num[target]==last->data){
			s_pop();
			target++;
			printf("poped: %d",num[target]);
		}else{
			s_push(pushnum);
			printf("pushed: %d\n",pushnum);
			pushnum++;
		}
		if(num[target]>last->data){
			printf("NO");
			return;
		}
	}
	printf("YES");
}

int main(){
	nojam1874();
}

void s_push(int N){
	if(last==NULL){
		Node *node;
		node = malloc(sizeof(Node));
		node->data = N;
		last=node;
		node->pre = NULL;
	}else{
		Node *node;
		node = malloc(sizeof(Node));
		node->data = N;
		node->pre = last;
		last= node;
	}
}
void s_pop(){
	Node *trash;
	trash=last;
	if(trash->pre==NULL){
		last=NULL;
		free(trash);
	}else{
		last=last->pre;
		free(trash);
	}
}
