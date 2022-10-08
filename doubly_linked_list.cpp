#include <iostream>
using namespace std;

class Node {
  public:
    Node *prev;
    int data;
    Node *next;
    Node() {
        this->prev = nullptr;
        this->data = 0;
        this->next = nullptr;
    }

    Node(int val) {
        this->prev = nullptr;
        this->data = val;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
  private:
    Node *head;

  public:
    void traverse() {
        Node *temp = this->head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

        temp = this->head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }

    void insertAtGivenPostion(int val, int position) {
        Node *temp = this->head;

        for (int i = 2; i < position; i++) {
            if (temp->next != nullptr) {
                temp = temp->next;
            }
        }

        Node *temp2 = temp;
        Node *newNode = new Node(val);
        temp2 = temp2->next;
        newNode->next = temp2;
        temp2->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }

        Node *temp = this->head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning() {
        Node *temp = this->head;
        temp = temp->next;
        temp->prev = nullptr;
        this->head = temp;
    }

    void deleteAtGivenPosition(int position) {
        Node *temp = this->head;
        for (int i = 2; i < position; i++) {
            temp = temp->next;
        }

        Node *temp2 = temp;

        temp->next = temp->next->next;
        temp = temp->next;

        temp->prev = temp2;
    }

    void deleteAtEnd() {
        Node *temp = this->head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node *temp2 = temp;
        temp->next = nullptr;
    }

    int search(int val) {
        Node *temp = this->head;
        int inc = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                return inc++;
            }
            temp = temp->next;
            inc++;
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {

    DoublyLinkedList l = DoublyLinkedList();

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertAtEnd(7);

    l.insertAtBeginning(0);

    l.insertAtGivenPostion(10, 6);

    cout << l.search(10) << endl;

    l.deleteAtBeginning();

    l.deleteAtEnd();

    l.deleteAtGivenPosition(5);

    l.traverse();

    cout << l.search(10) << endl;
    cout << l.search(1) << endl;
    cout << l.search(3) << endl;

    return 0;
}
