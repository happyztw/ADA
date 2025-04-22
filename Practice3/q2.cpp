#include <bits/stdc++.h>

using namespace std;

struct item {
    string name;
    int l, r;
} jb[100];

bool cmp(item a, item b) {
    return a.r <= b.r;
}

signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> jb[i].name >> jb[i].l >> jb[i].r;
    }
    sort(jb + 1, jb + 1 + n, cmp);
    int R = -1;
    for(int i = 1; i <= n; i ++) {
        if(jb[i].l >= R) {
            cout << jb[i].name << " ";
            R = jb[i].r;
        }
    }
    return 0;
}