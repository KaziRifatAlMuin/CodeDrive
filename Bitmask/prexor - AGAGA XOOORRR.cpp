#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <ll> v(n), prexor(n+1);
    for(int i = 0; i < n; i++) cin >> v[i], prexor[i+1] = prexor[i] ^ v[i];
    for(int i = 1; i < n; i++){
        if(prexor[i] == (prexor[n] ^ prexor[i])){
            cout << "YES\n";
            return;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((prexor[i] == (prexor[j] ^ prexor[i])) && ((prexor[j] ^ prexor[i]) == (prexor[n] ^ prexor[j]))){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
// https://codeforces.com/problemset/problem/1516/B