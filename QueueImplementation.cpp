#include <iostream>
#include "Queue.h"

using namespace std;

// Inserts a new element at the rear of the 
void Linkedlist::push_back(int data)   
{
    Node* newNode = new Node(data);
    
    // if the Queue is empty make the new node the head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    
    // transverse the Queue until the end
    while (temp->next != NULL) {
  
        // Update temp to iterate through list
        temp = temp->next;
    }
  
    // Insert after last node in the list
    temp->next = newNode;
}

// function to pop the front of the list
int Linkedlist::pop_front()
{
    Node *temp1 = head;
 
    // if the head is empty, notify the user
    if (head == NULL) {
        cout << "List empty." << endl;
    }
    int element;
    element = head->data;
    // set the head to the next node
    head = head->next;
    
    // delete the previous head node
    delete temp1;
    
    return element;
}

// Now cout the front of the list
void Linkedlist::front() {
    
    // Check if the list is empty
    if (head == NULL) {
        cout << "The Queue is empty, therefore it has no front element" << endl;
        return;
    }  
    // if list not empty cout the value at the front of the list
    cout << "The front of the Queue is: " << head->data << endl;
}

bool Linkedlist::empty()
{
    if (head == NULL) {
        cout << "This Queue is empty." << endl;
        return false;
    } else {
        cout <<"This Queue is not empty." << endl;
        return true;
    }
}

int Linkedlist::numElement()
{
    // initialize pointer variable and listlength
    Node *temp1 = head, *temp2 = tail;
    int ListLen = 0;

    // iterate throught the entire list or until value is found
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }
    cout << "The number of elements in the Queue is: " << ListLen << endl;
    return ListLen;
}

void Linkedlist::printList()
{
    Node* temp = head;
    
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
