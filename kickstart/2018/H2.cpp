#include<bits/stdc++.h>
using namespace std;
#define MAXI pow(2,30)
#define MAXL pow(2,60)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

// vi tree;

// void buildTree(vi arr, int k, int x, int y){
//     if (x==y) tree[k] = arr[x];
//     else {
//         long mid = long(x)+long(y); mid/=2;
//         buildTree(arr, 2*k, x, mid);
//         buildTree(arr, 2*k+1, mid+1, y);
//         tree[k] = tree[2*k] + tree[2*k+1];
//     }
// }

// int maxSub(int k, int x, int y, int a, int b){
//     if (a<=x && y<=b) return tree[k];
//     else if (x>b || y<a) return 0;

//     long mid = long(x) + long(y); mid/=2;
//     return maxSub(2*k, x, mid, a, b) + maxSub(2*k+1, mid+1, y, a, b);

// }

void solve(){
    int n; cin>>n;
    string beauty; cin>>beauty;
    vi arr(n,0);
    vl psum(n+1,0);
    for(int i=0; i<beauty.size(); i++){
        char c = beauty[i];
        int num = int(c) - '0';
        arr[i] = num;
        psum[i+1] = long(psum[i]) + long(arr[i]);
    }

    int sz = (n+1)/2;
    long biggest = -MAXL;
    for(int i=0; i<=n-sz; i++){
        int si = i, ei = si+sz-1;
        biggest = max(biggest, psum[ei+1] - psum[si]);
    }

    cout << biggest << endl;

    // int sz = arr.size(); tree.resize(0);
    // tree.assign(4*sz, 0);
    // buildTree(arr, 1, 0, sz-1);

    // for(int num : tree){
    //     cout << num << ' ';
    // }
    // cout << endl;
    // cout << maxSub(1,0,sz-1,0,sz-1) << endl;
}


int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}