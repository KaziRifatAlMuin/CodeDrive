#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Manacher {
    vector<int> p[2];  // p[0]: even-length, p[1]: odd-length palindromes
    // p[1][i] = (maximum half-length of odd-length palindrome centered at i)
    // p[0][i] = (maximum half-length of even-length palindrome centered at i)
    // For s = "abbabba", 
    // p[1][3] = 3, "abbabba" centered at index 3 has a length of 7, and 7/2 = 3.
    // p[0][2] = 2, "abba" centered between index 1 and 2 has a length of 4, and 4/2 = 2.
    Manacher(string s) {
        int n = s.size();
        p[0].resize(n + 1);
        p[1].resize(n);
        for (int z = 0; z < 2; z++) {
            for (int i = 0, l = 0, r = 0; i < n; i++) {
                int t = r - i + !z;  // calculate how much we can reuse
                if (i < r) p[z][i] = min(t, p[z][l + t]);  // reuse previous results if possible
                // Expand around center i for the current z (even/odd)
                int L = i - p[z][i], R = i + p[z][i] - !z;
                while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) {
                    p[z][i]++; L--; R++;
                }
                if (R > r) l = L, r = R;
            }
        }
    }
    bool is_palindrome(int l, int r) {
        int mid = (l + r + 1) / 2;
        int len = r - l + 1;
        // Check if the palindrome from mid can cover the substring of length 'len'
        return 2 * p[len % 2][mid] + len % 2 >= len;
    }
};

void solve() {
    string s;
    cin >> s;
    Manacher m(s);
    int n = s.size();
    int min_addition = n;
    for (int i = 1; i < n; ++i){
        if(m.is_palindrome(i, n - 1)){
            min_addition = i;
            break;
        }
    }
    string t = s.substr(0, min_addition);
    reverse(t.begin(), t.end());
    cout << s + t << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://acm.timus.ru/problem.aspx?space=1&num=1354