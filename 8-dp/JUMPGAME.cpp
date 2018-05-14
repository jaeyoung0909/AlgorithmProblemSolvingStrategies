#include <iostream>
#include <string.h>

using namespace std;

int board[100][100];
int cache[100][100];

string isPossible(int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(i==0 && j==0){
                cache[i][j] = 1;
                if(i+board[i][j] < size)    cache[i+board[i][j]][j] = 1;
                if(j+board[i][j] < size)    cache[i][j+board[i][j]] = 1;
            }
            else if(cache[i][j]){
                if(i+board[i][j] < size)    cache[i+board[i][j]][j] = 1;
                if(j+board[i][j] < size)    cache[i][j+board[i][j]] = 1;
            }
        }
    }
    if(cache[size-1][size-1])   return "YES";
    return "NO";
}

int main(){
    int C;
    cin >> C;
    for(int test =0; test<C; test++){
        int size;
        cin >> size;
        memset(board, 0, sizeof(board));
        memset(cache, 0, sizeof(cache));
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                int ele;
                cin >> ele;
                board[i][j] = ele;
            }
        }
        cout << isPossible(size) << endl;
    }
    return 0;
}
