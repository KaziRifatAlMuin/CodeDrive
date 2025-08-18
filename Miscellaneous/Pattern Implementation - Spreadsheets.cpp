#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    bool ischar = 0;
    int cnt = 0;
    string a, b;
    char ara[26];
    for(int i = 0; i < 27; i++){
        ara[i] = 'A' + i - 1;
    }
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        if(ischar == 0 && s[i] >= 'A' && s[i] <= 'Z'){
            ischar = 1;
            cnt++;
        }
        else if(s[i] >= '0' && s[i] <= '9') {
            ischar = 0;
            if(cnt == 1) a += s[i];
            if(cnt == 2) b += s[i];
        }
    }
    if(cnt > 1){
        // RxCy -> colrow
        ll r = stoll(a);
        ll c = stoll(b);
        string col;
        while(c > 0){
            int d = c % 26;
            if(d == 0) d = 26, c -= 26;
            c /= 26;
            col += ('A' + d - 1);
        }
        reverse(col.begin(), col.end());
        cout << col << r << "\n";
    }
    else{
        ll r = 0, c = 0;
        string col, row;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                col += s[i];
            }
            else row += s[i];
        }
        r = stoll(row);
        ll k = 1;
        // cout << col << " ";
        if(col.size() > 0) reverse(col.begin(), col.end());
        for(int i = 0; i < col.size(); i++){
            ll d = (col[i] - 'A' + 1);
            c += (d * k);
            k *= 26;
            // cout << c << "\n";
        }
        cout << 'R' << r << 'C' << c << "\n";
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1/problem/B