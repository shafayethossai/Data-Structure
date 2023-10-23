#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *ladd;
    struct Node *radd;
};

Node *start = NULL;

void push(int n) {
    if (start == NULL) {
        Node *new1 = new Node();

        new1->ladd = NULL;
        new1->data = n;
        new1->radd = NULL;

        start = new1;
        return;
    }
    else {
        Node *temp = new Node();
        temp = start;

        while (temp->radd != NULL) {
            temp = temp->radd;
        }

        Node *new1 = new Node();

        new1->ladd = NULL;
        new1->data = n;
        new1->radd = NULL;

        temp->radd = new1;
        new1->ladd = temp;
        temp = temp->radd;
    }
}

void display_forward () {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *temp = new Node();
        temp = start;

        cout << "List forwardly : ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->radd;
        }
        cout << endl;
    }
}

void display_reverse () {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *temp = new Node();
        temp = start;

        while (temp->radd != NULL) {
            temp = temp->radd;
        }
        cout << "List reversely : ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->ladd;
        }
        cout << endl;
    }
}

void insert_first (int n) {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *new1 = new Node();

        new1->ladd = NULL;
        new1->data = n;
        new1->radd = NULL;

        new1->radd = start;
        start->ladd = new1;

        start = new1;
    }
}

void insert_last (int n) {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *new1 = new Node();

        new1->ladd = NULL;
        new1->data = n;
        new1->radd = NULL;

        Node *temp = new Node();
        temp = start;

        while (temp->radd != NULL) {
            temp = temp->radd;
        }
        temp->radd = new1;
        new1->ladd = temp;
    }
}

void insert_middle (int pos, int n) {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *new1 = new Node();

        new1->ladd = NULL;
        new1->data = n;
        new1->radd = NULL;

        Node *next = new Node();
        Node *prev = new Node();
        next = start;

        int i = 0;

        while (i < pos) {
            prev = next;
            next = next->radd;
            i++;
        }
        prev->radd = new1;
        new1->ladd = prev;
        new1->radd = next;
        next->ladd = new1;
    }
}

void delete_first () {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *temp = new Node();
        temp = start;
        start = start->radd;
        delete(temp);
    }
}

void delete_last () {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *temp = new Node();
        Node *prev = new Node();
        temp = start;

        while (temp->radd != NULL) {
            prev = temp;
            temp = temp->radd;
        }
        prev->radd = NULL;
        delete(temp);
    }
}

void delete_middle (int value) {
    if (start == NULL) {
        cout << "List not found" << endl;
    }
    else {
        Node *temp = new Node();
        Node *next = new Node();
        Node *prev = new Node();

        temp = start;
        next = start;
        int i = 0;

        while (temp->data != value) {
            prev = temp;
            temp = temp->radd;
        }
        next = temp->radd;
        prev->radd = next;
        next->ladd = prev;
        delete(temp);
    }
}

int main () {
    push(10);
    push(20);
    push(30);
    push(50);

    insert_first(5);
    insert_last(100);
    insert_middle(4, 40);

    display_forward();
    display_reverse();
    cout << endl;

    cout << "delete At first : ";
    delete_first();
    display_forward();
    cout << endl;

    cout << "delete At middle : ";
    delete_middle(50);
    display_forward();
    cout << endl;

    cout << "delete At last : ";
    delete_last();
    display_forward();
    cout << endl;

    return 0;
}
