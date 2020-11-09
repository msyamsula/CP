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

deque<int> arr;

int main(){
    int n;cin>>n;
    arr.resize(0);
    for(int i=0; i<n; i++){
        string c; cin>>c;
        if (c == "push_back"){
            int ntemp; cin>>ntemp;
            arr.push_back(ntemp);
        } else if (c == "push_front"){
            int ntemp; cin>>ntemp;
            arr.push_front(ntemp);
        } else if (c == "pop_back"){
            arr.pop_back();
        } else {
            arr.pop_front();
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}
