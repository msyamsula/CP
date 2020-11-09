#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<char, int> pci;
typedef priority_queue<pair<int, char>> pqi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)

void solve(int c){
    int n;
    scanf("%i", &n);
    pqi senat;
    f(i,0,n,1){
        int quan;
        scanf("%i", &quan);
        pci pair = {quan, char(i+65)};
        senat.push(pair);
    }

    vector<char> q;

    while(senat.size()>0){
        int s = senat.size();
        if (s == 1){
            q.push_back(senat.top().second);
            senat.pop();
            continue;
        }

        if (s > 1){
            q.push_back(senat.top().second);
            pci p = {senat.top().first-1, senat.top().second};
            senat.pop();
            if (p.first != 0){
                senat.push(p);
            }
        }
    }

    string s = "";
    vector<char>::iterator i;
    for(i=q.begin(); i!=q.end(); i++){
        int idx = i-q.begin();
        // cout << idx << endl;
        s += *i;
        if (i != q.end()){
            s += (idx%2==0) ? "":" ";
        }
    }

    printf("Case %c%i: %s\n", '#', c, s.c_str());
}

int main(){
    int TC;
    scanf("%i", &TC);
    f(tc,0,TC,1){
        solve(tc+1);
    }
    
}