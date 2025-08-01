#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int op, cl;

ll ask1(int low, int high){
    cout << "? " << high - low + 1 << " ";
    for(int i = low; i <= high; i++){
        cout << i << " ";
    }
    cout << "\n";
    fflush(stdout);
    ll res; cin >> res;
    return res;
}

ll ask2(int a, int b){
    cout << "? " << 6 << " ";
    cout << op << " " << a << " " << b << " " << cl << " " << op << " " << cl << "\n";
    fflush(stdout); // (??)()
    ll res; cin >> res;
    return res;
}

ll ask3(int a){
    cout << "? " << 2 << " ";
    cout << op << " " << a << "\n";
    fflush(stdout);
    ll res; cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string ans;
    int k = ask1(1, n);
    if(k == 0) op = n, cl = 1;
    else{
        // 111111111110000
        int low = 1, high = n, firstzero = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int k = ask1(mid, n);
            if(k > 0){
                low = mid + 1;
            }
            else{
                firstzero = mid;
                high = mid - 1;
            }
        }
        cl = firstzero;
        op = firstzero - 1;
    }
    for(int i = 1; i+1 <= n; i += 2){
        int k = ask2(i, i+1);
        // (xx)()
        if(k == 2) ans += "))";      // ()))()
        else if(k == 3) ans += "(("; // ((()()
        else if(k == 4) ans += "()"; // (())()
        else if(k == 6) ans += ")("; // ()()()
    }
    if(n & 1){
        int k = ask3(n);
        if(k == 0) ans += "(";
        else ans += ")";
    }
    cout << "! " << ans << "\n";
    fflush(stdout);
}
    
int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}