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

using namespace std;

// const int N = 2e3 + 10;
const int M = 1e5 + 10;
int n, m, f[M];

signed main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i ++) {
        f[i] = -2e9;
    }
    for(int i = 1; i <= n; i++) {
        int op, c, v;
        cin >> op >> c >> v;
        if(op == 0) {
            for(int j = c; j <= m; j ++) {
                f[j] = max(f[j], f[j-c] + v);
            }
        }
        else if(op == 1) {
            for(int j = m; j >= c; j --) {
                f[j] = max(f[j], f[j-c] + v);
            }
        }
        else {
            int x;
            cin >> x;
            swap(c, v), swap(v, x);
            for(int k = 1; k <= x; k ++) {
                for(int j = m; j >= c; j --) {
                    f[j] = max(f[j], f[j-c] + v);
                }
            }
        }
    }
    cout << max(0, f[m]) << endl;
    return 0;
}