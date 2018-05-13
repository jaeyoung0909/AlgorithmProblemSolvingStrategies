#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> karatsuba(vector<int> &A, vector<int> &B){
    
}

int solve(string& mem, string& fen){
    int M = mem.size(), F = fen.size();
    std::vector<int> A(M), B(F);

    for(int i=0; i<M; i++)  A[i] = (mem[i]=='M');
    for(int i=0; i<F; i++)  B[F-i-1] = (fen[i]=='M');
    vector<int> C = karatsuba(A, B);
    int hugNum=0;
    for(int i=M-1;i<F; i++){
        if(C[i]==0) hugNum++;
    }
    return hugNum;
}

int main(){
    int c;
    cin >> c;
    for(int test=0; test<c;c++){
        string MEM, FEN;
        cin >> MEM >> FEN;
    }
    return 0;
}