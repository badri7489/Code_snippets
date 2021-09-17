#include<bits/stdc++.h>
using namespace std;

void rem(unordered_map<char, int>& mp, char ch) {
    if (mp[ch] == 1)
        mp.erase(ch);
    else
        mp[ch]--;
}

long long int for_one(string s) {
    long long int ans = 0;
    unordered_map<char, int> mp;
    int i = -1, j = -1, n = s.length();
    while (true) {
        bool f1 = false, f2 = false;
        while (i < n - 1) {
            f1 = true;
            mp[s[++i]]++;
            if (mp.size() == 2) {
                rem(mp, s[i]);
                i--;
                break;
            }
        }
        while (j < i) {
            f2 = true;
            if (mp.size() == 1)
                ans += i - j;
            j++;
            rem(mp, s[j]);
            if (mp.size() == 0)
                break;
        }
        if (!f1 && !f2)
            break;
    }
    return ans;
}

long long int substrCount(string s, int k) {
    if (k == 1)
        return for_one(s);
    long long int ans = 0;
    unordered_map<char, int> big;
    unordered_map<char, int> small;
    int is = -1, ib = -1, j = -1, n = s.length();
    while (true) {
        bool f1 = false, f2 = false, f3 = false;
        while (ib < n - 1) {
            f1 = true;
            big[s[++ib]]++;
            if (big.size() == k + 1) {
                rem(big, s[ib]);
                ib--;
                break;
            }
        }
        while (is < ib) {
            f2 = true;
            small[s[++is]]++;
            if (small.size() == k) {
                rem(small, s[is]);
                is--;
                break;
            }
        }
        while (j < is) {
            f3 = true;
            if (big.size() == k && small.size() == k - 1)
                ans += ib - is;
            j++;
            rem(big, s[j]);
            rem(small, s[j]);
            if (big.size() < k || small.size() < k - 1)
                break;
        }
        if (!f1 && !f2 && !f3)
            break;
    }
    return ans;
}

int most_k_chars(string& s, int k) {
    unordered_map<char, int> mp;
    long long int ans = 0;
    int left = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        while (mp.size() > k) {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }
        ans += i - left + 1;
    }
    return ans;
}
long long int substrCount(string s, int k) {
    return most_k_chars(s, k) - most_k_chars(s, k - 1);
}

int main() {
    int k;
    string s;
    cout << "INPUT: ";
    cin >> s >> k;
    cout << "Output: " << substrCount(s, k) << endl;
}