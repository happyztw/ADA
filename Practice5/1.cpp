#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+10;
int n, m, a[N];
priority_queue<int> q;

int Max() {
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        q.push(a[i]);
    }
    while(q.size() > 1) {
        int tmp = q.top(); q.pop();
        tmp += q.top(); q.pop();
        sum += tmp;
        q.push(tmp);
    }
    while(q.size()) q.pop();
    return sum;
}
int Min() {
    for(int i = 1; i <= n; i ++) {
        q.push(-a[i]);
    }
    int tmp, sum = 0, cnt = n;
    if(m > 2) {
        while(cnt % (m-1) != 1) {
            q.push(0);
            cnt ++;
        }
    }
    while(q.size() > 1) {
        // cout << q.size() << endl;
        cnt = m;
        tmp = 0;
        while(cnt --) {
            tmp -= q.top(); q.pop();
        }
        sum += tmp;
        q.push(-tmp);
    }
    return sum;
}

signed main() {
    // ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    // cout << Min();
    cout << Max() << " " << Min();
    return 0;
}