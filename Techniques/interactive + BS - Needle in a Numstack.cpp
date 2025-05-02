#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(int i){
    cout << "? " << i << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}

void print(int a, int b){
    cout << "! " << a << " " << b << "\n";
    cout.flush();
}

void fail(){
    cout << "! " << -1 << "\n";
    cout.flush();
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> a(k), b(k);
    for(int i = 0; i < k; i++) a[i] = ask(i+1);
    for(int i = 0; i < k; i++) b[i] = ask(n-i);
    if(n == 2*n){
        print(k, k);
        return;
    }
    int low = k, high = n - k - 1, ans = k - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int i = -1;
        for(int j = 0; j < k; j++){
            int ix = mid - j;
            int v1 = a[ix % k];
            int v2 = b[(n - ix - 1) % k];
            if(v1 != v2) {
                i = ix;
                break;
            }
        }
        if(i == -1) break;
        int res = ask(i + 1);
        // AAAAAAAAAAABBBBBBB
        if(res == a[i % k]) ans = i, low = mid + 1;
        else high = mid - 1;
    }
    int i = ans + 1;
    int v1 = a[i % k];
    int v2 = b[(n - i - 1) % k];
    if(i  < n - k && v1 == v2) fail();
    else print(ans + 1, n - (ans + 1));
}  

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2108/problem/D