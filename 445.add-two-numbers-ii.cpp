// 82. Remove Duplicates from Sorted List II
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

    public:
        ListNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtTail(ListNode* &tail, int data){
    ListNode* temp = new ListNode(data);
    tail->next = temp;
    tail = tail->next;
}

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head) {
    
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL) {
        ListNode* forward = curr->next;

        // reverse
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    stack<ListNode*> s1; 
    stack<ListNode*> s2;

    ListNode* temp1 = l1;
    ListNode* temp2 = l2;

    while(temp1 != NULL) {
        s1.push(temp1);
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        s2.push(temp2);
        temp2 = temp2->next;
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    int carry = 0;

    temp1 = l1;
    temp2 = l2;

    while(!s1.empty() && !s2.empty()) {

        ListNode* e1 = s1.top();
        s1.pop();
        ListNode* e2 = s2.top();
        s2.pop();

        cout << e1->data << endl;
        // int sum = e1->data + e2->data + carry;

        // if(sum >= 10) {
        //     carry = 1;
        //     sum = sum % 10;
        // }

        // ListNode* newNode = new ListNode(sum);

        // dummy->next = newNode;

        // dummy = dummy->next;
    }

    // delete dummy
    ListNode* d = temp;
    temp = temp->next;
    delete d;

    ListNode* x = reverseList(temp);

    return x;
}

int main(){
    
    ListNode* node = new ListNode(7);
    
    ListNode* head = node;
    ListNode* tail = node;

    insertAtTail(tail, 2);
    insertAtTail(tail, 4);
    insertAtTail(tail, 3);

    print(head);

    ListNode* node2 = new ListNode(5);
    
    ListNode* head1 = node2;
    ListNode* tail1 = node2;

    insertAtTail(tail1, 6);
    insertAtTail(tail1, 4);

    print(head1);

    ListNode* temp = addTwoNumbers(head, head1);

    // print(temp);

    return 0;
}