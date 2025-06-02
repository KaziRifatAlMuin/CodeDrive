#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7;

vector <int> need;

void seive()
{
    vector<bool> isPrime(N+10, true), isPower(N+10, false);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; (ll) i * i < N; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
    vector <int> primes;
    for(int i = 2; i < N; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    for(auto x : primes){
        ll c = x;
        while(c < N){
            isPower[c] = true;
            c = 1ll * c * x;
        }
    }
    need.push_back(1);
    for(int i = 2; i < N; i++){
        if(isPrime[i] || isPower[i]){
            need.push_back(i);
        }
    }
}

void solve(){
    int n; cin >> n;
    vector <int> v(n);
    set <int> st;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        st.insert(v[i]);
    }
    for(auto x : need){
        if(st.count(x) == 0){
            cout << x << "\n";
            return;
        }
    }
}  

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    seive();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/contest/720970#problem/K