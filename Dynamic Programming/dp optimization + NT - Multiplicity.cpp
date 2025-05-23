#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7, mod = 1e9 + 7;

vector <int> divs[N+10];
void pre(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divs[j].push_back(i);
        }
    }
    for(int i = 1; i < N; i++) reverse(divs[i].rbegin(), divs[i].rend());
}

// Good subseq : ith element of subseq is divisible by i
// Goal : Count the number of good subsequence 
// dp[max_index][subseq_length]
// dp[i][j] = number of good subseq which have a 
// last index <= i and are length j (1-based)
// ans = dp[n][1] + dp[n][2] + ... + dp[n][n]
// Base case : dp[1][1] = 1, dp[i][0] = 1 for all i = [1,n]
// There is exactly one subseq of length = 0 : {empty}
// Recursive case : 
// not take : dp[i][j] = dp[i-1][j]
// take (if a[i] % j == 0) : dp[i][j] += dp[i-1][j-1]
// Time : O(n^2); space : O(n^2)

// Memory Optimization
// dp[N][N] -> dp[2][N]
// using the fact that we are using only 2 rows of the dp at a time
// just mod i and (i-1) with 2 will ensure it

void TLEsolve(){
    int n; cin >> n;
    vector <int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector <vector <int>> dp(2, vector<int> (n+1));
    dp[0][0] = dp[1][0] = 1;
    ll ans = 0;
    pre();
    for(int i = 1; i <= n; i++){
        dp[i % 2] = dp[(i-1) % 2]; // Replace the whole row with previous row : O(n) which gives TLE
        // Access j if v[i] is divisible by j
        // In other words: update dp[i][j] if j is a divisor of v[i]
        // we can get the divisors at O(sqrt(n)) time
        /*
        for(int j = 1; j <= n; j++){
            dp[i % 2][j] = dp[(i-1) % 2][j];
            if(v[i] % j == 0) dp[i % 2][j] = (dp[i % 2][j] + dp[(i-1) % 2][j-1]) % mod;
            // if v[i] is divisible by j, then v[i] is the jth element in our good subsequence
        }
        // Transition time is too slow
        // we only need the divisors of v[i] and update dp there
        */
        for(auto j : divs[v[i]]) if(j <= n) dp[i % 2][j] = (dp[i % 2][j] + dp[(i-1) % 2][j-1]) % mod;
    }
    for(int j = 1; j <= n; j++) ans = (ans + dp[n % 2][j]) % mod;
    cout << ans << "\n";
}

// Final Optimization
// Use a 1D dp array of (n+1) size
// dp[i] = number of good subsequences of length i

void solve(){
    int n; cin >> n;
    vector <int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector <int> dp(n+1);
    dp[0] = 1; // empty subsequence, which starts every good subseq
    ll ans = 0;
    pre();
    for(int i = 1; i <= n; i++){
        // Need to be careful that we are updating dp[j] in the correct order
        for(auto j : divs[v[i]]){
            if(j <= n){
                dp[j] = (dp[j] + dp[j-1]) % mod;
                // We are assuming that dp[j-1] refers to the previous dp row
                // To maintain it, this loop must run greater to smaller
                // So that smaller values contain previous values that needed and update later
            }
        }
    }
    for(int j = 1; j <= n; j++) ans = (ans + dp[j]) % mod;
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1061/C