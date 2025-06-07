#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll sum = 0, got = 0;
    queue <string> q;
    set <string> visited;
    visited.insert(s);
    q.push(s); // BFS node generating + traversal
    got++; sum += n;
    while(!q.empty() && got < k){
        string t = q.front(); q.pop();
        if(t.size() == 1) continue;
        for(ll i = 0; i < t.size(); i++){
            string next = t;
            next.erase(i, 1);
            if(visited.count(next) == 0){
                q.push(next);
                visited.insert(next);
                got++;
                sum += next.size();
            }
            if(got == k) break;
        }
    }
    if(got < k) got++; // empty subsequence
    if((got == k)) cout << n*k - sum << "\n";
    else cout << -1 << "\n";
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
// https://codeforces.com/contest/1183/problem/E