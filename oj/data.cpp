#include <bits/stdc++.h>

using namespace std;

int random(int L, int R) { return L + 1ll * rand() * RAND_MAX % (R-L+1); }

signed main() {
    freopen("1.in","w",stdout);
    srand(time(0));
    int n = random(100, 100);
    int m = n * (n-1) / 2;
    cout << n << endl;
    for(int i = 2; i <= n; i ++) {
        int p = random(1, i-1);
        cout << i << " " << p << endl;
    }
    cout << m << endl;
    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            cout << i << " " << j << endl;
        }
    }
    return 0;
}