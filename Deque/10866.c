#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node * next,pre;
	int data;
}Node;
int N;

void order(){
	char *command;
	command = malloc(sizeof(char)*10);

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
