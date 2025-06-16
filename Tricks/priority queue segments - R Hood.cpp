#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7, inf = 1e9 + 7;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector <pair<int,int>> v;
    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    int next = 0;

    priority_queue<int> pq;
    int maxi = 0, mini = 1e9, max_ix = 1, min_ix = 1;

    for(int i = 1; i+d-1 <= n; i++){
        while(v[next].first <= i+d-1 && next < k){
            pq.push(-v[next].second);
            next++;
        }
        while(!pq.empty() && abs(pq.top()) < i) pq.pop();
        ll cur = pq.size();
        // cout << i << " -> " << cur << "\n";
        if(cur > maxi) maxi = cur, max_ix = i;
        if(cur < mini) mini = cur, min_ix = i;
    }
    cout << max_ix << " " << min_ix << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2014/problem/D