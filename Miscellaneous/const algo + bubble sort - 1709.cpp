#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector <pair<int,int>> ans;
    int mid = min((n+1)/2 + 1, n);
    for(int k = 1; k <= mid; k++){
        int ar, p;
        for(int i = 0; i < n; i++){
            if(a[i] == k){
                ar = 1;
                p = i;
                break;
            }
            if(b[i] == k){
                ar = 2;
                p = i;
                break;
            }
        }
        int need = k - 1;
        if(ar == 1){
            for(int i = p; i > need && i > 0; i--){
                swap(a[i], a[i-1]);
                ans.push_back({1, i});
            }
        }
        else{
            if(p > need){
                for(int i = p; i > need && i > 0; i--){
                    swap(b[i], b[i-1]);
                    ans.push_back({2, i});
                }
                swap(a[need], b[need]);
                ans.push_back({3, need+1});
            }
            else{
                for(int i = p; i < need && i < n-1; i++){
                    swap(b[i], b[i+1]);
                    ans.push_back({2, i+1});
                }
                swap(a[need], b[need]);
                ans.push_back({3, need+1});
            }
        }
    }
    // for(auto x : a) cout << x << " ";
    // cout << "\n";
    // for(auto x : b) cout << x << " ";
    // cout << "\n\n";
    int need = n;
    for(int k = 2*n; k >= (2*n - mid + 1); k--){
        int ar, p;
        need--;
        for(int i = 0; i < n; i++){
            if(a[i] == k){
                ar = 1;
                p = i;
                break;
            }
            if(b[i] == k){
                ar = 2;
                p = i;
                break;
            }
        }
        if(ar == 2){
            for(int i = p; i < need && i < n-1; i++){
                swap(b[i], b[i+1]);
                ans.push_back({2, i+1});
                // cout << 2 << " " << i << "\n";
            }
        }
        else{
            if(p > need){
                for(int i = p; i > need && i > 0; i--){
                    swap(a[i], a[i-1]);
                    ans.push_back({1, i});
                }
                swap(a[need], b[need]);
                ans.push_back({3, need+1});
            }
            else{
                for(int i = p; i < need && i < n-1; i++){
                    swap(a[i], a[i+1]);
                    ans.push_back({1, i+1});
                }
                swap(a[need], b[need]);
                ans.push_back({3, need+1});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                ans.push_back({1, j+1});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(b[j] > b[j+1]){
                swap(b[j], b[j+1]);
                ans.push_back({2, j+1});
            }
        }
    }
    // for(auto x : a) cout << x << " ";
    // cout << "\n";
    // for(auto x : b) cout << x << " ";
    // cout << "\n";
    cout << ans.size() << "\n";
    for(auto [t, i] : ans){
        cout << t << " " << i << "\n";
    }
    // for(int i = 80; i > 0; i--) cout << i << " ";
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
// https://codeforces.com/contest/2121/problem/D