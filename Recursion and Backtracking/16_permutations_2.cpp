#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// My Solution.
// Doing same as in permutation 1, just storing the answers in a set,
// and then putting it in a vector.
class Solution {
private:
    set<vector<int>> st;
    void helper(vector<int>& arr, int index) {
        if (arr.size() == index) {
            st.insert(arr);
            return;
        }
        for (int i = index; i < arr.size(); i++) {
            swap(arr[i], arr[index]);
            helper(arr, index + 1);
            swap(arr[i], arr[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        helper(arr, 0);
        vector<vector<int>> ans;
        for (auto it : st)
            ans.push_back(it);
        return ans;
    }
};

// Without using set solution.
class Solution {
private:
    vector<vector<int>> ans;
    void helper(vector<int>& arr, int index) {
        if (arr.size() == index) {
            ans.push_back(arr);
            return;
        }
        for (int i = index; i < arr.size(); i++) {
            if (index != i && arr[i] == arr[index]) // Skipping all the elements with same value, to avoid duplicates.
                continue;
            swap(arr[i], arr[index]);
            helper(arr, index + 1);
        }
        for (int i = arr.size() - 1; i > index; i--)    // Swapping back all those have been swapped.
            swap(arr[i], arr[index]);
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        sort(arr.begin(), arr.end());   // Sorting the array so that we get duplicates close to each other.
        helper(arr, 0);
        return ans;
    }
};