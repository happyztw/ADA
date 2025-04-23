#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
const int S = 26;
int n, k, ans, str[N], nxt[N][S], sum[N][S];
string s;

signed main() {
    cin >> s >> k;
    n = s.length();
    for(int i = 1; i <= n; i ++) {
        str[i] = s[i-1] - 'a';
        for(int j = 0; j < S; j ++)
            sum[i][j] = sum[i-1][j];
        sum[i][str[i]] ++;
    }
    for(int i = n-1; i; i --) {
        for(int j = 0; j < S; j ++)
            nxt[i][j] = nxt[i+1][j];
        nxt[i][str[i+1]] = i + 1;
    }
    // for(int x = 0; x < S; x ++) {
    //     for(int i = 1; i <= n; i ++) {
    //         cout << nxt[i][x];
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i ++) {
        int r = n, pre;
        while(1) {
            pre = n + 1;
            for(int x = 0, y; x < S; x ++) {
                y = sum[r][x] - sum[i-1][x];
                if(0 < y && y < k) pre = min(pre, nxt[i-1][x]-1);
            }
            if(pre == n + 1) break ;
            r = pre;
            if(pre < i) break ;
        }
        ans = max(ans, r - i + 1);
    }
    cout << ans << endl;
    return 0;
}