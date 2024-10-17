#include <bits/stdc++.h>
using namespace std;

// policy based data structure *************************************************************

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using specia_set = tree<T, null_type, less<T>,rb_tree_tag,
 tree_order_statistics_node_update>;

 // ****************************************************************************************

// Using this special data structure pbds we can use all the operation of set.
// also, we can scope any index or index's value in set and we can find how many value in set is strictly less than k.



int main () {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int q;
    cin >> q;
    specia_set<int> st;

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int k;
            cin >> k;
            st.insert(k);
        }
        else if (c == 2) {
            int k;
            cin >> k;
            cout << *st.find_by_order(k) << endl; // find the value in kth index in pbds set
        }
        else {
            int k;
            cin >> k;
            cout << st.order_of_key(k) << endl; // find how many value in set is less than k
        }
    }

    return 0;
}
