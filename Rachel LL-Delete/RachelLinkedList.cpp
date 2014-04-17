/**************************************************
* 
*      program name:       DeleteNode
*      Author:             Rachel Chapman
*      date due:            
*      remarks:            LinkedList C code 
*                          Add delete node function    
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>                // needed for I/O
#include <cstdlib>
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
		
		int* number;		//value of the node
		Node* prev;			//points to previous node
		Node* next;			//points to next node
	
	public:
		//constructor
		Node();
		Node(int);
		
		//destructor
		~Node();
		
		//setters
		void setPrev(Node* pp)	{prev = pp;}
		void setNext(Node* np)	{next = np;}
		void setNumber(int n)	{*number = n;}
	
		//getters
		Node* getPrev()	{return next;}
		Node* getNext()	{return next;}
		int getNumber()	{return *number;}
		
		void display();
};
/****************************************
*         member functions
****************************************/
//constructor
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
	//cout << "\n in deconstructor \n";
	delete prev;
	delete next;
	delete number;
}
void Node :: display()
{
	cout << "\n";
	cout << "node number   " << getNumber() << "\n";
	cout << "previous node " << getPrev() 	<< "\n";
	cout << "next node     " << getNext() 	<< "\n";
	cout << "current node  " << this	    << "\n";
	cout << "\n";
}

/****************************************
*          function prototypes
****************************************/
void loadLinkedList(Node**);
void traverse(Node** start);
void addNode(Node** start, int addNum);
void delNode(Node** start, int delNum);

/************************************************
void delNode(Node** start, int delNum)
{
	Node* current;
	current = *start;
	while((delNum != current->getNumber() && current->getNext()!=NULL))
	{
		current = current->getNext();
	}
	//current->display();
}
*************************************************************/

/////////////////////////////////////////////////////
//                                                 //
// FUNCTION: delNode                               //
//                                                 //
/////////////////////////////////////////////////////
void delNode(Node** start, int delNum)
{
    // LOCAL VARIABLES
    Node* current = *start;                                     /// Hold address of the first object in the list
    
    // FIND NODE TO DELETE                                      /// Test for end of list or a value higher than del
    while (current->getNext() != NULL && current->getNumber() < delNum)
    {
        current = current->getNext();                           /// Progress to next object
    }
    
    //DELETE NODE
    if (current->getNumber() == delNum)
    {
        // ONLY NODE
        if (current->getPrev() == NULL && current->getNext() == NULL)
        {
        	*start = NULL;
        	cout << "Deleted only node in list" << endl;
        }
        
        // FIRST NODE
        else if (current->getPrev() == NULL)
        {
            *start = current->getNext();
            current->getNext()->setPrev(NULL);
        }
        
        // LAST NODE
        else if (current->getNext() == NULL)
        {
           current->getPrevious->setNext(NULL);
        }
        
        // MIDDLE NODE
        else
        {
           current->getPrev()->setNext(current->getNext());
           current->getNext()->setPrev(curren->getPrev());
        }
        cout << "Deleted " << current->getNumber() << ".\n";    /// Display deleted number
        Node xx(0);
    }
    
    // PRINT ERROR IF NO MATCHING NODE
    else
    {
        cout << "No match for " << delNum << ".\n";
    }
}


void addNode(Node** start, int addNum)
{
	Node* current;
	current = *start;
	
	while(current->getNext()!= NULL || current->getNumber() >= addNum)
	{
		current = current-> getNext();
	}
		current -> display();
		
	if (current-> getNumber() == addNum)
	{
		cout << "duplicate add";
	}
	else if(current-> getPrev() == NULL)
	{
		cout << "add before start";
	}
	else if(current-> getNext() == NULL)
	{
		cout << "add after start";
	}
	else if(current-> getNumber() > addNum)
	{
		cout << "regular add";
	}
	else
	{
		cout << "add after end";
	}
}
void traverse(Node** start)
{
	Node* current = *start;
	//current->display();
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
    savePtr->display();
    //system("pause");  
        
    temp = new Node(3);         // create the next NEW Node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT Node using saved pointer
    savePtr = temp;             // save address of CURRENT Node in savePtr to use with next Node
    savePtr->display();
    //system("pause");
        
    temp = new Node(5);         // create the next NEW Node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT Node using saved pointer
    savePtr = temp;             // save address of CURRENT Node in savePtr to use with next Node
    savePtr->display();
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


/////////////////////////////////////////////////////
//                                                 //
// FUNCTION: testDelNode                           //
//                                                 //
/////////////////////////////////////////////////////
void testDelNode(Node** start)
{
	Node** ppStart = start;
    // TEST VALUES
    delNode(start, 0);                                          /// Test value that isn't in the list	cout << "\n\n";                                       
    cout << "***********************************\n";
    cout << "*   node 0 not there - beginning  *\n";
    cout << "***********************************\n";
    traverse(ppStart);    
    
	delNode(start, 4);                                          /// Test value that isn't in the list	cout << "\n\n";                                       
    cout << "***********************************\n";
    cout << "*   node 4 not there - middle     *\n";
    cout << "***********************************\n";
    traverse(ppStart);       
    
    delNode(start, 44);                                          /// Test value that isn't in the list	cout << "\n\n";                                       
    cout << "***********************************\n";
    cout << "*   node 44 not there - end       *\n";
    cout << "***********************************\n";
    traverse(ppStart);    	
	
	delNode(start, 5);   										/// Test value in the middle of the list
	cout << "\n\n";                                       
    cout << "***********************************\n";
    cout << "*   node 5 should be deleted      *\n";
    cout << "*        middle of list           *\n";
    cout << "***********************************\n";
    traverse(ppStart);
    
    delNode(start, 1);                                          /// Test beginning value
    cout << "\n\n";                                       
    cout << "***********************************\n";
    cout << "*   node 1 should be deleted      *\n";
    cout << "*        start of list            *\n";    
    cout << "***********************************\n";
    traverse(ppStart);
    
    delNode(start, 13);                                         /// Test last value
    cout << "\n\n";                                       
    cout << "***********************************\n";
    cout << "*   node 13 should be deleted      *\n";
    cout << "*      last node in list           *\n";    
    cout << "***********************************\n";
    traverse(ppStart);
 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                   //
// FUNCTION: main                                                                                    //
//                                                                                                   //
///////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    // LOCAL VARIABLES
    Node* start;                                                /// Start of linked list
    Node** ppStart = &start;                                    /// Pointer to address of start
    
    // BUILD LINKED LIST
    loadLinkedList(ppStart);
    cout << "***********************************\n";
    cout << "*          initial list           *\n";
    cout << "***********************************\n";
    traverse(ppStart);
    // TEST DELETE NODE
    testDelNode(ppStart);
    
    ///system("PAUSE");                                         /// Pause Program (Dev++)
    return 0;
}                                                               /// End Main




     
     
     
    











 

