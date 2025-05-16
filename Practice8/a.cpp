#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int n, m, f[N];

signed main() {
    cin >> n;
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i ++) {
        f[i] = f[i-1] + f[i-2];
    }
    cout << f[n] << endl;
    return 0;
}

// time complexty O(n)