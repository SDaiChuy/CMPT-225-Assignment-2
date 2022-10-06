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
    return head->elementCount;
}

bool Stack::isEmpty() const{
    cout << "testing isEmpty()" << endl;

    if(head == NULL){
        return false;
    }
    else{
        return true;
    }
}

int Stack::peek() const{
    cout << "testing peek()" << endl;
    int top = getData();
    return top;
}

bool Stack::pop(){
    cout << "Testing pop()" << endl;

    if(head != NULL){
        int ret = head->data;
        head = head->next;
        head->elementCount--;
        if(head->elementCount == 0){
            head = NULL;
            head->next = NULL;
        }
        return true;
    }
    return false;
}

bool Stack::push(int newElement){
    cout << "Testing push()" << endl;
    //StackNode* newNode;

   StackNode* newNode = new StackNode();

    if(head->elementCount == 0){
        newNode->data = newElement;
        newNode->next = NULL;
        head = newNode;
        return true;

    }
    else{
        newNode->data = newElement;
        newNode->next = head;
        head = newNode;
        return true;
    }
    return false;
}
