// class MinStack {
// public:
// stack<pair<int,int>> st;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()) st.push({val,val});
//         else {int minVal = min(val, st.top().second);
//         st.push({val, minVal});}
         
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//          return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second  ;  
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(value);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */




 class MinStack {
public:
    stack<long long int> st;
    long long int minVal;
    MinStack() {
       
    }
    
    void push(int val) {
        if(st.empty()) 
        {st.push(val);
        minVal = val;}
        
        else if (val < minVal){
            st.push((long long) 2 * val-minVal);
            minVal = val;
        } else st.push(val);
    }
    
    void pop() {
        
        if(st.top()<minVal){
            minVal = 2*minVal - st.top();

        }
        st.pop();
    }
    
    int top() {
        if(st.top()<minVal){
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
     return minVal;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */