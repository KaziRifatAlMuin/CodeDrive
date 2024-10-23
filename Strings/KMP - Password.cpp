#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> build_lps(string p) {
    vector<int> lps(p.size());
    int j = 0;
    for(int i = 1; i < p.size(); ) {
        if(p[i] == p[j]){
            lps[i] = j + 1;
            ++i, j++;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else lps[i] = 0, ++i;
        }
    }
    return lps;
}

void solve()
{
    string s;
    cin >> s;
    vector <int> lps = build_lps(s);
    int n = s.size();
    int last = lps[n-1];
    vector <bool> midfix(n, false);
    for(int i = 1; i < n - 1; i++){
        midfix[lps[i]] = true;
    }
    while(last > 0){
        if(midfix[last]){
            cout << s.substr(0, last);
            return;
        }
        last = lps[last - 1];
    }
    cout << "Just a legend\n";
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
// https://codeforces.com/problemset/problem/126/B