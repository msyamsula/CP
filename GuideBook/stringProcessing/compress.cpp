#include<bits/stdc++.h>
using namespace std;
#define _slen 1000000

typedef deque<string> dq;

int main (){
    char line[_slen];
    // fgets(line, _slen, stdin);
    // cout << strlen(line) << endl;
    // char * ptr = strtok(line, " ");
    // while(ptr != 0){
    //     // cout << ptr << endl;
    //     cout << line << endl;
    //     ptr = strtok(0, " ");
    // }
    dq a;
    char token[_slen];
    while(fgets(line, _slen, stdin)){
        if (line[0] == '0') break;
        line[strlen(line)-1] = '\0';
        bool first = true;

        for (int i=0; i<strlen(line); i++){
            if (isalpha(line[i])){
                printf("%c", line[i]);
            } else if (!isdigit(line[i])){
                strcat(token, &line[i]);
                char * ptr;
                if (first){
                    ptr = strtok(line, token);
                    first = false;
                } else {
                    ptr = strtok(0, token);
                }
                if (ptr != 0) a.push_front(ptr);
            } else {
                int num = int(line[i]) - '1';
                printf("%s", a[num].c_str());
            }
        }
        cout << endl;
    }

    return 0;
}