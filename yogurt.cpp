#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef queue<int> qi;

void solve(int tc){
    int n,k; cin>>n>>k;
    vi yogurt(n);
    for(int i=0; i<n; i++){
        cin>>yogurt[i];
    }

    sort(yogurt.begin(), yogurt.end());
    qi q;
    for(int i=0; i<k; i++){
        q.push(yogurt[i]);
    }

    int maxDays = ceil(double(n)/k);
    for(int day=0; day<=maxDays; day++){

    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}