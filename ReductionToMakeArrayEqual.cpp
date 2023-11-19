// 1887. Reduction Operations to Make the Array Elements Equal
// Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps:

// Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. If there are multiple elements with the largest value, pick the smallest i.
// Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
// Reduce nums[i] to nextLargest.
// Return the number of operations to make all elements in nums equal.

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size(),count=0;
        sort(nums.begin(),nums.end());
        // int max=nums[n-1];
        // int secondMax;
        // for(int i=n-1;i>=0;i--){
        //     if(nums[i]!=max){
        //         secondMax=nums[i];
        //         int j=i;
        //         while(j<n-1){
        //             j++;
        //             nums[j]=secondMax;
        //             // j++;
        //             max=secondMax;
        //             count++;
        //         }
                
        //     }
        // }

        // optimized solution
        int start=0;
        int smallest=nums[0];
        while(start<n && nums[start]==smallest){
            start++;
        }
        int initialId=0;
        
        for(int i=start;i<n;i++){
            if(nums[i]!=nums[i-1])
            initialId++;
            count+=initialId;
        }
        return count;
    }
};