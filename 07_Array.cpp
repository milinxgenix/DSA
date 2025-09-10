                                        // 1. Largest Element in Array

// Optimized: Iteration (Linear Searching)     Time : O(N)      Space : O(1)       ✅ better than sorting
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"-1 to stop giving inputs"<<endl;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }
    int max = INT_MIN;                          //insted of INT_MIN, v[0] can be also be taken 
    for(int i=0; i<v.size(); i++){
        if(v[i]>max){
            max = v[i];
        }
    }
    cout<<max;
    return 0;
}
*/



// Brute Force :- Sorting           Time : O(N*log(N))              Space : O(n)
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"-1 to stop giving inputs"<<endl;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    cout<<*(v.end()-1)<<endl;
    cout<<v.back();
}
 */


                 

                                        // 2. Second Largest & Second Smallest 

//Brute Force      Time Complexity: O(NlogN)            Space Complexity: O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"-1 to stop giving inputs"<<endl;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    if (v.size() < 2) {
        cout << "-1" << endl;
    }

    // Sort the vector first
    sort(v.begin(), v.end());

// unique() moves unique elements to front(beginning of array) and return an iterator to last unique element
    auto it = unique(v.begin(), v.end());

// Erase the trailing duplicates
    v.erase(it, v.end());                       // erase from it(last unique element) to the end of array ; all the duplicates coming after unique elements will be removed

    cout<<"2nd largest: "<<*(v.end()-2)<<endl;
    cout<<"2nd smallest: "<<*(v.begin()+1);
}
   */                              




// Slight better :              Time : O(2N)  Traversed Twice         Space : O(1)
/* 
#include<iostream>
#include<climits>                                   // for INT_MAX & INT_MIN
using namespace std;
void getElements(int arr[],int n)
{
    if(n==0 || n==1){
        cout<<-1<<" "<<-1<<endl;                    // edge case when only one element is present in array
        return;
    }

    int small=INT_MAX, second_small=INT_MAX;
    int large=INT_MIN, second_large=INT_MIN;
    int i;

// Finding the smallest and largest :
        for(i=0;i<n;i++)
        {
            small=min(small,arr[i]);
            large=max(large,arr[i]);
        }

// Finding the 2nd smallest and 2nd largest :
        for(i=0;i<n;i++)
        {
            if(arr[i]<second_small && arr[i]!=small)
                second_small=arr[i];
            if(arr[i]>second_large && arr[i]!=large)
                second_large=arr[i];
        }

// Handle edge case where all elements are same
    if (second_small == INT_MAX)
        cout << "No second smallest exists" << endl;
    else
        cout << "Second smallest is " << second_small << endl;

    if (second_large == INT_MIN)
        cout << "No second largest exists" << endl;
    else
        cout << "Second largest is " << second_large << endl;
}

int main()
{
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    getElements(arr,n);
    return 0;
} 
*/
 


// Optimal Approach :     Single time traversal     Time : O(N)   space : O(1)     
/* 
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    if (n < 2) {
        cout << "Not enough elements" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;


    for (int i = 0; i < n; i++) {
        // 2nd largest
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }

        // 2nd smallest
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    if (max2 == INT_MIN || max2 == max1)
        cout << "No distinct 2nd largest element" << endl;
    else
        cout << "2nd largest: " << max2 << endl;

    if (min2 == INT_MAX || min2 == min1)
        cout << "No distinct 2nd smallest element" << endl;
    else
        cout << "2nd smallest: " << min2 << endl;

    return 0;
}
 */



 

                                        // 3. Sorted in Ascending or NOT

// Brute force :- using nested loops   Time - O(n^2)   space - O(1)   


// Optimal Approach :-  Time - O(n)  Space - O(1)  
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool isSorted = true;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            isSorted = false;
            break;
        }
    }
    cout<<(isSorted ? "True" : "False");
}
 */



                                    // Sorted in either Ascending or Descending
// Same T&S compl. as above
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool isSorted = true;
    if(arr[0]<arr[1]){                        // checking ascending series
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                isSorted = false;
                break;
            }
        }
    }

    else{                                    // checking descending series
        for(int i=0; i<n-1; i++){
            if(arr[i]<arr[i+1]){
                isSorted = false;
                break;
            }
        }
    }

    cout<<(isSorted ? "True" : "False");
} 
*/






                                //    Leet-C 1752  (Check if Array Is Sorted and Rotated)

