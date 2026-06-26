#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *arr[26];
    bool isEnd;
    int cnt;
    int maxi;
    string res;

    Node() {
        isEnd = false;
        cnt = 0;
        maxi = 0;
        res = "";

        for (int i=0; i<26; i++) {
            arr[i] = NULL;
        }
    }
};

Node *root = new Node();

void insertWord(string &s) {
    Node *curr = root;
    vector<Node*> path;

    for (char c : s) {
        int idx = c - 'a';

        if (curr->arr[idx] == NULL) {
            curr->arr[idx] = new Node();
        }
        curr = curr->arr[idx]; // next node
        path.push_back(curr);
    }
    curr->isEnd = true;
    curr->cnt++;

    for (Node *node : path) {
        if ((node->maxi < curr->cnt) || (node->maxi == curr->cnt && node->res > s)) {
            node->maxi = curr->cnt;
            node->res = s;
        }
    }
}

pair<string, int> startsWith(string &s) {
    Node *curr = root;
    
    for (char c : s) {
        int idx = c - 'a';
        
        if (curr->arr[idx] == NULL) {
            return {"", -1};
        }
        curr = curr->arr[idx];
    }
    if (curr->maxi == 0) {
        return {"", -1};
    }
    return {curr->res, curr->maxi};
}

void solve() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        insertWord(s);
    }
    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        auto [res, cnt] = startsWith(s);
        
        if (cnt == -1) {
            cout << -1 << endl;
        }
        else {
            cout << res << " " << cnt << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc = 1;
    //cin >> tc;
    
    while (tc--) {
        solve();
    }

    return 0;
}