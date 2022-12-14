/* 
 * Queue.h - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author:
 * Date:
 */
 
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue {

/* You cannot remove/modify the data members below, but you can add to them. */
	
    private:
        static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        int* elements;                 // To do: replace this by int * elements -> Question 4.a)

        unsigned int elementCount = 0;                  // Number of elements in the Queue - if you need it!
        unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex = 0;                    // Index of front element (next dequeued/peeked element)
        unsigned int backindex = 0;                     // Index of where the next element will be enqueued     

        //Check to see if the queue is empty
        bool isFull() const;

        //Sets the capacity to the new capacity
        void setCapacity(unsigned int newCapacity);

        //Sets the back index to the new back index
        void setBack(unsigned int newBack);

        //Sets the front index to the new front index
        void setFront(unsigned int newFront);   
        
        //Returns the capacity of the queue
        int getCapacity() const;    

        //Returns the front index of the queue
        int getFront() const;   

        //Returns the back index of the queue
        int getBack() const;

        int* resize(int* elements);


        

        /* You can add private methods. */

        //Description: check to see if the element count has reached the capacity
        // if so the resize the array by creating a new array of size 2 times the inital sie
        // and adding the elements into the new array. Delete the old array at the end
        int* resize(int* elements);

        //get the capacity to the new capacity
        void setCapacity(unsigned int newCapacity);

        //set front to the new front
        void setFront(unsigned int newFront);

        //set the back to the new back
        void setback(unsigned int newBack);

    public:
 
/* You cannot remove/modify the public methods below. This also applies to their documentation. */

        // Description: Constructor
        Queue();

<<<<<<< HEAD
        //Description: Destructor
=======
        // Description: Destructor
>>>>>>> refs/remotes/origin/main
        ~Queue();

        // Description: Inserts element x at the back of Queue
        // Time Efficiency: O(1)
        void enqueue(int x);

        // Description: Removes the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        void dequeue();

        // Description: Returns a copy of the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        int peek() const;

        // Description: Returns true if and only if Queue empty
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
};
#endif


