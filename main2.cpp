#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Linkedlist queue;
     
    // Inserting nodes
    queue.push_back(4);
    queue.push_back(9);
    queue.push_back(2);
  
    cout << "Elements of the list are: ";
  
    // Print the list
    queue.printList();
    cout << endl;
    
    // front member function outputs the front element of the queue
    queue.front();    
    
    int poppedFront;
    
    // pop_front removes the front element of the queue and returns it
    poppedFront = queue.pop_front();
    
    // output to user what pop_front does and display removed element
    cout << "Removed value from front of Queue is: " << poppedFront << endl;
    
    cout << "Elements of the list are: ";
    queue.printList();
    cout << endl;

    // numElement returns the number of elements in the queus
    queue.numElement();
   
    
    return 0;
}
