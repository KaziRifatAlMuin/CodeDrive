#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 3e5 + 7;

ll n, m;
vector <ll> mate[N];


bool isPossible(ll k){
    vector <ll> orders;
    for(int i = 0; i < m; i++){
        // cout << i << " ";
        if(mate[i].size() < k) return false;
        for(int j = mate[i].size() - 1, lim = k; lim > 0; lim--, j--){
            orders.push_back(mate[i][j]);
        }
    }
    // cout << "Here\n";
    sort(orders.begin(), orders.end());
    for(int i = 0; i < orders.size(); i++){
        // cout << i << " " << orders[i] << "\n";
        if(orders[i] < i) return false;
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    vector <ll> a(n), b(n);
    for(int i = 0; i < max(n,m); i++) mate[i].clear();
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++){
        mate[a[i] - 1].push_back(b[i]);
    }
    for(int i = 0; i < m; i++){
        sort(mate[i].begin(), mate[i].end());
    }

    // for(int i = 0; i < m; i++){
    //     for(auto x : mate[i]){
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
    ll low = 0, high = n, ans = 0;

    // cout << isPossible(0) << "\n";

    while(low <= high){
        // TTTTTTTFFFFFFF
        ll mid = low + (high - low) / 2;
        if(isPossible(mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        // cout << mid << " ";
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/gym/105167/problem/H