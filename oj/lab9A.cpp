#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10, X = 5e3+10, inf = 1e9;
int n, l, m1, x1, c1, m2, x2, c2, ans = inf;
bool f[X][X], stone[N];

signed main() {
    cin >> n >> l;
    cin >> x1 >> m1 >> c1;
    cin >> x2 >> m2 >> c2;
    stone[0] = 1; stone[l] = 1;
    for(int i = 1, a; i <= n; i ++) {
        cin >> a;
        stone[a] = 1;
    }
    f[0][0] = 1;
    for(int i = 0; i <= m1; i ++) {
        for(int j = 0; j <= m2; j ++) {
            int len = i * x1 + j * x2;
            if(len > l || !stone[len] || !f[i][j]) continue ;
            if(len + x1 <= l && i < m1 && stone[len+x1]) {
                f[i+1][j] = 1;
            }
            if(len + x2 <= l && j < m2 && stone[len+x2]) {
                f[i][j+1] = 1;
            }
            if(len == l && f[i][j]) ans = min(ans, i * c1 + j * c2);
        }
    }
    if(ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}