#include<bits/stdc++.h>
// #include<vector>
// #include<iostream>
using namespace std;

typedef vector<int> vi;

void solve(int tc){
    int n, q;
    cin>>n>>q;
    vi arr(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        // int temp; cin>>temp;
        // pxor[i+1] = pxor[i]^temp;
    }

    vi pxor(n+1,0);
    int carry = 0;
    cout << "Case #" << tc << ":";
    for (int i=0; i<q; i++){
        int idx; int num;
        cin>>idx>>arr[idx];
        for (int ii=0; ii<n; ii++){
            pxor[ii+1] = pxor[ii]^arr[ii];
        }
        // int cnum = pxor[idx+1]^pxor[idx];
        // carry ^= cnum^num;
        int m = 0;
        for (int s=0; s<n; s++){
            for (int e=s; e<n; e++){
                int tot = e-s+1;
                int xorsum = pxor[e+1]^pxor[s];
                if (__builtin_popcount(xorsum)%2 == 0 && tot > m && xorsum != 0){
                    m = tot;
                }
            }
        }
        cout << ' ' << m;
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}