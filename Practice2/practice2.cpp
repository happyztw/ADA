#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, cnt;
int a[N*2][N], cp[N*2], b[N][N];
string nm[N*2], _nm;
unordered_map<string, int> mp;

signed main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> _nm;
        nm[++cnt] = _nm;
        mp[_nm] = cnt;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> _nm;
        nm[++cnt] = _nm;
        mp[_nm] = cnt;
    }
    for(int i = 1; i <= cnt; i ++) cp[i] = -1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> _nm;
            a[i][j] = mp[_nm];
        }
    }
    for(int i = n+1; i <= n*2; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> _nm;
            a[i][j] = mp[_nm];
            b[i-n][a[i][j]] = j;
        }
    }
    while(1) {
        int sl = -1, nw;
        for(int i = 1; i <= n; i ++)
            if(cp[i] == -1) {
                sl = i;
                break;
            }
        if(sl == -1) break;
        for(int i = 1; i <= n; i ++) {
            nw = a[sl][i];
            if(cp[nw] == -1) {
                cp[nw] = sl;
                cp[sl] = nw;
            }
            else {
                if(b[nw-n][cp[nw]] > b[nw-n][sl]) {
                    cp[cp[nw]] = -1;
                    cp[nw] = sl;
                    cp[sl] = nw;    
                }
            }
            if(cp[sl] != -1) break ;
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << nm[i] << " " << nm[cp[i]] << endl;
    }
    return 0;
}