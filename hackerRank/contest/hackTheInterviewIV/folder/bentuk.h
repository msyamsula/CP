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

class bentuk{
    public:
    ll area, perimeter,d1,d2;
    void carea(){
        area = d1*d2;
    }

    void cperimeter(){
        perimeter = (d1+d2)*2;
    }

    bentuk(ll x,ll y){
        d1=x; d2=y;
        carea(); cperimeter();
    }
};
