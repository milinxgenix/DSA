                                    // 2 Pointers
// Use to manipulate Array without creating new one (No auxilary/Extra space)  :- In-Place Technique




                            // Check if a Pair Sums to Target (Sorted Array)   :- Won't work in Q-1 LeetC (Two Sum) as array was not sorted there
/*
#include <iostream>
#include <vector>
using namespace std;

bool hasPairWithSum(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 9};
    int target = 10;

    if (hasPairWithSum(arr, target))
        cout << "Pair Found\n";
    else
        cout << "No Pair Found\n";

    return 0;
}
*/ 



                                    // Reverse a Vector Using 2 Pointers
/*
void reverseVector(vector<int> &v) {
    int left = 0, right = v.size() - 1;

    while (left < right) {
        swap(v[left], v[right]);
        left++;
        right--;
    }
}
*/



                                    // Remove Duplicates from Sorted Array
/*
int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) return 0;

    int i = 0;                                          // slow pointer
    for (int j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;  // new length
}
*/



                                        // Move Zeros to End
/*
void moveZeros(vector<int> &nums) {
    int lastNonZero = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[lastNonZero]);
            lastNonZero++;
        }
    }
}
*/



                                    // Valid Palindrom - LeetC - 125
/*       
class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}                       //If the start character is not a letter or digit, skip it
           if(!isalnum(s[end])){end--; continue;}                           //continue restarts the loop without doing the comparison 
           if(tolower(s[start])!=tolower(s[end]))return false;              // compare alphanum keys, after converting to lowercase 
           else{                                                            
               start++;                                                     // if start and end matched then move inwards for next match
               end--;
           }
       }
       return true;
}
};
*/


                                // Valid Palindrom - 2 LeetC - 680
//     {Better to understand} 
/*                         
class Solution {
public:
    bool checkP(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }


    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            if(s[start] != s[end]){
                return checkP(s, start+1, end) || checkP(s, start, end-1);      //where ever getting mismatch, we will skip one char either from start or end and check if remaining string is palindrome or not 
            }
            start++;
            end--;
        }
        return true;
    }
};
*/ 
                // ✅ Final Complexity Summary
                // Time Complexity: O(n)
                // Space Complexity:
                // Current code: O(n) (because we passed a copy of string as an argument in func)
                // Optimized space - (const string&): O(1)              //Passing address instead of copy of value of string 


                
// To avoid function call {Tough to understand}
/* 
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            if (s[start] != s[end]) {                               // 1st mismatch found which needed to be replaced

        // 1st case : Try skipping s[start]
                int left = start + 1;
                int right = end;
                while (left <= right && s[left] == s[right]) { 
                    left++; 
                    right--;
                }
                if (left > right) return true;                      // Palindrome if skipping s[start] works return true here only don't go for below case

        // 2nd case : Try skipping s[end] if 1st case didn't give palindrome
                left = start;
                right = end - 1;
                while (left <= right && s[left] == s[right]) { 
                    left++; 
                    right--; 
                }
                return left > right;                                // Palindrome if skipping s[end] works
            }

            // If characters match, move inward
            start++;
            end--;
        }

        // If loop finishes → already palindrome
        return true;
    }
};
*/
                    // ✅ Final Complexity
                    // Time Complexity: O(n)
                    // Space Complexity: O(1)   Optimised space as no function call recursion 





                                        // LeetC-2108. Find First Palindromic String in the Array
/*                                        
class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(auto &s : words){
            bool flag = true;
            int str = 0;
            int end = s.length()-1;

            while(str<=end){
                if(s[str]!=s[end]){
                    flag = false;
                    break;
                }
                str++;
                end--;
            }
            if(flag){
                return s;
            }
        }
        return "";
    }
};
*/


// more easy if create a separate palindrome check fn
/* 
class Solution {
    bool isPalindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &s : words) {
            if (isPalindrome(s)) return s;
        }
        return "";
    }
};
 */

 // Time Comp : O(n·m)     n - each string length    m - no of strings in "word" array
 // Space com : O(1)


 