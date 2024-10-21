#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int backtrack(int cnt, int pos, int target, int unknown){
    if(cnt == unknown) return pos == target;
    return backtrack(cnt + 1, pos + 1, target, unknown) + backtrack(cnt + 1, pos - 1, target, unknown);
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int target = 0, cur = 0, unknown = 0;
    for(auto x : s1){
        x == '+' ? target++ : target--;
    }
    for(auto x : s2){
        if(x == '+') cur++;
        else if(x == '-') cur--;
        else unknown++;
    }
    if(unknown == 0){
        cout << (target == cur ? 1.0 : 0.0) << "\n";
        return;
    }
    int a = backtrack(0, cur, target, unknown), b = 1 << unknown;
    cout << fixed << setprecision(10) << (double) a / b << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/476/B