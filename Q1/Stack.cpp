#include <iostream>
#include "Stack.h"

using namespace std;

//Constructors
Stack::Stack(){
    int data = 0;
    unsigned int elementCount = 0;
}

// Destructor
Stack::~Stack(){

}

int Stack::getData() const{
    return head->data; 
}

unsigned int Stack::getElementCount() const{
    return elementCount;
}

bool Stack::isEmpty() const{
    //testing purpose
    //cout << "testing isEmpty()" << endl;

    if(head->next == NULL){
        return true;
    }
    else{
        return false;
    }
}

int Stack::peek() const{
    //testing purpose
    //cout << "Testing peek()" << endl;
    int top = head->data;
    return top;
}

bool Stack::pop(){
    //testing purpose
    //cout << "Testing pop()" << endl;

    if(head->next != NULL){
        head = head->next;
        elementCount--;
        if(elementCount == 0){
            head = NULL;
            head->next = NULL;
        }
        return true;
    }
    return false;
}

bool Stack::push(int newElement){
    //testing purpose
    //cout << "Testing push()" << endl;

   StackNode* newNode = new StackNode();

    if(elementCount == 0){
        newNode->data = newElement;
        newNode->next = NULL;
        head = newNode;
        elementCount++;
        return true;

    }

    else{
        newNode->data = newElement;
        newNode->next = head;
        head = newNode;
        elementCount++;
        return true;
    }
    return false;
}