/*
// class Solution {
// public:
//     bool isSortedArray(const vector<int>& arr) {                    // Funct to check whether it's Sorted or not
//         for (int i = 0; i < arr.size() - 1; i++) {
//             if (arr[i] > arr[i + 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         int min1 = 0, min2 = 0;

//         for (int i = 0; i < n; i++) {
//             if (nums[min1] > nums[i]) min1 = i;              // Occurance of minimest element for 1st time
//         }

//         for (int i = 0; i < n; i++) {
//             if (nums[min2] >= nums[i]) min2 = i;            // Last occuring index of minimest element
//         }

//         vector<int> arr1 = nums;
//         vector<int> arr2 = nums;

//         rotate(arr1.begin(), arr1.begin() + min1, arr1.end());
//         rotate(arr2.begin(), arr2.begin() + min2, arr2.end());

//         return isSortedArray(arr1) || isSortedArray(arr2);
//     }
// };
*/

//  1 Test Case failed cause in this rotation taking place only about 1st and last min element found 
//  Below one ⤵️ is correct as we are rotating for all minimum positions 

//  int minIndex = min_element(nums.begin(), nums.end()) - nums.begin(); 
//  int minVal   = *min_element(nums.begin(), nums.end());                          -- BuiltIN functions




                                // Time - O(n), worst - O(n^2)  && Space - O(n)
/*
class Solution {
public:
    bool isSorted(vector<int>& nums){                   // Function to check Sorted or not
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());           // Built-In func to find minimest element in array 

        for(int i=0; i<nums.size(); i++){                           // Finding all minimum values at diff index and rotating for each of them
            if(nums[i] == min){
                vector<int> arr(nums);                              // Copy constructor to copy elements of one vector to another
                rotate(arr.begin(), arr.begin()+i, arr.end());      // Rotating by each i (i is indices at which min value is present)
                if(isSorted(arr)){
                    return true;                                    // Don't directly return isSorted(arr) as it will check for 1st min rotation only
                } 
            }
        }
        return false;
    }
};
*/




// Another method -- more optimised solution   ;-  Time - O(n)  && Space - O(1)
/* 
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

// Count drops (places where previous > current)
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
    
// Also check the "wrap-around" drop: last > first
        if(nums[n-1]>nums[0]){                                // nums[n-1] is the last element 
            cnt++;
        }
        return cnt<=1;                                        // Return true only if count is equal or smaller than 1
    }
};
 */


// check for number of rotations and wrap-around condition
// There should be single rotation (one 1 drop so count<=1) and also do wrap around to check below testcase conditions
// count <=1 as [3,4,5,1,2]  one drop is allowed "5>2" -- "{nums[i-1]>nums[i]}" in sorted array this thing can be occur for atmost 1 time it there's some rotation
// cnt == 0 → Already sorted (no rotation needed)
// cnt == 1 → Valid rotated sorted array (one rotation point)
// cnt > 1 → Not valid (more than one inversion → can't fix by one rotation)  
// wrap-around drop :- [2, 1, 3, 4]  :-  
/*
Drops in loop:
    2 > 1 ❌ → 1 drop
    1 < 3 ✅
    3 < 4 ✅

Check wrap-around:
    4 > 2 ❌ → extra drop ⇒ cnt = 2  so false...     instead of '2' there should be numb>4 then it would be sorted and return true.
*/







                                // 4. Remove Duplicates in-place from SORTED Array

// Brute-Force :- Didn't use In-Place  tech   Time:- O(n)  Space :- O(n)
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> v;
    for(int i=0; i<n; i++){
        if(arr[i]!=arr[i+1]){
            v.push_back(arr[i]);
        }
    }
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}
*/



// Using Hash-Set as it's doesn't stores duplicate elements   (Not an In-Place tech, need to create a extra data structure)
/*                  Time : O(n*log(n))+O(n)    space : O(n) 
#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    set <int> s;
    for(int i=n-1; i>0; i--){
        s.insert(arr[i]);
    }
    
    int j = 0;
    for (int x: s) {                // placing the set elements into array and replacing old array elements
      arr[j++] = x;
    }

    n = s.size();                   // Redefined the size of array equvalence to set size garbage duplicate values will be trimmed out
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
 */



