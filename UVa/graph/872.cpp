#include<bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef map<char, vc> mcvc;
typedef pair<char, vc> cvc;
typedef vector<int> vi;
typedef map<char, int> mci;
typedef vector<vc> vvc;

void alltoposort(mcvc adjList, mci &indegree, mci &visited, vc &result, bool &breakStat, vvc &resultCumul){
    bool flag = false;

    for(cvc item: adjList){
        int u = item.first;
        if (indegree[u] == 0 && visited[u] == 0){
            visited[u] = 1;
            result.push_back(u);
            for(char v: adjList[u]){
                indegree[v]--;
            }

            alltoposort(adjList, indegree, visited, result, breakStat, resultCumul);

            visited[u] = 0;
            result.erase(result.end()-1);
            for(char v: adjList[u]){
                indegree[v]++;
            }

            flag = true;
        }
    }


    if(!flag){
        resultCumul.push_back(result);
    }

}

void solve(){
    string line1; getline(cin, line1);
    // cout << line1 << endl;
    stringstream ss1(line1);
    char a;
    mcvc adjList;
    while(ss1>>a){
        adjList[a] = {};
    }

    // cout << "tes " << endl;

    string line2; getline(cin, line2);
    stringstream ss2(line2);
    char b;
    while(ss2>>a){
        char sign; ss2>>sign;
        ss2>>b;
        adjList[a].push_back(b);
    }

    int n = adjList.size();
    mci indegree;
    mci visited;
    for(cvc temp : adjList){
        // cout << temp.first << ' ';
        for(char v : temp.second){
            indegree[v] += 1;
            visited[v] = 0;
            // cout << v << ' ';
        }
        // cout << endl;
    }

    vc result;
    bool breakStat = 0;
    vvc resultCumul;
    alltoposort(adjList,indegree,visited,result,breakStat,resultCumul);
    if (resultCumul[0].size() != n){
        cout << "NO" << endl;
    } else {
        for(vc temp : resultCumul){
            for(char u : temp){
                cout << u << ' ';
            }
            cout << endl;
        }
    }

}

int main(){
    int t; cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0; i<t; i++){
        // cout << i << endl;
        string newline; getline(cin, newline);
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}