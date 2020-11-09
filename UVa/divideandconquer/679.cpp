#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

struct node{
    bool flag;
    bool isTerminal;
    ll no,level;
    node *left,*right;
    node(){
        isTerminal = flag = 0;
        left = right = 0;
        no = level = 0;
    }
};

class Tree{
    node *root;
    ll depth;
public:
    Tree(ll d){
        depth = d;
        root = build(depth);
    }

    node * build(ll p, node *ptr, ll d){
        if (d==depth) return 0;
        ptr = new node;
        ptr->no = p;
        ptr->level = d;
        if (d+1 == depth) ptr->isTerminal = 1;
        ptr->left = build(2*p, ptr->left, d+1);
        ptr->right = build(2*p+1, ptr->right, d+1);

        return ptr;
    }

    node * build(ll d){
        return build(1,root,0);
    }


    ll insert(node *ptr){
        // cout << "no: " << ptr->no << endl;
        if (ptr->isTerminal) return ptr->no;

        ptr->flag = !(ptr->flag);
        if (ptr->flag){
            return insert(ptr->left);
        }

        return insert(ptr->right);
    }

    ll insert(){
        return insert(root);
    }
};

ll h,n;

void solve(){
    cin>>h>>n;
    Tree t(h);
    ll ans;
    for(ll i=0; i<n; i++){
        ans = t.insert();
    }
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
