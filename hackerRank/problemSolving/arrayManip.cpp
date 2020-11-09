#include <bits/stdc++.h>

using namespace std;
typedef map<string, int> msi;
typedef vector<int> vi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)

void show(vi a){
    int s = a.size();
    f(i,0,s,1){
        cout << a[i] << " \n"[i==s-1];
    }
}

vi createTree(vi &arr){
    int s = arr.size();
    // vi arr = a;
    vi tree;
    int lz = __builtin_clz(s);
    int p = 32-lz;
    int base_size = 1<<p;
    int tree_size = base_size<<1;
    tree.resize(tree_size);
    tree[0] = 0;
    while(arr.size() < base_size){
        arr.push_back(0);
    }

    f(i,0,s,1){
        tree[i+base_size] = arr[i];
    }

    for (int i=base_size-1; i>0; i--){
        // show(arr);
        // show(tree);
        int c1 = i*2;
        int c2 = (i*2)+1;
        tree[i] = (tree[c1] > tree[c2]) ? tree[c1] : tree[c2];
        // cout << i << ' ' << tree[i] << ' ' << tree[c1] << ' ' << tree[c2] << endl;
    }

    return tree;
}

void add(vi &arr, vi &tree, int idx, int plus){
    arr[idx] += plus;
    idx += arr.size();
    tree[idx] += plus;
    int idx2 = (idx%2==0) ? idx+1 : idx-1;
    int v1 = tree[idx];
    int v2 = tree[idx2];
    while(v1 > v2 && idx2>0 && idx>0){
        // cout << idx << endl;
        // cout << tree[idx] << endl;
        idx /= 2;
        tree[idx] = v1;
        v1 = tree[idx];
        idx2 = (idx%2==0) ? idx+1 : idx-1;
        v2 = tree[idx2];
    }

    // show(tree);
}



int main(){
    int N=5;
    // int arr[] = {1, 4, 3, 2, 5};
    // vi arr;
    // arr.resize(10);
    // arr={0};
    // vi tree = createTree(arr);
    // show(tree);
    // show(arr);
    // add(arr,tree,3,1);
    // show(arr);
    // show(tree);

    int n, m;
    scanf("%i %i", &n, &m);
    vi arr;
    f(i,0,n,1){
        arr.push_back(0);
    }
    vi tree = createTree(arr);

    f(q,0,m,1){
        int a,b,k;
        scanf("%i %i %i", &a, &b, &k);
        f(i,a-1,b,1){
            // cout << i << endl;
            add(arr, tree, i, k);
        }
    }

    cout << tree[1] << endl;


    return 0;
}