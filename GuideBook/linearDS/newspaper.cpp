#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;

void solve(){
    int k; cin>>k;
    mci mem;
    for (int i=0; i<k; i++){
        char ct; int p;
        cin>>ct; cin>>p;
        mem[ct] = p;
    }
    int m; cin>>m;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    string line;
    double argo = 0;
    for(int i=0; i<m; i++){
        getline(cin, line);
        int idx = 0;
        // cout << "tes" << endl;
        while(line[idx] != '\0'){
            // cout << line[idx];
            try{
                argo += mem.at(line[idx]);
            }catch (const exception &e){}

            idx++;
        }
    }

    cout << fixed;
    cout << setprecision(2) << argo/100 << '$' << endl;
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve();
    }

    return 0;
}