// 1838. Frequency of the Most Frequent Element

// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long int r=0,l=0,n=nums.size(),total=0,maxFreq=1;
        sort(nums.begin(),nums.end());
        for(r=0;r<n;r++){
            total+=nums[r];
            if(l+1<=r && (nums[r]*(r-l+1)>total+k)){
                total-=nums[l];
                l++;
            }
            maxFreq=max(maxFreq,(r-l+1));
        }
        return maxFreq;
    }
};