#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e6 + 7;

vector <ll> primes, pre(N);

void seive()
{
    vector<bool> isPrime(N + 10, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; (ll) i * i <= N; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for(int i = 2; i <= N; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    int i = 1;
    for(auto x : primes){
        pre[i++] = pre[i-1] + x;
    }
    // cout << primes.size() << " ";
}

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n), coin(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++){
        coin[i+1] = coin[i] + (v[i] - 2);
    }
    ll low = 1, high = n, stay = 0;
    while(low <= high){
        // TTTTTTFFFFFF
        ll mid = low + (high - low) / 2;
        ll need = pre[mid] - 2 * mid;
        if(need <= coin[mid]) stay = mid, low = mid + 1;
        else high = mid - 1;
    }
    cout << n - stay << "\n";
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
// https://codeforces.com/contest/2104/problem/D