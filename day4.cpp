//78. Subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int subsets = 1<<n;
        for(int i = 0;i<subsets;i++){
            vector<int> list;
            for(int j = 0;j<n;j++){
                if((i & (1<<j))!=0){
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};


//137. Single Number II

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bitIndex = 0;bitIndex < 32;bitIndex++){
            int count = 0;
            for(int i = 0;i<nums.size();i++){
                if((nums[i]&(1<<bitIndex)) != 0){
                    count++;
                }
            }
            if(count % 3 == 1){
                ans = ans| (1<<bitIndex);
            }
        }
        return ans;
    }
};



// 260.  Single Number III



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};