class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int times;
    public:
    
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums) {
            minHeap.push(i);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        times = k;
    }
    
    int add(int val) {
            if(!minHeap.empty() && minHeap.size() == times && minHeap.top() < val) {
                minHeap.pop();
                minHeap.push(val);
            }
        if(minHeap.size() < times)
            minHeap.push(val);
        return minHeap.top();
     }
};