#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10, Mod = 1e9+7;
int n, m, in[N], out[N], cnt1[N], cnt2[N];
vector<int> G1[N], G2[N];
queue<int> q;

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i ++) {
        cin >> u >> v;
        in[v] ++;
        out[u] ++;
        G1[u].push_back(v);
        G2[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) {
        // cnt1[i] = cnt2[i] = 1;
        if(in[i] == 0) q.push(i), cnt1[i] = 1;
    }
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int i = 0; i < G1[x].size(); i ++) {
            int y = G1[x][i];
            in[y] --;
            cnt1[y] += cnt1[x];
            if(cnt1[y] >= Mod) cnt1[y] -= Mod;
            if(in[y] == 0) q.push(y);
        }
    }
    for(int i = 1; i <= n; i ++)
        if(out[i] == 0) q.push(i), cnt2[i] = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int i = 0; i < G2[x].size(); i ++) {
            int y = G2[x][i];
            out[y] --;
            cnt2[y] += cnt2[x];
            if(cnt2[y] >= Mod) cnt2[y] -= Mod;
            if(out[y] == 0) q.push(y);
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << 1ll * cnt1[i] * cnt2[i] % Mod << " ";
        // cout << cnt1[i] << " " << cnt2[i] << endl;
    }
    return 0;
}