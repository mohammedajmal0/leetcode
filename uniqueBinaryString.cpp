// 1980. Find Unique Binary String
// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         int n=nums.size();
//         string ans="";
//         for(int i=0;i<n;i++){
//             char c=nums[i][i];
//             ans+= c=='1' ? '0' : '1';
//         }
//         return ans;
//     }
// };

// updated code with less time complexity

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans="";
        for(int i=0;i<n;i++){
            char c=nums[i][i];
            ans.push_back(c=='1'? '0' : '1');
            // if(c=='1')
            // ans.push_back('0');
            // else
            // ans.push_back('1');
        }
        return ans;
    }
};