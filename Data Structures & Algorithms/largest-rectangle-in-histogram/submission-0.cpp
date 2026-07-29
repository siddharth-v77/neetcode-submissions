class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;

        for( int i=n-1 ; i>=0; i--){
            while(st.size()>0 && height[i] <= height[st.top()]){
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
 while(!st.empty()) st.pop();

         for( int i=0 ; i<n; i++){
            while(st.size()>0 && height[i] <= height[st.top()]){
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

     

        int ans =0;

        for(int i =0 ; i<n ; i++){
            int width = right[i] - left[i] -1;
            int currentarea = height[i] * width;
            ans= max(ans,currentarea);
        }
        return ans;
    }
};