// Two Pointer :- Optimised sol for removing duplicates using In-Place    Time :- O(n)   Space :- O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    if(n==0){                       //Empty Array
        cout << "0";
        return 0;
    }

    int i=0;
    for(int j=1; j<n; j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
// after this loop arr will be transformed to [1,2,3,_,_,_,_]

    n = i+1;                             // change the lenght of array and trimmed it to i+1 means upto 3
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
} 
*/



                                        // LeetC - 26 Remove Duplicates from sorted array
/*                                        
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for(int j=1; j<nums.size(); j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};                
*/






                                        // 5. Left Rotate the Array by One
// Brute Force :        T - O(n)   S - O(n) 
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"-1 to stop taking element input"<<endl;
    vector<int> v;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    int n = v.size();
    int temp[n];                   // Created extra array (don't create vector, As "temp[i-1] = v[0]" this syntax doesn't works in vector)
    for(int i=1; i<n; i++){
        temp[i-1] = v[i];
    }
    temp[n-1] = v[0];

    for(int i = 0; i<n; i++){
        cout<<temp[i]<<" ";
    }
    return 0;
}
 */



// 2-Pointer        T - O(n)    S - O(1)
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"-1 to stop taking element input"<<endl;
    vector<int> v;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    int n = v.size();
    int temp = v[0];                                // storing 1st element in temp to switch with last, at the end

    int i = 0;
    for(int j=1; j<n; j++){
        v[i] = v[j];
        i++;
    }
    
    // for (int i = 0; i < n - 1; i++) {            // instead of 2 pointers, it can be done like this also
    //   arr[i] = arr[i + 1];
    // }

    v[n-1] = temp;                                  // assigning last element as temp

    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}
*/



// Using Built-IN function:
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"-1 to stop taking element input"<<endl;
    vector<int> v;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    rotate(v.begin(), v.begin()+1, v.end());

    for(int i:v){
        cout<<i<<" ";
    }
} 
*/



                                    // 6. Rotate an array by D places in either Left/Right
// Bruteforce :- T - O(n*k)     S - O(1)
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"-1 to stop taking element input"<<endl;
    vector<int> v;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    cout<<"enter value of K: "<<endl;
    int k;
    cin>>k;

    int n = v.size();
    if (n == 0)                 //Empty Array
      return 0;
    k = k % n;                  // Finding the number of rotations possible        if k = n, means 1 complete rotation means elements back to same positions           

    cout<<"Enter rotation direct(Right/Left)"<<endl;
    string d;
    cin>>d;

    if(d=="Left"){
        while(k>0){
            int temp = v[0];
            for(int i=0; i<n; i++){
                v[i] = v[i+1];
            }
            v[n-1] = temp;
            k--;
        }
    }
    if(d=="Right"){
        while(k>0){
            int temp = v[n-1];
            for(int i=n-1; i>=0; i--){
                v[i] = v[i-1];
            }
            v[0] = temp;
            k--;
        } 
    }

    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}  
*/



                                        // Brute Force :-   T-O(n)    S-O(k)
// For Rotating the Elements to left :
/* #include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"-1 to stop taking element input"<<endl;
    vector<int> v;
    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }

    cout<<"enter value of K: "<<endl;
    int k;
    cin>>k;

    int n = v.size();
    if (n == 0)                 //Empty Array
      return 0;
    k = k % n;                  // Finding the number of rotations possible            if n=5 and k=6 then 6th rotation is same as 1st rotation so {k = k%n (6%5=1)} 



    int temp[k];                        // Storing 1st 'k' elements
    for(int i=0; i<k; i++){
        temp[i] = v[i];
    }

    for(int i=k; i<n; i++){             // Left Shifting remaining elements by 'K'
        v[i-k] = v[i]; 
    }


    for(int i=n-k; i<n; i++){            // placing-back 1st 'k' element at last
        v[i] = temp[i-(n-k)];
    }

    // int j=0;
    // for(int i=n-k; i<n; i++){           // placing-back 1st 'k' element at last (can be done this way also)
    //     v[i] = temp[j];
    //     j++;
    // }

    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
} 
*/



