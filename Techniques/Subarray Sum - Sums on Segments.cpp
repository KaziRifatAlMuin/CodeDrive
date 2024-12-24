#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    set <ll> ans;
    int other = -1;
    ll maxpos = 0, maxneg = 0, curpos = 0, curneg = 0, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] != 1 && v[i] != -1) other = i;
    }
    
    if(other == -1){
        sum = 0;
        for(ll i = 0; i < n; i++){
            sum = max(v[i], sum + v[i]);
            maxpos = max(maxpos, sum);
        }
        sum = 0;
        for(ll i = 0; i < n; i++){
            sum = min(v[i], sum + v[i]);
            maxneg = min(maxneg, sum);
        }
    }
    for(ll i = maxneg; i <= maxpos; i++){
        ans.insert(i);
    }
    if(other != -1){
        ll presum = 0, premin = 0, premax = 0, sufsum = 0, sufmin = 0, sufmax = 0;
        for(int i = other + 1; i < n; i++){
            sufsum += v[i];
            sufmin = min(sufmin, sufsum);
            sufmax = max(sufmax, sufsum);
        }

        for(int i = other - 1; i >= 0; i--){
            presum += v[i];
            premin = min(premin, presum);
            premax = max(premax, presum);
        }
        // cout << premax << " " << premin << " " << sufmax << " " << sufmin << "\n";
        for(ll i = v[other] + premin + sufmin; i <= v[other] + premax + sufmax; i++){
            ans.insert(i);
        }
        sum = 0;
        for(ll i = other + 1; i < n; i++){
            sum = max(v[i], sum + v[i]);
            maxpos = max(maxpos, sum);
        }
        sum = 0;
        for(ll i = other + 1; i < n; i++){
            sum = min(v[i], sum + v[i]);
            maxneg = min(maxneg, sum);
        }
        sum = 0;
        for(ll i = other - 1; i >= 0; i--){
            sum = max(v[i], sum + v[i]);
            maxpos = max(maxpos, sum);
        }
        sum = 0;
        for(ll i = other - 1; i >= 0; i--){
            sum = min(v[i], sum + v[i]);
            maxneg = min(maxneg, sum);
        }
        for(ll i = maxneg; i <= maxpos; i++){
            ans.insert(i);
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// https://codeforces.com/contest/2043/problem/C