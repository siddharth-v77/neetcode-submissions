class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,ans=0,n=s.size();
        int count[26]={};

        for(i=0;i<n;i++){
            count[s[i]-'A']++;
            while(i-j+1 - *max_element(count,count+26)>k){
                count[s[j]-'A']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
