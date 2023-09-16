// range updates

#include <bits/stdc++.h>
using namespace std;

int sum (int i, int bit[], int n) {
    int ans = 0;

    for ( ; i > 0; i -= (i & (-i))) {
        ans += bit[i];
    }
    return ans;
}

void update (int i, int inc, int bit[], int n) {
    for ( ; i <= n; i += (i & (-i))) {
        bit[i] += inc;
    }
}

int main () {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        int bit[n+10] = {0};
        int u;
        cin >> u;

        while (u--) {
            int l, r, inc;
            cin >> l >> r >> inc;
            l++;
            r++;
            update (l, inc, bit, n);// A[L..] + inc
            update (r+1, -inc, bit, n);// A[R+1..] - inc
            //A[L...R] + inc
        }
        int q;
        cin >> q;

        while (q--) {
            int w;
            cin >> w;
            w++;
            cout << sum (w, bit, n) << endl;
        }
    }
}
