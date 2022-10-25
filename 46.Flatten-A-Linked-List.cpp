#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* bottom;

    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->bottom = NULL;
        }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        Node* bottom = temp;
        
        while(bottom != NULL){
            cout << bottom->data << " ";
            bottom = bottom->bottom;
        }
        cout << endl;
        temp = temp->next;
    }
}

void printx(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtBottom(Node* &head, int data, Node* &tailOfBottom){
    Node* temp = new Node(data);
    tailOfBottom->bottom = temp;
    tailOfBottom = tailOfBottom->bottom;
}


Node* merge(Node* head1, Node* head2){

    Node* dummy = new Node(-1);
    Node* res = dummy;

    while(head1 != NULL && head2 != NULL){

        if(head1->data <= head2->data){
            dummy->bottom = head1;
            head1 = head1->bottom;
            dummy = dummy->bottom;
            dummy->next=NULL;
        }
        else{
            dummy->bottom = head2;
            head2 = head2->bottom;
            dummy = dummy->bottom;
            dummy->next=NULL;
        }
    }

    if(head1 != NULL){
        dummy->bottom = head1;
    }

    if(head2 != NULL){
        dummy->bottom = head2;
    }

    return res->bottom;
}

Node* flattenLinkedList(Node* head) {

    if(head == NULL || head->next == NULL)
        return head;

    head->next = flattenLinkedList(head->next);

    return merge(head, head->next);
}

int main(){
    
    // LL-1 
    Node* node1 = new Node(1);
    Node* head = node1;
    
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* tailOfBottom1 = node1;

    // LL
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 7);

    // Bottom 1
    insertAtBottom(head1, 2, tailOfBottom1);
    insertAtBottom(head1, 3, tailOfBottom1);

    // Bottom 2
    Node* head2 = head1->next;
    Node* tailOfBottom2 = head2;
    insertAtBottom(head2, 5, tailOfBottom2);
    insertAtBottom(head2, 6, tailOfBottom2);

    print(head);

    Node* realHead = flattenLinkedList(head);

    printx(head);

    // cout << realHead->child->data << endl;

    return 0;
}