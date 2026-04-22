#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *root = NULL;
Node *tail = NULL;

void push(int value) {
    Node *newNode = new Node(); // create new node in root
    newNode->data = value;
    newNode->next = NULL;

    if(root == NULL) { // If the list is empty
        root = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
}

void insert(int value, int newValue) {
    Node *current = root;
    Node *prevNode = NULL;

    while(current != NULL && current->data != value) {
        prevNode = current;
        current = current->next;
    }

    if(current == NULL) { // value not found
        cout << "Value not found in the list." << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = current;

    if(prevNode == NULL) { // inserting at the beginning
        root = newNode;
    }
    else {
        prevNode->next = newNode;
    }
}

void deleteNode(int value) {
    Node *current = root;
    Node *prevNode = NULL;

    while(current != NULL && current->data != value) {
        prevNode = current;
        current = current->next;
    }

    if(current == NULL) { // value not found
        cout << "Value not found in the list." << endl;
        return;
    }

    if(prevNode == NULL) { // deleting the root node
        root = current->next;
    }
    else {
        tail = prevNode;
        prevNode->next = current->next;
    }

    delete current;
}

void print() {
    Node *current = root;

    while(current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}

int main() {
    push(5);
    push(11);
    push(2);
//    push(7);
//    push(9);

    cout << "Original list:" << endl;
    print();
    cout << endl;

    insert(5, 1); // insert at first
    insert(11, 8); // insert at middle
    insert(2, 5); // insert at last

    cout << "List after insertions:" << endl;
    print();
    cout << endl;

    deleteNode(1); // delete first element
    deleteNode(8); // delete middle element
    deleteNode(2); // delete last element

    cout << "List after deletions:" << endl;
    print();
    cout << endl;

    push(10);
    cout << "Original list:" << endl;
    print();
    cout << endl;


    return 0;
}
