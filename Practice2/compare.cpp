#include <bits/stdc++.h>
using namespace std;
signed main() {
    int s;
    
    double st = clock();
    system("practice2.exe");
    double ed = clock();
    
    if((s = system("spj.exe"))) {
        printf("Wa %d \n", s);
    }
    else printf("AC time : %.3lfs\n", (ed - st) / 1000);
    return 0;
}