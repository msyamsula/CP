#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<vi, int, int> viii;
typedef map<viii, int> mviii;

int dp(vi cp, int l, int r, mviii &mem){
    viii key = make_tuple(cp,l,r);
    if (mem.find(key) != mem.end()){
        // cout << "memo" << endl;
        // for (int i=0; i<cp.size(); i++){
        //     cout << cp[i] << ' ' << endl;
        // }
        // cout << l << ' ' << r << endl;
        return mem.at(key);
    }

    cout << "calculation" << endl;
    if (cp.size() == 0) return mem[key] = 0;
    if (cp.size() == 1) return mem[key] = r-l;

    int min_energy = 1<<30;
    for(int i=0; i<cp.size()-1; i++){
        // int temp = cp[i];
        // cp.erase(cp.begin()+i);
        vi temp1(cp.begin(),cp.begin()+i);
        vi temp2(cp.begin()+i+1, cp.end());
        // for (int ii=0; ii<cp.size(); ii++){
        //     cout << cp[ii] << ' ';
        // } cout << endl;
        int energy = r-l + dp(temp1,l,cp[i], mem) + dp(temp2,cp[i],r, mem);
        min_energy = min(min_energy, energy);
        // cp.insert(cp.begin()+i, temp);
        // for (int ii=0; ii<cp.size(); ii++){
        //     cout << cp[ii] << ' ';
        // } cout << endl;
    }

    // cout << min_energy << endl;
    return mem[key] = min_energy;
}

int main(){
    int m, n;
    cin>>m>>n;
    vi cp(n);
    for(int i=0; i<n; i++){
        cin>>cp[i];
    }

    mviii mem;
    cout << dp(cp,0,m,mem) << endl;

    return 0;
}