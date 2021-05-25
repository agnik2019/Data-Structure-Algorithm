// OUR PATTERN POP-> ANS -> PUSH

//Approach-1 (stack and using idx variable for trackign index)

 class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index = -1;
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) 
    {
      index++;
      while(!st.empty() && st.top().first<= price )
        st.pop();
      int res = 1;
      res = (st.empty())?index+1: index-st.top().second;
      st.push({price, index});
      return res;           
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */





//Approach-2 (Stack and using count variable)
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!st.empty() && st.top().first <= price) {
            count += st.top().second;
            st.pop();
        }
        
        st.push({price, count});
        
        return count;
        
    }
};