#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+10;
unordered_map<int,int> hs;
int hd, tl, siz, n, m, cnt;
struct item {
    int l, r, key, val;
} arr[N];

signed main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    string s;
    while(m --) {
        cin >> s;
        int ky, vl, pos;
        if(s[0] == 'p') {
            cin >> ky >> vl;
            pos = hs[ky];
            if(!pos) {
                pos = ++ cnt;
                arr[pos].key = ky;
                hs[ky] = cnt;
                siz ++;
                if(siz == 1) {
                    hd = tl = cnt;
                    arr[pos].l = arr[pos].r = cnt;
                }
                else {
                    if(siz > n) {
                        hs[arr[tl].key] = 0;
                        tl = arr[tl].l;
                        arr[tl].r = tl;
                        siz = n;
                    }
                    arr[hd].l = cnt;
                    arr[pos].r = hd;
                    arr[pos].l = cnt;
                    hd = pos;
                }
            }
            else {
                if(pos == tl) {
                    tl = arr[pos].l;
                    arr[tl].r = tl;
                }
                else {
                    arr[arr[pos].l].r = arr[pos].r;
                    arr[arr[pos].r].l = arr[pos].l;
                }
                if(pos != hd) {
                    arr[hd].l = pos;
                    arr[pos].r = hd;
                    arr[pos].l = pos;
                    hd = pos;
                }
            }
            arr[pos].val = vl;
        }
        else {
            cin >> ky;
            pos = hs[ky];
            if(!pos) {
                printf("-1\n");
            }
            else {
                if(pos == tl) {
                    tl = arr[pos].l;
                    arr[tl].r = tl;
                }
                else {
                    arr[arr[pos].l].r = arr[pos].r;
                    arr[arr[pos].r].l = arr[pos].l;
                }
                if(pos != hd) {
                    arr[hd].l = pos;
                    arr[pos].r = hd;
                    arr[pos].l = pos;
                    hd = pos;
                }
                printf("%d\n", arr[pos].val);
            }
        }
    }
    return 0;
}