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

ll R,C,K;
vvl grid;

struct node{
    ll max, min;
};

class segment_tree{
public:
    vector<node> st;
    vl arr;
    segment_tree(){}

    void show_max(){
        for(node temp : st){
            cout << temp.max << ' ';
        }
        cout << endl;
    }

    void show_min(){
        for(node temp : st){
            cout << temp.min << ' ';
        }
        cout << endl;
    }

    void build(vl a){
        arr = a;
        ll n = arr.size();
        st.resize(0); st.resize(4*n);
        build(1, 0, n-1);
    }

    ll rmq_min(ll x, ll y){
        return rmq_min(1,0,arr.size()-1, x, y);
    }

    ll rmq_max(ll x, ll y){
        return rmq_max(1,0,arr.size()-1, x, y);
    }

private:
    void build(ll p, ll a, ll b){
        if (a==b){
            st[p].min = arr[a];
            st[p].max = arr[a];
            return;
        }

        ll mid = (a+b)/2;
        build(2*p, a, mid); build(2*p+1, mid+1, b);
        st[p].min = min(st[2*p].min, st[2*p+1].min);
        st[p].max = max(st[2*p].max, st[2*p+1].max);
    }

    ll rmq_min(ll p, ll a, ll b, ll x, ll y){
        if (b<x || a>y) return MAXLL;
        if (x<=a && b<=y) return st[p].min;

        ll mid = (a+b)/2;
        ll left = rmq_min(2*p, a, mid, x, y), right = rmq_min(2*p+1, mid+1, b, x, y);
        return min(left, right);
    }

    ll rmq_max(ll p, ll a, ll b, ll x, ll y){
        if (b<x || a>y) return -MAXLL;
        if (x<=a && b<=y) return st[p].max;

        ll mid = (a+b)/2;
        ll left = rmq_max(2*p, a, mid, x, y), right = rmq_max(2*p+1, mid+1, b, x, y);
        return max(left, right);
    }
};

vector<segment_tree> my_st;


void solve(){
    cin>>R>>C>>K;
    grid.resize(0); grid.assign(R, vl(C, 0));
    my_st.resize(0); my_st.resize(R);
    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            cin>>grid[i][j];
        }
        my_st[i].build(grid[i]);
        // my_st[i].show_max();
        // my_st[i].show_min();
    }

    ll ans = 0;

    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            for(ll ii=i; ii<R; ii++){
                for(ll jj=j; jj<C; jj++){
                    bool pass = 1;
                    for (ll r=i; r<=ii; r++){
                        ll gap = my_st[r].rmq_max(j,jj) - my_st[r].rmq_min(j,jj);
                        if (gap > K){
                            pass = 0;
                            break;
                        }
                    }

                    if (pass){
                        // cout << i << ' ' << j << endl;
                        // cout << ii << ' ' << jj << endl;
                        ans = max(ans, (jj-j+1)*(ii-i+1));
                        // cout << endl;
                    }
                }
            }
        }
    }

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
