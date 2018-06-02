#include <iostream>
#include <string.h>
using namespace std;

int tri[100][100];
int cash[100][100];

int main(){
    int C;
    cin >> C;
    for(int test=0; test<C; test++){
        int n;
        cin >> n;
        memset(tri, 0, sizeof(tri));
        memset(cash, 0, sizeof(cash));
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                int ele;
                cin >> ele;
                tri[i][j] = ele; 
            }
        }
        int ret = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(i==0 && j==0)    cash[i][j] = tri[i][j];
                else if(j==0)   cash[i][j]  = cash[i-1][j] + tri[i][j];
                else if (i==j)  cash[i][j] = cash[i-1][j-1] + tri[i][j];  
                else    cash[i][j] = tri[i][j] + max(cash[i-1][j-1], cash[i-1][j]);
                if(i==n-1)  ret = max(ret, cash[i][j]);
            }
        }
        cout << ret <<endl;
    }
    return 0;
}