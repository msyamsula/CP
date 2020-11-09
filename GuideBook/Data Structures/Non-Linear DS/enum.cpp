#include<bits/stdc++.h>
using namespace std;

typedef map<int, int> mii;
typedef vector<int> vi;
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)

void build(vi &tree, int p, int l, int r, vi data){
    if (l == r){
        tree[p] = data[l];
        return;
    } else {
        int mid = (l+r)/2;
        build(tree, 2*p, l, mid, data);
        build(tree, 2*p+1, mid+1,r, data);
    }

    tree[p] = (tree[2*p] > tree[2*p+1]) ? tree[2*p] : tree[2*p+1];
}

int main(){
    vi data = {3,2,4,1,5,6,7,8,3,3,91,-1,2,3,59};
    int sz = data.size();
    if ( (sz&(sz-1)) != 0){
        int p = 32 - __builtin_clz(sz);
        sz = 1<<p;
    }
    vi tree(4*(),0);
    build(tree,1,0,data.size()-1, data);
    cout << tree[1] << endl;
    // cout << sz << endl;

    return 0;
}