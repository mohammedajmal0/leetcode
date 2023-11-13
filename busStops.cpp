class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> busStopToBid; // here we reverse map routes to bus_id
        /*
            example busstops   bid
                        1       {0,7} indicates that at bus stop 1 bus.no 0 and bus.no 7 meets
        */
        for(int i=0;i<routes.size();i++){
            int bid=i;
            vector<int> busStops=routes[i];
            for(auto busStop : busStops){
                busStopToBid[busStop].push_back(bid);
            }
        }
        queue<pair<int,int>> q; // current stop , bus changed
        q.push({source,0});
        unordered_map<int,bool> busVisited,busStopVisited;
        busStopVisited[source]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                int currStop=p.first;
                int busTravelled=p.second;
                if(currStop==target) return busTravelled;
                for(auto bus: busStopToBid[currStop]){
                    if(busVisited[bus]) continue;
                    busVisited[bus]=true;
                    for(auto stop : routes[bus]){
                        if(busStopVisited[stop]) continue;
                        busStopVisited[stop]=true;
                        q.push({stop,busTravelled+1});
                    }
                }
            }
        }
        return -1;    
    }
};