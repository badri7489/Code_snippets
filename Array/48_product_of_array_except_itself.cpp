#include<iostream>
#include<vector>
using namespace std;

// O(n) time and O(1) space using division.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int k = 1, n = arr.size(), zero = 0;
        vector<int> ans(n, 0);
        for (int i : arr) {
            if (i == 0) // count number of zeros
                zero++;
            else
                k *= i; // calculate the product.
        }
        if (zero > 1)   // If we have more than one zero, we will get all answers as zero.
            return ans;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)    // if the element is 0
                ans[i] = k;
            else if (zero)  // if there is any zero in the array.
                ans[i] = 0;
            else    // if there is no zeros.
                ans[i] = k / arr[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, arr[0]);    // multiplication of all the elements up till that element from left side.
        vector<int> right(n, arr[n - 1]);   // multiplication of all the elements up till that element from right side.
        vector<int> ans(n);
        for (int i = 1; i < n; i++)
            left[i] = left[i - 1] * arr[i]; // calculate left.
        for (int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] * arr[i];   // calculate right.
        ans[0] = right[1];  // boundary
        ans[n - 1] = left[n - 2];   // boundary
        for (int i = 1; i < n - 1; i++)
            ans[i] = left[i - 1] * right[i + 1];    // the rest of the elements.
        return ans;
    }
};

// doing the same with O(1) space and O(n) time.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size(), prod = 1;
        vector<int> ans(n);
        ans[0] = arr[0];
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * arr[i];
        ans[n - 1] = ans[n - 2];
        for (int i = n - 2; i > 0; i--) {
            prod *= arr[i + 1];
            ans[i] = prod * ans[i - 1];
        }
        ans[0] = prod * arr[1];
        return ans;
    }
};