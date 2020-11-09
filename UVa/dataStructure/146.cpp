#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

void solve(string line){
    if (next_permutation(line.begin(), line.end())){
        cout << line << endl;
    } else {
        cout << "No Successor" << endl;
    }
}

int main(){
    string line;
    while(cin>>line){
        if (line == "#") break;
        solve(line);
    }

    return 0;
}