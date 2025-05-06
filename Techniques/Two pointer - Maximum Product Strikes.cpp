#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ansL = 0, ansR = n, cur = 0, maxi = 0, neg = 0, curL = 0, curR = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 0 || i == n - 1){
            if(v[i] != 0){
                if(abs(v[i]) == 2) cur++;
                if(v[i] < 0) neg++;
            }
            else curR--;
            ll cur1 = 0, cur2 = 0, l1 = curL, r2 = curR;
            // cout << curL << " " << curR << " > \n";
            if(neg & 1){
                for(int j = curL; j <= curR; j++){
                    l1 = j + 1;
                    if(abs(v[j]) == 2) cur1++;
                    if(v[j] < 0) break;
                }
                for(int j = curR; j >= curL; j--){
                    r2 = j - 1;
                    if(abs(v[j]) == 2) cur2++;
                    if(v[j] < 0) break;
                }
                // cout << l1 << " " << r2 << " > \n";
                if(cur1 < cur2){
                    curL = l1;
                    cur -= cur1;
                }
                else{
                    curR = r2;
                    cur -= cur2;
                }
            }
            // cout << cur1 << " - " << cur2 << " - " << cur << " ? ";
            if(cur >= maxi){
                maxi = cur;
                ansL = curL;
                ansR = curR;
            }
            cur = 0, neg = 0, curL = i + 1, curR = i + 1;
        }
        else{
            if(abs(v[i]) == 2) cur++;
            curR++;
            if(v[i] < 0) neg++;
        }
        // cout << cur << " " << maxi << " : " << ansL << " " << ansR << "\n";
    }
    cout << ansL << " " << n - ansR - 1 << "\n";   
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
// https://codeforces.com/problemset/problem/1660/D