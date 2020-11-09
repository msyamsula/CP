#include<bits/stdc++.h>
using namespace std;


void solve(int tc){
    int n; cin>>n;
    priority_queue<int> pq;
    for (int i=0; i<n; i++){
        int temp; cin>>temp;
        pq.push(temp);
    }

    cout << "Case " << tc << ": " << pq.top() << endl;
}

int main(){
    int tc; cin >>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}