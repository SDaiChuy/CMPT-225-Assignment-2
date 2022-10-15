/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author:
 * Date:
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {

}

Queue::~Queue() {

}

// Description: Inserts element x at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int x) {
    /*
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;    
    return;
    */

    if(isFull()){
        resize(elements);
        if(elements == NULL){
            exit(1);
        }
    }
    else{
        for(int i = backindex; i < frontindex; i++ ){
            elements[i + 1] = elements[i];
        }
        elements[backindex] = x;   
        elementCount++;     
    }
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}
 

bool Queue::isFull() const{
    if(frontindex == 0 && backindex == INITIAL_CAPACITY - 1){
        return true;
    }
    else if(frontindex == 0 && backindex == INITIAL_CAPACITY + 1){
        return true;
    }
    else{
        return false;
    }
}        



int* Queue::resize(int* elements){
    if(elementCount > INITIAL_CAPACITY){
        int* temparray = new int(2*INITIAL_CAPACITY);
        for(int i = 0; i < INITIAL_CAPACITY; i++ ){
            temparray[i] = elements[i];
        }
        delete[] elements;
        elements = temparray;
        INITIAL_CAPACITY = setCapacity(INITIAL_CAPACITY*2);
    }
    return elements;
}

void Queue::setCapacity(unsigned int newCapacity){
    elements->capacity = newCapacity;
}

void Queue::setBack(unsigned int newBack){
    elements->backindex = newBack;
}

void Queue::setFront(unsigned int newFront){
    elements->frontindex = newFront;
}

int Queue::getCapacity() const{
    return elements->INITIAL_CAPACITY;
}

int Queue::getFront() const{
    return elements->frontindex;
}

int Queue::getBack() const{
    return elements->backindex;
}
