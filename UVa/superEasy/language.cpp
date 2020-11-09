#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


int main(){
    char word[20];
    int c = 1;
    mss dict;
    dict["HELLO"] = "ENGLISH";
    dict["HOLA"] = "SPANISH";
    dict["HALLO"] = "GERMAN";
    dict["BONJOUR"] = "FRENCH";
    dict["CIAO"] = "ITALIAN";
    dict["ZDRAVSTVUJTE"] = "RUSSIAN";

    while (scanf("%s", word)){
        if (strstr(word, "#") != nullptr){
            break;
        }

        string result;
        try{
            result = dict.at(word);
        } catch (const exception &e){
            result = "UNKNOWN";
        }

        // char r[100];
        // strcpy(r, &result[0]);

        printf("Case %i: %s\n", c, &result[0]);
        c++;
    }

    return 0;
}