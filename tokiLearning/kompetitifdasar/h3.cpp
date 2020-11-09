#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<double, double> ii;
typedef pair<ii, double> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vector<iii> ppk;

bool comp(iii a, iii b){
    if(a.second != b.second){
        return a.second > b.second;
    } else if (a.first.second != b.first.second){
        return a.first.second > b.first.second;
    }

    return 0;
}

int main(){
    double n,x; cin>>n>>x;
    ppk.resize(0); ppk.resize(n);
    for(int i=0; i<n; i++){
        double wtemp; cin>>wtemp;
        ppk[i].first.second = wtemp;
    }

    for(int i=0; i<n; i++){
        double ctemp; cin>>ctemp;
        ppk[i].first.first = ctemp;
        ppk[i].second = ppk[i].first.first/ppk[i].first.second;
    }

    sort(ppk.begin(), ppk.end(), comp);

    double cost = 0;
    for(iii temp : ppk){
        double w = temp.first.second, p = temp.second;
        if (x>=w){
            cost += p*w;
            x -= w;
        } else if (x<w){
            cost += p*x;
            x -= x;
        }

        if (x==0){
            break;
        }
    }

    cout << fixed << setprecision(5) << cost << endl;
    return 0;
}
