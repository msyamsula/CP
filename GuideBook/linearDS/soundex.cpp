#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;
typedef unordered_map<char, int> umci;

mci mem;

int main(){
    mem = {
        {'B',1},
        {'F',1},
        {'P',1},
        {'V',1},
        {'C',2},
        {'G',2},
        {'J',2},
        {'K',2},
        {'Q',2},
        {'S',2},
        {'X',2},
        {'Z',2},
        {'D',3},
        {'T',3},
        {'L',4},
        {'M',5},
        {'N',5},
        {'R',6},
    };

    string word;
    while(cin>>word){
        stack<char> stk;
        stk.push('.');
        string ans = "";
        for (int i=0; i<word.size(); i++){
            char temp;
            try{
                temp = char(mem.at(word[i])+48);
            } catch (const exception &e){
                stk.push('.');
                continue;
            }

            if (temp == stk.top()) continue;
            stk.push(temp);
            ans += temp;
        }


        cout << ans << endl;
    }

    return 0;
}