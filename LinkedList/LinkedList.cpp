/**************************************************
* 
*      program name:       Skeleton
*      Author:             Captain Kirk
*      date due:            
*      remarks:            Skeleton C code 
*                          Start with this format    
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>             // needed for I/O
#include <cstdlib>              // needed for system call

/******************************************
*     pre-processor
******************************************/
#define PI 3.14159
using namespace std;
/****************************************
*         Class definitions
****************************************/
class Node
{
	private:
		int* number;			// value of the node
		Node* prev;				// pointer to the previous node
		Node* next;				// pointer to the next node
		
	public:
		// Constructor
		Node();
		Node(int);
		// Deconstructor
		~Node();
		
		// Methods
		void display();	
		// setters
		void setPrev(Node* np) 	{prev = np;}
		void setNext(Node* np)	{next = np;}
		void setNumber(int x)	{*number = x;}
		
		// getters
		Node* getNext()		{return next;}
		Node* getPrev()		{return prev;}
		int getNumber()		{return *number;}
};
/****************************************
*         member functions
****************************************/
//Constructor
Node :: Node()
{
	cout << "\n in constructor \n";
	number = new int();
	prev = NULL;
	next = NULL;
}
Node::Node(int value)
{
	cout << "\n in constructor \n";
	number = new int(value);
	prev = NULL;
	next = NULL;
}
Node::~Node()
{
	cout << "\n in deconstructor \n";
	delete prev;
	delete next;
	delete number;
}
void Node::display()
{
	cout << endl;
	cout << "node number   " << getNumber() << endl;
	cout << "previous node " << getPrev()   << endl;
	cout << "next node     " << getNext()   << endl;
	cout << "current node  " << this        << endl;
	cout << endl; 
}
/****************************************
*          function prototypes
****************************************/
void loadLinkedList(Node**);
void traverse(Node** start);
void addNode(Node** start, int addNum);
void delNode(Node** start, int delNum);

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
	//Node n1;
	//n1.setNumber(99);
	//n1.display();
	
	Node* start;
	Node* temp;
	Node* savePtr;
	Node** ppStart;
	ppStart = &start;
	
	loadLinkedList(ppStart);
   	traverse(&start);
   	//delNode(&start,5);
   	//delNode(&start,6);
   
    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

void delNode(Node** start, int delNum)
{
	Node* current;
	current = *start;
	while((delNum != current->getNumber() && current->getNext()!=NULL))
	{
		current = current->getNext();
	}
	current->display();
}
void addNode(Node** start, int addNum)
{
	
}
void traverse(Node** start)
{
	Node* current = *start;
	current->display();
	while(current->getNext()!=NULL)
	{
		current = current->getNext();
		current->display();
	}
	
}
void loadLinkedList(Node** pps)
{
    // we are basically just dealing with addresses of objects
    // we will store the address of the current object 
    // and the address of the previous and next objects
    /*****************/
    Node* start;
    Node* temp;
    Node* savePtr;         
    // create linked list (using new for each Node)
    
    start = new Node(1);          // create the 1st (start) Node
    savePtr = start;              // save address of CURRENT Node in savePtr
    //savePtr->display();
    //system("pause");  
        
    temp = new Node(3);         // create the next NEW Node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT Node using saved pointer
    savePtr = temp;             // save address of CURRENT Node in savePtr to use with next Node
    //savePtr->display();
    //system("pause");
        
    temp = new Node(5);         // create the next NEW Node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT Node using saved pointer
    savePtr = temp;             // save address of CURRENT Node in savePtr to use with next Node
    //savePtr->display();
    //system("pause");
         
    temp = new Node(7);         
    savePtr->setNext(temp);     
    temp->setPrev(savePtr);     
    savePtr = temp;             
    
    temp = new Node(9);         
    savePtr->setNext(temp);     
    temp->setPrev(savePtr);     
    savePtr = temp;            
  
    temp = new Node(11);        
    savePtr->setNext(temp);    
    temp->setPrev(savePtr);     
    savePtr = temp;             
        
    temp = new Node(13);         
    savePtr->setNext(temp);     
    temp->setPrev(savePtr);    
    savePtr = temp;             
    
    //traverseList(start);
    cout << "\n Start address after Traverse call inside Linked List = " << start << "\n\n";
    *pps = start;
    system ("pause");
}   
     
    











 

