#include "polynomial.hh"
#include <stdio.h>

Node::Node(double v, Node* n){
	/*Your code goes here */
}

Node* Poly::getHead(){
	/*Change code below*/
	return 0;
}

Poly::Poly(){
	/*Your code goes here*/
}

void Poly::append(double v){
	/*Your code goes here */
}

void Poly::print(){
	Node* temp = getHead();
	while(temp!=0){
		printf("%.2f", temp->value);
		temp = temp->next;
	}
}