#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *arr[26];
    bool isEnd;

    Node() {
        isEnd = false;

        for (int i=0; i<26; i++) {
            arr[i] = NULL;
        }
    }
};

Node *root = new Node();

void insertWord(string &s) {
    Node *curr = root;

    for (char c : s) {
        int idx = c - 'a';

        if (curr->arr[idx] == NULL) {
            curr->arr[idx] = new Node();
        }
        curr = curr->arr[idx]; // next node
    }
    curr->isEnd = true; // mark end of word
}

bool searchWord(string &s) {
    Node *curr = root;

    for (char c : s) {
        int idx = c - 'a';

        if (curr->arr[idx] == NULL) {
            return false;
        }
        curr = curr->arr[idx];
    }
    return curr->isEnd; // word exists only if isEnd == true
}

bool startsWith(string &s) {
    Node *curr = root;
    
    for (char c : s) {
        int idx = c - 'a';
        
        if (curr->arr[idx] == NULL) {
            return false;
        }
        curr = curr->arr[idx];
    }
    return true; // if we can traverse full prefix
}

void solve() {
    int k;
    string str;
    cin >> k >> str;

    if (k == 1) {
        insertWord(str);
    } 
    else if (k == 2) {
        if (searchWord(str) == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    } 
    else if (k == 3) {
        if (startsWith(str) == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        solve();
    }

    return 0;
}

/*

Time Complexity : 

1. Insert : O(s)
2. Searching : O(s)
3. Check Prefix : O(s)

*/