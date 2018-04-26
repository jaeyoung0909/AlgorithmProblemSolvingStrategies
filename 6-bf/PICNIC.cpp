#include <iostream>
#include <string.h>

using namespace std;
int n;
bool friendsPair[10][10];

int countPair(int taken[10]){
    int firstUnpair=-1;
    for(int i=0; i<n; i++){
        if(taken[i]!=1){
            firstUnpair = i;
            break;
        }
    }
    if(firstUnpair == -1)   return 1;
    int ret=0;
    for(int i=firstUnpair+1; i<n; i++){
        if(taken[i]!=1 && friendsPair[i][firstUnpair] ==1){
            taken[i]=taken[firstUnpair] = 1;
            ret += countPair(taken);
            taken[i]=taken[firstUnpair]=0;
        }
    }
    return ret;
}

int main(){
    int c, m;
    cin >> c;
    for(int i=0;i<c;i++){
        cin >> n >> m;
        for(int x=0; x<n; x++)  memset(friendsPair[x], 0, sizeof(bool)*10);
        for(int x=0; x<m;x++){        
            int row, col;
            cin >> row >> col;
            friendsPair[row][col] = friendsPair[col][row] = 1;
            
        }
        int taken[10]={};
        cout << countPair(taken) << endl;
    } 
    return 0;
}