// 1424. Diagonal Traverse II
// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,4,2,7,5,3,8,6,9]
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
static const int _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>> q;
        vector<int> ans;
        q.push({0,0});
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [i,j] = q.front();
                q.pop();
                ans.push_back(nums[i][j]);
                if(j==0 && i+1 < nums.size()){
                    q.push({i+1,j});
                }
                if(j+1<nums[i].size()){
                    q.push({i,j+1});
                }
            }
        }
        return ans;
    }
};