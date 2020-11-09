#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef stack<char> sc;
typedef bitset<2000000> bs;
typedef vector<bs> vbs;

bs createLog(int start, int end){
    int s = 1<<start;
    int e = 1<<end;
    bs result = (e|s)|((e-1)^(s-1)); 
    return result;
}

void showvi(vbs a){
    vbs::iterator i;
    iter(a, i){
        cout << (*i) << endl;
    }
}

int main(){
    vi A = {1,4,5,8};
    vi B = {4,5,9,10};
    vi C = {4,6,7,10,2};

    int n = A.size();
    vbs log;
    f(i,0,n,1){
        log.push_back(createLog(A[i], B[i]));
    }

    // sort(log.begin(), log.end());

    showvi(log);

    int connectStat = 0;

    // f(i,0,s,1){

    // }

    return 0;
}