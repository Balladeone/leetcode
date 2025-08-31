#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for (size_t i = 0; i <nums.size(); ++i){
        int sum =nums[i];
        //一级剪枝
        if (sum > target && sum >= 0) break;
        //一级去重
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (size_t j = i + 1; j < nums.size(); ++j){
            sum = nums[i] + nums[j];
            //二级去重
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            //二级剪枝
            if (sum > target && sum >= 0) break;
            int left = j + 1;
            int right = nums.size() - 1;
            while(left < right){
                int64_t sum = static_cast<int64_t>(nums[i]) + nums[j] + 
                                                nums[left] + nums[right];
                if (sum == target){
                    vector<int> oneRes = {nums[i], nums[j], nums[left], nums[right]};
                    res.push_back(oneRes);
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right-1]) --right;

                    --right;
                    ++left;
                    }
                else if (sum > target){
                    --right;
                }
                else {
                    ++left;
                }    
            }
        }
    }
    return res;
}