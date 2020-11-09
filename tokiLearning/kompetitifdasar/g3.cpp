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

vi arr;

int main(){
    int n; cin>>n;
    arr.resize(0);
    for(int i=0; i<n; i++){
        int ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    sort(arr.begin(), arr.end());

    if (n%2==1){
        cout <<fixed << setprecision(1) << double(arr[(n-1)/2]) << endl;
    } else {
        int l = floor(double(n-1)/2);
        int u = ceil(double(n-1)/2);
        double ans = double(arr[l]) + double(arr[u]); ans /= 2;
        cout << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}
