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
