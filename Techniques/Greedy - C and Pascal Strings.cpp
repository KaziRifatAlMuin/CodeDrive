#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    getline(cin, s);
    map <char, int> mp;
    mp['0'] = 0;
    mp['1'] = 1;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['a'] = 10;
    mp['b'] = 11;
    mp['c'] = 12;
    mp['d'] = 13;
    mp['e'] = 14;
    mp['f'] = 15;
    vector <int> v;
    int n = s.size();
    int L = mp['2'] * 16 + mp['0'];
    int R = mp['7'] * 16 + mp['f'];
    // cout << L << " " << R << "\n";
    for(int i = 0; i < n; i += 3){
        int a = mp[s[i]] * 16 + mp[s[i+1]];
        v.push_back(a);
    }
    n = v.size();
    bool C = false, pascal = false;
    for(int i = 0; i < n; i++){
        if(v[i] < L || v[i] > R){
            if(v[i] == 0) C = true;
            break;
        }
    }
    int len = v[0];
    if(len < n){
        bool ok = true;
        for(int i = 1; i <= len; i++){
            if(v[i] < L || v[i] > R) ok = false;
        }
        pascal = ok;
    }
    if(C == true && pascal == true) cout << "Both\n";
    else if(C == true && pascal == false) cout << "C\n";
    else if(C == false && pascal == true) cout << "Pascal\n";
    else cout << "None\n";
}

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/gym/104842/problem/C