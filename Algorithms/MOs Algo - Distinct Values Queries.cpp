#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int SZ = sqrt(N) + 1;

struct qry {
    int l, r, id, blk;
    bool operator<(const qry& p) const {
        return blk == p.blk ? r < p.r : blk < p.blk;
    }
};

qry queryList[Q];
int ans[Q];
int freq[N];
int n, q, distinctCount = 0;
vector <int> v;

void add(int id) {
    freq[id]++;
    if(freq[id] == 1){
        distinctCount++;
    }
}

void remove(int id) {
    freq[id]--;
    if(freq[id] == 0) {
        distinctCount--;
    }
}

long long get() {
    return distinctCount;
}

void MO() {
    sort(queryList, queryList + q);
    int cur_l = 0, cur_r = -1;
    for (int i = 0; i < q; i++) {
        qry currentQuery = queryList[i];
        while (cur_l > currentQuery.l) add(v[--cur_l]);
        while (cur_r < currentQuery.r) add(v[++cur_r]);
        while (cur_l < currentQuery.l) remove(v[cur_l++]);
        while (cur_r > currentQuery.r) remove(v[cur_r--]);
        ans[currentQuery.id] = get();
    }
}

void solve()
{
    cin >> n >> q;
    v.resize(n);
    map <int, int> firstOccur;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(firstOccur.find(v[i]) == firstOccur.end()) firstOccur[v[i]] = i;
    }
    for(int i = 0; i < n; i++) v[i] = firstOccur[v[i]];
    for(int i = 0; i < q; i++){
        cin >> queryList[i].l >> queryList[i].r;
        queryList[i].l--; queryList[i].r--; 
        queryList[i].id = i;
        queryList[i].blk = queryList[i].l / SZ;
    }
    MO();
    for(int i = 0; i < q; i++) cout << ans[i] << "\n";
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
// https://cses.fi/problemset/task/1734/