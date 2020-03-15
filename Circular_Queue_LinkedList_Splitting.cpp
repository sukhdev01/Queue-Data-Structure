/*
	Name: sukhdev singh
	Author:  linked list
	Date: 11-09-18 23:15
	Description: functions are : inserting , searching , travering and main
*/

#include <iostream>
using namespace std ;

struct Node {
	int data ;
	Node* next ;
};
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
void traverse ( Node * head){
	Node * temp = head ;
	do {                                // do while loop To print first Node with while stopping condition
		cout << temp-> data << "  ";
		temp= temp->next ;
	} while ( temp != head );
	//cout<< "\n Traverse complete so 1st data " << temp->data;
}
int split(Node **head, Node **head1){
	Node *temp=NULL, *endptr=NULL; temp =*head; int k=0;
	do {
		endptr=temp;
		temp= temp->next ;      k++;
	} while ( temp != *head );
	for ( int i=1;i<k/2; i++){          //4 mid (k/2)-1
		temp= temp->next ;            // to get middle of the CLL
	}
	*head1= temp->next;
	endptr->next = *head1;
	temp->next = *head; 			// original Head Node
	return 0;
}
int main () {
	Node * head = NULL ,*head1=NULL, *prev = NULL ;
	for ( int i=0,d=10; i<15; i++ ,d +=10 ){
		search ( head, & prev , d);
		insert ( &head ,prev, d ) ;
	}
	traverse(head);
	split(&head,&head1);
	cout<<"\nAfter splitting the CLL into 2 part :\n";
	cout<<"First Part is:\n";	traverse(head);
	cout<<"\nSecond Part is:\n";	traverse(head1);
	return 0;
}
