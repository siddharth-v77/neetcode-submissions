class Solution {
public:

    bool caneatall(vector<int>& piles, int mid, int h){
        double actualhr =0;
       for( int x: piles){
        actualhr += x/mid;

        if(x%mid != 0){
            actualhr++;
        }

       }
       return actualhr <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        double mid = 0;

        int l= 1;
        int r = *max_element(piles.begin(),piles.end());

        while(l<=r){
            mid = l + (r-l)/2;

            if(caneatall(piles,mid,h)){
                r=mid-1;
            }
            else l = mid +1;
        }
return l;
    }
};