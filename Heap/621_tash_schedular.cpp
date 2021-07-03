class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //tasks--> A,A,A,B,B
        unordered_map<char, int> count;
        for(auto t: tasks)
            count[t]++;    //count[A] = 3
                            //count[B] = 2
        priority_queue<int> pq;
        for(auto c: count) pq.push(c.second); //pq->3,2
        int result=0; 
        while(!pq.empty())
        {
            vector<int> tmp;
            int time=0;
            for(int i=0;i<(n+1);i++)
            {
                if(!pq.empty())
                {
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t: tmp)
                if(t) pq.push(t);
        result+= pq.empty() ? time : (n+1);
        }
        return result;
     }
};