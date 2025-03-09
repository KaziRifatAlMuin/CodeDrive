#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), ans;
    bool ok = false; // divisible by 8 if last 3 digit divisible by 8
    for(int i = 0; i < n; i++){
        int a = s[i] - '0';
        if(a % 8 == 0) ok = true, ans = a;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int a = s[i] - '0', b = s[j] - '0';
            int num = a * 10 + b;
            if(num % 8 == 0) ok = true, ans = num;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int a = s[i] - '0', b = s[j] - '0', c = s[k] - '0';
                int num = a * 100 + b * 10 + c; 
                if(num % 8 == 0) ok = true, ans = num;
            }
        }
    }
    if(ok) cout << "YES\n" << ans << "\n";
    else cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}