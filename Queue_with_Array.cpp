/*
	Name: sukhdev singh
	Date: 07-09-18 00:34
	Description: Queue using Array
				Functions are insertion , deletion , traversion , isEmpty & isFull . 
*/

#include <iostream>
using namespace std ;
struct queue {
    int front , rear ;
    int arr[20];
};
// for checking empty
int isEmpty (queue * q) {
    if( q->rear==q->front )
        return 1;
    else 
        return 0;
}
// for checking full
int isFull (queue * q) {
    if (q->rear==19)
        return 1;
    else 
        return 0;
}
// for inserting 
int enqueue ( queue * q, int data ) {
    if (isFull(q))
		return 1;
	if (isEmpty(q))
		q->front = 0;
	q->arr[++q->rear] = data;
	return 0;
}
// for deleting
int dequeue ( queue * q ) {
	if ( isEmpty(q) ) 
		return 0;
	if ( q->rear == q->front )			// in case of only one data
		q->front = q->rear = -1 ;
	for (int i= q->front ; i < q->rear ; i++ ) {
		q->arr[i] = q->arr[i+1] ;
	}
	q->front = 0 ;
	q->rear -- ;
	return 0;
} 
// for traversing
void traverse ( queue * q) {
	int i=1;
	while ( q->front != q->rear ) {
		cout<<i<<"->"<< q->arr[q->front] <<endl;
		q->front ++ ; 
		i ++ ;
	}
	q->front = 0 ;
}
// main function
int main () {
	queue * q ;
	q->front = q->rear = -1 ;
	for ( int i=0, d=10; i<19; i++, d +=10 ) {
		enqueue (q, d) ;
	}
	traverse (q);
		dequeue (q);dequeue (q);dequeue (q);dequeue (q);dequeue (q);
	cout << "After some deleting\n";
	traverse (q);	
	return 0;
}
