#include <iostream>
#include <string>

using namespace std;

string reverse(string::iterator& it){
    char head = *it;
    it++;
    if(head == 'w'||head == 'b'){
        return string(1, head);
    }
    string leftupper = reverse(it);
    string rightupper = reverse(it);
    string leftlower = reverse(it);
    string rightlower = reverse(it);
    return string("x")+leftlower + rightlower+leftupper+rightupper;
}

int main(){
    int C;
    cin >> C;
    for(int test=0; test<C; test++){
        string str;
        cin >> str;
        string::iterator it = str.begin();
        str = reverse(it);
        cout << str <<endl;
    }
    return 0;
}