#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

void create (Node *r, Node *new1) {
    if (new1->data < r->data) {
        if (r->left == NULL) {
            r->left = new1;
        }
        else {
            create(r->left, new1);
        }
    }
    else if (new1->data > r->data) {
        if (r->right == NULL) {
            r->right = new1;
        }
        else {
            create(r->right, new1);
        }
    }
    else {
        cout << "Duplicate" << endl;
    }
}
void inorder (struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder (struct Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder (struct Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int main () {
    cout << "Enter the size of nodes : ";
    int number;
    cin >> number;

    while (number--) {
        int n;
        cin >> n;

        Node *new1 = new Node();
        new1->left = NULL;
        new1->right = NULL;
        new1->data = n;


        if (root == NULL) {
            root = new1;
        }
        else {
            create(root, new1);
        }
    }

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}
