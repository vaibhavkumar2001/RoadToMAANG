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

void InsertAtBegining(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtBegining(head,tail,10);
    InsertAtBegining(head,tail,20);
    InsertAtBegining(head,tail,30);
    PrintLL(head);
}