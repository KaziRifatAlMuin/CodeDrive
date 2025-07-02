#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int spf[N+2];

void pre(){
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; 1ll * i * i < N; i++) {
        if(spf[i] == i){ // i is prime
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector <int> p(n+1);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 2; i <= n; i++){
        if(i * 2 <= n) swap(p[i], p[i*2]);
        else if(p[i] == i) swap(p[i], p[spf[i]]);
    }
    for(int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
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
// https://codeforces.com/contest/2123/problem/F