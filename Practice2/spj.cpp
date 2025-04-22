#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, cnt;
int a[N*2][N], cp[N*2], b[N*2][N*2];
string nm[N*2], _nm;
map<string, int> mp;

bool check() {
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) if(i != j) {
			int man1 = i, man2 = j;
			int wom1 = cp[i], wom2 = cp[j];
			if(b[man1][wom1] > b[man1][wom2] && b[wom2][man2] > b[wom2][man1])
				return 1;
		}
	}
	return 0;
}

signed main() {
	// FILE*f1 = fopen("in.txt","rb");
	// if(!f1) return 1;
    // 创建一个ifstream对象用于读取文件
    std::ifstream inputFile;
    // 打开文件
    inputFile.open("in.txt");
    // 检查文件是否成功打开
    
    if (!inputFile.is_open()) {
        std::cerr << "in wrong" << std::endl;
        return 1;
    }
    
    std::string word;
    inputFile >> word;
    
    std::stringstream ss(word);
    ss >> n;
    // cin >> n;
    for(int i = 1; i <= n; i ++) {
        // cin >> _nm;
        inputFile >> _nm;
        nm[++cnt] = _nm;
        mp[_nm] = cnt;
    }
    for(int i = 1; i <= n; i ++) {
        // cin >> _nm;
        inputFile >> _nm;
        nm[++cnt] = _nm;
        mp[_nm] = cnt;
    }
    for(int i = 1; i <= cnt; i ++) cp[i] = -1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            // cin >> _nm;
            inputFile >> _nm;
            a[i][j] = mp[_nm];
            b[i][a[i][j]] = j;
        }
    }
    for(int i = n+1; i <= n*2; i ++) {
        for(int j = 1; j <= n; j ++) {
            // cin >> _nm;
            inputFile >> _nm;
            a[i][j] = mp[_nm];
            b[i][a[i][j]] = j;
        }
    }
    inputFile.close();
    
    inputFile.open("out.txt");
    if (!inputFile.is_open()) {
        std::cerr << "out wrong" << std::endl;
        return 2;
    }
    
    for(int i = 1; i <= n; i ++) {
		// cin >> _nm;
        inputFile >> _nm;
		int sl = mp[_nm];
        // cout << sl << " " << _nm << endl;
        inputFile >> _nm;
		cp[sl] = mp[_nm];
    }
    
    inputFile.close();

    // for(int i = 1; i <= n; i ++) {
    //     cout << nm[i] << " " << nm[i + n] << " " << i << " " << cp[i] << endl;
    // }
    
	if(check()) return 3;
    cout << "OK" << endl;
	return 0;
}