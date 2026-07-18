class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int i=0;
        int j=1;
        int l =1;
        int n = s.size();

        if(n == 0) return 0;
        us.insert(s[i]);
        while(j<n && i<=j){
            while( j<n && us.find(s[j]) == us.end()){
                us.insert(s[j]);
                j++;
            }
            if(j-i>l){
                l=j-i;
            }
            us.erase(s[i]);
            i++;
        }
        return l;
    }
};