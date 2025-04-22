#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int n, val[N], F[N], ans;
vector<int> G[N];

void dfs(int p) {
    int ls = p << 1, rs = p << 1 | 1;
    if(ls > n) {
        F[p] = val[p];
        ans = max(ans, F[p]);
    }
    else if(rs > n) {
        dfs(ls);
        F[p] = F[ls] + val[p];
        ans = max(ans, F[p]);
    }
    else if(rs <= n) {
        dfs(ls); dfs(rs);
        F[p] = max(F[ls], F[rs]) + val[p];
        ans = max(ans, F[ls] + val[p] + F[rs]);
    }
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> val[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}