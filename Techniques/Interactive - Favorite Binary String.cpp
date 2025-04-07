#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(int l, int r){
    cout << "? " << l << " " << r << "\n";
    fflush(stdout);
    int ret;
    cin >> ret;
    return ret;
}

void solve() {
    int n;
    cin >> n;
    int total = ask(1, n);
    string ans;
    if(total == 0){
        cout << "! IMPOSSIBLE\n";
        fflush(stdout);
    }
    else{
        int found = 0, prev = 0;
        for(int i = 2; i <= n; i++){
            int res = ask(1, i);
            if(res > 0 && found == 0){
                int zero = res;
                int one =  i - zero - 1;
                while(one--) ans += '1';
                while(zero--) ans += '0';
                ans += '1';
                found = true;
            }
            else if(res > 0) {
                if(prev == res) ans += '0';
                else ans += '1';
            }
            prev = res;
        }
        cout << "! " << ans << "\n";
        fflush(stdout);;
    }
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
// https://codeforces.com/contest/2037/problem/E