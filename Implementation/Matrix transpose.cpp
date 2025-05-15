#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    bool swaped = false;
    if(m < n){
        swap(n, m);
        swaped = true;
    }
    vector <vector <int>> mat(n, vector<int>(m, 1));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < m; j++){
            mat[i][j] = mat[i][j-1] + 1;
        }
    }
    set <int> ans;
    for(int i = 0; i < n; i++){
        set <int> cur;
        for(int j = 0; j < m; j++){
            cur.insert(mat[i][j]);
        }
        ans.insert(cur.size());
    }
    for(int j = 0; j < m; j++){
        set <int> cur;
        for(int i = 0; i < n; i++){
            cur.insert(mat[i][j]);
        }
        ans.insert(cur.size());
    }
    cout << ans.size() << "\n";
    if(!swaped){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        
    } 
    else{
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }  
    }
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