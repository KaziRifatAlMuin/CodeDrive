#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt {
    ll x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++) {
        if(i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if(i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if(include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for(int i = 0; i < (int)up.size(); i++) a.push_back(up[i]);
    for(int i = down.size() - 2; i > 0; i--) a.push_back(down[i]);
}

ll area(pt a, pt b, pt c){
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    auto [x3, y3] = c;
    return abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1);
}

bool check(pt a, pt b, pt c, pt m){
    ll ar1 = area(a, b, m);
    ll ar2 = area(a, c, m);
    ll ar3 = area(b, c, m);
    ll ar4 = area(a, b, c);
    return (ar1 + ar2 + ar3) == ar4;
}

void solve(){
    int n; cin >> n;
    vector <pt> xy(n), ch;
    set <pair<ll,ll>> st;
    map <pair<ll,ll>, int> mp;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        xy[i].x = x;
        xy[i].y = y;
        mp[{x,y}] = i + 1;
    }
    ll mid = 0;
    ch = xy;
    convex_hull(ch);

    if(ch.size() == n){
        cout << -1 << "\n";
        return;
    }

    for(auto [x,y] : ch){
        st.insert({x, y});
    }
    for(int i = 0; i < n; i++){
        if(st.count({xy[i].x, xy[i].y}) == 0){
            mid = i;
            break;
        }
    }
    struct pt a = ch[0], m = xy[mid];
    int aa = mp[{ch[0].x, ch[0].y}], bb, cc;
    bool ok = false;
    for(int i = 1; i < ch.size(); i++){
        for(int j = i + 1; j < ch.size(); j++){
            pt b = ch[i];
            pt c = ch[j];
            if(check(a,b,c,m)){
                bb = mp[{b.x, b.y}];
                cc = mp[{c.x, c.y}];
                ok = true;
                break;
            }
        }
    }
    if(ok) cout << mid + 1 << " " << aa << " " << bb << " " << cc << "\n";
    else cout << -1 << "\n";
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
// https://codeforces.com/gym/105884/problem/C