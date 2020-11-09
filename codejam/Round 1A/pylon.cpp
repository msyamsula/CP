#include <iostream>
using namespace std;

// void nextMove(int &curRow, int &curCol, int totRow, int totCol, int board[20][20], int &bs, int result[400][2], int index){
//     for (int i=0; i<totRow; i++){
//         bool s = false;
//         for (int j=0; j<totCol; j++){
//             int status = board[i][j];
//             if (status == 1){
//                 continue;
//             }
//             int x = j+1;
//             int y = i+1;
//             bool con2 = curCol == x;
//             bool con1 = curRow == y;
//             bool con3 = curRow-curCol == y-x;
//             bool con4 = curRow+curCol == y+x;
//             if (y == curRow && x == curCol){
//                 board[i][j] = 1;
//             } else if (!con1 && !con2 && !con3 && !con4 && status!=1){
//                 board[i][j] = 1;
//                 bs++;
//                 curCol = x;
//                 curRow = y;
//                 result[index][0] = y;
//                 result[index][1] = x;
//                 s = true;
//                 break;
//             } else {
//                 board[i][j] = 0;
//             }
//         }

//         if (s){
//             break;
//         }
//     }
// }

// bool gamePlay(int R, int C, int currRow, int currCol, int result[400][2]){
//     // int R = 2;
//     // int C = 5;
//     // int currRow = 2;
//     // int currCol = 3;
//     int board[20][20];
//     int boardSum = 1;
//     int nextBoardSum = boardSum;
//     // int resultSize = R*C;
//     // int result[resultSize][2];
//     result[0][0] = currRow;
//     result[0][1] = currCol;

//     for (int i=0; i<R; i++){
//         for (int j=0; j<C; j++){
//             board[i][j] = (i+1 == currRow && j+1 == currCol) ? 1 : 0;
//         }
//     }

//     int resultIndex = 1;
//     while(true){
//         nextMove(currRow,currCol,R,C,board,nextBoardSum,result,resultIndex);
        
//         for (int i=0; i<R; i++){
//             for (int j=0; j<C; j++){
//                 if (j<C-1){
//                     cout << board[i][j] << ' ';
//                 } else {
//                     cout << board[i][j] << endl;
//                 }
//             }
//         }
//         cout <<endl;

//         if (nextBoardSum == boardSum){
//             break;
//         } else {
//             boardSum = nextBoardSum;
//             resultIndex++;
//         }
        

//     }

//     if (boardSum == R*C){
//         return true;
//         // cout << "Possible" << endl;
//         // for (int i=0; i<boardSum; i++){
//         //     cout << result[i][0] << ' ' << result[i][1] << endl;
//         // }
//     } else {
//         return false;
//         // cout << "Impossible" << endl;
//         // for (int i=0; i<boardSum; i++){
//         //     cout << result[i][0] << ' ' << result[i][1] << endl;
//         // }
//     }
// }

// int main(){
//     int T;
//     cin >> T;

//     for (int t=1; t<T+1; t++){
//         int R, C;
//         cin >> R;
//         cin >> C;
//         int result[400][2];
//         bool s1 = false;
//         for (int i=1; i<R+1; i++){
//             for (int j=1; j<C+1; j++){
//                 cout << i << 'a' << j << endl;
//                 bool s2 = gamePlay(R,C,i,j,result);
//                 if (s2){
//                     s1 = true;
//                     cout << "Case #" << t << ": POSSIBLE" << endl;
//                     for (int p=0; p<(R*C); p++){
//                         cout << result[p][0] << ' ' << result[p][1] << endl;
//                     }
//                     break;
//                 }
//             }

//             if (s1){
//                 break;
//             }
//         }

//         if (!s1){
//             cout << "Case #" << t << ": IMPOSSIBLE" << endl;
//         }
//     }

//     return 0;
// }

class Board {
    public:
        int row;
        int col;
        int b[20][20];
        int curRow;
        int curCol;
        int boardSum;
        Board(int r=1, int c=1, int cR=0, int cC=0, int boardSum=1){
            row = r;
            col = c;
            curRow = cR;
            curCol = cC;
            boardSum = boardSum;
            for (int i=0; i<r; i++){
                for (int j=0; j<c; j++){
                    int x = j+1;
                    int y = i+1;
                    b[i][j] = (x==curCol && y==curRow) ? 1 : 0;
                }
            }
        }

        void showBoard(){
            for (int i=0; i<row; i++){
                for (int j=0; j<col; j++){
                    if (j<col-1){
                        cout << b[i][j] << ' ';
                    } else {
                        cout << b[i][j] << endl;
                    }
                }
            }
        }

