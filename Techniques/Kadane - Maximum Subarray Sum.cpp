#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

void print(vector <ll> v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}

ll kadane(vector <ll> v){
    ll n = v.size();
    ll maxi = -1e18, sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return maxi;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    string s; cin >> s;
    for(int i = 0; i < n; i++) cin >> v[i];
    ll maxi = -1e9, sum = 0, start, subL, subR, must = -1e9, add = 0;
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i;
        sum += v[i];
        if(sum > maxi){
            maxi = sum;
            subL = start, subR = i;
        }
        if(sum < 0) sum = 0;
        // special
        add += v[i];
        if(add > must) must = add;
        if(add < 0 || s[i] == '0') add = 0;
    }
    // cout << k << " ? ";
    // cout << must << " ! ";
    // cout << maxi << " " << subL << " " << subR << "\n";
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        if(maxi == k){
            cout << "Yes\n";
            print(v);
        }
        else{
            cout << "No\n";
        }
    }
    else{
        if(k < must){
            cout << "No\n";
            return;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '0') v[i] = -1e18;
        }
        ll low = -1e18, high = 1e18, ans = 0;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            vector <ll> temp = v;
            temp[pos] = mid;
            ll res = kadane(temp);
            if(res == k){
                cout << "Yes\n";
                print(temp);
                return;
            }
            else if(res < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << "No\n";
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
// https://codeforces.com/contest/2107/problem/C