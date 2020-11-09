#include<bits/stdc++.h>
using namespace std;

typedef vector<long> vi;

int main(){
    int n,q; cin>>n>>q;
    vi fmin(n), fmul(n);
    cin >> fmin[0];
    cin>>fmin[0];
    fmul[0] = fmin[0];
    for(int i=1; i<n; i++){
        cin>>fmin[i];
        fmul[i] = fmul[i-1]*(fmin[i]-fmin[i-1]);
    }

    vi rmin(n), rmul(n);
    cin >> rmin[0];
    cin>>rmin[0];
    rmul[0] = rmin[0];
    for(int i=1; i<n; i++){
        cin>>rmin[i];
        rmul[i] = rmul[i-1]*(rmin[i]-rmin[i-1]);
    }

    for(int i=0; i<q; i++){
        int l,r; cin>>l>>r;
        bool fs = (fmul[r]/fmul[l] > 0) ? 1 : 0;
        bool rs = (rmul[l]/rmul[r] > 0) ? 1 : 0;

        if (fs || rs){
            cout << 0 << endl;
            return 0;
        }
    }

    return 0;
}