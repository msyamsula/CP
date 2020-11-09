#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;
typedef pair<string, string> pss;
typedef stack<pair<string, string>> spss;

mss rack;
mss borrow;
mss table;

int main(){
    string book;
    // ifstream file;
    // file.open("./test.txt");
    while(getline(cin, book)){
        // cout << book << endl;
        if (book == "END"){
            break;
        }
        char * ptr = strstr(&book[0], " by ");
        int l = ptr - &book[0];
        string b = book.substr(0, l);
        string a = book.substr(l+4, book.size()-l-4);
        rack.insert({b,a});
    }


    string command;
    while(getline(cin, command)){
        // cout << command << endl;
        if (command == "END"){
            break;
        }

        if (command == "SHELVE"){
            mss::iterator i;
            iter(table, i){
                string prev = rack.rbegin()->first;
                // prev = (prev == "") ? "first" : prev;
                // cout << prev << endl;
                if (prev == ""){
                    cout << "Put " << i->second << " first"<< endl;
                } else {
                    cout << "Put " << i->second << " after " << prev << endl;
                }
                // cout << rack.rbegin()->first << endl;
                rack.insert({i->second, i->first});
            }
            table.clear();
            cout << "END" << endl;
            continue;
        }

        string c = strtok(&command[0], " ");
        string tit = command.substr(7, command.size()-7);
        if (c == "BORROW"){
            borrow.insert({tit, rack[tit]});
            rack.erase(tit);
        }

        if ( c == "RETURN"){
            table.insert({borrow[tit], tit});
            borrow.erase(tit);
        }
    }

    return 0;
}