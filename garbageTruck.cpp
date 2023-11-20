// 2391. Minimum Amount of Time to Collect Garbage
// You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

// You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

// There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

// Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

// Return the minimum number of minutes needed to pick up all the garbage.

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char,int> last;
        int n=garbage.size(),ans=0;
        for(int i=0;i<n;i++){
            ans+=garbage[i].size();
            for(auto c : garbage[i]) last[c]=i;
        }
        for(int i=1;i<travel.size();i++){
            travel[i]+=travel[i-1]; // prefix sum[1,2,3]=>[1,3,6]
        }
        for(auto c : "MPG"){
            if(last[c]!=0)
            ans+=travel[last[c]-1];
        }
        return ans;
    }
};