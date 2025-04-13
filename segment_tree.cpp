#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tree;

void init(int node, int b, int e) {
    if (b == e) {
        tree[node] = arr[b];
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j) {
    if (j < b || i > e) return 0;
    if (i <= b && e <= j) return tree[node];

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    int l = query(left, b, mid, i, j);
    int r = query(right, mid + 1, e, i, j);

    return l + r;
}

void update(int node, int b, int e, int index, int value) {
    if (index < b || index > e) return;

    if (b == e) {
        tree[node] = value;
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    update(left, b, mid, index, value);
    update(right, mid + 1, e, index, value);

    tree[node] = tree[left] + tree[right];
}

int main() {
    int n, q;
    cin >> n >> q;

    arr.resize(n + 1);
    tree.resize(4 * n);

    for (int i = 1; i <= n; i++) { // 3 2 4 5 1 1 5 3
        cin >> arr[i];
    }

    init(1, 1, n);

    while (q--) {
        string type;
        cin >> type;
        if (type == "sum") {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        } 
        else if (type == "update") {
            int index, value;
            cin >> index >> value;
            arr[index] = value;
            update(1, 1, n, index, value);
        }
    }

    return 0;
}
