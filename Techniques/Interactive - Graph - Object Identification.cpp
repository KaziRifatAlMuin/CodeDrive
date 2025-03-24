#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ask(ll a, ll b){
    cout << "? " << a << " " << b << "\n";
    fflush(stdout);
    ll c; cin >> c;
    return c;
}

void solve() {
    ll n;
    cin >> n;
    ll p = -1;
    vector <ll> x(n+1), have(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
        have[x[i]] = 1;
    }
    for(ll i = 1; i <= n; i++){
        if(!have[i]){
            p = i;
            break;
        }
    }
    ll d1, d2;
    bool A = false;
    if(p != -1){
        if(p == 1) d1 = ask(p, p+1), d2 = ask(p+1, p);
        else d1 = ask(p, p-1), d2 = ask(p-1, p);
        if(d1 == 0 || d2 == 0) A = true;
        else A = false;
    }
    else{
        ll a, b;
        for(ll i = 0; i < n; i++){
            if(x[i] == 1) a = i+1;
            if(x[i] == n) b = i+1;
        }
        d1 = ask(a,b), d2 = ask(b,a);
        if(d1 != d2) A = true;
        else if(d1 == d2 && d1 >= n-1) A = false;
        else A = true;
    }
    if(A){
        cout << "! A\n";
        fflush(stdout);
    }
    else{
        cout << "! B\n";
        fflush(stdout);
    }
}

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2067/problem/D