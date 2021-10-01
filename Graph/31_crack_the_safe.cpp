#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Solution {
private:
    unordered_set<string> visited;
    string ans;
    int total;
    bool dfs(int n, int k) {
        if (visited.size() == total)
            return true;
        for (int i = 0; i < k; i++) {
            ans.push_back(i + '0');
            string curr = ans.substr(ans.size() - n);   // Taking string of length n
            if (visited.find(curr) == visited.end()) {  // If the string is not in the set we insert in the set.
                visited.insert(curr);
                // We recursively travel and append for each and every combinations by adding k at the end and function call.
                if (dfs(n, k))
                    return true;
                visited.erase(curr);    // If not reached the end of all combinations we remove that string from the set.
            }
            ans.pop_back();
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        ans.resize(n, '0');
        total = pow(k, n);
        visited.insert(ans);    // Marking the source as visited.
        dfs(n, k);
        reverse(ans.begin(), ans.end());    // Reversing for the exact same euler path.
        return ans;
    }
};