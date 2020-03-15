/*
	Name:sukhdev singh
	Date: 11-09-18 23:25
	Description: functions are :- enqueue ,dequeue , traverse & main
*/

#include <iostream>
using namespace std ;

struct Node {
	int data ;
	Node * next ;
};

struct queue {
	Node * front , * rear ;
};
int init ( queue * q ) {
	q->front = NULL ;
	q->rear = NULL ;
	return 0;
}
//inserting Node
int enqueue ( queue * q , int data ){
	Node * newNode = new Node ;
	if ( !newNode )
		return 1;
	newNode-> data = data;
	if ( q->front == NULL){
		newNode -> next = NULL ;
		q->front = q->rear = newNode ;
	}
	else  {
		newNode ->next = q->rear->next ;          //or   =NULL;
		q-> rear->next = newNode ;
		q->rear = newNode ;                 // to make last one rear
	}
}
// traversing of Linked List
void traverse (queue * q ){
	Node * temp = q-> front ;
	while ( temp ){
		cout << temp -> data << " -> " ;
		temp = temp -> next ;
	}
}
// deletion of a Node at a time
int dequeue ( queue * q) {
	if (! q->front )
		return 1;
	Node * temp = new Node ;
	if ( q->front == q->rear ){
		temp = q->front ;
		q->front = q->rear= NULL;
		cout<<"\n temp   (f=r)  "<< temp->data ;
		delete(temp);
	}
	else {
		temp = q->front ;
		q->front = q->front ->next;
		cout<<"\n temp     "<< temp->data <<"     front     "<<q->front ->data ;
		delete (temp);
	}
	return 0;
}
// int main
int main () {
	queue * q = new queue;
	init ( q ) ;
	for ( int i=0,d=10; i<10; i++ ,d +=20 ){
		enqueue ( q , d ) ;
	}
	traverse ( q );
	for ( int i=0 ; i<10 ; i++ )
		dequeue (q) ;
	cout<<"\n After delete Nodes : ";
	traverse (q); cout << " Nothing ";
	return 0;
}
