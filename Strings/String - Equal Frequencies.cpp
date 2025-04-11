#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s, ans;
    cin >> s;
    vector <int> v, fq(26);
    for(auto x : s){
        fq[x - 'a']++;
    }
    vector <pair<int,char>> ord;
    for(int i = 0; i < 26; i++) ord.push_back({fq[i], 'a' + i});
    sort(ord.rbegin(), ord.rend());
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && i * 26 >= n) v.push_back(i);
    }
    int maxi = 0, cur = 0;
    for(auto freq : v){
        int diff = n / freq;
        queue <char> wait;
        cur = 0;
        vector <int> tmpfq(26);
        for(int j = 0; j < diff; j++){
            auto[f, c] = ord[j];
            cur += min(freq, f);
            if(f < freq){
                for(int k = f; k < freq; k++) wait.push(c);
            }
            tmpfq[c - 'a'] = freq;
        }
        // cout << cur << " " << wait.size() << " " << maxi << "\n";
        string temp = "";
        if(cur >= maxi){
            maxi = cur;
            for(int i = 0; i < n; i++){
                if(tmpfq[s[i] - 'a'] > 0){
                    temp = temp + s[i];
                    tmpfq[s[i] - 'a']--;
                }
                else{
                    char ch = wait.front();
                    temp = temp + ch;
                    tmpfq[ch - 'a']--;
                    wait.pop();
                }
            }
            ans = temp;
        }
    }
    cout << n - maxi << "\n";
    cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/1781/C