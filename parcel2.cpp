#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef queue<ii> qii;


void bfs(vii sp, int n, int m, vi &dis){
    vi visited(n*m, 0);
    qii start;
    for (int i=0; i<sp.size(); i++){
        ii cp = sp[i];
        int idi = get<0>(cp), idj=get<1>(cp);
        int idx = idi*m+idj;
        visited[idx] = 1;
        start.push(cp);
    }


    while(!start.empty()){
        ii cp = start.front(); start.pop();
        int i = get<0>(cp);
        int j = get<1>(cp);
        int ci = i*m+j;

        vii next;

        int top = i-1;
        if (0<=top && top<n){
            int idx = top*m+j;
            if (visited[idx] == 0) next.push_back({top,j});
        }

        int bot = i+1;
        if (0<=bot && bot<n){
            int idx = bot*m+j;
            if (visited[idx] == 0) next.push_back({bot,j});
        }

        int left = j-1;
        if (0<=left && left<m){
            int idx = i*m+left;
            if (visited[idx] == 0) next.push_back({i,left});
        }

        int right = j+1;
        if (0<=right && right<m){
            int idx = i*m+right;
            if (visited[idx] == 0) next.push_back({i,right});
        }

        for (int iii=0; iii<next.size(); iii++){
            start.push(next[iii]);
            ii cp = next[iii];
            int idxi = get<0>(cp);
            int idxj = get<1>(cp);
            int idx = idxi*m+idxj;
            visited[idx] = 1;
            dis[idx] = dis[ci]+1;
        }
    }
}

bool solvemin(int k, vs line, vi dis){
    

    int n = line.size(), m = line[0].size();
    int maxplus = -(1<<30);
    int minmin = (1<<30);
    for (int i=0; i<line.size(); i++){
        for (int j=0; j<line[0].size(); j++){
            int idx = i*m+j;
            if (dis[idx] >= k){
                int maxtemp = i+j, mintemp = i-j;
                if (maxtemp > maxplus) maxplus = maxtemp;
                if (mintemp < minmin) minmin = mintemp;
            }
        }
    }

    int maxd = -(1<<30);
    for (int i=0; i<line.size(); i++){
        for (int j=0; j<line[0].size(); j++){
            int mandis = max(abs(maxplus-(i+j)), abs(minmin-(i-j)));
            if (mandis > maxd) maxd = mandis;
        }
    }

    cout << maxd << endl;
    if (maxd >= k) return 0;

    return 1;
}

void solve(int tc){
    int n, m;
    cin>>n; cin>>m;
    vi dis(n*m,1<<30);
    vs line(n);
    vii start;
    for (int i=0; i<n; i++){
        cin>>line[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (line[i][j] == '1'){
                start.push_back({i,j});
                dis[i*m+j] = 0;
            }
        }
    }

    bfs(start, n, m, dis);
    // for(int i=0; i<dis.size(); i++){
    //     cout << dis[i] << ' ';
    // } cout << endl;

    int maxdis = 1<<30;
    int mindis = 0;

    while (maxdis != mindis){
        int mid = (mindis+maxdis)/2;
        bool a = solvemin(mid, line, dis);
        if (a){
            maxdis = mid;
        } else {
            mindis = mid+1;
        }
    }

    cout << "Case #" << tc << ": " << mindis << endl;

}


int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}