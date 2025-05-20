#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#define int long long 
using namespace std;

template<typename T>
inline void read(T&x) {
	x = 0; bool w = 1; char c = getchar();
	while(!isdigit(c)) { if(c=='-')w=0; c = getchar(); }
	while(isdigit(c)) { x = x*10+c-'0'; c = getchar(); }
	x = w ? x : -x;
}

const int N = 5e5 + 10, inf = 0x3f3f3f3f;
int n, m, s, t, dep[N], H[N], to[N], nxt[N], edg[N], tot = 1, Max;
bool v[N];

inline void add(int x, int y, int z) {
	to[++tot] = y, edg[tot] = z, nxt[tot] = H[x], H[x] = tot; 
	to[++tot] = x, edg[tot] = 0, nxt[tot] = H[y], H[y] = tot;
}

inline bool bfs() {
	for(int i = 0; i <= n; i++) dep[i] = 0, v[i] = 0;
	dep[s] = 1; queue<int> q; q.push(s); int x, y;
	while(q.size()) {
		x = q.front(); q.pop();
		for(int i = H[x]; i; i = nxt[i]) {
			if(!edg[i] || dep[to[i]]) continue;
			y = to[i]; dep[y] = dep[x] + 1;
			if(y == t) return 1;
			if(!v[y]) v[y] = 1, q.push(y); 
		}
	}
	return 0;
}

inline int dfs(int x, int flow) {
	if(x == t) return flow;
	int ret = flow, k;
	for(int i = H[x]; i && ret; i = nxt[i]) {
		if(!edg[i] || dep[to[i]] != dep[x] + 1) continue;
		k = dfs(to[i], min(edg[i], ret));
		if(!k) dep[to[i]] = 0;
		ret -= k, edg[i] -= k, edg[i^1] += k;
	}
	return flow - ret;
}

signed main() {
	read(n), read(m), read(s), read(t);
	for(int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		add(u, v+n, inf);
        add(v, u+n, inf);
	}
    add(s + n, s, inf);
    add(t + n, t, inf);
    for(int i = 1; i <= n; i++) {
        if(i == s || i == t) continue;
        add(i+n, i, 1);        
    }
    t += n;
    n += n;
	int flow;
	while(bfs()) 
		while(flow = dfs(s, inf))  Max += flow;
	cout << Max << endl;
	return 0;
}