// For Rotating the Elements to Right :   
/* 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "-1 to stop taking element input" << endl;
    vector<int> v;
    while (true) {
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }
        v.push_back(x);
    }

    cout << "Enter value of K: " << endl;
    int k;
    cin >> k;

    int n = v.size();
    if (n == 0) return 0;

    k = k % n;

    // Store last k elements in temp
    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = v[n - k + i];
    }

    // Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        v[i] = v[i - k];
    }

    // Put the temp values in front
    for (int i = 0; i < k; i++) {
        v[i] = temp[i];
    }

    // Print rotated array
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
 */



                            // Optimal Approach (Left Rotation)  -- for right check leetC soln
//  T - O(N)  &  S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout << "-1 to stop taking element input" << endl;
    vector<int> v;
    while (true) {
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }
        v.push_back(x);
    }

    cout << "Enter value of K: " << endl;
    int k;
    cin >> k;

    int n = v.size();
    if (n == 0) return 0;

    k = k % n;


    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    reverse(v.begin(),v.end());

// For manual reversing :
// void Reverse(int arr[], int start, int end){
//     while(start<=end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }
    
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
 */


// Using Buit-IN Funct:       
// Left :- rotate(v.begin(), v.begin()+k, v.end());
// Right :- rotate(v.begin(), v.end()-k, v.end());





                                        // Leet-C 189 (Rotation of Array by 'K')
// Brute Force :- time limit exceeds   
/*                  T - (O*k)  S - O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return;
        k = k % n;

        while(k>0){
            int temp = nums[n-1];
            for(int i=n-1; i>0; i--){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            k--;
        }
    }
}; 
*/


// Accepted bruteForce :            T - O(n+d)   S - O(k)
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = k % n;  // handle k > n

        // Step 1: Store last k elements
        vector<int> temp(k);
        for(int i = 0; i < k; i++){
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift the first n-k elements to the right by k positions
        for(int i = n - 1; i >= k; i--){
            nums[i] = nums[i - k];
        }

        // Step 3: Copy temp elements to the beginning
        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};
*/



// Optimal Approach :-  T - O(2n)   S - O(1)
/* 
class Solution {
public:
    void Reverse(vector<int>& nums, int start, int end){
        while(start <= end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        //  swap(nums[start],nums[end])         // could be done like this also
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;

        Reverse(nums, 0, n-k-1);
        Reverse(nums, n-k, n-1);
        Reverse(nums, 0, n-1);
    }
}; 
*/



// Optimal approach without manual reversing
/* 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
    }
}; 
*/



// using built-in funt:   T - O(n)   S - O(1)
/* 
#include <algorithm>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        std::rotate(nums.begin(),nums.end()-k, nums.end());
    }
};  
*/




                                                // 7. Move Zeros to end

// Brute Force          T - O(n^2)      S - O(n)                {Nested Loops}
/* 
#include<iostream>
#include<string>
using namespace std;
void shiftZero(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
            }
        }
    }
    for(int i:nums){
        cout<<i<<" ";
    }
}
int main()
{
    vector<int> nums;
    cout<<"Enter any negative element to stop taking input: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    shiftZero(nums);
    return 0;
}  
 */




// Brute Force          T - O(2*n)      S - O(n)                      {Auxiliary Vector}
/* 
#include<iostream>
#include<string>
using namespace std;
void shiftZero(vector<int> nums){
    vector<int> v;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            v.push_back(nums[i]);
        }
    }

    for(int i=v.size(); i<nums.size(); i++){
        v.push_back(0);
    }

    for(int i=0; i<nums.size(); i++){
        cout<<v[i];
    }
}

int main()
{
    vector<int> nums;
    cout<<"Enter any negative element to stop taking input: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    shiftZero(nums); 
    
    return 0;
}
 */




//  Optimal Approach         T - O(n)        S - O(1)                   {Two Pointer}
/* 
#include<iostream>
#include<string>
using namespace std;
void shiftZero(vector<int> nums){
    int i=0;
    for(int j=1; j<nums.size(); j++){
        if(nums[i]==0 && nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        else if(nums[i]!=0){
            i++;
        }
    }

        for(int i:nums){
        cout<<i<<" ";
    }
}

int main()
{
    vector<int> nums;
    cout<<"Enter any negative element to stop taking input: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    shiftZero(nums);
    return 0;
}  
*/



                                            // Leet-C   Q-283   {Move Zeroes}

