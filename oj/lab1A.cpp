#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int n, m, root, cnt = 0, vis[N], now_time;
struct item {
    string name, content;
    int type, father;
    vector<int> son;
    void del_node() {
        name = "";
        content = "";
        type = 0;
        father = 0;
        son.clear();
    }
} id[N];

int find_son(int node, string s, int tp) {
    for(int i = 0; i < id[node].son.size(); i ++) {
        int x = id[node].son[i];
        if(id[x].father != node) 
            id[node].son[i] = x = 0;
        if(x == 0) continue ;
        if(id[x].name == s && (tp == 0 || id[x].type == tp))
            return x;
    }
    return 0;
}

int new_node(int fa, int tp, string nm, string ct) {
    id[++cnt].father = fa;
    id[cnt].type = tp;
    id[cnt].name = nm;
    id[cnt].content = ct;
    id[fa].son.push_back(cnt);
    return cnt;
}

vector<string> splitPath(const string& path) {
    vector<string> parts;
    stringstream ss(path);
    string part;
    while (getline(ss, part, '/')) {
        if (!part.empty()) parts.push_back(part);
    }
    return parts;
}

void create_file(const string& path, string content) {
    vector<string> parts = splitPath(path);
    int pos = root, next_pos;
    string part;
    for(int i = 0; i < parts.size() - 1; i ++) {
        part = parts[i];
        if(part == ".") {
            // assert(0);
            continue ;
        }
        if(part == "..") {
            // assert(0);
            pos = id[pos].father;
            continue ;
        }
        next_pos = find_son(pos, part, 1);
        if(!next_pos) {
            next_pos = new_node(pos, 1, part, "");
        }
        pos = next_pos;
    }
    part = parts[parts.size()-1];
    next_pos = new_node(pos, 2, part, content);
}

void create_folder(const string& path) {
    vector<string> parts = splitPath(path);
    int pos = root, next_pos;
    string part;
    for(int i = 0; i < parts.size(); i ++) {
        part = parts[i];
        if(part == ".") {
            // assert(0);
            continue ;
        }
        if(part == "..") {
            // assert(0);
            pos = id[pos].father;
            continue ;
        }
        next_pos = find_son(pos, part, 1);
        if(!next_pos) {
            next_pos = new_node(pos, 1, part, "");
        }
        pos = next_pos;
    }
}

int get_node(const string& path, int tp = 0) {
    vector<string> parts = splitPath(path);
    if(parts.empty()) return root;
    int pos = root, next_pos;
    string part;
    for(int i = 0; i < parts.size(); i ++) {
        part = parts[i];
        // cout << part << " " << pos << endl;
        if(part == ".") {
            continue ;
        }
        if(part == "..") {
            pos = id[pos].father;
            continue ;
        }
        next_pos = find_son(pos, part, i == parts.size()-1 ? tp : 1);
        if(!next_pos) return 0; 
        pos = next_pos;
    }
    return pos;
}

void remove(const string& path) {
    int pos = get_node(path);
    id[pos].del_node();
}

void move(const string& src, const string& dst) {
    int src_pos = get_node(src), dst_pos = get_node(dst);
    id[src_pos].father = dst_pos;
    id[dst_pos].son.push_back(src_pos);
}

void cat(const string& path) {
    int pos = get_node(path, 2);
    if(pos && id[pos].type == 2)
        cout << id[pos].content << endl;
    else cout << endl;
}

void find_all_paths(int node, vector<int>& paths) {
    // cout << currentPath << endl;
    paths.push_back(node);
    for(int i = 0; i < id[node].son.size(); i ++) {
        int x = id[node].son[i];
        if(id[x].father != node)
            id[node].son[i] = x = 0;
        if(x == 0) continue ;
        // cout << i <<        " father : " << node << " son : " << x << endl;
        find_all_paths(x, paths);
    }
}

string sub_path(int op, int ed) {
    string path = "";
    while(op != ed) {
        path = "/" + id[ed].name + path; 
        ed = id[ed].father;
    }
    return path;
}

void find(const string& path, const string& name, const string& type) {
    // cout << path + " " + name + " " + type << endl;
    int pos = get_node(path), op;
    // cout << pos << endl;
    op = pos;
    vector<int> paths;
    find_all_paths(pos, paths);
    vector<int> result;
    for (int i = 0; i < paths.size(); i ++) {
        pos = paths[i];
        if(pos && (type == "" || (type == "f" && id[pos].type == 2) || (type == "d" && id[pos].type == 1)) 
          && (name == "" || id[pos].name == name)) {
            if(vis[pos] == now_time) continue ;
            vis[pos] = now_time;
            result.push_back(pos);

          }
    }
    sort(result.begin(), result.end());
    unique(result.begin(), result.end()) - result.size();
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i ++) {
        pos = result[i];
        cout << path + sub_path(op, pos) << endl;
    }
}

signed main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    string line;
    root = ++cnt;
    id[cnt].father = 1;
    id[cnt].type = 1;
    id[cnt].name = ".";
    id[cnt].content = "";
    getline(cin, line);

    for (int i = 0; i < n; i ++) {
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;
        if (command == "echo") {
            string content, path;
            ss >> content;
            if(content == ">") content = ""; 
            else ss >> path; 
            ss >> path;
            create_file(path, content);
        } else if (command == "mkdir") {
            string path;
            ss >> path;
            create_folder(path);
        } else if (command == "rm") {
            string path;
            ss >> path;
            if (path == "-rf") {
                ss >> path;
                remove(path);
            } else {
                remove(path);
            }
        } else if (command == "mv") {
            // assert(0);
            string src, dst;
            ss >> src >> dst;
            move(src, dst);
        }
    }
    for (int i = 0; i < m; i ++) {
        now_time = i+1;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;
        if (command == "cat") {
            string path;
            ss >> path;
            cat(path);
        } else if (command == "find") {
                // assert(0);
            string path = "", name = "", type = "";
            string expr;
            ss >> expr;
            if(expr != "") {
                if(expr[0] != '-') {
                    path = expr;
                    ss >> expr;
                }
                if(expr[0] == '-') {
                    if(expr == "-name") {
                        ss >> name;
                    }
                    else {
                        ss >> type;
                    }
                    ss >> expr;
                }
                if(expr[0] == '-') {
                    if(expr == "-name") {
                        ss >> name;
                    }
                    else {
                        ss >> type;
                    }
                    ss >> expr;
                }
            }
            find(path, name, type);
        }
    }
    return 0;
}