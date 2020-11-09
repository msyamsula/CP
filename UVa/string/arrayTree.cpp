#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

vs arrayTree(string T){
    int n = T.size();
    vs suffix(n);
    for(int i=0; i<n; i++){
        suffix[i] = T.substr(i, n);
    }

    for(int i=0; i<n; i++){
        cout << suffix[i] << endl;
    }

    sort(suffix.begin(), suffix.end());

    return suffix;
}


int main(){
    string T = "GATAGACA$";

    vs at = arrayTree(T);

    cout << endl;

    for(int i=0; i<at.size(); i++){
        cout << at[i] << endl;
    }

    return 0;
}