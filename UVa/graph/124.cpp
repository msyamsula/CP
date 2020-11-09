#include<bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef map<char, int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, char> mic;
typedef pair<int, char> ic;
typedef pair<char, int> ci;

void alltoposort(vvi adjList, vi &indegree, vi &result, vi &visited, mic numb){

    bool flag = false;

    for(int i=0; i<indegree.size(); i++){
        int u = i;
        if (indegree[u] == 0 && visited[u] == 0){
            visited[u] = 1;
            result.push_back(u);
            for(int v : adjList[u]){
                indegree[v]--;
            }
            alltoposort(adjList, indegree, result, visited, numb);
            visited[u] = 0;
            result.erase(result.end()-1);
            for(int v : adjList[u]){
                indegree[v]++;
            }

            flag = true;
        }
    }

    if (!flag){
        for(int u : result){
            cout << numb[u];
        }
        cout << endl;
    }

}

int main(){
    string line;
    int t = 0;
    while( getline(cin, line) ){
        if (t!=0) cout << endl;
        t++;
        // cout << "first line " << line << endl;
        stringstream ss(line);
        char a;
        mci alphabet;
        mic numb;
        string firstLine = "";
        while(ss>>a){
            firstLine += a;
        }
        sort(firstLine.begin(), firstLine.end());

        int number = 0;
        for(char a : firstLine){
            alphabet[a] = number;
            numb[number] = a;
            number++;
        }

        int n = alphabet.size();
        vvi adjList(n);
        vi indegree(n);

        string line2; getline(cin, line2);
        // cout << "line two " << line2 << endl;
        stringstream ss2(line2);
        char b;
        while(ss2>>a){
            ss2>>b;
            int u = alphabet.at(a), v = alphabet.at(b);
            adjList[u].push_back(v);
            indegree[v]++;
        }

        // for(ci temp : alphabet){
        //     cout << temp.first << ' ' << temp.second << endl;
        // }

        // for(vi neighbor : adjList){
        //     for(int v : neighbor){
        //         cout << v << ' ';
        //     }
        //     cout << endl;
        // }

        vi result;
        vi visited(n,0);
        alltoposort(adjList, indegree, result, visited, numb);
    }
    
    

    return 0;
}