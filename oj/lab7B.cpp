#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+10;
int n, m;
struct hp {
    priority_queue<int> q, p;
    void update() {
        while(q.size() && p.size() && q.top() == p.top()) 
            q.pop(), p.pop();
    }
    int top() {
        update();
        return q.size() ? q.top() : 0;
    }
    void push(int x) {
        q.push(x);
    }
    void del(int x) {
        p.push(x);
    }
} Q;
struct reg {
    int x, h;
    bool op;
} a[N];

bool cmp(reg x, reg y) {
    return x.x < y.x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0, l, r, h; i < n; i ++) {
        cin >> l >> r >> h;
        a[i<<1].x = l;
        a[i<<1].op = 1;
        a[i<<1].h = h;
        a[i<<1|1].x = r;
        a[i<<1|1].op = 0;
        a[i<<1|1].h = h;
    }
    n <<= 1;
    sort(a, a + n, cmp);
    int p = 0, ans = 0 ;
    while(p < n) {
        while(p < n && a[p].x == a[p+1].x) {
            if(a[p].op) Q.push(a[p].h);
            else Q.del(a[p].h);
            p ++;
        }
        if(a[p].op) Q.push(a[p].h);
        else Q.del(a[p].h);
        int tmp = Q.top();
        if(tmp != ans) {
            ans = tmp;
            cout << a[p].x << " " << ans << endl;
        }
        p ++;
    }
    return 0;
}