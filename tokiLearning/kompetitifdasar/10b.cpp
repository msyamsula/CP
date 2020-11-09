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

priority_queue<int> pq;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int c; cin>>c;
        if (c == 1){
            int x; cin>>x;
            pq.push(x);
        } else if (c==2){
            cout << pq.top() << endl;
        } else {
            pq.pop();
        }
    }
    return 0;
}
