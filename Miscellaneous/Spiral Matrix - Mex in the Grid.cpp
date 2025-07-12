#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, zero = 0;
    cin >> n;
    int mat[n+1][n+1];
    int k = n*n - 1, i = 1, j = 1, turn = 0, right = n, left = 1, up = 2, down = n;
    while(k >= 0){
        mat[i][j] = k--;
        if(turn % 4 == 0){
            if(j == right){
                right--;
                turn++;
                i++; 
            }
            else{
                j++;
            }
        }
        else if(turn % 4 == 1){
            if(i == down){
                down--;
                turn++;
                j--;
            }
            else{
                i++;
            }
        }
        else if(turn % 4 == 2){
            if(j == left){
                left++;
                turn++;
                i--;
            }
            else{
                j--;
            }
        }
        else if(turn % 4 == 3){
            if(i == up){
                up++;
                turn++;
                j++;
            }
            else{
                i--;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
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
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/2101/A