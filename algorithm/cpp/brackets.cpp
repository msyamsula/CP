#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a,i) for(i=a.begin(); i!=a.end(); i++)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef stack<char> sc;


int main(){
    sc a;
    string str = "{[()}";

    string::iterator i;
    iter(str, i){
        if (i==str.begin()){
            a.push(*i);
            continue;
        }
        bool popCon = (a.top() == '(' && *i == ')') || (a.top() == '[' && *i == ']') || (a.top() == '{' && *i == '}');
        if (popCon){
            a.pop();
        } else {
            a.push(*i);
        }
    }

    if (a.size()==0){
        // return 1;
        cout << "perfect" << endl;
    } else {
        cout << "imperfect" << endl;
        // return 0;
    }

    return 0;
}