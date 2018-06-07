#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int A[101];
int B[101];
int cache[101][101];

int n, m;

int jlis(int startA, int startB){
    int& ret = cache[startA + 1][startB + 1];
    if(ret != -1)   return ret;
    //if(A[startA] == B[startB])  ret = 1;
    //else    
    ret = 0;
    
    long long a = (startA != -1 ? A[startA] : NEGINF);
    long long b = (startB != -1 ? B[startB] : NEGINF);

    long long maxLen = max(a, b);
    
    for(int nextA = startA+1; nextA < n; nextA++){
        if(maxLen < A[nextA])   ret = max(ret, jlis(nextA, startB) + 1);
    }
    for(int nextB = startB+1; nextB < m; nextB++){
        if(maxLen < B[nextB])   ret = max(ret, jlis(startA, nextB) + 1);
    }
    cout << ret << endl;
    return ret;
    
}

int main(){
    int c;
    cin >> c;
    for(int i=0; i<c; i++){
        
        cin >> n;
        cin >> m;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        memset(cache, -1, sizeof(cache));
        for(int j=0; j<n; j++)  cin >> A[j];
        for(int j=0; j<m; j++)  cin >> B[j];
        cout << jlis(-1, -1) << endl;
    }
}