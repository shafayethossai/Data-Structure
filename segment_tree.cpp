#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> arr;
vector<ll> tree;

void init(ll node, ll b, ll e) {
    if (b == e) {
        tree[node] = arr[b];
        return;
    }

    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = node * 2 + 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int query(ll node, ll b, ll e, ll i, ll j) {
    if (j < b || i > e) return 0;
    if (i <= b && e <= j) return tree[node];

    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = node * 2 + 1;

    ll l = query(left, b, mid, i, j);
    ll r = query(right, mid + 1, e, i, j);

    return l + r;
}

void update(ll node, ll b, ll e, ll index, ll value) {
    if (index < b || index > e) return;

    if (b == e) {
        tree[node] = value;
        return;
    }

    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = node * 2 + 1;

    update(left, b, mid, index, value);
    update(right, mid + 1, e, index, value);

    tree[node] = tree[left] + tree[right];
}

int main() {
    ll n, q;
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
            ll l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        } 
        else if (type == "update") {
            ll index, value;
            cin >> index >> value;
            arr[index] = value;
            update(1, 1, n, index, value);
        }
    }

    return 0;
}
