#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vl;
typedef vector<vl> vvl;
#define onenine 1000000000

long Mup, Mright, Mdown, Mleft;

void move(char c, long &v1, long &v2, long &v3, long &v4){
    if (c == 'N'){
        v1++;
    } else if (c == 'E'){
        v2++;
    } else if (c == 'S'){
        v3++;
    } else if (c == 'W'){
        v4++;
    }

    v1 %= onenine;
    v2 %= onenine;
    v3 %= onenine;
    v4 %= onenine;
}

tuple<long, long, long, long, long> recurseMove(long m, long i, string line){
    tuple<long, long, long, long, long> ans = {0,0,0,0,0};
    // cout << m << endl;
    while(line[i] != ')'){
        // cout << line[i] << ' ';
        if (line[i] == 'N'){
            get<0>(ans)++;
        } else if (line[i] == 'E'){
            get<1>(ans)++;
        } else if (line[i] == 'S'){
            get<2>(ans)++;
        } else if (line[i] == 'W'){
            get<3>(ans)++;
        } else if (isdigit(line[i])){
            long m = long(line[i]) - '0';
            tuple<long,long,long,long,long> temp = recurseMove(m, i+2, line);
            get<0>(ans) += get<0>(temp);
            get<1>(ans) += get<1>(temp);
            get<2>(ans) += get<2>(temp);
            get<3>(ans) += get<3>(temp);
            i = get<4>(temp);
        }
        i++;
    }
    // cout << endl;
    get<0>(ans) *= m;
    get<1>(ans) *= m;
    get<2>(ans) *= m;
    get<3>(ans) *= m;
    get<0>(ans) %=onenine;
    get<1>(ans) %=onenine;
    get<2>(ans) %=onenine;
    get<3>(ans) %=onenine;
    get<4>(ans) = i;

    return ans;
}

void solve(int tc){
    long ans = 0;
    Mright = Mdown = Mup = Mleft = 0;
    string line; cin>>line;
    for(int i=0; i<line.size(); i++){
        if (isalpha(line[i])){
            move(line[i], Mup, Mright, Mdown, Mleft);
        } else if (isdigit(line[i])){
            long m = long(line[i]) - '0';
            tuple<long, long, long, long, long> temp = recurseMove(m, i+2, line);
            Mup += get<0>(temp);
            Mright += get<1>(temp);
            Mdown += get<2>(temp);
            Mleft += get<3>(temp);
            i = get<4>(temp);
            // cout << get<0>(temp) << ' ' << get<1>(temp) << endl;
        } else {
            continue;
        }
    }

    Mup %= onenine;
    Mright %= onenine;
    Mdown %= onenine;
    Mleft %= onenine;

    long i = 1+Mdown-Mup;
    long j = 1+Mright-Mleft;
    // cout << i << ' ' << j << endl;

    if (i <= 0){
        i = onenine + i;
    } else if (i>onenine){
        i %= onenine;
    }

    if (j <= 0){
        j = onenine + j;
    } else if (j>onenine){
        j %= onenine;
    }

    cout << "Case #" << tc << ": " << j << ' ' << i << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0;i<tc; i++){
        solve(i+1);
    }

    return 0;
}