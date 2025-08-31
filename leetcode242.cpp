//异位词问题
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    multiset<char> s1;
    multiset<char> t1;
    for(auto x = s.begin(); x != s.end(); x++){
        s1.insert(*x);
    }
    for(auto y = t.begin(); y != t.end(); y++){
        t1.insert(*y);
    }
    if (t1 == s1) return true;
    else return false;
}
int main(){
    string s = "a", t = "aa";
    if(isAnagram(s,t)) cout<<1;
    else cout<<0;
    return 0;
}