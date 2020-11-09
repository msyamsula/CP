#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef queue<ii> qii;
typedef queue<int> qi;

void solve(int tc, int n, int m){
    n++;
    vvii graph(n);
    for(int i=0; i<m; i++){
        int s; cin>>s;
        int e; cin>>e;
        int d; cin>>d;
        graph[s].push_back({e,d});
        graph[e].push_back({s,d});
    }

    vi nt(n,-1);
    nt[1] = 0;
    qi q; q.push(1);

    while(!q.empty()){
        int cn = q.front(); q.pop();
        for(int i=0; i<graph[cn].size(); i++){
            int cnn = graph[cn][i].first;
            if (nt[cnn] == -1){
                nt[cnn] = nt[cn] + graph[cn][i].second;
                q.push(cnn);
            }
            else nt[cnn] = min(nt[cnn], nt[cn] + graph[cn][i].second);
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << nt[i] << ' '; 
    // } cout << endl;
    q.push(1);
    vi visited(n, 0);
    double tmax = 0;
    string status = "at key domino 1.";
    while(!q.empty()){
        int cn = q.front(); q.pop();
        for (int i=0; i<graph[cn].size(); i++){
            int cnn = graph[cn][i].first, nd = graph[cn][i].second;
            if (visited[cnn] == 0){
                q.push(cnn);
                visited[cnn] = 1;
                // if (nt[cnn] > tmax){
                //     tmax = nt[cnn];
                //     status = "at key domino " + to_string(cnn) + '.';
                // }
                // continue;
            }
            
            if (nt[cn]+nd == nt[cnn]){
                if (nt[cnn] > tmax){
                    tmax = nt[cnn];
                    status = "at key domino " + to_string(cnn) + '.';
                }
            } else if (nt[cn]-nd == nt[cnn]){

            } else if (nt[cn]+nd > nt[cnn]){
                double t = double(nt[cn] + nd + nt[cnn])/2;
                if (t>tmax){
                    tmax = t;
                    status = "between key dominoes " + to_string(cn) + " and " + to_string(cnn) + '.';
                }
            }
        }
    }

    cout << "System #" << tc << endl;
    cout << "The last domino falls after " << fixed << setprecision(1) << tmax << " seconds, " << status << endl << endl;
}

int main(){
    int n; int tc=0;
    while(cin>>n){
        int m; cin>>m;
        if (n==0 && m==0) break;
        tc++;
        solve(tc, n, m);
    }

    return 0;
}