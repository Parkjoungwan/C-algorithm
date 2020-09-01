#include <stdio.h>
#include <stdlib.h>

struct Linked_list{
	struct Linked_list *next;
	int data;	
};
int order=1;
int max=0;
struct Linked_list *head;
struct Linked_list *last;
void insert(int i){
	int N;
	scanf("%d",&N);
	struct Linked_list *node = malloc(sizeof(struct Linked_list));
	if(i==0){
		node->next=NULL;
		node->data=N;
		head=node;
		last=node;
	}else{
		node->next=NULL;
		node->data=N;
		last->next=node;
		last=node;
	}
}
void search(){
	struct Linked_list *curr=head;
	max=curr->data;
	int i=1;
	while(curr != NULL){
		if(curr->data>max){
			max=curr->data;
			order=i;
		}
		curr=curr->next;
	       i++;	
	}
	printf("%d\n%d\n",max,order);
}

void nojam2562(){
	for (int i=0;i<9;i++){
		insert(i);
	}
	search();
}

int main(){
	nojam2562();
}
