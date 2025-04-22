#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
int n, m, p[N], q[N], c, t;

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> c >> t;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= m; i ++) cin >> q[i];
    sort(p + 1, p + 1 + n);
    sort(q + 1, q + 1 + m);
    int ans = 0, tmp = c;
    int i, j;
    for(i = 1, j = 1; i <= n && j <= m; i ++) {
        if(p[i] <= q[j]) {
            if(q[j] - p[i] <= t) {
                tmp --;
                if(tmp == 0) {
                    tmp = c;
                    j ++;
                }
                ans ++;
            }
        }
        else {
            while(p[i] - q[j] > t && j <= m) {
                tmp = c;
                j ++;
            }
            if(j > m) break ;
            if(abs(p[i] - q[j]) <= t) {
                tmp --;
                if(tmp == 0) {
                    tmp = c;
                    j ++;
                }
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}