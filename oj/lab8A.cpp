#include <bits/stdc++.h>

using namespace std;

typedef double lf;
const int N = 1<<18;
const lf pi = acos(-1);
int n, m, L, R[N];
struct Complex {
    lf a, b; // a + bi;
    Complex(lf a = 0, lf b = 0) : a(a), b(b) {}
    lf len() { return sqrt(a * a + b * b); }
} f[N], w[N];
Complex operator-(Complex x, Complex y) { return Complex(x.a - y.a, x.b - y.b); }
Complex operator+(Complex x, Complex y) { return Complex(x.a + y.a, x.b + y.b); }
Complex operator*(Complex x, Complex y) { return Complex(x.a*y.a - x.b*y.b, x.a*y.b + x.b*y.a); }


void FFT(Complex *a, int f) {
	for(int i = 0; i < L; i++)
		if(i < R[i]) swap(a[i], a[R[i]]);
	w[0].a = 1;
	for(int len = 2; len <= L; len <<= 1) {
        Complex wn = Complex(cos(pi*2/len), f*sin(pi*2/len));
		for(int i = 1; i < (len >> 1); ++i)
			w[i] = w[i-1]*wn;
		for(int st = 0; st < L; st += len)
			for(int k = 0; k < (len>>1); k++) {
				Complex x = a[st+k], y = w[k] *a[st+k+(len>>1)];
				a[st+k] = x + y;
				a[st+k+(len>>1)] = x - y;
			}
	}
}

signed main() {
    cin >> n;
    L = 1 << n;
	for(int i = 0; i < L; i++) cin >> f[i].a;
	for(int i = 0; i < L; i++)
		R[i] = (R[i>>1]>>1) | ((i&1) << (n-1));
	FFT(f, 1);
	for(int i = 0; i < L; i++)
        printf("%.10lf\n", f[i].len());
	return 0;
}