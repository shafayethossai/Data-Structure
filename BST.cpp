#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *ladd;
    Node *radd;
};

Node *root = NULL;


void create (Node *r , Node *new1) {
    if (new1->data < r->data) {
        if (r->ladd == NULL) {
            r->ladd = new1;
        }
        else {
            create(r->ladd, new1);
        }
    }
    if (new1->data > r->data) {
        if (r->radd == NULL) {
            r->radd = new1;
        }
        else {
            create(r->radd, new1);
        }
    }
    if (new1->data == r->data) {
        cout << "Duplicate element not allower" << endl;
    }
}

void inorder (Node *r){
    if (r != NULL) {
        inorder(r->ladd);
        cout << r->data << " ";
        inorder(r->radd);
    }
}

void preorder (Node *r){
    if (r != NULL) {
        cout << r->data << " ";
        preorder(r->ladd);
        preorder(r->radd);
    }
}

void postorder (Node *r){
    if (r != NULL) {
        postorder(r->ladd);
        postorder(r->radd);
        cout << r->data << " ";
    }
}

signed main () {
    int ch;
    char choice;
    do {
        cout << endl << "1. create" << endl;
        cout << "2. inorder" << endl;
        cout << "3. preorder" << endl;
        cout << "4. postorder" << endl;
        cout << "5. exit" << endl;
        cout << "enter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1 :
                do {
                    cout << endl;
                    int n;
                    cout << "enter an element : ";
                    cin >> n;

                    Node *new1 = new Node();
                    new1->ladd = new1->radd=NULL;
                    new1->data = n;

                    if (root == NULL) {
                        root = new1;
                    }
                    else {
                        create (root, new1);
                    }
                    cout << "Want to continue : " ;
                    cin >> choice;
                }while(choice == 'y' || choice == 'Y');break;

            case 2 :
                cout << endl;
                inorder(root);
                cout << endl;
                break;

            case 3 :
                cout << endl;
                preorder(root);
                cout << endl;
                break;

            case 4 :
                cout << endl;
                postorder(root);
                cout << endl;
                break;

        }
    }while(ch != 5);


    return 0;
}
