class CustomStack {
private:
    vector<int> stck;
    int currSize = 0, maxSize = 0;
public:
    CustomStack(int maxSize) {
        stck.resize(maxSize);
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (currSize < maxSize) {
            stck[currSize++] = x;
        }
    }
    
    int pop() {
        if (currSize == 0) return -1;
        else {
            int item = stck[currSize - 1];
            if (currSize > 0) currSize--;
            return item;
        }
    }
    
    void increment(int k, int val) {
        int indx = 0;
        while (k-- > 0 && indx < currSize) {
            stck[indx++] += val;
        }
    }
};