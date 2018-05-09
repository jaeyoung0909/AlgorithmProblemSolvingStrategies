#include <iostream>
#include <vector>

using namespace std;
const int INF = 9999;
const char link[10][17] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areTwelve(vector<int>& clocks){
    for(int clock=0; clock<16; clock++){
        if(clocks[clock]!=12) return 0;
    }
    return 1;
}

void push(vector<int>& clocks, int sw){
    for(int clock=0; clock<16; clock++){
        if(link[sw][clock]=='x'){    
            clocks[clock] = clocks[clock]+3;
            if(clocks[clock]==15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int sw){
    if(sw == 10)   return areTwelve(clocks) ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt < 4; cnt++){
        ret = min(ret, cnt+solve(clocks, sw+1));
        push(clocks, sw);
    } 
    return ret;
}

int main(){
    int C; 
    cin >> C;
    for(int i=0; i<C; i++){
        vector<int> clocks;
        for(int j=0; j<16; j++)
        {int num;
        cin >> num;
        clocks.push_back(num);
        }
        int ret = solve(clocks, 0);
        if(ret == INF)  cout << -1 << endl;
        else cout << ret << endl;
    }
    return 0;
}