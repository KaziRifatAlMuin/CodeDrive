#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI acos(-1.0)

ld dis(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x1 - x2) * (x1 - x2)  + (y1 - y2) * (y1 - y2));
}

void solve(){
    ld a, b, h, m;
    cin >> a >> b >> h >> m;
    ld x1, y1, x2, y2, angle1, angle2;
    angle1 = h * 30 + m * 0.5;
    angle2 = m * 6;
    x1 = a * cos(angle1 * PI / 180);
    y1 = a * sin(angle1 * PI / 180);
    x2 = b * cos(angle2 * PI / 180);
    y2 = b * sin(angle2 * PI / 180);
    // cout << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n";
    ld d = dis(x1, y1, x2, y2);
    cout << fixed << setprecision(14) << d << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://atcoder.jp/contests/abc168/tasks/abc168_c?lang=en