#include<bits/stdc++.h>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> myMap;
    for(auto x : magazine){
        auto res = myMap.insert(make_pair(x,1));
        if (!res.second){
            ++res.first->second;
        }
    }
    for (auto y : ransomNote){
        auto it = myMap.find(y);
        if (it != myMap.end()){
            if (myMap[y] > 0)  myMap[y]--;
            else return false;
        }
        else return false;
    }
    return true;
}