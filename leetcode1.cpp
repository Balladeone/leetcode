//两数之和，用哈希法的原因：仅判断元素存在性问题就可以考虑哈希
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> myMap;
    vector<int> res;
    for (size_t i = 0; i < nums.size(); ++i){
        if (myMap.find(target-nums[i]) == myMap.end()){
            myMap.insert(make_pair(nums[i],i));
        }
        else{
            res.push_back(i);
            res.push_back(myMap[target-nums[i]]);
            return res;
        }
    }
    return res;
    