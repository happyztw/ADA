#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, m, a[N], b[N], f[N][N];

signed main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(a[i] == b[j]) 
                f[i][j] = max(f[i-1][j-1] + 1, f[i][j]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

// 4 5
// 1 2 3 7
// 3 2 4 6 7

//2

// time complexty O(n^2)