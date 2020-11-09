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

ll R,C;
vs grid;

void solve(){
    cin>>R>>C;
    grid.resize(0);
    for(ll i=0; i<R; i++){
        string temp; cin>>temp;
        grid.push_back(temp);
    }

    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            if (i%2 == 0 && (i+j)%2==0){
                grid[i][j] = '>';
            } else if (i%2 != 0 && (i+j)%2==0){
                grid[i][j] = '<';
            }
        }
    }

    for(string s:grid){
        cout << s << endl;
    }
}

int main(){
    solve();

    return 0;
}
