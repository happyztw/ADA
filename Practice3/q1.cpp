#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int n, m, in[N];
vector<int> G[N];
priority_queue<int> q;

signed main() {
    // ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i ++) {
        cin >> u >> v;
        in[v] ++;
        G[u].push_back(v);
    }
    for(int i = 1; i <= n; i ++) {
        if(in[i] == 0) q.push(-i);
    }
    while(q.size()) {
        int x = -q.top(); q.pop();
        cout << x << " ";
        for(int i = 0; i < G[x].size(); i ++) {
            int y = G[x][i];
            in[y] --;
            if(in[y] == 0) q.push(-y);
        }
    }
    return 0;
}