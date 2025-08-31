#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
//用什么数据结构保存括号集合
    stack<char> q1;
    for(auto x : s){
        if (x == '{' || x == '(' || x == '['){
            q1.push(x);
        }
        else{
            if (x == '}'){
                if (q1.top() == '{') q1.pop();
                else return false;
            }
             if (x == ')'){
                if (q1.top() == '(') q1.pop();
                else return false;
            }
            if (x == ']'){
                if (q1.top() == '[') q1.pop();
                else return false;
            }
       }    
    }
    if (q1.empty()) return true;
    return true;
}
int main(){
    string s1="()[]{}";
    string s2="(]";
    string s3="([)]";
    cout<<isValid(s1)<<endl;
    cout<<isValid(s2)<<endl;
    cout<<isValid(s3)<<endl;
    return 0;
}