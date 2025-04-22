#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+10;
int n, m, cnt, top[N], dep[N], pos[N], siz[N], dfn[N], son[N], fa[N];
vector<int> G[N];

void dfs1(int x, int f) {
    siz[x] = 1; fa[x] = f;
    for(int i = G[x].size(), y; i; i --) {
        y = G[x][i-1]; 
        if(y == f) continue ;
        dep[y] = dep[x] + 1;
        dfs1(y, x);
        siz[x] += siz[y];
        if(siz[son[x]] < siz[y]) 
            son[x] = y;
    }
}

void dfs2(int x, int tp) {
    top[x] = tp; dfn[x] = ++ cnt; pos[cnt] = x;
    if(!son[x]) return ;
    dfs2(son[x], tp);
    for(int i = G[x].size(), y; i; i --) {
        y = G[x][i-1];
        if(y == fa[x] || y == son[x]) continue ;
        dfs2(y, y);
    }
}

int lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] > dep[top[v]]) swap(u, v);
        v = fa[top[v]];
    }
    return dep[u] < dep[v] ? u : v;
}



int find(int x, int dp) {
    int p = x;
    while(dfn[p] - dfn[top[p]] < dp) {
        dp -= dfn[p] - dfn[top[p]] + 1;
        p = fa[top[p]];
    }
    p = pos[dfn[p]-dp];
    return p;
}

int Dis(int u, int v) {
    return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}

int bf(int u, int v) {
    int tmp = 0;
    for(int i = 1; i <= n; i ++)
        tmp += Dis(u, i) == Dis(v, i);
    return tmp;
}

int work(int u, int v) {
    if(u == v) return n;
    int f = lca(u, v);
    int dis = dep[u] + dep[v] - dep[f] * 2;
    if(dis & 1) return 0;
    dis /= 2;
    if(dep[u] == dep[v]) 
        return n - siz[find(u, dis-1)] - siz[find(v, dis-1)];
    if(dep[u] < dep[v]) u = v;
    return siz[find(u, dis)] - siz[find(u, dis-1)];
}

signed main() {
    // freopen("1.in","r",stdin);
    // ios::sync_with_stdio(0);
    int u, v;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    cin >> m;
    while(m --) {
        cin >> u >> v;
        // if(work(u, v) != bf(u, v)) puts("SB");
        cout << work(u, v) << endl;
    }
    return 0;
}
// 5
// 1 2
// 1 3
// 3 4
// 3 5
// 3
// 1 4
// 2 3
// 3 3