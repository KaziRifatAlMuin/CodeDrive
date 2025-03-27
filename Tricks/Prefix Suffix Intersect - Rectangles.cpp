#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <int> x1(n+1), y1(n+1), x2(n+1), y2(n+1);
    vector <int> Xpremin(n+2, inf), Xsufmin(n+2, inf), Ypremin(n+2, inf), Ysufmin(n+2, inf);
    vector <int> Xpremax(n+2, -inf), Xsufmax(n+2, -inf), Ypremax(n+2, -inf), Ysufmax(n+2, -inf);
    // To check intersection, I need max of left(x1,y1) and minimum of right(x2,y2)
    for(int i = 1; i <= n; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        Xpremax[i] = max(Xpremax[i-1], x1[i]);
        Ypremax[i] = max(Ypremax[i-1], y1[i]);
        Xpremin[i] = min(Xpremin[i-1], x2[i]);
        Ypremin[i] = min(Ypremin[i-1], y2[i]);
    }
    for(int i = n; i >= 1; i--){
        Xsufmax[i] = max(Xsufmax[i+1], x1[i]);
        Ysufmax[i] = max(Ysufmax[i+1], y1[i]);
        Xsufmin[i] = min(Xsufmin[i+1], x2[i]);
        Ysufmin[i] = min(Ysufmin[i+1], y2[i]);
    }
    for(int i = 1; i <= n; i++){
        int X1 = max(Xpremax[i-1], Xsufmax[i+1]);
        int X2 = min(Xpremin[i-1], Xsufmin[i+1]);
        int Y1 = max(Ypremax[i-1], Ysufmax[i+1]);
        int Y2 = min(Ypremin[i-1], Ysufmin[i+1]);
        if(X1 <= X2  && Y1 <= Y2){
            cout << X1 << " " << Y1 << "\n";
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1028/problem/C