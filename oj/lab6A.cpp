#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6+10;
int n, a[N], b[N];
ll ans;

void merge(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    merge(l, mid), merge(mid+1, r);
    int i = l, j = mid + 1, p = l;
    for( ; i <= mid && j <= r; ) {
        if(a[i] > a[j]) b[p++] = a[j++];
        else b[p++] = a[i++], ans += j - mid - 1;
    }
    while(i <= mid) b[p++] = a[i++], ans += j - mid - 1;
    while(j <= r) b[p++] = a[j++];
    for(i = l; i <= r; i ++) 
        a[i] = b[i];
}

signed main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    merge(1, n);
    cout << ans << endl;
    return 0;
}