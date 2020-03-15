/*
	Name: sukhdev singh
	Date: 10-09-18 23:49
	Description: queue cicular array
		enqueue data ( using push, isFull,isEmpty ) ;traverse data;
*/

#include <iostream>
using namespace std;

struct cq {
	int arr[10];
	int front ;
	int rear ;
};
// checking empty
int isEmpty ( cq *q ){
	if (q->front == -1 && q->rear== -1)
		return 1;
	else
		return 0;
}
// checking full
int isFull (cq *q) {
	if ( (q->rear + 1) % 10 == q->front )
		return 1;
	else
		return 0;
}
// inserting data
int enqueue ( cq * q, int data) {
	if ( isFull(q) )
		return 1;
	if (isEmpty(q))
		q->front = 0 ;
	q->rear = ( q->rear + 1) % 10 ;
	q->arr[ q->rear] = data ;
	cout<< q->rear<<endl;
	return 0 ;
}
// deleting data
int dequeue ( cq * q , int *data ){
	if( isEmpty(q) )
		return 1;
	* data = q->arr[q->front];
	if ( q->front==q->rear){
		q->rear=q->front= -1;
	}
	else {
		q->front = ( q->front + 1 ) % 10 ;
	}
	return 0;
}
// traversing data
void traverse1 ( cq * q ) {
	q->front = 0;
	cout << q->arr[q->front++] <<"->" ; cout <<"1\n";
	cout << q->arr[1] <<"->" ; cout <<"2\n\n\n";
}
void traverse ( cq * q) {
	int i=1;q->rear=0; q->front=0;
	while ( (q->rear + 1) % 10 != q->front ) {         // condition makes q->rear=1 not equal to q->front and then loop will start
		cout<<i++<<"->"<< q->arr[q->rear] <<endl;
		q->rear = (q->rear +1) % 10 ;        // bcoz when q->rear= 8 will print and q->rear makes 9 then while conditon faild
	}
	cout << i<< "->" << q->arr[q->rear]<<"\n";       //  so , To print q->rear=9 "cout" is to be used
}

int main () {
	cq *q = new cq;
	q->front = -1 ;
	q->rear = -1 ;
	for( int i=0,d=5; i<10; i++ ,d+=5){
		enqueue (q, d);
	}
	traverse1 (q); // only print first two data
	traverse (q);
/*	int data = 0;dequeue (q , &data);cout<< " delete data is "<< data << endl ;
	for(int i=0; i<5; i++){
 		dequeue (q , &data);
		cout<< " delete data is "<< data << endl ;
	}
	traverse (q);
*/
	return 0;
}
