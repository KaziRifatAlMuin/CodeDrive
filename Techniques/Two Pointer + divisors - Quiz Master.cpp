#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <int> divs[N];

void pre(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divs[j].push_back(i);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector <int> cnt(m+1);
    set <int> st;
    sort(v.begin(), v.end());
    int p1 = 0, p2 = 0;
    while(p2 < n && st.size() < m){
        for(auto x : divs[v[p2]]){
            if(x <= m){
                cnt[x]++;
                st.insert(x);
            }
            else break;
        }
        p2++;
    }
    int cur = v[p2-1] - v[p1], ans = -1;
    if(st.size() == m) ans = cur;
    else{
        cout << -1 << "\n";
        return;
    }
    while(p1 < n){
        bool remove = true;
        for(auto x : divs[v[p1]]){
            if(x > m) break;
            if(cnt[x] <= 1) remove = false;
        }
        if(remove){
            for(auto x : divs[v[p1]]){
                if(x <= m) cnt[x]--;
            }
            p1++;
            cur = v[p2-1] - v[p1];
            ans = min(ans, cur);
        }
        else{
            if(p2 == n) break;
            for(auto x : divs[v[p2]]){
                if(x <= m) cnt[x]++;
            }
            p2++;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1777/C