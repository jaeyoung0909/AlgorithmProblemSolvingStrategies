#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

vector<int> kmpPreprocessing(string& target){
    int size = target.size();
    vector<int> pre(size, 0);
    int end = size-1;
    int count = 0;

    for(int i=0; i < size; i++){
        if(i == 0)  pre[0] = 0;
        else if(target[i] == target[pre[i-1]]){
            pre[i] = pre[i-1]+1;
        }
        else{
            if(target[i] == target[0])  pre[i] = 1;
            
        }
    }

    return pre;
}

// vector<int> kmpPreprocessing(string& N){
//     int m= N.size();
//     vector<int> pi(m, 0);
//     int begin = 1, matched = 0;
//     while(begin + matched < m){
//         if(N[begin+matched] == N[matched]){
//             ++matched;
//             pi[matched+begin-1] = matched;
//         }
//         else{
//             if(matched == 0)    ++begin;
//             else{
//                 begin += matched - pi[matched-1];
//                 matched = pi[matched- 1];
//             }
//         }
//     }
//     return pi;
// }

vector<int> getPrefix(string& s){
    vector<int> prepro = kmpPreprocessing(s);
    vector<int> ret;
    int k = s.size();
    while(k >0){
        ret.push_back(k);
        k = prepro[k-1];
    }
    return ret;
}

int main(){
    char str1[400000];
    char str2[400000];
    scanf(" %s %s", str1, str2);

    const int len1 = strlen(str1);
    const int len2 = strlen(str2);
    char *input;
    input = (char* )malloc(len1+len2+1);
    strcpy(input, str1);
    strcat(input, str2);
    string rst(input);
    vector<int> ret = getPrefix(rst);
    for(int i=ret.size()-1;i>=0; i--){
        printf("%d ", ret[i]);
    }
    return 0;
}
