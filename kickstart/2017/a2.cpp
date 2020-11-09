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

string lo, sh, a,b;

void solve(){
    cin>>lo>>sh;
    ll los=lo.size(),shs=sh.size();
    ll n,m;
    if (los>=shs){
        a=lo; b=sh;
        n=los; m=shs;
    } else {
        a=sh; b=lo;
        n=shs; m=los;
    }
    ll i=0,j=0;
    ll count = 0;
    // cout << "tes" << endl;
    // cout << a << ' ' << b << endl;
    while(i<n && j<m){
        // cout << i << ' ' << j << ' ' << count << endl;

        if (a[i]=='*' && b[j]=='*'){
            i++;
            continue;
        }

        if (a[i] == b[j]){
            i++; j++;
            continue;
        }

        if (a[i]=='*' && b[j] != '*'){
            if (count < 3){
                j++; count++;
                continue;
            } else if (count == 3){
                count = 0;
                i++; j++;
            }
        } else if (a[i] != '*' && b[j] == '*' ){
            if (count < 3){
                i++; count++;
                continue;
            } else if (count == 3){
                count = 0;
                i++; j++;
            }
        } else if (a[i] != '*' && b[j]!= '*' && b[j]!=a[i]){
            cout << "FALSE" << endl;
            return;
        }
    }

    // cout << "afterward " << i << ' ' << j << endl;

    if (j==m && i==n) cout << "TRUE" << endl;
    else{
        if (i==n){
            bool pass = 1;
            for(ll jj=j; jj<m; jj++){
                if (b[jj]!='*') pass = 0;
            }
            if(pass) cout << "TRUE" << endl;
            else cout << "FALSE" << endl;
        } else if (j==m){
            bool pass = 1;
            for(ll ii=i; ii<n; ii++){
                // cout << a[ii] << ' ';
                if (a[ii]!='*'){
                    pass = 0;
                    // cout<<"goes here" << endl;
                }
            }
            if(pass) cout << "TRUE" << endl;
            else cout << "FALSE" << endl;
        }
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
