//34. Find First and Last Position of Element in Sorted Array


class Solution {
public:
    int firstOccur(vector<int>& nums, int target){
            int n = nums.size();
            int start = 0;
            int end = n-1;
            int ans1 = -1;
            while(start<=end){
                int mid = start +(end-start)/2;

                if(nums[mid]==target){
                    ans1 = mid;
                    end = mid-1;
                }
                else if(nums[mid]<target){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            return ans1;
        }
public: 
    int lastOccur(vector<int>& nums, int target){
            int n = nums.size();
            int start = 0;
            int end = n-1;
            int ans2 = -1;
            while(start<=end){
                int mid = start +(end-start)/2;

                if(nums[mid]==target){
                    ans2 = mid;
                    start = mid+1;
                    
                }else if(nums[mid]>target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            return ans2;
        }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurance = firstOccur(nums,target);
        int lastOccurance = lastOccur(nums,target);

        if(firstOccurance == -1 || lastOccurance == -1){
            return {-1,-1};
        }
        if(nums.size()==1){
            return{0,0};
        }
        return {firstOccurance,lastOccurance};
    }
};



//35. Search Insert Position



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        for(int i = 0;i<n;i++){
            int mid = (high-low)+low/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
