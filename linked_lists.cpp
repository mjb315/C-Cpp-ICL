// Programming II - Department of Bioengineering at Imperial College London
// 2015 Exam
// Question q7.cpp

#include <iostream>
#include <string>

using namespace std;

class Node{
	private:
		string Name;
		Node* next_ptr;
		
	public:
		Node();
		Node(string name_in, Node* next_ptr_in);
		
		string getName(){return Name;};
		Node* getNext(){return next_ptr;};	
		void setName(string name_in){Name = name_in;};
		void setNext(Node* next_ptr_in){next_ptr = next_ptr_in;};
};

Node::Node(){
	Name = "";
	next_ptr = 0;
}

Node::Node(string name_in, Node* next_ptr_in){
	Name = name_in;
	next_ptr = next_ptr_in;
}

class Queue{
	private:
		Node* current_ptr;
	
	public:
		Queue();
		
		void addNode(string name_in);
		void printQueue();
		string removeNode();
};

Queue::Queue(){
	current_ptr = 0;
}

void Queue::addNode(string name_in){
	current_ptr = new Node(name_in,current_ptr);
}

void Queue::printQueue(){
	cout << "Current Queue: " << endl;
	for(Node* it_ptr = current_ptr; it_ptr != 0; it_ptr = it_ptr->getNext()){
		cout << it_ptr->getName() << endl;
	}
}

string Queue::removeNode(){
	string deleted_name = "";
	Node* tmp_ptr;
	
	for(Node* it_ptr = current_ptr; it_ptr != 0; it_ptr = it_ptr->getNext()){
		
		if(it_ptr==current_ptr && it_ptr->getNext()==0){
			deleted_name = it_ptr->getName();
			
			current_ptr = 0;
			
		}else if(it_ptr->getNext()->getNext()==0){
			deleted_name = it_ptr->getNext()->getName();
			delete it_ptr->getNext();
			it_ptr->setNext(0);	
		}
	}
	
	return deleted_name;
}
int main()
{
	Queue line;
	
	line.addNode("james");
	line.addNode("greg");
	line.addNode("sarah");
	line.addNode("catherine");
	line.addNode("julie");
	line.addNode("alex");
	
	line.printQueue();

	cout<< " > removing " << line.removeNode() << " from queue." <<endl;
	cout<< " > removing " << line.removeNode() << " from queue." <<endl;
	
	line.printQueue();
	
	line.addNode("jack");
	line.addNode("angela");

	line.printQueue();
	
	return 0;	
}






