#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5+10;
int n, k;
ll ans;
struct item {
    int siz, dis;
} a[N];

bool cmp(item x, item y) {
    return x.dis < y.dis;
}

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i].dis;
    for(int i = 1; i <= n; i ++) cin >> a[i].siz;
    sort(a + 1, a + 1 + n, cmp);
    int p = 1, tmp;
    while(p <= n && a[p].dis < 0) {
        ans -= 2ll * a[p].dis;
        tmp = k;
        while(p <= n && a[p].dis < 0 && tmp) {
            if(a[p].siz <= tmp) {
                tmp -= a[p].siz;
                a[p].siz = 0;
                p ++;
            }
            else {
                a[p].siz -= tmp;
                tmp = 0;
            }
        }
    }
    p = n;
    while(p >= 1 && a[p].dis > 0) {
        ans += 2ll * a[p].dis;
        tmp = k;
        while(p >= 1 && a[p].dis > 0 && tmp) {
            if(a[p].siz <= tmp) {
                tmp -= a[p].siz;
                a[p].siz = 0;
                p --;
            }
            else {
                a[p].siz -= tmp;
                tmp = 0;
            }
        }
    }
    ans -= max(-a[1].dis, a[n].dis);
    cout << ans << endl;
    return 0;
}