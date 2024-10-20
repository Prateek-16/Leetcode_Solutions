class MedianFinder {
public:
    priority_queue<int> maxi ;
    priority_queue<int,vector<int>, greater<int> > mini ;
    float median = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.size() == mini.size()){
            if( num > median ){
                mini.push(num);
                median = mini.top();
            }
            else{
                maxi.push(num);
                median = maxi.top();
            }

        }
        else if(maxi.size() == mini.size()+1){
            if(num > median){
                mini.push(num);
            }
            else{
                int temp = maxi.top();
                maxi.pop();
                mini.push(temp);
                maxi.push(num);
            }
            median = float(maxi.top() + mini.top())/2;
        }
        else{//mini.size() = maxi.size()+1
            if(num > median){
                int temp =mini.top();
                mini.pop();
                maxi.push(temp);
                mini.push(num);
            }
            else{
                maxi.push(num);
            }
            median = float(maxi.top() + mini.top())/2;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */