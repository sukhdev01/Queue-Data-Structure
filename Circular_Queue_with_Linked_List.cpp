/*
	Name: sukhdev singh
	Date: 11-09-18 23:15
	Description: functions are : inserting , searching , travering and main
*/

#include <iostream>
using namespace std ;

struct Node {
	int data ;
	Node* next ;
};
// insert Node
int insert ( Node ** head , Node * prev , int data ) {
	Node * newNode = new Node ;
	if ( ! newNode )
		return 1 ;
	newNode -> data = data ;
	if ( !*head ) {                                             // or  (!prev)
		// at first
		* head = newNode ;
		newNode ->next = * head ;
	}
	else if ( data < (*head)->data ) {                    // put at 2nd position and swap with first
		newNode->next = (*head)->next ;                 // ( to put at 1st position when data < 1st data of Linked list
		(*head)->next = newNode ;
		// swapping
		int t = (*head) -> data ;
	 	(*head) -> data = newNode-> data;
		newNode-> data = t ;
	}
	else {                                                      // or     if(prev)
		newNode ->next = prev->next ;
		prev->next = newNode;
	}
	return 0;
}
// searching Node
int search (Node * head , Node ** prev , int data) {
	Node * temp= head ;
	*prev = NULL ;
	if (!temp)
		return 1;
	else {
		*prev = temp ;
		temp = temp->next ;
		if ( data == (*prev)->data )
			return 0 ;
		else if( data < (*prev)->data )
			return 1;
	}
	while (temp != head && data > temp->data){
		*prev = temp ;
		temp = temp->next ;
	}
	if ( temp ->data == data )
		return 0 ;
	else
		return 1;
}
//traversing
void traverse ( Node * head){
	Node * temp = head ;
	do {                                // do while to print first Node with while stopping condition
		cout << temp-> data << " -> ";
		temp= temp->next ;
	} while ( temp != head );
	cout<< "\n Traverse complete so 1st data " << temp->data;
}
// main
int main () {
	Node * head = NULL , *prev = NULL ;
	for ( int i=0,d=10; i<10; i++ ,d +=10 ){
		search ( head, & prev , d);
		insert ( &head ,prev, d ) ;
	}
	traverse(head);
	cout << endl <<"Hi\n";
			search ( head, & prev ,55 );              //to insert at middle pos.
			insert ( &head ,prev, 55 ) ;
				search ( head, & prev ,110 );  //to insert at last pos.
		 		insert ( &head ,prev, 110 ) ;
	insert ( &head ,prev, 5 ) ;  	           // no need  of prev's address bcoz one cond. is there to handle it in insert
	insert ( &head ,prev, 2 ) ;  	//to insert at first pos.
		traverse(head);
		cout<< "\nsearch & prev-data " << prev->data <<"\n";
		cout<< "\nsearch & prev-next-data " << (prev->next)->data <<"\n";
	return 0;
}