        void moveTo(int nR, int nC){
            b[nR-1][nC-1] = 1;
            curRow = nR;
            curCol = nC;
        }
    
};

// void boardProgress(Board b, Board progress[1000], int &proIdx){
//     for (int i=0; i<b.row; i++){
//         for (int j=0; j<b.col; j++){
//             int status = b.b[i][j];
//             if (status == 1){
//                 continue;
//             }
//             int x = j+1;
//             int y = i+1;
//             bool con2 = b.curCol == x;
//             bool con1 = b.curRow == y;
//             bool con3 = b.curRow-b.curCol == y-x;
//             bool con4 = b.curRow+b.curCol == y+x;
//             if (!con1 && !con2 && !con3 && !con4){
//                 // cout << y << ' ' << x << " " << l << endl;
//                 progress[proIdx] = b;
//                 progress[proIdx].moveTo(y,x);
//                 progress[proIdx].curRow = y;
//                 progress[proIdx].curCol = x;
//                 // bl[proIdx].showBoard();
//                 proIdx++;
//                 // cout<<endl;
//             }
//         }
//     }
// }

// void nextBoard(Board bl[1000], int &inLength){
//     Board temp[1000];
//     int tempIdx = 0;
//     for (int i=0; i<inLength; i++){
//         boardProgress(bl[i], temp, tempIdx);
//         // cout << tempIdx <<endl;
//     }
    
//     inLength = tempIdx;

//     for (int i=0; i<inLength; i++){
//         bl[i] = temp[i];
//     }
//     // return index;
// }

int nextMove(Board b, int nX, int nY){
    b.b[nX-1][nY-1] = 1;
    int possibility = 0;
    for (int i=0; i<b.row; i++){
        for (int j=0; j<b.col; j++){
            int status = b.b[i][j];
            if (status == 1){
                continue;
            }
            int x = j+1;
            int y = i+1;
            bool con2 = nX != x;
            bool con1 = nY != y;
            bool con3 = nY-nX != y-x;
            bool con4 = nY+nX != y+x;

            if (con1 && con2 && con3 && con4){
                possibility++;
            }
        }
    }

    return possibility;
}

int main(){
    int R = 3;
    int C = 4;
    Board b(R,C);
    b.showBoard();
    cout << endl;
    b.curCol = 0;
    b.curRow = 0;

    for (int t=0; t<12; t++){
        int pos = 0;
        int nX, nY;
        if (b.curCol == 0 && b.curRow == 0) {
            for (int i=0; i<R; i++){
                for (int j=0; j<C; j++){
                    int x = j+1;
                    int y = i+1;
                    int newPos = nextMove(b, x, y);
                    // cout << y << ' ' << x << ' ' << newPos << endl;
                    if (newPos > pos){
                        pos = newPos;
                        nX = x;
                        nY = y;
                    }
                }
            }
        } else {
            for (int i=0; i<R; i++){
                for (int j=0; j<C; j++){
                    int status = b.b[i][j];
                    if (status == 1){
                        continue;
                    }
                    int x = j+1;
                    int y = i+1;
                    bool con2 = b.curCol != x;
                    bool con1 = b.curRow != y;
                    bool con3 = b.curRow-b.curCol != y-x;
                    bool con4 = b.curRow+b.curCol != y+x;
                    int newPos;
                    if (con1 && con2 && con3 && con4){
                        newPos = nextMove(b, x, y);
                        cout << y << ' ' << x << ' ' << newPos << endl;
                        if (newPos >= pos){
                            pos = newPos;
                            nX = x;
                            nY = y;
                        }
                    }
                }
            }
        }

        // cout << pos << endl;
        b.moveTo(nY, nX);
        b.showBoard();
        cout << endl;
        // cout << b.curRow << ' ' << b.curCol << endl;
    }

    // b.showBoard();
    // Board boardList[1000];
    // boardList[0] = b;
    // int length = 1;
    // Board moveOption[100];
    // int outputLength = 0;

    // for (int i=0; i<11; i++){
    //     nextBoard(boardList, length);
    // }

    // cout << length << endl;
    // for (int i=0; i<length; i++){
    //     boardList[i].showBoard();
    //     cout << endl;
    // }


    // for (int i=0; i<outputLength; i++){
    //     moveOption[i].showBoard();
    //     cout << endl;
    // }
    // for (int i=0; i<length; i++){
    //     boardList[i].showBoard();
    //     cout << endl;
    // }
    return 0;
}