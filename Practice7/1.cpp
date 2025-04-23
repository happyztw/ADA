#include <bits/stdc++.h>

using namespace std;

const int N = 1<<5;
int n, m, X, Y, val[N][N];

void div(int x1, int y1, int x2, int y2, int x3, int y3) {
    if(x1 == x2 && y1 == y2)  return ;
    int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
    if(x3 <= mx) {
        if(y3 <= my) {
            div(x1, y1, mx, my, x3, y3);
            div(mx+1, y1, x2, my, mx+1, my);
            div(x1, my+1, mx, y2, mx, my+1);
            div(mx+1, my+1, x2, y2, mx+1,my+1);
            val[mx+1][my] = val[mx][my+1] = val[mx+1][my+1] = ++m;
        }
        else {
            div(x1, y1, mx, my, mx, my);
            div(mx+1, y1, x2, my, mx+1, my);
            div(x1, my+1, mx, y2, x3, y3);
            div(mx+1, my+1, x2, y2, mx+1,my+1);
            val[mx+1][my] = val[mx][my] = val[mx+1][my+1] = ++m;
        }
    }
    else {
        if(y3 <= my) {
            div(x1, y1, mx, my, mx, my);
            div(mx+1, y1, x2, my, x3, y3);
            div(x1, my+1, mx, y2, mx, my+1);
            div(mx+1, my+1, x2, y2, mx+1,my+1);
            val[mx][my] = val[mx][my+1] = val[mx+1][my+1] = ++m;
        }
        else {
            div(x1, y1, mx, my, mx, my);
            div(mx+1, y1, x2, my, mx+1, my);
            div(x1, my+1, mx, y2, mx, my+1);
            div(mx+1, my+1, x2, y2, x3, y3);
            val[mx+1][my] = val[mx][my+1] = val[mx][my] = ++m;
        }
    }
}

signed main() {
    cin >> n >> X >> Y;
    n = 1 << n;
    div(1, 1, n, n, X, Y);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << val[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}