#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e6 + 7;

vector <ll> mem[10000];
ll row[N];

void pre(){
    ll r = 1, cur = 1;
    for(ll i = 1; i < N; i++){
        mem[cur].push_back(i);
        row[i] = cur;
        if(i == r){
            r += (cur + 1);
            cur++;
        }
    }
}

ll getsum(ll n){
    return (n * (n+1) * (2*n + 1) / 6);
}

void solve() {
    ll n;
    cin >> n;
    ll rr = row[n];
    ll sum = n * n;
    ll l = n, r = n;
    for(ll i = rr - 1, j = 1; i > 0; i--, j++){
        l = l - i - 1;
        r = r - i;
        if(l < mem[i][0]) l = mem[i][0];
        if(r > mem[i][mem[i].size() - 1]) r = mem[i][mem[i].size() - 1];
        sum += (getsum(r) - getsum(l-1));
    }
    cout << sum << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1829/G