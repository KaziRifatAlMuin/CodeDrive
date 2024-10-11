#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

bool NimGame(vector <ll> v){
    ll nimsum = 0;
    for(auto x : v) nimsum ^= x;
    return nimsum != 0; // Alice win, If last pick win
}

void solve()
{
    int n, m;
    vector <ll> v;
    cin >> n >> m;
    ll a[n][m];
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            sum += a[i][j];
        }
        v.push_back(sum);
    }
    if(NimGame(v)) cout << "Alice\n";
    else cout << "Bob\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1, st = clock();
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://lightoj.com/problem/matrix-game