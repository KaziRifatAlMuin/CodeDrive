#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    if(n & 1){
        int i, j, cur = 0, k = 1;
        i = n/2, j = n/2;
        mat[i][j] = 0;
        cur++;
        k += 2;
        int mini = i - 1, maxi = i + 1, next = k * k;
        j++;
        int l = i - 1, r = j + 1;
        while(cur < n*n){
            // cout << i << " " << j << "\n";
            mat[i][j] = cur++;
            if(cur == next){
                k += 2;
                next = k * k;
                i = l, j = r;
                l = i - 1, r = j + 1;
                mini--, maxi++;
                continue;
            }
            if(i == mini){
                if(j == maxi) i--;
                else j++;
            }
            else if(i == maxi){
                if(j == mini) i--;
                else j--;
            }
            else if(j == mini){
                i--;
            }
            else if(j == maxi){
                i++;
            }
        }
    }
    else{
        int i, j, cur = 0, k = 2;
        i = n/2 - 1, j = n/2 - 1;
        mat[i][j] = 0; mat[i][j+1] = 1; 
        mat[i+1][j+1] = 2; mat[i+1][j] = 3;
        cur = 4;
        k += 2;
        int mini = i - 1, maxi = i + 2, next = k * k;
        j += 2;
        int l = i - 1, r = j + 1;
        while(cur < n*n){
            // cout << i << " " << j << "\n";
            mat[i][j] = cur++;
            if(cur == next){
                k += 2;
                next = k * k;
                i = l, j = r;
                l = i - 1, r = j + 1;
                mini--, maxi++;
                continue;
            }
            if(i == mini){
                if(j == maxi) i--;
                else j++;
            }
            else if(i == maxi){
                if(j == mini) i--;
                else j--;
            }
            else if(j == mini){
                i--;
            }
            else if(j == maxi){
                i++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2102/problem/C