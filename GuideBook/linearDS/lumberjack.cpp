#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool comp(int i, int j){ return(j>1); }

void solve(){
    vi arr(10);
    for (int i=0; i<10; i++){
        cin >> arr[i];
    }

    vi asc = arr;
    vi dsc = arr;
    sort(arr.begin(), arr.end());
    if (arr == asc){
        cout << "Ordered" << endl;
        return;
    } else {
        sort(arr.begin(), arr.end(), comp);
        if (arr == dsc){
            cout << "Ordered" << endl;
            return;
        }
    }

    cout << "Unordered" << endl;
}

int main(){
    int tc; cin>>tc;
    cout << "Lumberjacks:" << endl;
    for (int i=0; i<tc; i++){
        solve();
    }
    return 0;
}