// Two Pointer      -- More simplified Syntax
/* 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
                i++;
            }
        }  
    }
}; 
*/




                                                // 8. Linear Search in C
//          T - O(n)    S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int searchElement(vector<int> nums, int k){
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == k){
            return i;
           // break;                // No matters we put break or not it will return the 1st found index of 'k' only
        }
    }
    return -1;
}
int main()
{
    cout<< "enter num to be find: ";
    int k;
    cin>>k;
    cout<<endl;
    vector<int> nums;
    cout<<"Enter any negative element to stop taking input: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    cout<<searchElement(nums,k);
    return 0;
    return 0;
} 
 */




                                        // 9. Union of Two Sorted Arrays

//  Optimal approach : 2-Pointer (Merge Algo)      T - O((n + m) log(n + m))      S - O(n + m)
/* 
#include<iostream>
#include<set>
using namespace std;
void unionArr(vector<int> nums, vector<int> mums){
    int np = 0;
    int mp = 0;

    set<int> temp;                                      // Created SET instead of Vector to store unique elements   
    while(np<nums.size() && mp<mums.size()){
        if(nums[np]<=mums[mp]){
            //if(temp.size() == 0 || temp.back() != nums[np]){          // No need to use this as have used set temp instead of vector temp   {this condition avoids duplicates within same array}                         
                temp.insert(nums[np]);
                np++;
            //}
        }

        // else if(nums[np]==mums[mp]){                 // No need of this as we have created a SET     {this condition avoids same elements in both array}
        //     temp.insert(nums[np]);
        //     np++;
        //     mp++;
        // }

        else{
            temp.insert(mums[mp]);
            mp++;
        }
    }
    while(np<nums.size()){
        temp.insert(nums[np]);
        np++;       
    }
    while(mp<mums.size()){
        temp.insert(mums[mp]);
        mp++;       
    }

    for(int i:temp){
        cout<<i<<" ";
    }
}
int main()
{
    vector<int> nums;
    vector<int> mums;

    cout<<"enter elements for 1st array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    cout<<endl;
    cout<<"enter elements for 2nd array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        mums.push_back(x);
    }    

    unionArr(nums,mums);
    return 0;
} 
*/
// If used SET then T - O((nlog(n) + mlog(m))  else if using those commented conditions T - O(m+n)      //Inserting in SET have higher time comp than VECTOR




// SET {Works for UNSORTED arrays also}       T - O((m+n)log(m+n))      S - O(m+n)
/* 
#include<iostream>
#include<set>
using namespace std;
void unionArr(const vector<int>& nums, const vector<int>& mums) {
    set<int> s;
    for (int num : nums) {                  T - O(n*logn)       Insertion time comp
        s.insert(num);
    }
    for (int mum : mums) {                  T - O(m*logm)
        s.insert(mum);
    }

    for (int i : s) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums;
    vector<int> mums;

    cout<<"enter elements for 1st array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    cout<<endl;
    cout<<"enter elements for 2nd array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        mums.push_back(x);
    }    

    unionArr(nums,mums);
    return 0;
} 
*/




// Map  {Works for UNSORTED arrays also}         T - O((m+n) * log(m+n))          S - O(m+n)  
/*
#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {

  map<int, int>freq;
  vector<int>Union;

  for (int i = 0; i < n; i++) freq[arr1[i]]++;

  for (int i = 0; i < m; i++) freq[arr2[i]]++;

  for (auto & it: freq)
    Union.push_back(it.first);              // map takes unique keys
  return Union;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
*/




