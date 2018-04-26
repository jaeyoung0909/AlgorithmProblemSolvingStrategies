#include <iostream>
#include <string.h>

using namespace std;

int x, y;
bool table[20][20];

bool check(int i, int j, int caseNum){
    switch(caseNum){
        case 0:
            return (i-1 > 0 && j-1 > 0) && (table[j-1][i-1]==table[j][i-1]==1);
        case 1:
            return (i-1 > 0 && j-1 > 0) && (table[j-1][i-1]==table[j-1][i]==1);
        case 2:
            return (i+1 < x && j-1 > 0) && (table[j-1][i+1]==table[j-1][i]==1);
        case 3:
            return (i+1 < x && j-1 > 0) && (table[j-1][i+1]==table[j][i+1]==1);
        case 4:
            return (i+1 < x && j+1 < y) && (table[j+1][i+1]==table[j][i+1]==1);
        case 5:
            return (i+1 < x && j+1 < y) && (table[j+1][i+1]==table[j+1][i]==1);
        case 6:
            return (i-1 > 0 && j+1 < y) && (table[j+1][i-1]==table[j+1][i]==1);
        case 7:
            return (i-1 > 0 && j+1 < y) && (table[j+1][i-1]==table[j][i-1]==1);
        default:
            return 0;
    }
}

void changeBlock(int i, int j, int caseNum, bool add){
    switch(caseNum){
        case 0:
            if(add) table[j][i]=table[j-1][i-1]=table[j][i-1]=1;
            else    table[j][i]=table[j-1][i-1]=table[j][i-1]=0;
            return;
        case 1:
            if(add) table[j][i]=table[j-1][i-1]=table[j-1][i]=1;
            else    table[j][i]=table[j-1][i-1]=table[j-1][i]=0;
            return;
        case 2:
            if(add) table[j][i]=table[j-1][i+1]=table[j-1][i]=1;
            else table[j][i]=table[j-1][i+1]=table[j-1][i]=0;
            return;
        case 3:
            if(add) table[j][i]=table[j-1][i+1]=table[j][i+1]=1;
            else table[j][i]=table[j-1][i+1]=table[j][i+1]=0;
            return;
        case 4:
            if(add) table[j][i]=table[j+1][i+1]=table[j][i+1]=1;
            else table[j][i]=table[j+1][i+1]=table[j][i+1]=0;
            return;
        case 5:
            if(add) table[j][i]=table[j+1][i+1]=table[j+1][i]=1;
            else table[j][i]=table[j+1][i+1]=table[j+1][i]=0;
            return;
        case 6:
            if(add) table[j][i]=table[j+1][i-1]=table[j+1][i]=1;
            else table[j][i]=table[j+1][i-1]=table[j+1][i]=0;
            return;
        case 7:
            if(add) table[j][i]=table[j+1][i-1]=table[j][i-1]=1;
            else table[j][i]=table[j+1][i-1]=table[j][i-1]=0;
            return;
        
    }
}

int coverNum(int cur_x, int cur_y){
    for(int j=cur_y; j<y;j++){
        bool flag = false;
        for(int i=cur_x; i<y;i++){
            if(table[j][i]){
                cur_y=j;
                cur_x=i;
                flag = true;
                break;
            }
        }
        if(flag)    break;
        else if(j==y-1){
            cur_y=y-1;
            cur_x=x-1;
            break;
        }
    }
    
    if(check(cur_x,cur_y,0)&&check(cur_x,cur_y,1)&&cur_y==y-1&&cur_x==x-1)  return 1;
    int ret = 0;
    for(int i=0; i<8; i++){
        if(check(cur_x, cur_y, i)){
            changeBlock(cur_x, cur_y,i,1);
            ret+=coverNum(cur_x, cur_y);
            changeBlock(cur_x, cur_y,i,0);
        }
    }
    return ret;
}

int main(){
    int c;
    cin >> c;
    for(int k=0; k<c;k++){
        cin >> y >> x;
        for(int i=0;i<y;i++)    memset(table[i], 0, sizeof(bool)*x);
        for(int j=0; j<y;j++){
            for(int i=0;i<x;i++){
                char block;
                cin >> block;
                if(block=='#')  table[j][i]=0;
                else    table[j][i]=1;
            }
        }
        cout << coverNum(0,0) << endl;
    }
    return 0;
}