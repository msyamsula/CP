#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;

void solve(int tc){
    int n,m,q;
    cin>>n>>m>>q;
    vi torn(n+1,0);
    for(int i=0; i<m; i++){
        int temp; cin>>temp;
        torn[temp] = 1;
    }

    vi page(n+1,0);
    for (int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            if (torn[j] == 1) continue;
            // cout << i << ' ' << j << endl;
            page[i]+=1;
        }
    }

    int sum_page = 0;
    for (int i=0; i<q; i++){
        int r; cin>>r;
        sum_page+=page[r];
    }

    // for(int i=0; i<n+1; i++){
    //     cout << page[i] << ' ';
    // }
    // cout << endl;

    cout << "Case #" << tc << ": " << sum_page << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}