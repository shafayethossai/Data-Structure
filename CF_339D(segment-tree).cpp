#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e6 + 100;

ll n, q, arr[500001], B[N];
int tree[400001];

void init(ll node, ll b, ll e, ll x) {
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = (node * 2) + 1;

    init(left, b, mid, x + 1);
    init(right, mid + 1, e, x + 1);

    if (B[x] != 0){
        tree[node] = tree[left] ^ tree[right];
    }
    else {
        tree[node] = tree[left] | tree[right];
    }
}

void update(int node, int b, int e, int i, int j, int value, int x) {
    if (j < b || i > e) {
        return;
    }

    if (i <= b && j >= e) {
        tree[node] = value;
        return;
    }

    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = (node * 2) + 1;

    update(left, b, mid, i, i, value, x + 1);
    update(right, mid+1, e, i, i, value, x + 1);

    if(B[x] != 0) {
        tree[node] = tree[left] ^ tree[right];
    }
    else {
        tree[node] = tree[left] | tree[right];
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    for(ll i = n - 1; i >= 1; i--) {
        if(B[ i + 1 ] == 0)
            B[ i ] = 1;
        else
            B[ i ] = 0;
    }
    //memset(B, 0, sizeof(B));

    ll w = (1 << n);

    for(ll i = 1; i <= w; i++) {
        cin >> arr[ i ];
    }

    init(1, 1, w, 1);

    while(m--) {
        ll pos, val;

        cin >> pos >> val;

        update(1, 1, w, pos, pos, val, 1);

        cout << tree[ 1 ] << endl ;

    }

    return 0;
}
