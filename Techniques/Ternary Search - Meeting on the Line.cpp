#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps 1e-7

void solve(){
    ll n;
    cin >> n;
    vector <double> x(n), t(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    double left = 0, right = 1e8;
    // unimodal function: exactly one minima or maxima
    while(fabs(right - left) > eps){
        double m1 = left + (right - left) / 3;
        double m2 = right - (right - left) / 3;
        double f1 = 0, f2 = 0;
        for(int i = 0; i < n; i++){
            f1 = max(f1, t[i] + fabs(x[i] - m1));
            f2 = max(f2, t[i] + fabs(x[i] - m2));
        } // ........min........
        if(f1 > f2) left = m1;
        else if(f1 < f2) right = m2;
        else left = m1, right = m2;
    }
    cout << fixed << setprecision(10) << left << "\n";
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
// https://codeforces.com/problemset/problem/1730/B