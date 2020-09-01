#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node * next;
	float data;
};
struct Node * head;
struct Node * last;
int N;
float max;
float avg=0;

void insert(int i){
	struct Node * node;
	node = malloc(sizeof(struct Node));
	if(i==0){
		scanf("%f",&node->data);
		max=node->data;
		node->next = NULL;
		last = node;
		head = node;
	}else{
		scanf("%f",&node->data);
		if(max<node->data){
			max=node->data;
		}
		node->next=NULL;
		last->next=node;
		last = node;
	}
}

void findavg(){
	struct Node * curr=head;
	while(curr != NULL){
		avg+=curr->data;
		curr=curr->next;
	}
	avg=avg/max*100/N;
	printf("%f\n",avg);
}

void nojam1546(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		insert(i);
	}
	findavg();
}

int main(){
	nojam1546();
}
