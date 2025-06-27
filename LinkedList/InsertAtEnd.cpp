#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void PrintLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void InsertAtEnd(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtEnd(head,tail,10);
    InsertAtEnd(head,tail,20);
    InsertAtEnd(head,tail,30);
    InsertAtEnd(head,tail,40);
    PrintLL(head);
}