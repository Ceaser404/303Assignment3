#include <iostream>
#include "Queue.h"


using namespace std;

int main()
{
    Linkedlist list;
     
    // Inserting nodes
    list.push_back(4);
    list.push_back(9);
    list.push_back(2);
  
    cout << "Elements of the list are: ";
  
    // Print the list
    list.printList();
    cout << endl;
    
    list.front();    
    
    int front;
    
    front = list.pop_front();
    
    cout << "Removed value from front of Queue is: " << front << endl;
    
    cout << "Lastly, Elements of the list are: ";
    list.printList();
    cout << endl;

  
    int num;
    num = list.numElement();
    cout << num << endl;
    /*
    // Delete node at position 2.
    list.deleteNode(2);
    
    list.back();
    
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    
    cout << "Elements of the list are: ";
    list.pop_front();
    list.printList();
    cout << endl;
    
    cout << "Elements of the list are: ";
    list.pop_back();
    list.printList();
    cout << endl;
    
    cout << "Elements of the list are: ";
    list.pop_back();
    list.printList();
    cout << endl;
    
    cout << "Elements of the list are: ";
    list.push_back(3);
    list.printList();
    cout << endl;
    
    
    list.pop_back();
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    
    list.back();
    
    
    list.pop_back();
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    
    list.empty();
    
    list.back();
    */
    
    return 0;
}