#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map <string, int> mp;
map <int, string> mp2;
vector <string> v;
vector <int> on[10], off[10];

void pre(){
    mp["1110111"] = 0; mp2[0] = "1110111";
    mp["0000011"] = 1; mp2[1] = "0000011";
    mp["0111110"] = 2; mp2[2] = "0111110";
    mp["0011111"] = 3; mp2[3] = "0011111";
    mp["1001011"] = 4; mp2[4] = "1001011";
    mp["1011101"] = 5; mp2[5] = "1011101";
    mp["1111101"] = 6; mp2[6] = "1111101";
    mp["0010011"] = 7; mp2[7] = "0010011";
    mp["1111111"] = 8; mp2[8] = "1111111";
    mp["1011111"] = 9; mp2[9] = "1011111";
    for(int i = 0; i <= 9; i++) v.push_back(mp2[i]);
    for(int j = 0; j < 7; j++){
        for(int i = 0; i <= 9; i++){
            string t = mp2[i];
            if(t[j] == '0') off[j].push_back(i);
            else on[j].push_back(i);
        }
    }
}

void solve(){
    string s;
    cin >> s;
    set <int> st;
    for(int i = 0; i <= 9; i++) st.insert(i);
    for(int j = 0; j < 7; j++){
        if(s[j] == 'G'){
            for(auto x : off[j]){
                if(st.count(x) == 1) st.erase(x);
            }
        }
        else if(s[j] == 'g'){
            for(auto x : on[j]){
                if(st.count(x) == 1) st.erase(x);
            }
        }
    }
    if(st.size() > 1) cout << '*';
    else cout << *st.begin();
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cout << "\n";
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/gym/105789/problem/L