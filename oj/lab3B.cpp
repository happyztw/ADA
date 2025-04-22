#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
int n, m, ed, ans;
struct item {
    int l, r, c;
} a[N];

bool cmp(item x, item y) {
    if(x.l == y.l) {
        if(x.c == y.c) {
            return x.r < y.r;
        }
        else return x.c < y.c;
    }
    else return x.l < y.l;
}

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].l >> a[i].r;
        a[i].c = 1;
    }
    for(int i = n + 1; i <= n + m; i ++) {
        cin >> a[i].l >> a[i].r;
        a[i].c = 0;
    }
    sort(a + 1, a + 1 + n + m, cmp);
    for(int i = 1; i <= n + m; i ++) {
        if(a[i].c) ans += a[i].r <= ed;
        else ed = max(ed, a[i].r);
    }
    cout << ans << endl;
    return 0;
}

// 9 3
// 1 2
// 2 4
// 2 4
// 3 8
// 3 7
// 5 11
// 8 9
// 10 16
// 10 15
// 2 4
// 4 11
// 10 16