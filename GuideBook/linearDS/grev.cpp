#include<bits/stdc++.h>
using namespace std;


void solve(int num, string line){
    // string line;
    // getline(cin, line);
    // scanf("%s", &line[0]);
    // line = line.c_str();
    // cout << line << endl;
    string ans = line;
    int I = num, J = line.size()/num;
    // cout << num << ' ' << J << endl;
    for (int i=0; i<I; i++){
        for (int j=0; j<J; j++){
            int idx = i*J+j;
            int nj = J-j-1;
            int nidx = i*J+nj;
            // cout << idx << ' ' << nidx << endl;
            ans[nidx] = line[idx];
        }
    }

    cout << ans << endl;
}

int main(){
    int num; string line;
    while(true){
        cin >> num;
        if (num == 0) break;
        cin >> line;
        // line = line.c_str();
        // cout << num << ' ' << line.size() << endl;
        solve(num, line);
    }

}