//平方和归一数
#include<bits/stdc++.h>
using namespace std;
int countSquare(int n){
    int sum=0;
    int val=n;
    while (val>0){
        int num=val%10;
        sum+=pow(num,2);
        val=val/10;
    }
    return sum;
}
bool isHappy(int n) {
    int val=n;
    set<int> mySet;
    while (val != 1){
        val=countSquare(val);
        auto result = mySet.insert(val);
        if (result.second==false) {
            return false;
        }
    }
    return true;
}