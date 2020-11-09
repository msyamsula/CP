#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)
typedef map<string, int> msi;
typedef unordered_map<int, int> mii;
typedef deque<int> dqi;

int main(){
    string input;
    int value;
    mii d;
    dqi dq;
    while(getline(cin, input)){
        stringstream ss(input);
        while(ss>>value){
            try{
                d.at(value)++;
            } catch (const exception &e){
                d[value] = 1;
                dq.push_back(value);
            }
        }
    }

    while(dq.size()>0){
        cout << dq.front() << ' ' << d[dq.front()] << endl;
        dq.pop_front();
    }

    return 0;
}