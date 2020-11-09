#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vs init;
vs fin;

void rotate90(){
    int n=init.size();
    vs temp(n, string(n,'.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = init[n-1-j][i];
        }
    }

    init = temp;
}

void verticalR(){
    int n=init.size();
    vs temp(n, string(n,'.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = init[n-1-i][j];
        }
    }
    init = temp;
}

void solve(int n, int tc){
    init.resize(0);
    fin.resize(0);
    for(int i=0; i<n;i++){
        string row1, row2; cin>>row1>>row2;
        init.push_back(row1);
        fin.push_back(row2);
    }

    // for(string a : init){
    //     cout << a << endl;
    // }
    // cout << endl;

    // for(string a : fin){
    //     cout << a << endl;
    // }
    // cout << endl;

    if (init == fin){
        cout << "Pattern " << tc << " was preserved." << endl;
        return;
    }

    rotate90();
    // for(string a : init){
    //     cout << a << endl;
    // }
    // cout << endl;
    if(init == fin){
        cout << "Pattern " << tc << " was rotated 90 degrees." << endl;
        return;
    }

    rotate90();
    if(init == fin){
        cout << "Pattern " << tc << " was rotated 180 degrees." << endl;
        return;
    }

    rotate90();
    if(init == fin){
        cout << "Pattern " << tc << " was rotated 270 degrees." << endl;
        return;
    }

    rotate90();
    verticalR();
    if(init == fin){
        cout << "Pattern " << tc << " was reflected vertically." << endl;
        return;
    }

    rotate90();
    if(init == fin){
        cout << "Pattern " << tc << " was reflected vertically and rotated 90 degrees." << endl;
        return;
    }

    rotate90();
    if(init == fin){
        cout << "Pattern " << tc << " was reflected vertically and rotated 180 degrees." << endl;
        return;
    }

    rotate90();
    if(init == fin){
        cout << "Pattern " << tc << " was reflected vertically and rotated 270 degrees." << endl;
        return;
    }

    cout << "Pattern " << tc << " was improperly transformed." << endl;

}

int main(){
    int n; 
    int tc=1;
    while(cin>>n){
        solve(n,tc);
        tc++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}