// Built-IN Functions {No Use}          T - O(n+m)          S - O(n+m)
/* 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void unionArr(vector<int> nums, vector<int> mums) {

    // // 1. Sort both arrays (if not already sorted)           T - O(n log n + m log m)   if arrays are not already sorted  
    // sort(nums.begin(), nums.end()); 
    // sort(mums.begin(), mums.end());

    // 2. Remove duplicates within each array
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    mums.erase(unique(mums.begin(), mums.end()), mums.end());

    // 3. Allocate space for result
    vector<int> result(nums.size() + mums.size());                    // max possible size of union vector  {need to assign size to use .begin() function}

    // 4. Compute union
    auto it = set_union(
        nums.begin(), nums.end(),
        mums.begin(), mums.end(),
        result.begin()
    );

    // 5. Resize and print
    result.resize(it - result.begin());

    cout << "Union: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums;
    vector<int> mums;

    cout<<"enter elements for 1st array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    cout<<endl;
    cout<<"enter elements for 2nd array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        mums.push_back(x);
    }    

    unionArr(nums,mums);
    return 0;
} 
*/





                                    // 10. Intersection of 2 sorted Arrays

// Nested loops     T - O(n*m)    S - O(k)   {k is common elements}                                
/* 
// Brute Force :
#include<iostream>
#include<string>
using namespace std;
void interArr(vector<int>& nums, vector<int>& mums){
    vector<int> temp;
    vector<bool> visited(mums.size(), false);               // boolean vector of the same size as mums, initialized with false, used to track which elements in mums have already been matched

    for(int i = 0; i<nums.size(); i++) {
        for(int j = 0; j<mums.size(); j++) {
            if(nums[i] == mums[j] && !visited[j]) {
                temp.push_back(nums[i]);
                visited[j] = true;                          // marks mums[j] as used so it won’t be matched again, this boolian vector stores true/false for each value of 'j'
                break;                                      // stops further checking for the current nums[i], and moves to the next i
            }

        }
    }

    for(int val : temp) {
        cout << val << " ";
    }
}

int main()
{
    vector<int> nums;
    vector<int> mums;

    cout<<"enter elements for 1st array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    cout<<endl;
    cout<<"enter elements for 2nd array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        mums.push_back(x);
    }    

    interArr(nums,mums);    
    return 0;
}
 */



// Two Pointers -->        T - O(n+m)      S - O(K)  {K= no. of common elements}
/* 
#include<iostream>
#include<string>
using namespace std;
void interArr(vector<int>& nums, vector<int>& mums){
    vector<int> temp;
    int i = 0, j = 0;

    while(i < nums.size() && j < mums.size()){
        if(nums[i] == mums[j]){
            temp.push_back(nums[i]);
            i++;
            j++;
        }
        else if(nums[i] < mums[j]){
            i++;
        }
        else{                                   // nums[i] > mums[j]
            j++;
        }
    }

    for(int val : temp){
        cout << val << " ";
    }
}

int main()
{
    vector<int> nums;
    vector<int> mums;

    cout<<"enter elements for 1st array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        nums.push_back(x);
    }

    cout<<endl;
    cout<<"enter elements for 2nd array and to stop enter any negative element: ";
    while(true){
        int x;
        cin>>x;
        if(x<0){
            break;
        }
        mums.push_back(x);
    }    

    interArr(nums,mums);
    return 0;   
} 
*/



                                        // Intersection of two UNSORTED array

// Optimal Approach :-  HashMap handles unsorted Arrays         T - O(n + m)       S - O(n) 
/* 
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void interArr(vector<int>& nums, vector<int>& mums) {
    unordered_map<int, int> freq;                           // store element counts from nums
    vector<int> result;

    // Step 1: Store frequency of nums[] elements
    for(int num : nums) {
        freq[num]++;
    }

    // Step 2: Find intersection
    for(int a : mums) {
        if(freq[a] > 0) {                                   // element of mums found in nums
            result.push_back(a);
            freq[a]--;                                      // reduce freq to avoid reuse
        }
    }

    // Step 3: Print result
    for(int val : result) {
        cout << val << " ";
    }
}

int main() {
    vector<int> nums, mums;
    int x;

    cout << "Enter elements for 1st array (negative to stop): ";
    while(true) {
        cin >> x;
        if(x < 0) break;
        nums.push_back(x);
    }

    cout << "Enter elements for 2nd array (negative to stop): ";
    while(true) {
        cin >> x;
        if(x < 0) break;
        mums.push_back(x);
    }

    interArr(nums, mums);
    return 0;
} 
*/






                                        // 11. Missing Number leetC - 286

// Brute Force :    Using nested loops      T - O(n^2)      S - O(1)                {Can also find more than 1 missings}

