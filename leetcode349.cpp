//数组交集问题
#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> myMap;
        for(auto x:nums1){
            if (myMap.count(x) == 0) myMap.insert({x,1});
        }
        for(auto y:nums2){
            if (myMap.count(y) == 1) myMap[y] = 2;
        }
        vector<int> res;
        for(auto kv : myMap){
            if (kv.second == 2) {
                int k = kv.first;
                res.push_back(k);
            }
        }
        return res;
    }
int main(){
    vector<int>nums1;
    vector<int> nums2;
    int number;
    char chr;
    while (cin>>number){
        nums1.push_back(number);
        cin.get(chr);
        if (chr == '\n') break;
    }
    while (cin>>number){
        nums2.push_back(number);
        cin.get(chr);
        if (chr == '\n') break;
    }
    vector<int> res = intersection(nums1,nums2);
    for (auto x : res){
        cout<<x<<" ";
    }
}