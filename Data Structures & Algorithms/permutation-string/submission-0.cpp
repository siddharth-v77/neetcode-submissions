class Solution {
public:
    bool isfreqsame(int freq1[],int freq2[]){
        for(int i=0; i<26 ;i++){
            if(freq1[i] != freq2[i]){
               
                return false ;

            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26]={};
        int n=s1.length();

        for(int i=0;i<n;i++){
            freq[s1[i]-'a']++;
        }
        int windsize = n;
        for(int i=0;i<s2.length();i++){
            int windfreq[26]={};
            int windindex=0,idx=i;
            
            while(windindex < windsize && idx<s2.length()){
                windfreq[s2[idx]-'a']++;
                windindex++ ,idx++ ;
        }

        if(isfreqsame(freq,windfreq)){
            return true;
        }
    }
    return false;
    }
};