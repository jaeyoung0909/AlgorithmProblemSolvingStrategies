#include <iostream>
#include <string.h>

using namespace std;

int fence[20000];

int solve(int left, int right){
    if(right==left) return fence[left];
    int mid = (left+right)/2;
    int ret = max(solve(left,mid), solve(mid+1, right));
    int lo = mid, hi = mid+1;
    int height = min(fence[lo], fence[hi]);
    ret = max(ret, 2*height);
    while(lo>left || hi < right){
        if(hi<right && (lo == left || fence[lo-1] <= fence[hi+1])){
            hi++;
            height = min(height, fence[hi]);
        }
        else{
            lo--;
            height = min(height, fence[lo]);
        }
        ret = max(ret, height*(hi-lo+1));
    }
    return ret;
    

}

int main(){
    int c;
    cin >> c;
    for(int i=0; i<c; i++){
        int fenNum;
        cin >> fenNum;
        memset(fence, 0, sizeof(int)*fenNum);
        for(int fenEle=0; fenEle<fenNum; fenEle++){
            int fen;
            cin >> fen;
            fence[fenEle] = fen;
        }
        cout << solve(0, fenNum-1) <<endl;
        
    }
    return 0;
}