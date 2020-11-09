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

int lte(int a, int b, int bound){
    if (b<a) return -1;
    int mid = (a+b+1)/2;
    if (a==b && (arr[mid]<=bound)) return mid;
    if (arr[mid] > bound) return lte(a,mid-1,bound);
    return lte(mid,b,bound);
}

int gt(int a, int b, int bound){
    if (b<a) return -1;
    int mid = (a+b)/2;
    // cout << mid << endl;
    if (a==b && (arr[mid] > bound)) return mid;
    if (arr[mid] <= bound) return gt(mid+1,b,bound);
    return gt(a,mid,bound);
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    int q;cin>>q;
    for(int i=0; i<q; i++){
        int x,y; cin>>x>>y;
        int u = lte(0,arr.size()-1,y);
        int l = gt(0, arr.size()-1,x);
        // cout << u << ' ' << l << endl;
        if (u == -1 || l == -1){
            cout << 0 << endl;
            continue;
        }
        cout << u+1-l << endl;
    }

    return 0;
}
