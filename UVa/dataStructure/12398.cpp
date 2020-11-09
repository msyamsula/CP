#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void push(int a){
    int R = mat.size(), C = mat[0].size();
    int r = a/C, c = a%C;
    mat[r][c] += 1; mat[r][c] %= 10;
    for(int i=0; i<4; i++){
        int nr = r+dy[i], nc = c+dx[i];
        if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
        mat[nr][nc] += 1; mat[nr][nc] %= 10;
    }
}

void solve(string s){
    mat.assign(3, vi(3,0));
    vi c(s.size(), 0);
    for(int i=0; i<s.size(); i++){
        int com = int(s[i]) - 97;
        c[i] = com;
    }

    for(int i=0; i<c.size(); i++){
        push(c[i]);
    }

    for(vi temp: mat){
        for(int i=0; i<temp.size(); i++){
            cout << temp[i] << " \n"[i==temp.size()-1];
        }
    }
}

int main(){
    string s;
    int i=0;
    while(getline(cin,s)){
        cout << "Case #" << i+1 << ':' << endl;;
        solve(s);
        i++;
    }

    return 0;
}