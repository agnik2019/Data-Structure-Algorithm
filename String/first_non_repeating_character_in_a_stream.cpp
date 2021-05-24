/*
Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is 
inserted to the stream and append it at the end to B. If no non-repeating character is found then 
append '#' at the end of B.


Input:   A = "abadbc"
Output:  "aabbdd"
*/
string Solution::solve(string A) {
    vector<char>v;
    unordered_map<char, int>m;
    string result;
    int i = 0;
    for(char c: A) {
        v.push_back(c);
        m[c]++;
        for (; i < v.size(); i++) {
            if (m[v[i]] == 1) {
                result.push_back(v[i]);
                break;
            }
        }
        if (i >= v.size()) {
            result.push_back('#');
        }
    }
    return result;
}
