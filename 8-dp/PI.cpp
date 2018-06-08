#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
string str;

int compute_cost(int start, int end){
    string m = str.substr(start, end-start+1);

    if(m == string(m.size(), m[0])) return 1;
    
    bool one_inc = true;
    for(int i=0; i<m.size()-2; i++){
        if(m[i+1]-m[i] != m[i+2]-m[i+1])  one_inc = false;
    }
    if(one_inc && abs(m[0] - m[1]) == 1)   {return 2;}
    
    bool alternating = true;
    char a;
    for(int i=0; i<m.size()-1; i++){
        if(i ==0) a = m[0];
        else if(m[i+1] != a) alternating = false;
        a = m[i];
    }
    if(alternating) {return 4;}
    
    if(one_inc) return 5;
    
    return 10;
}

int cache[10000];
const int INF = 33320;

int mem_pi(int start){
    if(start == str.size())   return 0;
    
    int& cost = cache[start];    
    if(cost != -1)  return cost;

    cost = INF;
    
    for(int L=3; L <= 5; L++){
        if(start+L <= str.size())   cost = min(cost, compute_cost(start, start+L-1) + mem_pi(start+L));
    }
    return cost;
}

int main(){
    int c;
    cin >> c;
    for(int test = 0; test < c; test++){
        memset(cache, -1, sizeof(cache));
        cin >> str; 
        cout << mem_pi(0) << endl;
    
    }
    return 0;
}