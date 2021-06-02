class Solution {
public:
    bool areInterwoven(string one, string two, string three, int i, int j,vector<vector<int>> &cache)
    {
        if (cache[i][j] != -1)
            return cache[i][j];
        int k = i + j;
        if (k == three.size())
             return true;
        if (i < one.size() && one[i] == three[k]) {
                 cache[i][j] = areInterwoven(one, two, three, i + 1, j, cache);
                 if (cache[i][j] == true)
                         return true;
                 }
        if (j < two.size() && two[j] == three[k]) {
              cache[i][j] = areInterwoven(one, two, three, i, j + 1, cache);
                  return cache[i][j];
        }
        cache[i][j] = false;
        return false;
}
    bool isInterleave(string one, string two, string three) {
        if (three.size() != one.size() + two.size())
        {
            return false;
         }
        vector<vector<int>> cache(one.size()+1, vector<int>(two.size()+1,-1));

         return areInterwoven(one, two, three, 0, 0, cache);
        
    }
};






// Recursive solution
using namespace std;
bool areInterwoven(string one, string two, string three, int i, int j);
// O(2^(n + m)) time | O(n + m) space - where n is the length
// of the first string and m is the length of the second string
bool interweavingStrings(string one, string two, string three) {
if (three.size() != one.size() + two.size()) {
return false;
}
return areInterwoven(one, two, three, 0, 0);
}
bool areInterwoven(string one, string two, string three, int i, int j) {
int k = i + j;
if (k == three.size())
return true;
if (i < one.size() && one[i] == three[k]) {
if (areInterwoven(one, two, three, i + 1, j))
return true;
}
if (j < two.size() && two[j] == three[k]) {
return areInterwoven(one, two, three, i, j + 1);
}
return false;
}