#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    vector <pair<int,int>> premin(n+2, {inf, 0}), sufmax(n+2, {0,n+1});
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++){
        if(a[i] < premin[i].first){
            premin[i+1] = {a[i], i};
        }
        else premin[i+1] = premin[i];
    }
    for(int i = n; i > 0; i--){
        if(a[i-1] > sufmax[i+1].first){
            sufmax[i] = {a[i-1], i-1};
        }
        else sufmax[i] = sufmax[i+1];
    } 
    ll ans = 0, low = 0, high = n;
    while(low <= high){ // TTTTTFFFFF
        ll mid = low + (high - low) / 2;
        ll mini = premin[mid].first;
        ll maxi = sufmax[mid+1].first;
        vector <int> v = a;
        if(maxi > mini){
            swap(v[premin[mid].second], v[sufmax[mid+1].second]);
        }
        ll point = 0;
        for(int i = 0, j = 0, k = 0; k < n; k++){
            if(v[i] > b[j]){
                point++;
                i++;
            }
            else{
                j++;
            }
        }
        if(point >= mid) ans = point, low = mid + 1;
        else high = mid - 1;
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/2113/problem/D