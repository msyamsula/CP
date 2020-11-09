#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef map<char, char> mcc;
typedef map<string, int> msi;
mcc mem;

void solve(){
    int n; cin>>n;
    msi lmem;
    for (int i=0; i<n; i++){
        string no; cin>>no;
        string ans = "";
        int idx=0;
        while(no[idx] != '\0'){
            // cout << no[idx] << endl;
            if(no[idx]=='-'){
                idx++;
                continue;
            }
            // cout << no[idx] << ' ' << mem[no[idx]] << endl;
            ans+=mem[no[idx]];
            idx++;
        }
        // cout << ans << endl;
        lmem[ans]+=1;
    }

    msi::iterator ii=lmem.begin();
    bool dup = 0;
    while(ii!=lmem.end()){
        // cout << ii->first << ' ' << ii->second << endl;
        if (ii->second == 1){
            ii++;
            continue;
        }
        dup = 1;
        string c = ii->first;
        string formal = c.substr(0,3)+"-"+c.substr(3,c.size());
        cout << formal << ' ' << ii->second << endl;
        ii++;
    }

    if (!dup) cout << "No duplicates." << endl;

}

int main(){
    vs alp = {
        "0000",
        "1111",
        "ABC2",
        "DEF3",
        "GHI4",
        "JKL5",
        "MNO6",
        "PRS7",
        "TUV8",
        "WXY9"
    };

    for (int i=0; i<alp.size(); i++){
        for (int j=0; j<4; j++){
            mem[alp[i][j]] = char(i+48);
        }
    }

    // mcc::iterator ii=mem.begin();
    // while(ii!=mem.end()){
    //     cout << ii->first << ' ' << ii->second << endl;
    //     ii++;
    // }

    int n; cin>>n;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    for(int i=0; i<n; i++){
        if (i!=0) cout << endl;
        string blank; 
        getline(cin, blank);
        // cout << "aaa " << n << ' ' << blank << endl;
        solve();
    }

    return 0;
}