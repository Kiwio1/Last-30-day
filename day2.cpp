#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{
	struct LinkNode* next;
	int data;
}Lnode, *Linknode;

void headInsert(Linknode L,int a){
	Lnode* p=(Lnode*)malloc(sizeof(Lnode));
	p->data=a;
	p->next=L->next;
	L->next=p;
}
void LastInsert(Linknode L,int a){
	Lnode* p=(Lnode*)malloc(sizeof(Lnode));
	p->data=a;
	Lnode*q=L;
	while(q->next!=NULL){
		q=q->next;
	}
	q->next=p;
	p->next=NULL;
}
void Traverse(Linknode L){
	Lnode* p=L->next;
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}
}
void reverse(Linknode L){
	Lnode* p=L->next;
	L->next=NULL;    //这一句很重要，如果不加的话，第一个节点就会自己连接自己
	while(p!=NULL){
		Lnode* q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
}



int main(){
	Linknode L=(Lnode*)malloc(sizeof(Lnode));
	L->next=NULL;
	LastInsert(L,1);
	LastInsert(L,2);
	LastInsert(L,3);
	headInsert(L,4);
	headInsert(L,5);
	Traverse(L);
	reverse(L);
	Traverse(L);
	
}