// Sorting :        T - O(nlogn)      S - O(1)                                      {Can also find more than 1 missings}
/* 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());             T - N(logN)

        for(int i=0; i<n; i++){                     T - N   
            if(i != nums[i]){
                return i;
            }
        }
        return n;
    }
}; 
*/
// Total time comp :- O(N) + O(NlogN) = O(NlogN) 



// Mapp :                   T - O(n logn)       S - O(n)                     {Can also find more than 1 missings}
/* 
#include<map>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int i=0; i<n; i++){                         // storing :- O(nlogn)
            m[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(m.find(i)==m.end()){                     // fetching using find fn :- O(nlogN)
                return i;
            }
        }
        return n;
    }
}; 
*/



// Hashing :                    T - O(2*n)     S - O(n)                         {Can also find more than 1 missings}
/* 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);         // hashing should always be kept array.size() + 1           

        for (int i = 0; i < n; i++) {       // T - O(n)
            hash[nums[i]] = 1;              // mark presence
        }

        for (int i = 0; i <= n; i++) {      // check up to n        T - O(n)
            if (hash[i] == 0) {
                return i;
            }
        }
        return -1;                          // should not reach here
    }
};
 */



 // Optimal Approach 1 :        Summation Approach   T - O(n)   S - O(1)        {Easiest}   {find only if single number is missing}
/*  
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){             // sum of all array elements
            sum = sum + nums[i];
        }
        int Tsum = (n*(n+1))/2;             // sum of all numbers upto 'n'
        return Tsum - sum;                  // missing number = (sum of all numbers)  - (sum of all array elements) 
    }
}; 
*/



// Optimal Approach 1 :        XOR Approach   T - O(n)   S - O(1)               {find only if single number is missing}
/* 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0, xorNums = 0;

        for (int i = 0; i < n; i++) {
            xorAll ^= i;                    // XOR from 0 to n-1 here
            xorNums ^= nums[i];             // XOR of all elements of array
        }
        xorAll ^= n;                        // include XOR of 'N'
        return xorAll ^ xorNums;
    }
}; 
*/





                                            // 12. Max Consecutive Ones {LeetC-485}

// Optimal Soln         T-O(n)      S- O(1)
/* 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        int flag2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                flag++;
                }
            if(nums[i]==0){
                flag = 0;
            }
            flag2 = max(flag2,flag);
        }
        return flag2;
    }
}; 
*/




                                        // 13. Single Number  {LeetC - 136}
// Linear runTime O(n)      constant space O(1)
/*                  
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xOr = 0;                    //can't take xor as variable name
        for(int i=0; i<n; i++){
            xOr = xOr ^ nums[i];        // Element with pair will have XOR as 0 and XOR(0,i) = i  where i is the only element occuring for single time 
        }
        return xOr;
    }
}; */


//Other approaches :- 
//  * BruteForce - nested loops    T{O(n^2)}                S{O(1)}
//  * Hashing -                    T{O(N)+O(N)+O(N)}        S{O(maxEle + 1)}
//  * Map     -                    T{O(N*logM) + O(M)}      S{O(M)}                 ; m is size of map
//  * XOR     -                    T{O(n)}                  S{O(1)}






                        //  15. Longest Subarray with given Sum K (POSITIVES + NEGATIVES)
/*
// Brute-force : 3 loops    T - O(n^3)      S - O(1)        (POSITIVES + ZEROES + NEGATIVES)
#include<iostream>
#include<string>
using namespace std;
int la(int arr[], int n, int m){
    int len = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];                  // sum is finded for each subarray again & again
            }
            if(sum == m){                       // here this need to be placed outside 'k' loop
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}
int main()
{
    int m;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>m;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The longest subarray with sum 5 is "<<la(arr, n, m);
    return 0;
}
*/



// Brute-force : 2 loops    T - O(n^2)      S - O(1)    (POSITIVES + ZEROES + NEGATIVES)
/*
#include<iostream>
#include<string>
using namespace std;
int la(int arr[], int n, int m){
    int len = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];        
            if(sum == m){                           // Here this can be place within 'j' loop as sum is incremented at every loop of j
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}
int main()
{
    int m;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>m;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The longest subarray with sum 5 is "<<la(arr, n, m);
    return 0;
}
*/



