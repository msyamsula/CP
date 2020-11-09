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

deque<ll> arr;
ll offset;

int main(){
    arr.resize(0); offset=0;
    ll n; cin>>n;
    for(ll i=0; i<n; i++){
        string c; cin>>c;
        if(c=="add"){
            ll x,y; cin>>x>>y;
            for(ll j=0; j<y; j++){
                arr.push_back(x);
            }
            cout << arr.size() << endl;
        } else if (c=="del"){
            ll y; cin>>y;
            if (arr.empty()){
                cout << endl;
                continue;
            }
            cout << (*arr.rbegin())+offset << endl;
            for(ll j=0; j<y; j++){
                if (arr.empty()) break;
                arr.pop_back();
            }
        } else if (c=="adx"){
            ll ntemp; cin>>ntemp;
            offset += ntemp;
        } else if (c=="dex"){
            ll ntemp; cin>>ntemp;
            offset -= ntemp;
        }
    }
    return 0;
}
