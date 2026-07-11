class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans ;
        unordered_map<int,int> st;

        for ( auto x : nums){
            st[x]++ ;
        }
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , 
        greater<pair<int,int>> > pq;

        for( auto x : st){
            pq.push(make_pair(x.second , x.first));
            
            if(pq.size() > k){
                pq.pop();
            }
         }
         vector<int> ams;
            while(!pq.empty()){
                pair<int,int> temp = pq.top();
                pq.pop();

                ans.push_back(temp.second);
            }
            return ans;
    }
};
