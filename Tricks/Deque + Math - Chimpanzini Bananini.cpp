#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    int q;
    cin >> q;
    ll n = 0, sum = 0, prev = 0, cur = 0;
    bool rev = false;
    deque <ll> a;
    while(q--){
        ll s; cin >> s;
        if(s == 1){
            ll x;
            if(!rev){
                x = a.back(); a.pop_back();
                a.push_front(x);
            }
            else{ // if reversed, logical last is in the first
                x = a.front(); a.pop_front();
                a.push_back(x);
            }
            cur = prev + sum - n * x;
        }
        else if(s == 2){
            rev ^= 1;
            cur = (n + 1) * sum - prev;
        }
        else if(s == 3){
            ll k; cin >> k; 
            if(rev) a.push_front(k);
            else a.push_back(k);
            n++; sum += k;
            cur += n * k;
        }
        cout << cur << "\n";
        prev = cur;
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
// https://codeforces.com/contest/2094/problem/G