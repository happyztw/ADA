#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int K = 1e7 + 10;
const int INF = 1e9;
int n, m, rt, siz[N], dis[N], len[K], Max, MM;
int sta[N], top;
bool w[N];
vector<int> G[N], W[N];

inline void dfs_rt(int S, int x, int fa) {
	siz[x] = 1;
	int mc = 0;
	for(int i = G[x].size(); i; i --) {
		int y = G[x][i-1];
		if(w[y] || y == fa) continue;
		dfs_rt(S, y, x);
		siz[x] += siz[y];
		mc = max(mc, siz[y]);
	}
	mc = max(mc, S - siz[x]);
	if(mc < Max) {
		rt = x;
		Max = mc;
	}
}

inline void dfs_dis(int x, int ww, int fa) {
	for(int i = G[x].size(); i; i --) {
		int y = G[x][i-1];
		if(w[y] || y == fa) continue;
		dis[y] = dis[x] + W[x][i-1];
		dfs_dis(y, ww, x);
	}
	if(dis[x] <= MM) len[dis[x]] += ww;
}

inline void sol(int x, int fa, int ww) {
	for(int i = G[x].size(); i; i --) {
		int y = G[x][i-1];
		if(w[y] || y == fa) continue;////
		sol(y, x, ww);
	}
	if(dis[x] <= MM) len[dis[x]] += ww;
	if(ww == -1 && dis[x] <= MM) sta[++top] = x;
}

inline void work(int S, int x) {
	Max = INF;
	dfs_rt(S, x, 0);
	w[x=rt] = 1;
	dis[x] = 0;
	dfs_dis(x, 1, 0);
	for(int i = G[x].size(); i; i --) {
		int y = G[x][i-1];
		if(w[y]) continue;
		top = 0;
		sol(y, x, -1);
		for(int k = 1; k <= top; k ++) {
            if(len[MM-dis[sta[k]]]) {
                puts("Yes");
                exit(0);
            }
		}
		sol(y, x, 1);
	}
	dfs_dis(x, -1, 0);
	for(register int i = G[x].size() - 1; i >= 0; i--) {
		int y = G[x][i];
		if(w[y]) continue;
		work(siz[y], y);
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> MM;
	for(int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
		G[a].push_back(b);
		W[a].push_back(c);
		G[b].push_back(a);
		W[b].push_back(c);
	}
	work(n, 1);//
    puts("No");
	return 0;
}
// 5 0
// 1 2 2
// 1 3 1
// 2 4 3
// 2 5 4