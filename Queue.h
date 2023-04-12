// Queue implemented as a linked list, making a node class necessary
class Node {
    public:
        int data;
        Node* next;
        
        Node()
        {
            data = 0;
            next = NULL;
        }
        
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

// Linked list will hold elements of the queue
class Linkedlist {
    Node* head;
    Node* tail;
    
    public:
        // functions included for queue functionality
        Linkedlist() { head, tail = NULL; }
        
        void push_back(int);
        
        void printList();
        
        int pop_front();
        
        bool empty();
        
        void front();
        
        int numElement();
};
