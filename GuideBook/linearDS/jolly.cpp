#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;

void solve(int n){
    // int n; cin >> n;
    vi arr;
    for (int i=0; i<n; i++){
        int temp; cin>>temp;
        // cout << temp << endl;
        arr.push_back(temp);
    }

    mii lmem;
    for (int i=1; i<n; i++){
        int d = (arr[i] > arr[i-1]) ? arr[i] - arr[i-1] : arr[i-1] - arr[i];
        lmem[d] = 1;
    }

    int sz = lmem.size();
    mii::iterator ii=lmem.begin();
    while(ii!=lmem.end()){
        int num = distance(lmem.begin(),ii);
        // cout << num+1 << ' ' << ii->first << endl;
        // int num = 0;
        if (num+1 != ii->first){
            cout << "Not jolly" << endl;
            return;
        }
        ii++;
    }

    if (sz == n-1 ) cout << "Jolly" << endl;
    else cout << "Not jolly" << endl;
}

int main(){
    int n;
    while(cin>>n){
        // cout << n << endl;
        solve(n);
    }
    return 0;
}