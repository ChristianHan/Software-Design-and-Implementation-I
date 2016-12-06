class Node{
	
public:
	double value;
	Node* next;

	Node(double v, Node* n);

};

class Poly{

public:
	Node* getHead();
	Poly();
	void print();
	void append(double v);
};
