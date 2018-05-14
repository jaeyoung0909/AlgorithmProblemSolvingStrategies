#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

string W; 
string ex;
int cache[101][101];

bool match(int w, int s){

    int& ret = cache[w][s];
    if(ret != -1)   return ret;
    if(W.size()>w && ex.size()> s && (W[w]=='?' || W[w]==ex[s])){
        return ret = match(w+1, s+1);
    }
    if(W.size() == w)   return ret = (ex.size()== s);
    if(W[w] == '*'){
        if(match(w+1, s) || (ex.size()>s && match(w,s+1)))
            return ret = 1;
    }
    return ret = 0;
}

int main(){
    int C;
    cin >> C;
    for(int test=0; test<C; test++){
        
        cin >> W;

        int exs;
        cin >> exs;
        vector<string> ret;
        for(int i=0; i<exs; i++){
            cin >> ex;
            memset(cache, -1, sizeof(cache));
            if(match(0, 0))    ret.push_back(ex);
        }
        sort(ret.begin(), ret.end());

        for(int i=0 ;i<ret.size(); i++){
            cout << ret[i] << endl;
        }
    }
    return 0;
}