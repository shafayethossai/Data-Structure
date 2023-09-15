#include <bits/stdc++.h>
using namespace std;

int arr[10] = {0, 5, 2, 7, 4, 3, 9, 8, 11, 2};
int tree[30];

void init (int node, int b, int e) {
    if (b == e) {
        tree[node] = arr[b];
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = (node * 2) + 1;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int sum (int node, int b, int e, int i, int j) {
    if (j < b || i > e) {
        return 0;
    }

    if (i <= b && j >= e) {
        return tree[node];
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = (2 * node) + 1;

    int l = sum(left, b, mid, i, j);
    int r = sum(right, mid+1, e, i, j);

    return l + r;
}

void update (int node, int b, int e, int i, int j, int value) {
    if (j < b || i > e) {
        return;
    }

    if (i <= b && j >= e) {
        tree[node] = value;
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = (node * 2) + 1;

    update (left, b, mid, i, j, value);
    update (right, mid+1, e, i, j, value);

    tree[node] = tree[left] + tree[right];
}

int main() {
    init (1, 1, 9);

    for (int i = 0; i < 30; i++) {
        cout << "node: " << i << " value: " << tree[i] << endl;
    }

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int i, j;
            cin >> i >> j;

            cout << sum (1, 1, 9, i, j) << endl;
        } else {
            int i, value;
            cin >> i >> value;
            update (1, 1, 9, i, i, value);
        }
    }

    return 0;
}
