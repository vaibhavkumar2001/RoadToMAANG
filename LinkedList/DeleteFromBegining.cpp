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

void printll(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void deleteFromBegining(Node* &head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}