// Better Approach : HashMaps               T - O(nlog(n))      S - O(n)           // Most Optimal soln for (POSITIVE + ZEROES + NEGATIVES)
/*
#include<iostream>
#include<map>
using namespace std;
int la(int arr[], int n, int k){
    int sum = 0;
    int maxlen = 0;
    map<int, int> m;

    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == k){
            maxlen = max(maxlen, i+1);                  // Length of 1st subarray with sum 'k'
        }

        int rem = sum - k;                              // Prefix Sum
        
        if(m.find(rem)!=m.end()){                       // If prefix sum exist in hashmap
            int len = i-m[rem];                         // Lenght of new subarray with sum 'k',    m[rem] is index of last element of prev subarray {index at which 'sum-k' is stored in hahsmap}
            maxlen = max(maxlen, len);                  // Update maxlen only when length of new subarray greater than the prev one
        }

        if(m.find(sum)==m.end()){                       // store into hashmap only if sum don't exist already, don't overwrite sum with new index 
            m[sum]=i;                                   // storing sum into hashmap along with indices;  sum = key  &&  index = values of hashmap
        }
    }
    return maxlen;
}

int main()
{
    int k;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>k;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The longest subarray with sum 5 is "<<la(arr, n, k);
    return 0;
}
*/
// Ordered Map : O(Nlog(n))   Unordered Map : O(1)   or  O(n^2) if collision occured




// Optimal Approach : 2-Pointer  for (Positives & Zeroes)      T - O(2N)      S - O(1)
/*     
#include<iostream>
#include<string>
using namespace std;
int la(int arr[], int n, int k){
    int sum = 0;
    int maxlen = 0;

    int j=0;
    for(int i=0; i<n; i++){

        sum += arr[i];                      // Summation 
    
        while(sum>k && j<=i){               // until sum doesn't exceeds 'K'
            sum -= arr[j];                  // remove beginning element one by one until sum<k
            j++;                           
        }
        if(sum==k){
            maxlen = max(maxlen, i-j+1);
        }
    }
    return maxlen;
}

int main()
{
    int k;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>k;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The longest subarray with sum k is "<<la(arr, n, k);
    return 0;
}
*/
// Time Comp will be O(2N) at worst case not O(n^2)  because the internal while loop is not always running for 'n' times for each iteration of 'i',  Max to Max j can be iterated to n so for whole(All) 'i' the inner while loop will run for n times in total so N+N= 2N







                                    // 16. Subarray Sum Equals K (Leet-C 560)    {Same as above concept}

// For (Positive & Zeroes) : 2-pointer  {Optimal} 
/*                   
#include<iostream>                                    
#include<climits>
using namespace std;
    int subarraySum(int nums[], int n, int k) {
        int sum = 0;
        int count = 0;

        int j=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum>k && j <= i){             // must add "&& j <= i"  as for k = 0, arr={1} it's showing count = 1 but it should show 0 
                sum -= nums[j];
                j++;
            }
            if(sum == k && j <= i){            // must add "&& j <= i"
                count++;
            }
        }
        return count;
    }

int main(){
    int k;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>k;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"No of subarrays with sum k is "<<subarraySum(arr, n, k);
    return 0;
}
*/



// For Negatives including : HashMap + prefix sum  (Optimal)        T- O(NlogN)  S- O(N)
/* 
#include<iostream>
#include<map>
using namespace std;
int subarraySum(int arr[], int n, int k){
    map<int, int> m;  
    int sum = 0;
    int count = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum == k){                
            count++;
        }
        
        int rem = sum-k;
        if(m.find(rem) != m.end()){
            count += m[rem];                // here m[rem] gives freq not index like in longest subarray Q
        }

        m[sum]++;                           // Here Map stores sum and the number of time it occured {freq. of sum}
    }
    return count;
}

int main()
{
    int k;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>k;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"No of subarrays with sum k is "<<subarraySum(arr, n, k);
    return 0;
} 
*/



// Brute-Force 
/* 
#include<iostream>
#include<string>
using namespace std;
int subarraySum(int arr[], int n, int k){

    int count = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int k;
    cout<<"enter equivalent sum to match with"<<endl;
    cin>>k;

    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"No of subarrays with sum k is "<<subarraySum(arr, n, k);
    return 0; 

} 
*/



