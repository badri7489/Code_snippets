#include<unordered_map>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;
        st.push(nums2[n - 1]);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (!st.empty())
                mp[nums2[i]] = st.top();    // Mapping all the next greater elements of nums2.
            else
                mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
            ans[i] = mp[nums1[i]];  // Since nums1 is a subset of nums2 we get all the elements with its nge from the map.
        return ans;
    }
};