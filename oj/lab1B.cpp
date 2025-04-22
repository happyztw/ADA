#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
int n, m, a, b, siza, sizb;
int dfn[N], u[N], v[N], w[N], ina[N], inb[N];
vector<int> G[N];

void dfs(int x) {
    for(int i = G[x].size(), y; i; i --) {
        y = G[x][i-1]; 
        if(dfn[y]) continue ;
        dfn[y] = dfn[x];
        dfs(y);
    }
}

void init() {
    siza = sizb = 0;
    for(int i = 1; i <= n; i ++) {
        G[i].clear();
        ina[i] = inb[i] = dfn[i] = 0;
    }
    for(int i = 1; i <= m; i ++) u[i] = v[i] = w[i] = 0;
}

void work() {
    init();
    bool flag = 0;
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= m; i ++) {
        cin >> u[i] >> v[i];
        if(u[i] == a || u[i] == b) continue ;
        if(v[i] == a || v[i] == b) {
            swap(u[i], v[i]);
            continue ;
        }
        w[i] = 1;
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    for(int i = 1; i <= n; i ++) {
        if(i == a || i == b) continue ;
        if(dfn[i]) continue ;
        dfn[i] = i;
        dfs(i);
    }
    for(int i = 1; i <= m; i ++) {
        if(w[i]) continue ;
        if(v[i] == a || v[i] == b) {
            flag = 1;
            continue;
        }
        if(u[i] == a) ina[dfn[v[i]]] = 1;
        else inb[dfn[v[i]]] = 1;
    }
    for(int i = 1; i <= n; i ++) {
        if(i == a || i == b) continue ;
        int x = dfn[i];
        if(ina[x] && inb[x]) {
            flag = 1;
            continue ;
        }
        if(ina[x]) siza ++;
        if(inb[x]) sizb ++;
    }
    if(flag) cout << (1ll * siza * sizb) << endl;
    else puts("0");
}

signed main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    work();
    return 0;
}