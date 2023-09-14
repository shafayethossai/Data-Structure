#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *root = NULL;

void push(int value) {
    if(root == NULL) { //If the list is empty
        Node *newNode = new Node(); //create new node in root
        newNode->data = value;
        newNode->next = NULL;

        root = newNode;
        return;
    }

    Node *current = root; //make a copy of root node

    while(current->next != NULL) { //Find the last node
        current = current->next; //go to next address
    }

    // here the last node is current
    Node *newNode = new Node(); //create a new node
    newNode->data = value;
    newNode->next = NULL;

    current->next = newNode;  //link the last node with new node
}

void insert(int value, int newValue) { // 11, 12
    Node *current = root;

    while(current->data != value) {
        current = current->next;
    }

    // current node's value is 11
    Node *nextNode = current->next;

    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = nextNode;

    current->next = newNode;
}

void deleteNode(int value) {
    Node *current = root;
    Node *prevNode = NULL;

    while(current->data != value) {
        prevNode = current;
        current = current->next;
    }

    Node *nextNode = current->next;
    prevNode->next = nextNode;
}

void print() {
    Node *current = root;

    while(current->next != NULL) {
        cout<<current->data<<endl;
        current = current->next;
    }

    cout<<current->data<<endl;
}

int main() {
    push(5);
    push(11);
    push(2);
    push(7);
    push(9);

    insert(11, 12);

    deleteNode(7);

    print();
    return 0;
}
