/**************************************************
* 
*      program name:    LL-Insert
*      Author:          Chris Jones
*      date due:        2014-03-05                
*      remarks:         Second Linked List Program.
*                       Add a node  
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
	//cout << "\n in constructor \n";
	number = new int();
	prev = NULL;
	next = NULL;
}
Node::Node(int value)
{
    //cout << "\n in constructor \n";
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
void testAddNode(Node** start);


/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
	
	Node* start;
	Node* temp;
	Node* savePtr;
	Node** ppStart;
	ppStart = &start;
	
	loadLinkedList(ppStart);
    testAddNode(ppStart);

    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main


void addNode(Node** start, int addNum)
{
    /****************************
    *   Local Variables
    ****************************/
    bool collision = false;     // used to detect duplicate add
    bool complete = false;      // have we completed the insert already?
    Node* current = *start;     // ptr to our current node
    Node* temp;                 // the node we may create
   
    // check to see if we are adding at the beginning of the list
    if ((current->getNumber() >= addNum) && (current->getPrev() == NULL))
    {
        if (current->getNumber() > addNum)
        {
            // we are inserting at the start, so this will be our new start pointer.
            temp = new Node(addNum);    // create the next NEW Node
            temp->setNext(current);     // set the new nodes next to be the existing start pointer     
            current->setPrev(temp);     // set the existing start pointer's previous to be our new node
            *start = temp;              // set the start of the list to be the newly created node
            complete = true;            
        }
        else
        {
            // We have a collision with the first element
            complete = true;
            collision = true;
        }
    }
    
    if (complete == false)
    {
        // Handle insertion in middle of list
	    while((current->getNext()!=NULL) && current->getNumber()<addNum)
	    {
            // this gets us to the node after our insertion point or the end of the list
		    current = current->getNext(); 
        }
        if(current->getNext()==NULL)    // we got to the end of our list
        {
            if(current->getNumber()!=addNum)
            {
                // we are inserting at the end of the list.
                temp = new Node(addNum);    // create the next NEW Node
                temp->setPrev(current);     // set the new nodes next to be the current end of the list     
                current->setNext(temp);     // set the existing last node's next to be out new nodee
                complete = true;
            }
            else    // collision with last node
            {
                collision = true;
            }
        }   
        else
        {
            if(current->getNumber() != addNum)
            {
                // we are not at the end of the list and we don't have a collision
                temp = new Node(addNum);            // create the next NEW Node
                temp->setNext(current);             // set the new node's next to be the node point to by the current NEXT
                temp->setPrev(current->getPrev());  // set new node prev to current's previous
                temp->getPrev()->setNext(temp);     // set n-1 node's next to new node
                current->setPrev(temp);             // set current node's previous to new node
            }
            else // collision in middle of list
            {
                collision = true;
            }   
        }
    }


    if (collision == false)
    {
        cout << "added node to list" << endl;
        cout << "**************************" << endl;
        temp->display();
        cout << "**************************" << endl << endl;

        traverse(start);
    }
    else
    {
        cout << "in addnode, value " << addNum << " collided with node:" << endl;
        current->display(); 
        cout << "list is currently" << endl;
        traverse(start);
    }

}

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

void traverse(Node** start)
{
    //cout << "in traverse list" << endl;
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
    //cout << "\n Start address after Traverse call inside Linked List = " << start << "\n\n";
    *pps = start;
    //system ("pause");
}

/*********************************************
*   Testing Functions
*********************************************/
void testAddNode(Node** pps)
{
    cout << "in testAddNode" << endl;
    cout << "testing collision at start of list " << endl;
    addNode(pps,1);         // test collision at beginning of list
    
    cout << endl << endl << endl << endl; 
    cout << "testing add at beginning of list" << endl;
    addNode(pps,0);         // test adding a node to the beginning of the list
    
    cout << endl << endl << endl << endl; 
    cout << "testing add in the middle of the list" << endl;
    addNode(pps,4);         // test adding a node to the middle of the list
    
    cout << endl << endl << endl << endl; 
    cout << "testing collision in middle of list" << endl;
    addNode(pps,9);         // test collision in middle of listt
     
    cout << endl << endl << endl << endl; 
    cout << "testing collision at end of list" << endl;
    addNode(pps,13);         // test adding a node to the middle of the list
    

    cout << endl << endl << endl << endl; 
    cout << "testing add at end of list" << endl;
    addNode(pps,974);         // test adding a node to the middle of the list
    
}









 

