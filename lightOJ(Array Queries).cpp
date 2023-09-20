// segment tree
#include <bits/stdc++.h>
using namespace std;
int arr[500001];
int tree[500001];
int cnt = 1;

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

    tree[node] = min(tree[left] , tree[right]);
}

int query (int node, int b, int e, int i, int j) {
    if (j < b || i > e) {
        return INT_MAX;
    }

    if (i <= b && j >= e) {
        return tree[node];
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = (2 * node) + 1;

    int l = query(left, b, mid, i, j);
    int r = query(right, mid+1, e, i, j);

    return min(l, r);
}

int main () {

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        init(1, 1, n);

//        for (int i = 1; i < n*2; i++) {
//            cout << "node: " << i << " value: " << tree[i] << endl;
//        }
        vector <int> ans;

        while (m--) {
            int i, j;
            cin >> i >> j;
            int s = query(1, 1, n, i, j);
            ans.push_back(s);
        }
        printf("Case %d:\n", cnt);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
        cnt++;
    }

    return 0;
}
