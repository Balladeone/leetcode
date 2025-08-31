//四数相加II
#include<bits/stdc++.h>
using namespace std;
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int answer=0;
    unordered_map<int,int> myMap1;
    unordered_map<int,int> myMap2;
    for (auto x : nums1) {
        for(auto y : nums2){
            if(myMap1.find(x+y) == myMap1.end()){
                myMap1.insert(make_pair(x+y,1));
            }
            else{
                ++myMap1[x+y];
            }
        }
    }
    for (auto x : nums3) {
        for(auto y : nums4){
            if(myMap2.find(x+y) == myMap1.end()){
                myMap2.insert(make_pair(x+y,1));
            }
            else{
                ++myMap2[x+y];
            }
        }
    }
    for(const auto& pair : myMap1){
        auto res = myMap2.find(0-pair.first);
        if (res != myMap2.end()){
            answer += pair.second * res->second;
        }
    }
    return answer;
}