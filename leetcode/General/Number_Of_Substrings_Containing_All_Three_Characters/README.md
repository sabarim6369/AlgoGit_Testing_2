# [Number Of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

![LeetCode](https://img.shields.io/badge/LeetCode-#2c2c2c?style=flat&logo=leetcode&logoColor=white)  
![C++](https://img.shields.io/badge/C++-17-blue)  
![License](https://img.shields.io/badge/license-MIT-green)  

## 📝 Problem Statement

You are given a string **s** consisting only of the characters `'a'`, `'b'`, and `'c'`.  
Return the number of substrings of **s** that contain **at least one occurrence of each** of these three characters.

**Examples**

| Input | Output | Explanation |
|-------|--------|-------------|
| `"abcabc"` | `10` | The valid substrings are: `abc`, `abca`, `abcab`, `abcabc`, `bca`, `bcab`, `bcabc`, `cab`, `cabc`, and `abc` (the second occurrence). |
| `"aaacb"` | `3` | The valid substrings are: `aaacb`, `aacb`, and `acb`. |
| `"abc"` | `1` | Only the substring `"abc"` satisfies the condition. |

### Constraints

- `3 <= s.length <= 5 × 10⁴`
- `s` consists only of the characters `'a'`, `'b'`, and `'c'`.

## 💡 Approach & Intuition

The task is to count **substrings** (contiguous subsequences) that contain all three distinct characters.  
A naive \(O(n^2)\) enumeration of all substrings followed by a check would be too slow for \(n=5·10^4\).

We can solve this in linear time using a **sliding window** (two‑pointer) technique:

1. Maintain a window \([left, right]\) that currently contains all three characters.
2. Move the right pointer one step at a time, adding the new character to a frequency map.
3. Once the window has all three characters, every extension of the current window to the right (i.e. `right+1 ... n-1`) also contains all three characters.  
   Therefore, for the current `right`, the number of valid substrings ending at `right` is `n - right`.  
4. We then shrink the window from the left while it still contains all three characters, counting each shrink as another valid substring.  
   Shrinking reduces the window size but still keeps all three characters, so every new left position still yields a valid substring ending at the same `right`.  
   This process ensures each valid substring is counted exactly once.

Mathematically, for each `right` we add
\[
\text{count} \;\gets\; \text{count} + (n - \text{right})
\]
whenever the window first becomes valid.

The algorithm uses a hash map of size at most 3 (constant space) and visits each character a constant number of times (left and right pointers), hence \(O(n)\) time.

## 📋 Step‑by‑Step Algorithm

1. **Initialize**  
   - `left = 0`, `count = 0`  
   - Frequency map `freq` (empty).  
2. **Iterate** `right` from `0` to `n-1`  
   a. Add `s[right]` to `freq` (`freq[s[right]]++`).  
   b. While `freq` contains all three characters (`freq.size() == 3`):  
      i. Increment `count` by `n - right` (all extensions to the right are valid).  
     ii. Remove `s[left]` from the window: decrement its frequency; if it becomes zero, erase it from the map.  
    iii. Move `left` one step right (`left++`).  
3. **Return** `count`.

## ⏱️ Complexity Analysis

| Metric | Complexity | Description / Justification |
|--------|------------|-----------------------------|
| ⏱️ **Time Complexity** | `O(n)` | Each character is processed by the right pointer once and the left pointer moves at most `n` times. |
| 💾 **Space Complexity** | `O(1)` | The frequency map holds at most 3 entries (`'a'`, `'b'`, `'c'`). |

## 💻 Code Solution

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int left = 0;
        long long count = 0;  // use long long to avoid overflow for large n

        for (int right = 0; right < n; ++right) {
            freq[s[right]]++;

            // When all three characters are present, every extension to the right
            // of the current window will also be valid.
            while (freq.size() == 3) {
                count += n - right;          // add all substrings ending at 'right'
                freq[s[left]]--;              // shrink window from the left
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);      // remove character when count hits zero
                }
                ++left;
            }
        }
        return static_cast<int>(count);
    }
};
```

*The solution follows the described sliding window strategy, ensuring linear time and constant auxiliary space.*