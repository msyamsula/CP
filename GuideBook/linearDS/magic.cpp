#include<bits/stdc++.h>
using namespace std;

#define _slen 1000
typedef vector<int> vi;
typedef vector<string> vs;

void solve(int n){
    vs ans(n);
    vi pos(n);
    for (int i=0; i<n; i++){
        pos[i]=i;
    }

    int ptr = -1;
    for(int i=0; i<n; i++){
        string card, name;
        scanf("%s %s", &card[0], &name[0]);
        card = card.c_str(); name = name.c_str();
        ptr+=name.size();
        ptr%=pos.size();
        // cout << ptr << ' ' << card << ' ' << name << endl;
        ans[pos[ptr]] = card;
        pos.erase(pos.begin()+ptr);
        ptr--;
        // for (int j=0; j<pos.size(); j++){
        //     cout << pos[j] << ' ';
        // } cout << endl;
    }

    for (int i=0; i<n; i++){
        cout << ans[i] << " \n"[i==n-1];
    }
}

int main(){
    int n;
    while(cin>>n){
        // cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        if (n == 0) break;
        solve(n);
    }
    return 0;
}