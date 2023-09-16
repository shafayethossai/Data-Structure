// point updates O(logn)

#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> bit;

void update (int idx, int val) {
    for ( ; idx <= n; idx += (idx & -idx)) {
        bit[idx] += val;
    }
}

int sum (int idx) {
    int ans = 0;
    for ( ; idx > 0; idx-= (idx & -idx)) {
        ans += bit[idx];
    }
    return ans;
}

int main () {
    cin >> n;
    bit = vector <int> (n+1);
    vector <int> arr(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    int q;
    cin >> q;

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int l, r;
            cin >> l >> r;
            int ans = sum (r) - sum (l-1);
            cout << ans << endl;
        }
        else if (c == 2) {
            int index, val;
            cin >> index >> val;
            update(index, -arr[index]);
            arr[index] = val;
            update (index, val);
        }
    }

    return 0;
}
