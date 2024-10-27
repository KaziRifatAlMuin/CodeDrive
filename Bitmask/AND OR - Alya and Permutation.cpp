#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1ll)
#define PowerOf2(v) (v && !(v & (v - 1)))
#define jinish(n) ((n == 0) ? 0 : ((1 << (31 - __builtin_clz(n))) - 1))
#define jinish2(n) ((n) ^ (1 << (31 - __builtin_clz(n))))

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    set <int> st;
    for(int i = 1; i <= n; i++) st.insert(i);
    if(n == 6){
        v = {1, 2, 4, 6, 5, 3};
    }
    else if(PowerOf2(n+1)){
        v[n-1] = n; // and
        v[n-2] = n - 1; // or
        v[n-3] = (n + 1) / 2 - 1; // and
        v[n-4] = 1; // or
        st.erase(n);
        st.erase(n - 1);
        st.erase((n + 1) / 2 - 1);
        st.erase(1);
    }
    else{
        int k = jinish(n);
        int p = jinish2(n);
        if(n & 1){
            v[n-1] = n; // and
            v[n-2] = n - 1; // or
            v[n-3] = p; // and
            v[n-4] = k; // or
            st.erase(v[n-1]);
            st.erase(v[n-2]);
            st.erase(v[n-3]);
            st.erase(v[n-4]);
        }
        else{
            v[n-1] = k + 1; 
            v[n-2] = k; // and
            v[n-3] = k - 1;
            v[n-4] = k - 2; // and
            v[n-5] = 1;
            st.erase(v[n-1]);
            st.erase(v[n-2]);
            st.erase(v[n-3]);
            st.erase(v[n-4]);
            st.erase(v[n-5]);
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i] == 0){
            v[i] = *st.begin();
            st.erase(v[i]);
        }
    }
    int ans = 0, it = 1;
    for(auto x : v){
        if(it & 1) ans &= x;
        else ans |= x;
        it++;
    }
    cout << ans << "\n";
    for(auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2035/problem/C