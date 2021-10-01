#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<set>
using namespace std;

// DFS Traversal.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Each node(airport) contains a set of outgoing edges (destination).
        unordered_map<string, multiset<string>> adj;
        // We are always appending the deepest node to the itinerary,
        // so we will need to reverse the itinerary in the end.
        // Creating the adjacency list, using map.
        for (vector<string>& t : tickets) {
            adj[t[0]].insert(t[1]);
        }
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {
            string src = st.top();
            if (adj[src].size() == 0) {
                // If there is no more outgoing edges, append to itinerary
                // Two cases:
                // 1. If it searches the terminal end first, it will simply get
                //    added to the itinerary first as it should, and the proper route
                //    will still be traversed since its entry is still on the stack.
                // 2. If it search the proper route first, the dead end route will also
                //    get added to the itinerary first.
                ans.push_back(src);
                st.pop();
            } else {
                // Otherwise push the outgoing edge to the dfs stack and
                // remove it from the node.
                auto dst = adj[src].begin();
                st.push(*dst);
                adj[src].erase(dst);
            }
        }
        // Reverse the itinerary.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};