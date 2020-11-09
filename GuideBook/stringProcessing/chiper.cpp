#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define _slen 1000

void solve(int n){
    // cout << n << endl;
    vi enc(n, 0), pos(n,0);
    for (int i=0; i<n; i++){
        scanf("%i", &enc[i]);
        pos[i] = i+1;
    }

    vvi evol;
    evol.push_back(pos);
    evol.push_back(enc);
    // int cyc = 0;
    while(true){
        // cout << "a" << endl;
        vi temp(n,0), lpos = evol[(evol.size()-1)];
        for(int i=0; i<n; i++){
            // cout << i << ' ' << enc[lpos[i]-1] << endl;
            temp[i] = enc[lpos[i]-1];
        }
        if( temp == evol[0] ) break;
        // if (cyc == 4) break;
        evol.push_back(temp);
        // cyc++;
    }

    // vvi::iterator i=evol.begin();
    // while(i!=evol.end()){
    //     vi::iterator ii=i->begin();
    //     while(ii!=i->end()){
    //         cout << *ii <<' ';
    //         ii++;
    //     } cout << endl;
    //     i++;
    // }

    while(true){
        int k;
        scanf("%i", &k);
        if (k==0) break;
        
        string s;
        getline(cin, s);
        s = s.substr(1,s.size());
        // cout << k << endl;
        // cout << s << endl;
        int mod = k%(evol.size());
        vi usage = evol[mod];

        string ans;
        for (int i=0; i<n; i++){
            int idx = usage[i]-1;
            if (isalpha(s[i]) || s[i] == ' '){
                ans[idx] = s[i];
            } else {
                ans[idx] = ' ';
            }
        }

        printf("%s\n", ans.c_str());
    }
}

int main(){
    int n;
    scanf("%i", &n);
    int i=0;
    while(true){
        // cout << n << endl;
        if (n==0) break;
        if (i!=0) cout << endl;
        solve(n);
        scanf("%i", &n);
        i++;
    }

    return 0;
}