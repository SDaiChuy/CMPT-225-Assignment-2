/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Steven Dai Chuy
 * Date: October 5, 2022
 */
 
class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
                unsigned int elementCount;
                
        };

    StackNode* head; 
/* Put your code here! */       
        

    public:
    
/* Put your code here! */   

//constructors
Stack();

//Destructor
~Stack();


//getters
int getData() const;

unsigned int getElementCount() const;

//setters;
void setData(int data);

//methods

// check to see if the stack is empty, return NULL if empty
bool isEmpty() const;

// push an element onto the top of the stack
bool push(int element);

// returns the values of the top element
int peek() const;

// Removes the top element of the stack
bool pop();




};
