#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef map<string, ii> msii;
typedef map<string, msii> mssii;
typedef vector<int> vi;
typedef map<string, int> msi;

void addGraph(mssii &graph, int a, string sa, int b, string sb){
    ii i1 = {b,a}, i2 = {a,b};
    graph[sa][sb] = i1;
    graph[sb][sa] = i2;
}

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

void dfs(mssii graph, string sa, string sb, msi &visited, int num, int den, bool &found, string ssa){

    if (sa == sb){
        int g = gcd(num,den);
        cout << den/g << ' ' << ssa << " = " << num/g << ' ' << sb << endl;
        found = 1;
    }

    visited[sa] = 1;
    msii::iterator i=graph[sa].begin();
    while(i!=graph[sa].end()){
        string ns = i->first;
        if (visited[ns] == 0){
            int num_mult = graph[sa][ns].first;
            int den_mult = graph[sa][ns].second;
            dfs(graph, ns, sb, visited, num*num_mult, den*den_mult, found, ssa);
        }
        i++;
    }
}

int main(){
    mssii graph;
    char status;
    while(cin>>status){
        // cout << "tes " << status << endl;
        if (status == '!'){
            int a, b;
            string sa, sb, eq;
            cin>>a>>sa>>eq>>b>>sb;
            addGraph(graph, a, sa, b, sb);
        } else if (status == '?'){
            // mssii::iterator ii=graph.begin();
            // while(ii!=graph.end()){
            //     cout << ii->first << ": " << endl;
            //     msii::iterator jj=ii->second.begin();
            //     while(jj!=ii->second.end()){
            //         cout << jj->first << ' ' << jj->second.first << ' ' << jj->second.second << endl;
            //         jj++;
            //     }
            //     ii++;
            // }
            string sa, eq, sb;
            cin>>sa>>eq>>sb;
            msi visited;
            bool found = 0;
            dfs(graph, sa, sb, visited, 1, 1, found, sa);
            if (!found){
                cout << "? " << sa << " = " << "? " << sb << endl;
            }
        }
    }

    return 0;
}