#include <iostream>
using namespace std;

const int N = 510, Mod = 99824353;
int n, m, f[N][N];

int main() {
    cin >> n >> m;
    f[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = max(0, i-m); j <= min(n, i+m); j ++) {
            for(int k = 0; k <= min(j, 1 + min(i-1, m) + min(m, n-i)); k ++) {
                f[i][j] = (f[i][j] + f[i-1][j-k]) % Mod;
            }
        }
    }
    cout << f[n][n] << endl;
    return 0;
}