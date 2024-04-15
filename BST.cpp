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
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL;  // Tree is empty
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
        if (root == NULL) {
            return NULL;  // Tree is empty
        }
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

Node* findSuccessor(Node* root, int key) {
    Node* current = root;
    Node* successor = NULL;

    while (current != NULL) {
        if (current->data > key) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return successor;
}

Node* findPredecessor(Node* root, int key) {
    Node* current = root;
    Node* predecessor = NULL;

    while (current != NULL) {
        if (current->data < key) {
            predecessor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return predecessor;
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

    cout << "In order "; // In order traverse
    inorder(root);
    cout << endl;

    cout << "Pre order : ";  // Pre order traverse
    preorder(root);
    cout << endl;

    cout << "Post order : "; // Post order traverse
    postorder(root);
    cout << endl;

    
    int key;
    cout << "Enter the value to search: "; // Searching any value
    cin >> key;

    Node* result = search(root, key);
    if (result != NULL) {
        cout << "Value found in the tree" << endl;
    }
    else {
        cout << "Value not found in the tree" << endl;
    }

    
    Node* minNode = findMin(root); // Finding Minimum value
    if (minNode != NULL) {
        cout << "Minimum value in the tree: " << minNode->data << endl;
    }
    else {
        cout << "Tree is empty" << endl;
    }

    
    Node* maxNode = findMax(root); // Finding Maximum value
    if (maxNode != NULL) {
        cout << "Maximum value in the tree: " << maxNode->data << endl;
    }
    else {
        cout << "Tree is empty" << endl;
    }

    
    int key_value;
    cout << "Enter the value to find its successor: "; // Finding successor
    cin >> key_value;

    Node* successorNode = findSuccessor(root, key_value);
    if (successorNode != NULL) {
        cout << "Successor of " << key_value << " is " << successorNode->data << endl;
    }
    else {
        cout << "No successor found for " << key_value << endl;
    }
    

    int keyToFindPredecessor;
    cout << "Enter the value to find its predecessor: "; // Finding predecessor
    cin >> keyToFindPredecessor;

    Node* predecessorNode = findPredecessor(root, keyToFindPredecessor);
    if (predecessorNode != NULL) {
        cout << "Predecessor of " << keyToFindPredecessor << " is " << predecessorNode->data << endl;
    }
    else {
        cout << "No predecessor found for " << keyToFindPredecessor << endl;
    }


    return 0;
}
