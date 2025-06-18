#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7, mod = 1e9 + 7;

ll subsum(vector <ll> v, ll s){
    if(v.size() == 0) return 0;
    ll n = v.size();
    vector <ll> pre(n+1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + v[i-1];
    map<ll,ll> mp;
    ll ans = 0;
    // pre[r] - pre[l-1] == s
    // pre[l-1] = pre[r] - s (count how many and add it)
    mp[0]++; // so that I can take single element with value s
    for(int i = 1; i <= n; i++){
        ans += mp[pre[i] - s];
        mp[pre[i]]++;
    }
    return ans;
}

ll submaxlessequ(vector <ll> v, ll s, ll x){
    ll n = v.size();
    vector <ll> temp;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > x){
            ans += subsum(temp, s);
            temp.clear();
        }
        else temp.push_back(v[i]);
    }
    ans += subsum(temp, s);
    return ans;
}

void solve(){
    ll n, s, x;
    cin >> n >> s >> x;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << submaxlessequ(v,s,x) - submaxlessequ(v,s,x-1) << "\n";
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
// https://codeforces.com/contest/2121/problem/F