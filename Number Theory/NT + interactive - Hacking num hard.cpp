#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll random(ll l, ll r) {
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return rng() % (r - l + 1) + l;
}

ll sod(ll n){
    ll sum = 0;
    while(n){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void test(){
    ll n = 100000, y = 999999999;
    set <ll> st;
    for(ll i = 1; i <= n; i++){
        ll x = random(int(1), int(1e9));
        // x = sod(x);
        st.insert(sod(x * y));
        // cout << x << " " << sod(x * y) << "\n";
    }
    for(auto x : st){
        cout << x << " ";
    }
    cout << "\n";
}

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
    ll n, f, y = 999999999;
    ll z = int(1e9) * y;
    // cout << (int) 1e9 - y << "\n";
    // cout << (ll) 1e18 - z << "\n";
    cin >> n;
    ask("mul", y); // multiplying by 999999999 always gives sod of 81
    cout << "digit\n";
    cout.flush();
    cin >> f;
    if(n == 81) print();
    else{
        ask("add", n - 81);
        print();
    }
}
    
int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    // test();
    while(t--){
        solve();
    }
    // cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2109/problem/C3