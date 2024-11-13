#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <pair<int,int>> ans;

void TOH(int n, int start, int end){
    int mid = 6 - start - end;
    if(n > 1) TOH(n - 1, start, mid);
    ans.push_back({start, end});
    if(n > 1) TOH(n - 1, mid, end);
    if(n == 1) return;
}

void solve() {
    int n;
    cin >> n;
    TOH(n, 1, 3);
    cout << ans.size() << "\n";
    for(auto [x,y] : ans){
        cout << x << " " << y << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/CSES-2165