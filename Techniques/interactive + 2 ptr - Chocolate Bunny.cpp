#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(int i, int j){
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve(){
    ll n;
    cin >> n;
    vector <int> ans(n+1);
    ll p, sum = 0;
    for(int i = 1, j = n; i <= j;){
        if(i == j){
            p = i;
            break;
        }
        int imodj = ask(i, j);
        int jmodi = ask(j, i);
        if(imodj > jmodi){
            ans[i] = imodj;
            i++; sum += imodj;
        }
        else{
            ans[j] = jmodi;
            j--; sum += jmodi;
        }
    }
    ans[p] = n * (n + 1) / 2 - sum;
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    cout.flush();
}
    
int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1407/C