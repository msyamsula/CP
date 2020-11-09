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

ll N;

struct node{
    bool end;
    vector<node*> child;
    ll passCount;
    ll depth;
    node(){
        end = 0; child.assign(26, 0); passCount=0;
        depth = 0;
    }
};

class Trie{
    public:
    node root; node *ptr;
    Trie(){
        ptr=&root;
    }

    void insert(string a){
        ptr = &root;
        root.passCount++;
        for(char temp : a){
            ll idx = temp - 65;
            if (ptr->child[idx] == 0){
                ptr->child[idx] = new node;
            }
            ptr->child[idx]->depth = ptr->depth+1;
            ptr = ptr->child[idx];
            ptr->passCount++;
        }
        ptr->end = 1;
    }

    ll count(node *cptr, ll sz, ll give){
        ll ans = 0;
        for(node *p : cptr->child){
            if (p == 0) continue;
            if (p->passCount >= sz){
                ll m= p->passCount/sz;
                give -= m*sz;
                ans += count(p, sz, m*sz);
            }
        }

        if (give >= sz) ans += (cptr->depth)*give/sz;

        return ans;
    }
};


void solve(){
    ll n,k; cin>>n>>k;
    N = n;
    Trie T;
    for (ll i=0; i<n; i++){
        string temp; cin>>temp;
        T.insert(temp);
    }

    ll ans = T.count(&T.root, k, n);
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
