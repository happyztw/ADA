#include <bits/stdc++.h>

using namespace std;
typedef double ull;
const int N = 4e6+10;
int n, m, id[N]; ull ans; 
struct P {
	ull x, y;
} p[N];
bool operator<(P a, P b) { return a.x * b.y > b.x * a.y; }

signed main() {
	int n; ans = 1e18; cin >> n;
	for(int i = 0; i < n; i ++)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	sort(p, p+n); 
	for(int i = 0; i < n; i ++) 
		for(int j = i+1, o = 0; o <= 65; o ++, j ++) {
			if(j == n) j = 0; if(i == j) continue ;
			ull x, y;
			if(p[i].x > p[j].x) x = p[i].x - p[j].x;
			else x = p[j].x - p[i].x;
			if(p[i].y > p[j].y) y = p[i].y - p[j].y;
			else y = p[j].y - p[i].y;
			ans = min(ans, x * x + y * y);
		}
	ans = sqrt(ans);
	printf("%.4lf", ans);
	return 0;
}