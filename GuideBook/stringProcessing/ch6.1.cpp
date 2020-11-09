#include<bits/stdc++.h>

using namespace std;
#define _max = 1<<30

// int main(){
//     string line;
//     while(getline(cin, line)){
//         if (line.substr(0,7) == ".......") break;
//         printf("%s\n", line.c_str());
//     }
//     return 0;
// }

// int main(){
//     string sentence;
//     getline(cin, sentence);
//     string word;
//     while(getline(cin, word)){
//         int i = sentence.find(word, 0);
//         // cout << i << endl;
//         if (i == -1) {
//             cout << -1 << endl;
//             continue;
//         }
//         while(i != -1){
//             cout << i << ' ';
//             i = sentence.find(word,i+1);
//         } cout << endl;
//     }
// }

// int main(){
//     string sentence;
//     getline(cin, sentence);
//     string token = " ,.";
//     int start = 0;
//     int i = sentence.find_first_of(token);
//     if (i==-1) {
//         printf("%s\n", sentence.c_str());
//         return 0;
//     }

//     while(i!=-1){
//         string sub = sentence.substr(start,i-start);
//         if (sub != "") printf("%s\n", sub.c_str());
//         start = i+1;
//         // cout << start <<endl;
//         i = sentence.find_first_of(token, start);
//         if (i==-1) {
//             printf("%s\n", sentence.c_str());
//         }
//     }

//     return 0;
// }

int main(){
    char a[10];
    strcat(a, "aaa");
    cout << strlen(a) << endl;
    // puts(a);
    // cout << a << endl;
    for (int i=0; i<10; i++){
        cout << i << ' ' << a[i] << endl;
    }

    return 0;
}