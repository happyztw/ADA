#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+10, M = 4e5+10;
int n, m, v[N], c[N], ans[N], tot;
long long Max, f[M];
int pre[M];

signed main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i] >> v[i];
        for(int j = c[i]; j <= m; j ++) {
            if(f[j] < f[j-c[i]] + v[i]) {
                f[j] = f[j-c[i]] + v[i];
                pre[j] =i;
            }
        }
    }
    Max = f[m];
    tot = m;
    while(pre[tot]) {
        int x = pre[tot];
        ans[x] ++;
        tot -= c[x];
    }
    cout << Max << endl;
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << endl;
    }
    return 0;
}