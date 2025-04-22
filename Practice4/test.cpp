#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int n, d, in[N], len[N], pre[N];
vector<int> G[N];
queue<int> q;
struct DD {
    vector<int> v;
} a[N];

bool check(int x, int y) {
    for(int i = 0; i < d; i ++) {
        if(a[x].v[i] > a[y].v[i]) return 0;
    }
    return 1;
}

signed main() {
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0, c; j < d; j ++) {
            cin >> c;
            a[i].v.push_back(c);
        }
        sort(a[i].v.begin(), a[i].v.end());
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            if(check(i, j)) {
                G[i].push_back(j);
                cout << i << " -> " << j << endl;
                in[j] ++;
            }
            if(check(j, i)) {
                G[j].push_back(i);
                cout << j << " -> " << i << endl;
                in[i] ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(!in[i]) q.push(i), len[i] = 1, pre[i] = -1;
    }
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int i = G[x].size(), y; i; i --) {
            y = G[x][i-1];
            if(len[y] >= len[x] + 1) continue ;
            len[y] = len[x] + 1;
            pre[y] = x;
            q.push(y);
        }
    }
    int ans = 0, pos;
    for(int i = 1; i <= n; i ++) {
        if(ans >= len[i]) continue ;
        ans = i; pos = i;
    }
    cout << ans << endl;
    while(pos != -1) {
        cout << pos << "<-";
        pos = pre[pos];
    }
    return 0;
}

// 5 1
// 1
// 2
// 3
// 4
// 5