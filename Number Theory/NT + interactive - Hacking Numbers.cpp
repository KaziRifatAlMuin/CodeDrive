#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ask(string s, ll y){
    cout << s << " " << y << "\n";
    cout.flush();
    ll x; cin >> x;
    return x;
}

void print(){
    cout << "!\n";
    cout.flush();
    ll x; cin >> x;
}

void solve(){
    ll n, f;
    cin >> n;
    ask("mul", 9); 
    // if n is divisible by 9, sum of digits also divisible by 9 
    cout << "digit\n";
    cout.flush();
    cin >> f;
    cout << "digit\n";
    cout.flush();
    cin >> f;
    ask("add", n - 9); // doing sum of digits twice, x = 9
    print();
}
    
int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2109/problem/C2