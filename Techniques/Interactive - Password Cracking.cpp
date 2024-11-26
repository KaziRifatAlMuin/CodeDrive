#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ok = 0;

int ask(string s){
    cout << "? " << s << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

void solve() {
    cin >> n;
    string s;
    while(s.size() < n){
        if(ask(s + '0') == 1){
            s += '0';
            continue;
        }
        if(ask(s + '1') == 1){
            s += '1';
            continue;
        }
        break;
    }
    while(s.size() < n){
        if(ask('0' + s) == 1){
            s = '0' + s;
            continue;
        }
        else {
            s = '1' + s;
            continue;
        }
        break;
    }
    cout << "! " << s << "\n";
    fflush(stdout);
}

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2013/problem/C