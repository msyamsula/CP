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

ll n;

void solve(){
    cin>>n;
    vector<double> student;
    double total=0;
    for(ll i=0; i<n; i++){
        double temp; cin>>temp;
        student.push_back(temp);
        total += temp;
    }

    double avg = total/n;
    double above = 0;
    for(ll i=0; i<n; i++){
        if (student[i] > avg) above++;
    }

    double percent = double(above*100)/n;
    cout << fixed << setprecision(3) << percent << '%' << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
