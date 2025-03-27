#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector <tuple<ll,ll,ll,ll>> v;
    multiset <ll> xx1, xx2, yy1, yy2;
    for(int i = 0; i < n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1,y1,x2,y2});
        xx1.insert(x1);
        xx2.insert(x2);
        yy1.insert(y1);
        yy2.insert(y2);
    }
    for(auto [x1,y1,x2,y2] : v){
        xx1.erase(xx1.find(x1));
        xx2.erase(xx2.find(x2));
        yy1.erase(yy1.find(y1));
        yy2.erase(yy2.find(y2));
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " : ";
        if(*xx1.rbegin() <= *xx2.begin() && *yy1.rbegin() <= *yy2.begin()){
            cout << *xx1.rbegin() << " " << *yy1.rbegin() << "\n";
            return;
        }
        xx1.insert(x1);
        xx2.insert(x2);
        yy1.insert(y1);
        yy2.insert(y2);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1028/problem/C