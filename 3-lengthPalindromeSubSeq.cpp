class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_map<int,pair<int,int>> mp;
        for(char c='a';c<='z';c++){
            mp[c]={-1,-1};
        }
        int n=s.length();
        for(int i=0;i<n;i++){
            char c =s[i];
            if(mp[c].first==-1)
            mp[c].first=i;
        }
        for(int i=n;i>=0;i--){
            char c=s[i];
            if(mp[c].second==-1)
            mp[c].second=i;
        }
        for(auto p : mp){
            int start=p.second.first;
            int end=p.second.second;
            unordered_set<int> set;
            for(int i=start+1 ;i<end;i++){
                set.insert(s[i]);
            }
            ans+=set.size();
        }
        return ans;
    }
};