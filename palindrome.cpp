#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;
typedef vector<mci> vmci;

void solve(int tc){
    int n; cin>>n;
    int q; cin>>q;
    string line; cin>>line;
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vmci vmem(n+1);
    // for (int i=0; i<alp.size(); i++){
    //     vmem[0][alp[i]] = 0;
    // }

    for (int i=0; i<n; i++){
        vmem[i+1] = vmem[i];
        vmem[i+1][line[i]] = vmem[i][line[i]] + 1;
    }

    // vmci::iterator it=vmem.begin();
    // while(it!=vmem.end()){
    //     mci::iterator iti=it->begin();
    //     while(iti!=it->end()){
    //         cout << iti->first << ' ' << iti->second <<endl;
    //         iti++;
    //     } cout << endl;
    //     it++;
    // }

    int yc = 0;
    for (int i=0; i<q; i++){
        int s; cin>>s;
        int e; cin>>e;
        int is = s-1, ie = e-1;
        // mci temp = vmem[ie+1] - vmem[is];
        mci temp;
        for (int i=0; i<26; i++){
            temp[alp[i]] = vmem[ie+1][alp[i]] - vmem[is][alp[i]];
            // cout << alp[i] << ' ' << temp[alp[i]] << endl;
        }


        int ol = ((ie-is+1)%2 == 0) ? 0 : 1;
        int oc = 0;
        // cout << ol << endl;
        mci::iterator ii=temp.begin();
        while(ii!=temp.end()){
            if (ii->second == 0){
                ii++;
                continue;
            }

            if (ii->second%2 != 0) oc++;
            if (oc > ol) break;
            ii++;
        }
        
        // cout << ol << ' ' << oc << endl;
        if (oc == ol){ 
            yc++;
            // cout << s << ' ' << e << endl;
        }
    }

    cout << "Case #" << tc << ": " << yc << endl;
    
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}