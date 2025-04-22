#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10, INF = 1e9;
typedef pair<int,int> pii;
int n, m, dis[2][N], U[N], V[N], E[N];
priority_queue<pii> q;
vector<int> G[N], W[N];

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> U[i] >> V[i] >> E[i];
        G[U[i]].push_back(V[i]);
        W[U[i]].push_back(E[i]);
        G[V[i]].push_back(U[i]);
        W[V[i]].push_back(E[i]);
    }
    for(int i = 1; i <= n; i ++) 
        dis[0][i] = dis[1][i] = INF;
    dis[0][1] = 0;
    q.push(pii(0, 1));
    while(q.size()) {
        pii tmp = q.top(); q.pop();
        int x = tmp.second, z = tmp.first;
        if(z + dis[0][x]) continue ;
        for(int i = G[x].size(), y; i; i --) {
            y = G[x][i-1], z = W[x][i-1];
            if(dis[0][y] <= dis[0][x] + z) continue ;
            dis[0][y] = dis[0][x] + z;
            q.push(pii(-dis[0][y], y));
        }
    }
    dis[1][n] = 0;
    q.push(pii(0, n));
    while(q.size()) {
        pii tmp = q.top(); q.pop();
        int x = tmp.second, z = tmp.first;
        if(z + dis[1][x]) continue ;
        for(int i = G[x].size(), y; i; i --) {
            y = G[x][i-1], z = W[x][i-1];
            if(dis[1][y] <= dis[1][x] + z) continue ;
            dis[1][y] = dis[1][x] + z;
            q.push(pii(-dis[1][y], y));
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << dis[0][i] + dis[1][i] << endl;
    }
    for(int i = 1; i <= m; i ++) {
        int ans = min(dis[0][U[i]] + dis[1][V[i]], dis[0][V[i]] + dis[1][U[i]]);
        ans += E[i];
        cout << ans << endl;
    }
    return 0;
}