#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map <string, set<int>> mp;
    for(int i = 1; i <= q; i++){
        char x, y;
        cin >> x >> y;
        string s; s += x; s += y;
        mp[s].insert(i);
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'b'){
            if(mp["ba"].size() > 0){
                s[i] = 'a';
                mp["ba"].erase(mp["ba"].begin());
            }
            else if(mp["bc"].size() > 0 && mp["ca"].size() > 0){
                int bc = *mp["bc"].begin();
                auto it = mp["ca"].upper_bound(bc);
                if(it != mp["ca"].end()){
                    s[i] = 'a';
                    mp["bc"].erase(mp["bc"].begin());
                    mp["ca"].erase(it);
                }
            }
        }
        else if(s[i] == 'c'){
            if(mp["ca"].size() > 0){
                s[i] = 'a';
                mp["ca"].erase(mp["ca"].begin());
            }
            else if(mp["cb"].size() > 0 && mp["ba"].size() > 0){
                int cb = *mp["cb"].begin();
                auto it = mp["ba"].upper_bound(cb);
                if(it != mp["ba"].end()){
                    s[i] = 'a';
                    mp["cb"].erase(mp["cb"].begin());
                    mp["ba"].erase(it);
                }
                else{
                    s[i] = 'b';
                    mp["cb"].erase(mp["cb"].begin());
                }
            }
            else if(mp["cb"].size() > 0){
                s[i] = 'b';
                mp["cb"].erase(mp["cb"].begin());
            }
        }
    }
    cout << s << "\n";
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
// https://codeforces.com/contest/2111/problem/E