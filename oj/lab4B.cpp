#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e4+10;
const ll INF = 1e18;
typedef pair<ll,int> pli;
int n, m;
ll in[N], dis[N];
priority_queue<pli> q;
vector<int> G[N], W[N];

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i ++) {
        cin >> u >> v >> w;
        G[u].push_back(v);
        W[u].push_back(w);
    }
    for(int i = 1; i <= n; i ++)
        dis[i] = INF;
    dis[1] = 0;
    q.push(pli(0, 1));
    while(q.size()) {
        pli tmp = q.top(); q.pop();
        int x = tmp.second;
        ll z = tmp.first;
        if(z + dis[x]) continue ;
        for(int i = G[x].size(), y; i; i --) {
            y = G[x][i-1];
            z = W[x][i-1];
            if(dis[y] < dis[x] + z) continue ;
            if(dis[y] == dis[x] + z && in[y] > z) {
                in[y] = z;
                continue ;
            }
            in[y] = z;
            dis[y] = dis[x] + z;
            q.push(pli(-dis[y], y));
        }
    }
    ll ans = 0;
    for(int i = 2; i <= n; i ++) ans += in[i];
    cout << ans << endl;
    return 0;
}