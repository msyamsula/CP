#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef queue<int> qi;
typedef map<pair<int,int>, long> miil;
#define modulo 1000000007
vi dis;
vi parent;
miil quotient;
vi primes;
bitset<10000005> bs;

void sieve(long upperbound){
    bs.set();
    bs[0]=0; bs[1]=0;
    for(long i=2; i<=upperbound; i++){
        if (bs[i]){
            for(long j=i*i; j<=upperbound; j+=i){
                // cout << i << ' ' << j << endl;
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }    
}

long countFactor(long a){
    map<long, long> pf;
    int pi = 0;
    while(a!=1){
        if (a%primes[pi] == 0){
            a/=primes[pi];
            pf[primes[pi]] += 1;
            continue;
        }
        pi++;
    }

    long ans=1;
    map<long,long>::iterator it=pf.begin();
    while(it!=pf.end()){
        ans *= ((it->second)+1);
        it++;
    }

    return ans;
}

void bfs(vvi graph, int start, vi a){
    dis.assign(graph.size(), -1);
    parent.assign(graph.size(),-1);
    start--;
    qi q; q.push(start);
    dis[start] = 0;
    parent[start] = -1;
    quotient[make_pair(start,start)] = a[start]%modulo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        // cout << u << endl;
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if (dis[v] == -1){
                dis[v] = dis[u]+1;
                parent[v] = u;
                q.push(v);
                quotient[make_pair(start,v)] = (quotient.at(make_pair(start,u))*a[v])%modulo;
            }
        }
    }
}

void solve(){
    int n; cin>>n;
    vvi graph(n);
    for(int i=0;i<n-1; i++){
        int u,v; cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vi a(n);
    int start;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if (graph[i].size()==1) start = i+1;
        // for(int j=0; j<graph[i].size(); j++){
        //     cout << graph[i][j] << ' ';
        // }
        // cout << endl;
    }
    // cout << endl;
    bfs(graph,start,a);
    start--;

    // miil::iterator it=quotient.begin();
    // while(it != quotient.end()){
    //     cout << it->first.first << ' ' << it->first.second << ' ' << it->second << endl;
    //     it++;
    // }
    // cout << endl;

    // for(int i=0; i<dis.size(); i++){
    //     cout << dis[i] << ' ';
    // }
    // cout << endl;

    // for(int i=0; i<parent.size(); i++){
    //     cout << parent[i] << ' ';
    // }
    // cout << endl;

    int q; cin>>q;
    for(int i=0; i<q; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        // cout << u << v << endl;
        long ans = 0;
        if(u==v){
            ans = long(a[u])%modulo;
        } else if (dis[u] < dis[v]){
            ans = ((quotient.at({start,v})/quotient.at({start,u}))* a[v])%modulo;
        } else if (dis[u] > dis[v]) {
            ans = (quotient.at({start,u})*a[u]/quotient.at({start,v}))%modulo;
        } else {
            int par = parent[u];
            // cout << start << ' ' << u << endl;
            // cout << start << ' ' << v << endl;
            // cout << start << ' ' << par << endl;
            ans = (quotient.at({start,u})*quotient.at({start,v})*a[par]/(quotient.at({start,par})*quotient.at({start,par})))%modulo;
        }
        // cout << ans << endl;
        ans = countFactor(ans);
        cout << ans << endl;
    }

}

int main(){
    sieve(10000000l);
    // for(int i=0; i<primes.size(); i++){
    //     cout << primes[i] << ' ';
    // }
    // cout << endl;
    int t; cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}