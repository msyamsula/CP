#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vi streets;
vi avenues;

void solve(){
    streets.resize(0); avenues.resize(0);
    int s, a, f; cin>>s>>a>>f;
    // long double sums=0, suma=0;
    for(int i=0; i<f; i++){
        int r,c; cin>>r>>c;
        streets.push_back(r); avenues.push_back(c);
        // friends.push_back({r,c});
        // sums += r;
        // suma += c;
    }
    sort(streets.begin(), streets.end());
    sort(avenues.begin(), avenues.end());
    int mid = (f-1)/2;
    cout << "(Street: " << streets[mid] << ", Avenue: " << avenues[mid] << ')' << endl;

    // cout << streets[mid] << ' ' << avenues[mid] << endl;

    // long double locy = sums/f, locx=suma/f;
    // cout << sums/f << ' ' << suma/f << endl;
    // vii loc={
    //     {floor(locy), floor(locx)},
    //     {ceil(locy), floor(locx)},
    //     {floor(locy), ceil(locx)},
    //     {ceil(locy), ceil(locx)}
    // };

    // for(ii temp : loc){
    //     cout << temp.first << ' ' << temp.second << endl;
    // }

    // long long mind = MAXLL;
    // int choice, i=0;;
    // // cout << "tes" << endl;
    // for(ii temp : loc){
    //     int y = temp.first, x = temp.second;
    //     long long d = 0;
    //     for(ii fr : friends){
    //         d += abs(y-fr.first) + abs(x-fr.second);
    //     }
    //     if (d < mind){
    //         choice = i;
    //         mind = d;
    //     }
    //     // cout << i << ' ' << mind << endl;
    //     i++;
    // }

    // cout << mind << ' ' << choice << endl;
    // cout << "choice " << choice << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}