#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll            long long
#define ull           unsigned long long
#define pb            push_back
#define rev(v)        reverse(v.begin(),v.end())
#define yes           cout << "YES" << "\n";
#define no            cout << "NO" << "\n";
#define endl          "\n"
#define srt(v)        sort(v.begin(), v.end())
#define csrt(v)       sort(v.begin(), v.end(), cmp)
#define rsrt(v)       sort(v.rbegin(), v.rend())
#define mem(v, val)   memset(v, val, sizeof(v))
#define mod           1000000000+7 // 10^9 + 7
#define inf           1e18
#define fast          ios::sync_with_stdio(false);cin.tie(nullptr)


template<class T> using special_set = tree<T, null_type, less<T>, rb_tree_tag,
 tree_order_statistics_node_update>;



struct Node {
    Node *arr[30];
};

Node *root = NULL;
int ans = 0;

void add (string s) {
    if (root == NULL) {
        root = new Node();
    }
    Node *curr = root;

    for (int i=0; i<s.size(); i++) {
        if (curr->arr[s[i] - 'a'] == NULL) {
            curr->arr[s[i] - 'a'] = new Node();
            ans++;
        }
        curr = curr->arr[s[i] - 'a'];
    }
}

void solve() {
    ll n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        reverse(s.begin(),s.end());
        add(s);
    }

    cout<<ans<<endl;
}

int main() {
    fast;
    int tc = 1;
    //cin >> tc;
    
    while(tc--) {
        solve();
    }
    

    return 0;
}