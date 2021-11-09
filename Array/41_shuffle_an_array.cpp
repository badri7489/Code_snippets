#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> og;
    int n;
public:
    Solution(vector<int>& nums) {
        this->og = nums;
        n = nums.size();
    }

    vector<int> reset() {
        return og;
    }

    // Fisher Yates Algorithm
    vector<int> shuffle() {
        vector<int> arr(og);
        int pos;
        // Shuffling all the elements upto the ith postion.
        for (int i = 0; i < n; i++) {
            pos = rand() % (n - i);
            swap(arr[i + pos], arr[i]); // Swapping the postions
        }
        return arr;
    }
};

class Solution {
private:
    vector<int> og;
    vector<int> arr;
    int n;
public:
    Solution(vector<int>& nums) {
        this->og = this->arr = nums;
        n = nums.size();
    }

    vector<int> reset() {
        return og;
    }

    vector<int> shuffle() {
        int x = rand() % n;
        int y = rand() % n;
        swap(arr[x], arr[y]);   // Choosing any two elements and swapping them.
        return arr;
    }
};