class MedianFinder {
    priority_queue<int> maxHeap; //by default priority queue stores in                                          decreasing order
    
    priority_queue<int, vector<int>, greater<int>> minHeap; //second arg is                             container type by default it is vector but since                             we need to give 3rd argument to make it minHeap                             we have to give even second;
    
public:
 
    /** initialize your data structure here. */
   
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num ) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        } 
        if(maxHeap.size()  > (1 + minHeap.size())) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if( (1 + maxHeap.size()) < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) return minHeap.empty() ? 0 : ( (minHeap.top() + maxHeap.top()) / 2.0);
      else return maxHeap.size() > minHeap.size() ?  maxHeap.top() :  minHeap.top();
    }
};
