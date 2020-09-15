#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	struct Node * pre;
	int data;
}Node;
int N;
Node *last=NULL;
char result[200001];
void s_push(int N);
void s_pop();
int s_empty();

void nojam1874(){
	scanf("%d",&N);
	int *num;
	num=malloc(sizeof(int)*(N+1));
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
	}
	int target=1;
	int pushnum=1;
	int i;
	for(i=1;i<=2*N;i++){
		if(last==NULL){
			s_push(pushnum);
			pushnum++;
			result[i]='+';
		}else if(num[target]==last->data){
			s_pop();
			target++;
			result[i]='-';
		}else{
			if(pushnum>N)break;
			s_push(pushnum);
			pushnum++;
			result[i]='+';
		}
		//need fix algorithm for find failure
	}
	if(s_empty()){
		for(int j=1;j<i;j++){
			printf("%c\n",result[j]);
		}
	}else{
		printf("NO");
	}
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
int s_empty(){
	if(last==NULL) return 1;
	else return 0;
}
