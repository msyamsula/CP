#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef vector<string > vs;
typedef vector< vector<int> > vvi;
typedef map<string, string> mss;
typedef pair<string, string> pss;
typedef stack<pair<string, string>> spss;
typedef map< string, vector<int> > msvi;


int main(){
    // ifstream file;
    // file.open("./test.txt");
    int N, R;
    scanf("%i %i", &N, &R);
    // vs name;
    vi L, U;
    msvi constant;
    f(i,0,N,1){
        char n[10];
        scanf("%s", n);
        // cout << n << endl;
        // name.push_back(n);
        int B, C, D;
        int sumCL = 0;
        scanf("%i %i %i", &B, &C, &D);
        L.resize(D+1);
        U.resize(D+1);
        f(d,1,D+1,1){
            int l, u;
            scanf("%i %i", &l, &u);
            L[d] = l;
            U[d] = u;
        }

        vi temp(D+1);
        for(int ii = D; ii>0; ii--){
            if (ii == D){
                temp[ii] = C;
                sumCL += temp[ii]*L[ii];
                continue;
            }

            temp[ii] = temp[ii+1]*(U[ii+1]-L[ii+1]+1);
            sumCL += temp[ii]*L[ii];
        }

        temp[0] = B - sumCL;
        constant.insert({n, temp});
    }

    f(r,0,R,1){
        char vn[10];
        // cout << vn << endl;
        scanf("%s", vn);
        int curS = constant[vn].size()-1;
        vi pos;
        f(i, 0, curS, 1){
            int value;
            scanf("%i", &value);
            pos.push_back(value);
        }

        int ans = constant[vn][0];
        f(i, 0, curS, 1){
            ans += (pos[i])*(constant[vn][i+1]);
        }

        cout << vn << '[';
        f(i,0,curS,1){
            if (i!=curS-1){
                cout << pos[i]<<", ";
            } else {
                cout << pos[i];
            }
        }
        cout<< "] = "<< ans << endl;
    }
    return 0;
}