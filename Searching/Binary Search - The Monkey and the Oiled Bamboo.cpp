#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

vector <ll> v(N);
ll n;

bool isPossible(ll k){
    int prev = 0;
    for(int i = 0; i < n; i++){
        if(v[i] - prev == k) k--;
        else if(v[i] - prev > k) return false;
        prev = v[i];
    }
    return true;
}

void solve()
{
    ll low = 1, high = 1e15, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    while(low <= high){
        // FFFFFFFFTTTTTTTTT
        ll mid = low + (high - low) / 2;
        if(isPossible(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        // cout << mid << " ";
    }
    cout << ans << "\n";
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
// https://lightoj.com/problem/the-monkey-and-the-oiled-bamb