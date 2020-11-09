#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


void solve(int tc){
    int n,b; cin>>n>>b;
    vi price(n,0);
    for(int i=0; i<n; i++){
        cin>>price[i];
    }

    sort(price.begin(), price.end());

    int total = 0, i =0;
    for(int i=0; i<n; i++){
        if (price[i] <= b){
            total++;
            b-=price[i];
        }
    }

    cout << "Case #" << tc << ": " << total << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}