class MedianFinder {
public:

priority_queue<int> lmaxheap;
priority_queue<int , vector<int>, greater<int>> rminheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lmaxheap.empty() || num < lmaxheap.top()){
        lmaxheap.push(num);
        }

    else{
        rminheap.push(num);
    }
    
    if(abs((int)lmaxheap.size() - (int)rminheap.size()) > 1){
        rminheap.push(lmaxheap.top());
        lmaxheap.pop();
    }
    else if (lmaxheap.size()<rminheap.size())
      { lmaxheap.push(rminheap.top());
        rminheap.pop();
    }
    }
    
    double findMedian() {
        if(lmaxheap.size() == rminheap.size()){
            double mean = (double)( lmaxheap.top()+rminheap.top())/2 ;
            return mean;
        }
        else return lmaxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */