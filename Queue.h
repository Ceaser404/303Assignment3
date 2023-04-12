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

class Linkedlist {
    Node* head;
    Node* tail;
    
    public:
        
        Linkedlist() { head, tail = NULL; }
        
        void push_back(int);
        
        void printList();
        
        int pop_front();
        
        bool empty();
        
        void front();
        
        int numElement();
};