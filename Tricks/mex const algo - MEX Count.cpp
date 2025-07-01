#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <int> v(n+1), cnt(n+1), cnt2(n+1), pre(n+2);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    int mex = 0, lagbe = 0;
    for(int i = 0; i <= n; i++){
        if(cnt[i] > 0) mex++, lagbe += cnt[i];
        else break;
    }
    for(int i = 0; i < mex; i++){
        cnt2[cnt[i]]++;
    }
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + cnt2[i];
    }
    int trash = n - mex;
    cout << 1 << " ";
    for(int k = 1; k <= n; k++){
        int maxi = mex + 1;
        if(k <= trash) maxi = mex + 1;
        else maxi = mex - (k - trash) + 1;
        int jhamela = mex - pre[k];
        cout << maxi - jhamela << " ";
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
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}