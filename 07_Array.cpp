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



// Brute Force :- Sorting           Time : O(N*log(N))              Space : O(n)  : space comp will be O(1) only but here in this code we are creating array by ourself so vector is taking space
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
        for(i=0;i<n;i++){
            if(arr[i]!=small){
                second_small = min(second_small,arr[i]);
            }
            if(arr[i]!=large){
                second_large = max(second_large,arr[i]);
            }
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

// Brute force : rotate from all indices of minimest element and check isSorted()                                
/*
class Solution {
public:
    bool isSorted(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == min){
                vector<int> arr(nums); 
                rotate(arr.begin(), arr.begin()+i, arr.end());
                if(isSorted(arr)){
                    return isSorted(arr);
                } 
            }
        }
        return false;
    }
};
*/



// Brute force : rotate from all breaking points and check isSorted()   
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    // Function to check if array is sorted
    bool isSorted(vector<int>& arr) {

        for(int i = 0; i < arr.size()-1; i++) {

            if(arr[i] > arr[i+1]) {
                return false;
            }
        }

        return true;
    }

    bool check(vector<int>& nums) {

        int n = nums.size();

        // Find all breaking points
        for(int i = 0; i < n-1; i++) {

            // Ascending order breaks here
            if(nums[i] > nums[i+1]) {

                vector<int> arr(nums);

                // Rotate from breaking point + 1
                rotate(arr.begin(), arr.begin()+i+1, arr.end());

                // Check if sorted after rotation
                if(isSorted(arr)) {
                    return true;
                }
            }
        }

        // Handle already sorted array
        return isSorted(nums);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3,4,5,1,2};

    if(obj.check(nums))
        cout << "True";
    else
        cout << "False";

    return 0;
}
*/

// Time for both above codes : O(N²)
// Space for both above code : O(N)




// Optimimal solution   ;-  Time - O(n)  && Space - O(1)
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



// Using Reverse tech :   T - O(N)   S - O(1) 
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    bool check(vector<int>& nums) {

        int n = nums.size();
        int breakPoint = -1;

        // Find breaking point
        for(int i = 0; i < n-1; i++) {

            if(nums[i] > nums[i+1]) {
                breakPoint = i;
                break;
            }
        }

        // Already sorted
        if(breakPoint == -1)
            return true;

        // Rotate using reverse method

        reverse(nums.begin(), nums.begin() + breakPoint + 1);           // reverse 1st part 

        reverse(nums.begin() + breakPoint + 1, nums.end());             // reverse 2nd part

        reverse(nums.begin(), nums.end());                              // reverse whole array 

        // Check if sorted
        for(int i = 0; i < n-1; i++) {

            if(nums[i] > nums[i+1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3,4,5,1,2};

    if(obj.check(nums))
        cout << "True";
    else
        cout << "False";

    return 0;
}
*/




                                    // 217. Contains Duplicate    {check leet code- 217}

//  CAN'T USE SUMMATION :   As it has negative elements too
//  CAN't USE XOR       :   As 1^2^3 too can return 0 
//  SET & HASHMAP       :   Best solutions
//  SORTING             :   Better approach
//  Cyclic sort         :   Can't use Index correction as for cyclic sort range should be [0,n] or [1,n]









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
/*                  Time : O(n)    space : O(n) 
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

            
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());

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

//  Optimal approach : 2-Pointer (Merge Algo)      T - O((n + m) log(n + m))      S - O(n + m)              //used set to store union of array else time comp would be O(n+m)
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

        // else if(nums[np]==mums[mp]){                 // No need of this as we have created a SET     {this condition avoids duplication of elements}
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

  for (auto &it: freq)
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



                                        


                                        // 11. Missing Number leetC - 268

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



// Optimal Approach 2 :        XOR Approach   T - O(n)   S - O(1)               {find only if single number is missing}
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



// Optimal Approach 3 :    Cyclic Sort          T - O(n)    S - O(1)
/* class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int i = 0;

        while(i < nums.size()) {                             
            int correctInd = nums[i];                       // 0 is included so correct ind is nums[i]    not  nums[i]-1

            if(nums[i] < nums.size() &&
               nums[i] != nums[correctInd]) {

                swap(nums[i], nums[correctInd]);
            }
            else {
                i++;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }
}; */





                                            // First Missing Positive   {Leet-41}

// Better Approach  - HASH MAP
/* class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        unordered_map<int,int> m;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                m[nums[i]]++;
            }
        }

        int i = 1;
        while(true){
            if(m.find(i)==m.end()){
                return i;
            }
            i++;
        }
    }
}; */



// OPTIMAL -  Cyclic Sort  -  Correct Index Method                  T - O(n)    S - (1)

/* class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            int i = 0;

            while (i < n) {     
                if (nums[i] > 0 && nums[i] <= n) {
                    int correctIndex = nums[i] - 1;                     // Only compute correctIndex if nums[i] is in range
                    if (nums[i] != nums[correctIndex]) {
                        swap(nums[i], nums[correctIndex]);
                        continue;
                    }
                }
                i++;
            }

            // Find first index where value is not index+1
            for (int i = 0; i < n; i++) {
                if (nums[i] != i + 1) return i + 1;
            }
 
            return n + 1;

    }
}; */

// For this Question we can't use summation or XOR as numbers are not in range of [0 to N]  there will be negative numbers too





                                                    // Repeating and Missing numbers

// Optimal :  Correct Index method      T - O(n)     S - O(1)

/* class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int i =0 ;
       while(i<arr.size()){
           int correctInd = arr[i]-1;
           if(arr[i] != arr[correctInd]){
               swap(arr[i],arr[correctInd]);
           }
           else{
               i++;
           }
       }
       for(int i=0; i<arr.size(); i++){
           if(arr[i] != i+1){
               return {arr[i],i+1};
           }
       }
        return {};
    }
}; */




// HASH MAP                         T - O(n)             S - O(n)

/* #include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        unordered_map<int,int> m;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            m[arr[i]]++;
        }

        int repeating = -1;                         // have to store repeating  and missing else it will print in worng order
        int missing = -1;

        for(int i = 1; i <= n; i++){                // check from n=1 as for 0 m[0] is 0 so it will give '0' as missing  but we need to find missing from [1,n]

            if(m[i] > 1){
                repeating = i;                      // store the repeating numb
            }

            if(m[i] == 0){
                missing = i;                        // store the missing number
            }
        }

        return {repeating, missing};                // need to be printed in this order only 
    }
}; */




// SUMMATION     T-O(n)   S-O(1)

/* class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
    
    long long s1 = 0;
    long long s2 = 0;
    
    int n = arr.size();
    
    long long ts1 = 1LL * n*(n+1)/2;                           // 1LL forces overflow multiplication in long long
    long long ts2 = 1LL * n * (n + 1) * (2 * n + 1) / 6;        // sum of sq of n natural numbers
    
    for(int i=0; i<n; i++){
        s1 += arr[i];
        s2 += 1LL * arr[i]*arr[i];       // 1LL forces overflow multiplication in long long
    }
    
    long long A = ts1 - s1;               // A = x-y
    long long B = ts2 - s2;               // B = (x+y)(x-y)
    
    long long C = B/A;                    // C = x+y
    
    int missing = (C+A) / 2;        // C+A = 2x      missing no = x
    int repeating = (C-A) /2;       // C-A = 2y      repeating no = y
    
    return {repeating,missing};
    }
}; */





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



// Optimal Approach : 2-Pointer(SLIDING WINDOW)  for (Positives & Zeroes)      T - O(2N)      S - O(1)
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
    
        while(sum>k && j<=i){               // until sum is greater than 'K',   j<=i helps inlcuding last element
            sum -= arr[j];                  // remove beginning element one by one until sum gets lower than 'k'
            j++;                           
        }
        if(sum==k && j<=i){                 // j<=i prevents empty subarray
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




// Better Approach : HashMaps {PREFIX SUM}             T - O(nlog(n))  or  O(n)      S - O(n)           // Most Optimal soln for (POSITIVE + ZEROES + NEGATIVES)
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
// Ordered Map : O(Nlog(n))   Unordered Map : O(n)   or  O(n^2) if collision occured              {unordered map takes O(1) but here time comp is O(n) cause using loop for traversal}






                                    // 16. Subarray Sum Equals K (Leet-C 560)    {Same as above concept}

// For (Positive & Zeroes) : 2-pointer  {Optimal}           SLIDING WINDOW
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
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;                                // this map will store sum and number of time those sum have been seen 

        int sum = 0;
        int count = 0;

        mp.insert({0,1});                               //inital sum is 0 so storing 1st sum with it's freq that's 1 time    testcase -> {-1,1}

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            if(mp.find(sum-k) != mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};
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



                                            // 17. Sort an array of 0s, 1s and 2s

// Brute-Force : Use any sorting tech.      T - O(n²)      S - O(1) 
/*                          
#include<iostream>
#include<string>
using namespace std;
void sortC(int n, int arr[]){           
    for(int i=n-1; i>=1; i--){                      // Bubble sort 
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortC(n, arr);
    return 0;
} 
*/
// With sorting we can either do like 0011122 or 2211000  ASC/DSC but can be possible to follow this kind of pattern : 002211 or 2200111 or 110022 etc



// 2 Pointers :              T - O(2n)       S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
void sortC(int n, int arr[]){ 
    int i = 0;
    for(int j=0; j<n; j++){
        if(arr[j]==0){
            swap(arr[j],arr[i]);
            i++;
            
        }
    }

    int k=i;
    for(int j=i; j<n; j++){
        if(arr[j]==1){
            swap(arr[j],arr[k]);
            k++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortC(n, arr);
    return 0;
} 
*/
// with this method we can sort colours into any pattern not necessarily ASC or DSC only 



// Using Counts :    T-O(2n)   S-O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
void sortC(int n, int arr[]){ 
    int c0=0, c1=0, c2=0;

// This loop have T-O(n)
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            c0++;
        }
        if(arr[i]==1){
            c1++;
        }
        if(arr[i]==2){
            c2++;
        }
    }

// These 3 loops collectively have T-O(n)
    for(int i=0; i<c0; i++){
        arr[i] = 0;                         //In-placing 0 upto 'c0' index in arr
    }

    for(int i=c0; i<c1+c2; i++){
        arr[i] = 1;                         //In-placing 1 from 'c0' to 'c1+c2' index in arr
    }

    for(int i=c1+c2; i<n; i++){
        arr[i] = 2;                         //In-placing 2 from 'c1+c2' to 'n' index in arr
    }


// Printing array won't contributes in T comp.
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortC(n, arr);
    return 0;
} 
*/



// Optimal Approach :  Dutch National flag algorithm (3-Pointers)       T - O(n)    S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
void sortC(int n, int arr[]){ 
    int i = 0; 
    int j = 0;
    int k = n-1;

    while(j<=k){                                // No need to go upto 'n' if j crosses k means array has been sorted already
        if(arr[j]==0){
            swap(arr[j],arr[i]);
            i++;
            j++;
        }
        else if(arr[j]==2){                     // don't increment j here!
            swap(arr[j],arr[k]);
            k--;
        }
        else{                                   // arr[j] == 1
            j++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortC(n, arr);

    return 0;
} 
*/



                                            // LeetC - 75. Sort Colours
/* 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;                                //Begin ptr
        int j=0;                                //Iterating ptr
        int k=nums.size()-1;                    //End ptr

        while(j<=k){
            if(nums[j]==0){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }

            else if(nums[j]==2){
                swap(nums[j], nums[k]);
                k--;
            }

            else{
                j++;
            }
        }
    }
}; 
*/




                                            // 18. Majority Element

// Brute-Force : T - O(n^2)  S - O(1)
        /*  for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (v[j] == v[i]) {             // counting the frequency of v[i]
                    cnt++;
                }
                if (cnt > (n / 2))
                return v[i];
            } */



// Using MAP    T - O(n log n)    S - O(n)
/* 
#include<iostream>
#include<unordered_map>
using namespace std;
void major(int n, int arr[]){
    unordered_map<int, int> m;

    for(int i=0; i<n; i++){                         // T - O(N*logN)
        m[arr[i]]++;
    }

    for (auto &p : m) {                             // T - O(N)
        if (p.second > n/2) {
            cout << "Majority element = " << p.first << endl;
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    major(n,arr);
    return 0;
} 
*/



// Sorting                  T - O(n log n)        S - O(1)
/* 
#include<iostream>
#include<algorithm>
using namespace std;
int major(int n, int arr[]){
    sort(arr, arr+n);                           // T - O(nlogN)
    int flag = 1;                               // Already counted the 1st occurance

    for(int i=1; i<n; i++){                     // T - O(n)
        if(arr[i] == arr[i-1]){
            flag++;
            if(flag > n/2) return arr[i];       // majority found
        } 
        else {
            flag = 1;                           // reset count for new element
        }
    }
    return -1;                                  // no majority element
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<major(n,arr);  
    return 0;
} 
*/



// Optimal Approach :        Boyer–Moore Majority Vote Algorithm:         T - O(n)    S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int major(int n, int arr[]){
    int c = 0;
    int e;

    for(int i=0; i<n; i++){
        if(c==0){
            c = 1;
            e = arr[i];
        }
        else if(e == arr[i]){
            c++;
        }
        else{
            c--;
        }
    }

// Checking if the stored element is the MAJORITY element:   MAJORITY CHECK
       int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) cnt1++;
        }

        if(cnt1 > (n / 2)){
            return e;
        }
        else{
            return -1;
        }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<major(n,arr); 
    return 0;
} 
 */
// Majority check is NOT REQUIRED for LEETc soln as it has already mentioned that there's surely 1 majority element present in test cases
// Ex: {1,2,3,4} this will returned e = 3 but it's not in majority so will return -1 instead using below code block of majority check 
// Ex: {1,2,2,3} it will return -1 only for this also as 2 is occuring twice which means not greater than n/2 so 2 is also not a majority element here.
 



                                        // LeetC - 169. Majority Element {Moore's Vote Algorithm}
/* 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int e;
        for(int i=0; i<nums.size(); i++){
            if(c == 0){
                c = 1;
                e = nums[i];
            }
            else if(e == nums[i]){
                c++;
            }
            else{
                c--;
            }
        }
        return e;
    }
}; 
*/




                                        // 19. Maximum Subarray Sum in an Array

// Brute Force : 2 nested loops      T - O(n^2)  S - (1)           could be done using 3 loops also 
/*
#include<iostream>
#include<string>
using namespace std;
int maxSum(int n, int arr[]){
    int c1 = INT_MIN;                           // Don't take 0 as max sum could be -ve also
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            c1 = max(c1,sum); 
        }
    }
    return c1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxSum(n,arr); 
    return 0;
} 
*/


                                                        // LeetC - 53
                                            // Kadane's Algo for Maximum Subarray Sum
/*              T - O(N)    S - O(1)
#include<iostream>
#include<string>
using namespace std;
int maxSum(int n, int arr[]){
    int sum = 0;
    int Tsum = arr[0];

    for(int i=1; i<n; i++){
        sum += arr[i];
        if(sum<0){
            Tsum = max(sum, Tsum);
            sum = 0;
        }
        else{
            Tsum = max(sum, Tsum);
        }
    }
    return Tsum;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxSum(n,arr);    
    return 0;
} */



// More shorten code of above algo              T - O(N)    S - O(1)
/*
#include <iostream>
#include <climits>
using namespace std;

int maxSum(int n, int arr[]) {
    int sum = arr[0];
    int Tsum = arr[0];

    for (int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);                    // either extend or restart
        Tsum = max(Tsum, sum);
    }
    return Tsum;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSum(n, arr);
    return 0;
}
*/



                                        // Kadane's Algo if need to print subarray too
/*                            
#include<iostream>
#include<string>
using namespace std;
void maxSum(int n, int arr[]){
    int sum = 0;
    int Tsum = arr[0];

    int start = -1;
    int end = -1;
    int tempStart = 0;

    for(int i=0; i<n; i++){
        if(sum == 0){
            tempStart = i;                      // Track the begining of subarray; starting index of current subarray; at sum <= 0, new subarray will start, old one is discarded
        }

        sum += arr[i];

        if(sum > Tsum) {
            Tsum = sum;

            start = tempStart;                  // jaha se subarray start hua tha; jaha sum negative hua uske next i se
            end = i;                            // till current iterating index 'i'
        }

        if(sum<0){
            Tsum = max(sum, Tsum);
            sum = 0;                            // this will enter into top(1st condn) and reset the subarary; new subarray will start from next i
        }
    }

    cout<<Tsum<<endl;
    for(int i=start; i<=end; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    maxSum(n,arr);    
    return 0;
}
 */




                                            // 20. Stock Buy And Sell
//  Brute Force :
/*                          // T - O(n^2)     S - O(1)
#include<iostream>
#include<string>
using namespace std;
int maxP(int n, int arr[]){
    int p = 0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[i]){
                p = max(p, arr[j] - arr[i]); 
            }
        }
    }
    return p;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxP(n,arr);
    return 0;
} */



// Optimal Approach :     T - O(n)   S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int maxP(int n, int arr[]){
    int p = 0;
    int min = arr[0];

    for(int i=0; i<n; i++){
        if(min>arr[i]){
            min = arr[i];
        }
        else{
            p = max(p, arr[i] - min);
        }
    }
    return p;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxP(n,arr); 
    return 0;
} 
*/




                                        // 21. Rearrange Array Elements by Sign   {LeetC - 2149}

//  Brute Force :       T - O(2n)           S - O(N/2 + N/2) = O(N)
/* 
#include<iostream>
#include<string>
using namespace std;
void alterSort(int n, int arr[]){
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            v1.push_back(arr[i]);
        }
        else{
            v2.push_back(arr[i]);
        }
    }

    for(int i=0; i<n/2; i++){
        cout<<v1[i]<<","<<v2[i]<<",";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    alterSort(n,arr);
    return 0;
}  
*/                                       



//  Optimal Approach     
/*                          T - O(n)   S - O(n)
#include<iostream>
#include<string>
using namespace std;
void alterSort(int n, int arr[]){
    int pos = 0;
    int neg = 1;
    vector<int> v(n,0);                 // need to initialise v with known size and all element as 0 then only will be able to use  "v[pos] = arr[i];"
    
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            v[pos] = arr[i];
            pos += 2;
        }
        else{
            v[neg] = arr[i];
            neg += 2;
        }
    }

    for(int val : v){
        cout<<val<<", ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    alterSort(n,arr);    
    return 0;
}
*/




                                            // 22. Leaders in an Array

//  Brute-Force     :   T - O(n^2)      S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
void leader(int n, int arr[]){

    for(int i=0; i<n-1; i++){
        int flag = 1;
        for(int j=i+1; j<n; j++){
            if(arr[i]<arr[j]){
                flag--;
            }
        }

        if(flag==1){
            cout<<arr[i]<<", ";
        }
    }
    cout<<arr[n-1];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    leader(n, arr);
    return 0;
} 
*/                                        



//    Optimal Approach : 2-Pointers         T - O(n)    S - O(1) {not counting the list data structure created to store the ans}
/* 
#include<iostream>
#include<list>
using namespace std;
void leader(int n, int arr[]){
    list<int> l;

    int j = n-1;
    l.push_front(arr[j]);

    for(int i=n-2; i>=0; i--){
        if(arr[i]>arr[j]){
            j = i;
            l.push_front(arr[j]);
        }
    }

    for(auto val:l){
        cout<<val<<", ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    leader(n, arr);  
    return 0;
} 
*/




                                            //24. Longest Consecutive Sequence in an Array

//  Brute Force :       T - O(n^3)          S - O(1)
/* 
#include<iostream>
#include<string>
using namespace std;
int cons(int n, int arr[]){
    int maxCount = 0;

    for(int i=0; i<n; i++){
        int count = 0;                             // for every element i, count will be initialized by 0
        int k = 0;                                 // for every element i, will start finding consecutives from beginning
        for(int j=0; j<n;){
            maxCount = max(count, maxCount);
            if(arr[i]+k == arr[j]){
                count++;
                k++;                                // increment k subsequntly everytime finding arr[i] + k
                j = 0;                              // again start from j=0 if arr[i] + k is found 
            }
            else{
                j++;                                // if didn't find arr[i]+k then do j++ to iterate through the whole array and when arr[i]+k is not present in whole array then move to next 'i'
            }
        }
    }
    return maxCount;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<cons(n, arr);  
    return 0;
}
*/




// Improving the above brute force by eliminating already counted elements:         T - O(n^2)   S - O(n)
/* 
#include <iostream>
#include <vector>
using namespace std;

int longestConsecutive(int n, int arr[]) {
    vector<bool> visited(n, false);                         // track elements already counted
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {                                  // only start new sequence if not counted before
            int count = 1;                                  // Unlike prev code here count will be initialized with 1 as that same element for which consecutives need to be found is not being taken into account due to "visited"

            int next = arr[i] + 1;                          // Count consecutive numbers forward
            for (int j = 0; j < n; j++) {
                if (!visited[j] && arr[j] == next) {
                    count++;
                    visited[j] = true;
                    next++;
                    j = -1;                                 // restart loop to find next consecutive number
                }
            }

            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestConsecutive(n, arr) << endl;
    return 0;
}
  */




// Better Brute-Force Approach :       T - O(N^2)    S - O(1)                                              ⭐️⭐️
/* 
#include<iostream>
#include<string>
using namespace std;

bool linearS(int n, int arr[], int k){

    for(int i=0; i<n; i++){
        if(arr[i]==k){
            return true;
        }
    }
    return false;
}

int cons(int n, int arr[]){
    int maxCount = 1;

    for(int i=0; i<n; i++){
        int count = 1;
        int x = arr[i];

        while(linearS(n, arr, x+1) == true){                 
            x++;
            count++;
        }
        maxCount = max(count, maxCount);
    }
    return maxCount;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<cons(n, arr); 
    return 0;
}
 */




// Optimizing above approach by replacing LINEAR SEARCH with SET FIND function 
// Better Approach :    T - O(n log n)             S - O(n)
/* 
#include<iostream>
#include<set>
using namespace std;
int cons(int n, int arr[]){
    if (n == 0) return 0;

    set<int> s;
    int maxCount = 1;

    for(int i=0; i<n; i++){                     // Inserting elements to set : O(n log n)
        s.insert(arr[i]);
    }

    for(int i=0; i<n; i++){                     // This loop : O(n)
        int count = 1;
        int x = arr[i]+1;
        if(s.find(arr[i]-1) == s.end()){
            while(s.find(x)!= s.end()){         // each Find funct under while loop will take O(log n) so overall :  O(n log n)
                count++;
                x++;
            }
        }
        maxCount = max(count, maxCount);
    }
    return maxCount;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<cons(n, arr);    
    return 0;
} 
*/
// Total Time comp : O(n log n) + O(n) + O(n log n)   =     O(n log n)




// Most Optimal Approach :   Replacing Set with Unordered SET           T - O(3*N)    S - O(n)          ⭐️⭐️⭐️⭐️⭐️
/* 
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int cons(int n, int arr[]){
    if (n == 0) return 0;

    unordered_set<int> s;
    int maxCount = 1;

    for(int i=0; i<n; i++){                             // Inserting 'n' elements to set : O(n)
        s.insert(arr[i]);
    }

    for(auto it : s){                                   // This loop will run over set 's'  so at most 'n' iterations
        if (s.find(it - 1) == s.end()){                 // Only if there's no number preceeding it means it's lowest number of consecutive sequence 
            int cnt = 1;
            int x = it; 
            while (s.find(x + 1) != s.end()){           // each find in unordered set is O(1) so under whole while loop :    O(n)
                x = x + 1;
                cnt = cnt + 1;                
            } 
            maxCount = max(cnt, maxCount);  
        }
    }
    return maxCount;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<cons(n, arr);    
    return 0;
} 
*/
// Total Time comp :  O(N) + O(2*N) => O(3*N)       
// Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).




// More Better Approach :   T - O(NlogN) + O(N)          S - O(1)                           ⭐️⭐️⭐️
/*                                
#include<iostream>
#include<string>
using namespace std;
int cons(int n, int arr[]){
    if (n == 0) return 0;
    sort(arr,arr+n);
    int count = 1;
    int maxCount = 0;

    for(int i=0; i<n; i++){
        maxCount = max(maxCount, count);
        if(arr[i+1]-arr[i]==1){
            count++;
        }
        else{
            count = 1;
        }
    }
    return maxCount;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<cons(n, arr); 
    return 0;
}  
  */       



                                                //25. Set Matrix Zero (Leet - 73)
// Brute Force          T- O(m * n * (m + n))                                       S- O(1)
/* class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                   
                   for(int col=0; col<m; col++){            // traverse through the column keeping same i for which element is 0
                        if(matrix[i][col]!=0){              // original element should be kept as 0
                            matrix[i][col] = -1000000000;            // marking as -1000000 not as -1 as in test case there an element with -1 as it's element
                        }
                   }

                   for(int row=0; row<n; row++){           //traverse through the row keeping same j for which element is 0
                        if(matrix[row][j]!=0){
                            matrix[row][j] = -1000000000;            //except original element which is 0, rest all element in that colm will be marked as -1
                        }
                   }
                    
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == -1000000000){                     //all elements marked as -1 will be overwrite  as 0
                    matrix[i][j]=0;
                }
            }
        }

    }
}; */



// Better Approach          T - O(m x n)    S - O(m+n)

/* #include<iostream>
using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
        //bool row[3] = {false};
        //bool col[3] = {false};

        vector<bool> row(matrix.size(), false);                     // create boolean for whole matrix
        vector<bool> col(matrix[0].size(), false);

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){                  // size of column in vector matrix is   matrix[row].size()   or   matrix[i].size()   or  matrix[0].size()-- if all rows of matrix have same number of columns
                if(matrix[i][j] == 0){
                    row[i] = true;                                  // those rows & col where [row][col] = 0 will be marked true
                    col[j] = true;  
                }
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(row[i] || col[j]){                               // if either row or col is true of certain element [row][col]  is true then that element will be marked 0
                    matrix[i][j] = 0;                                         
                }
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

int main(){

    vector<vector<int>> matrix(3, vector<int>(4));                  // create 3 rows of vectors having 4 columns/elements in each 

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            int k;
            cin>>k;
            matrix[i][j] = k;
        }
    }

    setZeroes(matrix);
}
 */



// OPTIMAL                      T - O(m*n)          S - O(1)
/* class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;


    // Marking the leading elements   (1st row & 1st column elements)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    // mark elements in 1st column (verticle leading elements)
                    matrix[i][0] = 0;

                    //mark elements in 1st col (horizontal leading elements)
                    if(j!=0){                // 0 is not in 1st column
                        matrix[0][j] = 0;
                    }    
                    else{
                        col0 = 0;
                    }

                }

            }
        }


    // Mutate 1st part (see notes to visualize)
        for(int i=1; i<n; i++){                                         // 1st part doesn't contains leading row and colm so i & j starting from 1 not 0
            for(int j=1; j<m; j++){
                    if(matrix[0][j]==0 || matrix[i][0]==0){          //if either side of leading element is 0 (horiz or vert)
                        matrix[i][j] = 0;
                    }               
            }
        }

    // Mutate 2nd part 
        if(matrix[0][0] == 0){
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }

    // Mutate 3rd (last) part
        if(col0 == 0){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
    }
}; */





                                                // Rotate Matrix Image (Leet-48)

//Brute Force           T - O(m*n)  S-O(m*n)

/* class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> matrix2(n, vector<int>(m));

//  Putting elements in new matrix in rotated way using formula   [i][j] = [j][n-i-1]
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix2[j][n-i-1] = matrix[i][j];
            }
        }

// Over write elements of original matrix a/q to newly rotated matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = matrix2[i][j];
            }
        }
    }
}; */




// Optimal Approach       T -> O(n*m) ~ O(n^2)        S-O(1)

/* class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

    // Transpose the matrix 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){               // j will loop from i+1 to handle re-swapping 
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    // invert the matrix vertically  :  reverse row wise
        for(int i=0; i<n; i++){
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
}; */






                                            //Longest Subarray with sum = 0

//Optimal Appraoch      T-O(n)  S-O(n)
/* #include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void Lsub(vector<int>& v, int n){

    unordered_map<int,int> m;
    int sum = 0;
    int maxL = 0;
    int r=0;                        // begining of required subarray
    int l=0;                        // ending of required subarray
       

    for(int i=0; i<n; i++){
        sum += v[i];

        if(sum == 0){
            maxL = max(maxL, i+1);
        }

        if(m.find(sum-0) != m.end()){                   // here k=0
            r = m[sum-0];                               // r will be index if previously stored sum
            l = i;                                      //l will be current iterating index
            maxL = max(maxL, l-r);
        }

        if(m.find(sum) == m.end()){                     // Store only if sum is not stored from before itself don't overwrite with new indices
            m[sum] = i;
        }
    }

    cout<<maxL;

}
int main(){
    int n;
    cin>>n;
    vector<int> v;

    for(int i=0; i<n; i++){
        int k=0;
        cin>>k;
        v.push_back(k);
    }

    Lsub(v,n);
} */





//Improvised Optimal Appraoch      T-O(n)  S-O(n)            As here K=0 so code can be further simplified

/* #include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void Lsub(vector<int>& v, int n){

    unordered_map<int,int> m;
    int sum = 0;
    int maxL = 0;
    int r=0;                        // begining of required subarray
    int l=0;                        // ending of required subarray
       

    for(int i=0; i<n; i++){
        sum += v[i];

        if(sum == 0){
            maxL = max(maxL, i+1);
        }

        if(m.find(sum) != m.end()){                   // here k=0
            r = m[sum-0];                               // r will be index if previously stored sum
            l = i;                                      //l will be current iterating index
            maxL = max(maxL, l-r);
        }
        else{                     // Store only if sum is not stored from before itself don't overwrite with new indices
            m[sum] = i;
        }
    }

    cout<<maxL;

}
int main(){
    int n;
    cin>>n;
    vector<int> v;

    for(int i=0; i<n; i++){
        int k=0;
        cin>>k;
        v.push_back(k);
    }

    Lsub(v,n);
} */



                                    // Count the number of subarrays with given xor K       

// optimal                          PrefixSum                        T-O(n)       S-O(n)
/* #include<iostream>
#include<unordered_map>
using namespace std;
void Sxor(vector<int>& v, int n, int k){

    int xorr = 0;
    int count = 0;

    unordered_map<int,int> m;

    for(int i=0; i<n; i++){

        xorr = xorr^v[i];

        if(xorr == k){
            count++;
        }

        if(m.find(xorr^k) != m.end()){
            count += m[xorr^k];                 // sum-k  is equivalent to xorr^k  as k^K = 0     ex: (1^2^3) need to remove 1   so (1^2^3)^1 = 2^3   as 1^1 = 0.
        }

        if(m.find(xorr) == m.end()){
            m[xorr]++;
        }
    } 

    cout<<count;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int m;
    cin>>m;
    for(int i=0; i<n; i++){
        int k=0;
        cin>>k;
        v.push_back(k);
    }

    Sxor(v,n,m);
} */




                                                // Printing maxLength for above Qs
/* #include<iostream>
#include<unordered_map>
using namespace std;
void Sxor(vector<int>& v, int n, int k){

    int xorr = 0;
    int maxL = 0;

    unordered_map<int,int> m;

    for(int i=0; i<n; i++){

        xorr = xorr^v[i];

        if(xorr == k){
            maxL = max(maxL, i+1);
        }

        if(m.find(xorr^k) != m.end()){
            int l = i-m[xorr^k];
            maxL = max(maxL,l);
        }

        if(m.find(xorr) == m.end()){
            m[xorr] = i;
        }
    } 

    cout<<maxL;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int m;
    cin>>m;
    for(int i=0; i<n; i++){
        int k=0;
        cin>>k;
        v.push_back(k);
    }

    Sxor(v,n,m);
} */






                                            // 88. Merge Sorted Array
// Soring   T - O(n+mlogn+m)    S-O(1)
/* class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        while(m<m+n && i<n){
            nums1[m++] = nums2[i++];
        }
        sort(nums1.begin(), nums1.end());
    }
}; */



// Merge function from Right to Left in decreasing order            T-O(N+M)   S-O(1)
/* class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1;
        int k = n-1;
        int i = m+n-1;

        while(l>=0 && k>=0 && i>=0){
            if(nums1[l]>=nums2[k]){
                nums1[i--] = nums1[l--];
            }
            else{
                nums1[i--] = nums2[k--];
            }
        }
        while(l>=0 && i>=0){
            nums1[i--]=nums1[l--];
        }
        while(k>=0 && i>=0){
            nums1[i--]=nums2[k--];
        }
    }
}; */




                                                // Count inversions in an array 
//BRUTE FORCE :     T - O(N^2)    S - O(1)

/* #include<iostream>
using namespace std;
void inverse(vector<int>& arr, int n){
    int count = 0;
     
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    cout<<count;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }

    inverse(arr, n);
} */



// Optimal Approach - Merge Sort   O(nlogn)   O(n)

/* #include <iostream>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {               // Function to merge two halves and count inversions
    
    vector<int> temp;                                                   // Temporary array to store merged elements

    int left = low;                                                     // Starting index of left half
    int right = mid + 1;                                                // Starting index of right half

    int cnt = 0;                                                       // Variable to count inversions

    while (left <= mid && right <= high) {                              // Merge elements in sorted order and count inversions
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);                        // All remaining left elements are inversions;   left is in ascending order so if right is smaller than 1st element then obv will be smaller than rest of elements of left half array 
            right++;
        }
    }

    while (left <= mid) {                                   // If left half still has elements
        temp.push_back(arr[left]);
        left++;
    }
                                                         
    while (right <= high) {                                 // If right half still has elements
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {                    // Copy back to original array
        arr[i] = temp[i - low];
    }

// Return inversion count
    return cnt;
}


int mergeSort(vector<int> &arr, int low, int high) {            // Merge sort function that counts inversions

    int cnt = 0;                                                // Variable to store inversion count

    if (low >= high) return cnt;                                // Base case

    int mid = (low + high) / 2;

// Count inversions in left half
    cnt += mergeSort(arr, low, mid);                            // every merge function returns count 

// Count inversions in right half
    cnt += mergeSort(arr, mid + 1, high);

// Count inversions during merge
    cnt += merge(arr, low, mid, high);

    return cnt;                                                 // Return stored count 
}


// Function to get number of inversions

    int numberOfInversions(vector<int>& a, int n) {
        return mergeSort(a, 0, n - 1);
    }

int main() {
    // Input array
    int n;
    cin>>n;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }

    // Count inversions
    int cnt = numberOfInversions(arr, n);

    cout << "The number of inversions are: " << cnt << endl;

    return 0;
} */





                                            //    493. Reverse Pairs

// Brute Force  - T-O(n^2)    S - O(1)

/* class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int j=nums.size()-1; j>0; j--){
            for(int i=j-1; i>=0; i--){
                if(nums[i]> 2LL * nums[j]){        // LL to avoid integer overflow 
                    count++;
                }
            }
        }
        return count;
    }
}; */




// Optimal      MERGE SORT    T - O(2nlogn)  S - O(n)
/* class Solution {
public:

// Merge function to sort the divided halves
void mergeS(vector<int>& nums, int low, int mid, int high, vector<int>& temp){

    int l = low;             // Starting index of left half
    int r = mid + 1;         // Starting index of right half
    int k = low;             // Index for temp array

    // Merge the two sorted halves into temp array
    while(l <= mid && r <= high){

        if(nums[l] <= nums[r]){
            temp[k++] = nums[l++];              //can't use push_back as passed temp vect in funct
        }
        else{
            temp[k++] = nums[r++];
        }
    }

    // If left half still has elements
    while(l <= mid){
        temp[k++] = nums[l++];
    }

    // If right half still has elements
    while(r <= high){
        temp[k++] = nums[r++];
    }

    // Copy sorted elements back to original array
    for(int i = low; i <= high; i++){
        nums[i] = temp[i];
    }
}


// Function to count reverse pairs
int Cnt(vector<int>& nums, int low, int mid, int high){

    int count = 0;

    int r = mid + 1;      // Pointer for right half

    // Traverse left half
    for(int i = low; i <= mid; i++){

        // Move right pointer until condition fails
        while(r <= high && nums[i] > 2LL * nums[r]){

            // 2LL is used to avoid integer overflow
            r++;
        }

        // Number of valid reverse pairs for current i
        count += r - (mid + 1);
    }

    return count;
}


// Recursive Merge Sort function
int divS(vector<int>& nums, int low, int high, vector<int>& temp){

    // Base condition of recursive function
    if(low >= high) return 0;

    int mid = low + (high - low) / 2;

    int count = 0;

    // Count from left half
    count += divS(nums, low, mid, temp);

    // Count from right half
    count += divS(nums, mid + 1, high, temp);

    // Count reverse pairs between left & right halves
    count += Cnt(nums, low, mid, high);

    // Merge the two sorted halves
    mergeS(nums, low, mid, high, temp);

    return count;
}


int reversePairs(vector<int>& nums) {

    int n = nums.size();

    // Temp array created only once
    vector<int> temp(n);

    int count = divS(nums, 0, n - 1, temp);

    return count;
}
}; */





                                                        // MAJORITY Ele - II
// Brute Force              T-O(N^2)    S - (1)
/* class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int> temp;

        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(int k=0; k<nums.size(); k++){
                if(nums[i] == nums[k]){
                    count++;
                }
            }


            bool vis = false;
            for(int k=0; k<temp.size(); k++){
                if(temp[k] == nums[i]){
                    vis = true;
                }
            }
            if(!vis && count>n){
                temp.push_back(nums[i]);
            }
        }
        return temp;                                        // temp won't contribute to space comp.
    }
}; */                                                        



//HASH MAP     :   T - O(N)             S - (N)  

/* class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size()/3;

        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        vector<int> temp;

        for(auto p : m){
            if(p.second>n){
                temp.push_back(p.first);
            }
        }
        return temp;
    }
}; */



// Optimal                              T - O(n)       S - O(1)

/* class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k1 = INT_MIN;
        int k2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        int  n = nums.size();

// firstly find candidates using moore method for 2 elements 
        for(int i=0; i<nums.size(); i++){
            if(count1 == 0 && nums[i]!=k2){
                k1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i]!=k1){
                k2 = nums[i];
                count2 = 1;
            }
            else if(nums[i] == k1){
                count1++;
            }
            else if(nums[i]==k2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

// Now check whether candidates are actually in majority or not (>n/3)
        int c1 = 0;
        int c2 = 0;          

        for(int i=0; i<nums.size(); i++){           // finding count of both candidates
            if(nums[i] == k1){
                c1++;
            }
            if(nums[i] == k2){
                c2++;
            }
        }

        if(c1>n/3 && c2>n/3){      
            return {k1,k2};             // return k1,k2 both as vector element {}
        }
        if(c2>n/3){
            return {k2};                // return on k2 as only count of k2 >n/3
        }
        if(c1>n/3){
            return {k1};                // return on k1 as only count of k1 >n/3
        }
        return {};                      // no maj element
    }
}; */





                                             // PASCAL TRI  L-118

//  TYPE 1   T- O(n^2)   S-O(n^2)                                       // Generatin entire Pascal triangle

/* class Solution {
public:
    vector<vector<int>> generate(int numRows) {             //only no of rows given in Qs function

        vector<vector<int>> nums(numRows);                  // initialize a 2D vector with only no of rows mentions

        for(int i=0; i<numRows; i++){

            // Resize current row
                nums[i].resize(i + 1);                      // need to done as we initialized 2D vector using rows only

            for(int j=0; j<=i; j++){
                if( j==0 || i==j ){
                    nums[i][j] = 1;
                }
                else{
                    nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
                }
            }
        }
        return nums;
    }
}; */





// TYPE - 2 :  Find element at particular place in pascal tringle     (𝑛Cr) permuration     T - O(rowSize)  S-(1)

/* #include <iostream>
using namespace std;

// Solution class to find the (r, c) element of Pascal's Triangle      r - row     c - colm
class Solution {
public:
    // Function to compute binomial coefficient (nCr)               ELEMENT : (row-1)C(col-1)   see notes
    long long findPascalElement(int r, int c) {
        // Element is C(r-1, c-1)
        int n = r - 1;                                  // numerator 
        int k = c - 1;                                  // denominator

        long long result = 1;

        // Compute C(n, k) using iterative formula
        for (int i = 0; i < k; i++) {                   // loop will run for k times {denominator times}
            result *= (n - i);                          // numerator : 10x9x8
            result /= (i + 1);                          // divide by denominator : 1x2x3   
        }                                               // in loop it will be like : (10/1) x (9/2) x (8/3) 

        return result;
    }
};

int main() {
    Solution sol;
    int r = 5, c = 3;
    cout << sol.findPascalElement(r, c);
    return 0;
} */
//Time Complexity: O(min(c,r−c)), The loop runs for min(c−1,r−c) iterations because binomial coefficients are symmetric.
//Space Complexity: O(1)





// TYPE - 3             find the elements of Pascal's Triangle in 'R'th  row

/* #include <iostream>
using namespace std; 
class Solution {
public:
    // Function to compute binomial coefficient      (see notes)
    void findPascalElement(int r) {

        long long result = 1;
        cout<<"1"<<" ";
        for (int i = 1; i < r; i++) {                  
            result *= (r - i);                      
            result /= i; 
            cout<<result<<" ";                         
        }                                         
    }
};

int main() {
    Solution sol;
    int r;
    cin>>r;

    sol.findPascalElement(r);
    return 0;
} */

// Time Complexity: O(N)   we iterate N times to compute each element of the row in O(1) time using the direct relation
// Space Complexity: O(N)  additional space used for storing the Nth row 






                                                    // Spiral Triangle

// Little Mistake :   First see this to understand
/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        for(int k=0; k<n; k++){
            for(int j=k; j<m-k; j++){
                ans.push_back(matrix[k][j]);
            }

            for(int i=1+k; i<n-k; i++){
                ans.push_back(matrix[i][m-1]);
            }

            for(int j=m-2-k; j>=0+k; j--){
                ans.push_back(matrix[n-1][j]);
            }

            for(int i=n-2-k; i>0+k; i--){
                ans.push_back(matrix[i][k]);
            }
        }
        return ans;
    }
}; */





// Fixed version of above code                      T - O(n × m)      S - O(1)

/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        int layers = (min(n, m) + 1) / 2;

        for(int k = 0; k < layers; k++){

            // top row
            for(int j = k; j < m-k; j++){
                ans.push_back(matrix[k][j]);
            }

            // right column
            for(int i = k+1; i < n-k; i++){
                ans.push_back(matrix[i][m-1-k]);
            }

            // bottom row
            if(n-1-k != k){
                for(int j = m-2-k; j >= k; j--){
                    ans.push_back(matrix[n-1-k][j]);
                }
            }

            // left column
            if(m-1-k != k){
                for(int i = n-2-k; i > k; i--){
                    ans.push_back(matrix[i][k]);
                }
            }
        }

        return ans;
    }
}; */




// Little Mistake : first see this to understand the mistake     {better & easier Approach}

/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> temp;
        // Boundaries : 
        int top = 0;
        int bot = n-1;
        int left = 0;
        int right = m-1;

        while(top<=bot && left<=right){
            for(int j=left; j<=right; j++){
                temp.push_back(matrix[top][j]);
            }
                top++;
            for(int i=top; i<=bot; i++){
                temp.push_back(matrix[i][right]);
            }
                right--;
            for(int j=right; j>=left; j--){
                temp.push_back(matrix[bot][j]);
            }
                bot--;
            for(int i=bot; i>=top; i--){
                temp.push_back(matrix[i][left]);
            }
                left++;
        }
        return temp;
    }
}; */



// improvised above code                T - O(m × n)          S - O(1)    

/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> temp;

        // Boundaries
        int top = 0;
        int bot = n - 1;
        int left = 0;
        int right = m - 1;

        while(top <= bot && left <= right){

            // Top row
            for(int j = left; j <= right; j++){
                temp.push_back(matrix[top][j]);
            }
            top++;

            // Right column
            for(int i = top; i <= bot; i++){
                temp.push_back(matrix[i][right]);
            }
            right--;

            // Bottom row                                           // include this condition else duplicate will get printed as in above code
            if(top <= bot){
                for(int j = right; j >= left; j--){
                    temp.push_back(matrix[bot][j]);
                }
                bot--;
            }

            // Left column
            if(left <= right){
                for(int i = bot; i >= top; i--){
                    temp.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return temp;
    }
}; */



                                                    // 3 SUM    LEET-15

// BRUTE {Mistake}  must see 1st
/* class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        for(int i = 0; i < nums.size()-2; i++){

            for(int k = i+1; k < nums.size()-1; k++){

                for(int j = k+1; j < nums.size(); j++){

                    if(nums[i] + nums[j] + nums[k] == 0){

                        ans.push_back({});

                        ans.back().push_back(nums[i]);
                        ans.back().push_back(nums[k]);
                        ans.back().push_back(nums[j]);
                    }
                }
            }
        }

        return ans;
    }
};  */                                                  



// Brute : Improved above code                 

/* class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;

        for(int i = 0; i < nums.size()-2; i++){

            for(int k = i+1; k < nums.size()-1; k++){

                for(int j = k+1; j < nums.size(); j++){

                    if(nums[i] + nums[j] + nums[k] == 0){

                        vector<int> temp = {nums[i], nums[k], nums[j]};     // Insert I,J,K         

                        sort(temp.begin(), temp.end());                     // SORT I,J,K ; elements inside pairs {I,J,K} should be sorted separately before inserting into SET

                        st.insert(temp);                                    // Now insert I,J,K ; SET  will avoid duplicate pair of {I,J,K} & insert pairs in sorted order
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
}; */

// Time Complexity: O(N^3 * log(no. of unique triplets))          Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

// Space Complexity: O(2 * no. of the unique triplets)           Reason: we are using a set data structure and a list to store the triplets.   {2 data structures been used}





// Better Approach      
/* class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;

        for(int i=0; i<nums.size(); i++){
            unordered_set<int> s;
            for(int j=i+1; j<nums.size(); j++){
                int m = -(nums[i]+nums[j]);
                if(s.find(m) != s.end()){
                    vector<int> v = {nums[i], m, nums[j]};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
                s.insert(nums[j]);
            }
        }
        return vector<vector<int>>(st.begin(), st.end());

    }
}; */

// Time Complexity: O(N^2 * log(no. of unique triplets)),
        // Reason : using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// Space Complexity: O(2 * no. of the unique triplets) + O(N) 
        // using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.





// Optimal Approach : 

/* class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());                         // Sort the array 
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;           // except 1st element for rest all elements it will check if i is taking duplicate elements

            int j = i+1;                                        // take 2 pointers j & k   {works like start and end    start++ end--}
            int k = nums.size()-1;                              

            while(j<k){
                int sum = (nums[i] + nums[j] + nums[k]);          

                if(sum>0){                                      // if sum is greater than target '0' then reduce k
                    k--;
                }
                else if(sum<0){                                 // if sum is smaller than target '0' then increase j
                    j++;
                }
                else{                                                       // if got sum = target'0'
                    vector<int> temp = {nums[i], nums[j], nums[k]};         // store pair in temp vector 
                    ans.push_back(temp);                                    // store this temp vector in ur ans which is a 2D vector
                    j++;                                                    // increase j and decrease k for finding next pair of answers keeping i fixed
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;                 // increment j and decrement k until getting same elements as can't take duplicate pairs
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
}; */

// Time Complexity: O(NlogN)+O(N^2)               REASON :  The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N^2). 

// Space Complexity: O(no. of quadruplets)        REASON :  This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).




 
                                                        // 4-SUM   {LEET-18}

// Brute Force                  T - O(n^4)          4 nested Loops
/* class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    for(int l=k+1; l<nums.size(); l++){
                        long long sum = 1LL * nums[i]+nums[j]+nums[k]+nums[l];          // prevent int overflow
                        if(sum == target){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        return vector<vector<int>> {st.begin(), st.end()};
    }
}; */

// Time Complexity: O(N^3 * log(no. of unique pairs))           Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

// Space Complexity: O(2 * no. of the unique pair)                as we are using a set data structure and a list to store the pairs.





// Better Approach                              HASHSET and 3 loops               

/* #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find all unique quadruplets
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>> st;  

        // First loop - pick first number
        for (int i = 0; i < n; i++) {
            // Second loop - pick second number
            for (int j = i + 1; j < n; j++) {
                // HashSet to store numbers between j and k
                unordered_set<int> seen;

                // Third loop - pick third number
                for (int k = j + 1; k < n; k++) {
                    // Find required fourth number
                    long long required = (long long)target - arr[i] - arr[j] - arr[k];

                    // If required number is already in set, we found a quadruplet
                    if (seen.count(required)) {
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    // Add current third number into set
                    seen.insert(arr[k]);
                }
            }
        }

        // Convert set into vector and return
        return vector<vector<int>>(st.begin(), st.end());
    }
};

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution obj;
    vector<vector<int>> ans = obj.fourSum(arr, target);

    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
} */

// Time Complexity: O(N^3*log(M))                           REASON: We are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.

// Space Complexity: O(2 * no. of pairs) + O(N)             REASON:  as we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).





// Optimal                                2 Nested loops + 2 pointers
/*
class Solution {
public:
    // Function to find all unique quadruplets
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;

        // Step 1: Sort array
        sort(arr.begin(), arr.end());

        // Step 2: First loop for first number
        for (int i = 0; i < n; i++) {
            // Skip duplicates for first number
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            // Step 3: Second loop for second number
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for second number
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;

                // Step 4: Two pointers for remaining two numbers
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)arr[i] + arr[j] +
                                    arr[left] + arr[right];

                    if (sum == target) {
                        ans.push_back({arr[i], arr[j],
                                       arr[left], arr[right]});

                        // Move left pointer skipping duplicates
                        while (left < right && arr[left] == arr[left + 1])
                            left++;
                        // Move right pointer skipping duplicates
                        while (left < right && arr[right] == arr[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
}; */

// Time Complexity: O(N^3)                      REASON : Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 

// Space Complexity: O(no. of pairs)     REASON: This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).












                                                    // 23. Next Permutation  {LEET - 31}  

//  Tricky                      T - O(N^2)      S - O(1)

/* class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(nums[i] < nums[j]){
                    swap(nums[i],nums[j]);
                    reverse(nums.begin()+i+1, nums.end());                   // make suffix ascending
                    return;                                                 // stop here —> we found the next permutation
                }
            }
        }
        reverse(nums.begin(), nums.end());                                   // if no i found, array was last permutation -> smallest permutation:
    }
}; */




// OPTIMAL:          T - O(3N)         S - O(n) or O(1)                         BEST ⭐️⭐️⭐️
/* class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;                                   //  ind is breaking point
        for(int i = n-2; i>=0; i--){                    
            if(nums[i] < nums[i+1]){                    // where an element(i) is smaller than it's next element(i+1)
                ind = i;                                // i will be ind(breaking pt)
                break;
            }
        }       
        if(ind == -1){                                      // if no breaking pt means it's last permutation
            return reverse(nums.begin(), nums.end());       // roll back to 1st permutation by reversing whole array 
        }

        for(int i=n-1; i>ind; i--){                                 // find element just greater than ind(breaking pt)
            if(nums[i]>nums[ind]){                                  // as it's in decreasing order so find from right to left       
                swap(nums[i], nums[ind]);                           // swap after getting that element         
                return reverse(nums.begin()+ind+1,nums.end());          // reverse the part of array after breaking point
            }
        }
    }
}; */




//  Brute Force :   T - O(n * n!)                                                           S -> O(n!)                   

/* #include<iostream>
#include<vector>
using namespace std;
void recurP(vector<int> &ds, vector<int> &v, vector<vector<int>> &ans, int freq[]){
    if(ds.size()==v.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<v.size(); i++){
        if(!freq[i]){
            ds.push_back(v[i]);
            freq[i] = 1;
            recurP(ds, v, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
    
vector<vector<int>> nxtP(vector<int>& v){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[v.size()];
    for(int i=0; i<v.size(); i++){
        freq[i] = 0;
    }
    recurP(ds, v, ans, freq);
    return ans;
}

int main()
{
    vector<int> v = {1,3,2};
    vector<vector<int>> ans = nxtP(v); 
    
    cout << "All permutations are:\n";
    for (auto &perm : ans) {
        for (auto &num : perm)
            cout << num << " ";
        cout << endl;
    }   
    return 0;
}  */  

// Time comp -  O(n * n!)                            {n! permutations are being generated   n times the loop is running}                                           
// Space comp - O(n) + O(n) + O(n!) + O(n)           {O(n) for data struct funct, O(n) for map, O(n!) to store ans, O(n) for stack recur call}                                                    




// Improvised Brute Force  :   T - O(n * n!)           S - O(n!) + O(n)         {n! for storing ans and n for stack recursion call}
/* 
#include<iostream>
#include<vector>
using namespace std;
void recurP(int index, vector<int> &v, vector<vector<int>> &ans){
    if(index == v.size()){
        ans.push_back(v);
        return;
    }

    for(int i=index; i<v.size(); i++){
        swap(v[index], v[i]);
        recurP(index+1, v, ans);
        swap(v[index], v[i]);
    }
}

vector<vector<int>> nxtP(vector<int>& v){                     // Will return vector of vectors {set of all possible permutations}
    vector<vector<int>> ans;
    recurP(0, v, ans);
    return ans;
}

int main()
{
    vector<int> v = {1,3,2};
    vector<vector<int>> ans = nxtP(v); 
    
    cout << "All permutations are:\n";
    for (auto &perm : ans) {
        for (auto &num : perm)
            cout << num << " ";
        cout << endl;
    }
    return 0;
} 
*/
// This will generate all premutations, but not in proper sequence 




// We can also use in-built STL Library
/*
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
        string s = "abc";
        next_permutation(s.begin(),s.end());
        cout<<s<<endl;
        next_permutation(s.begin(),s.end());
        cout<<s<<endl;
        prev_permutation(s.begin(),s.end());
        cout<<s<<endl;
cout<<endl<<endl;
*/





                                                    // 56. Merge Intervals
//  BruteForce      T - O(N^2)      S- O(N)

/* class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        for(int i=0; i<n;){
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i+1;
            while(j<n && intervals[j][0] <= end){
                end = max(intervals[j][1], end);
                j++;
            }
            ans.push_back({start, end});
            i = j;
        }

        return ans;
        
    }
}; */




// Optimal              T - O(N*logN) + O(N)                S - O(N)

/* class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int n = intervals.size();

        for(int i=0; i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
}; */








                                            // 152. Maximum Product Subarray

//  BRUTE                           T - O(N^2)               S - O(1)                                       
/* class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        for(int i=0; i<nums.size(); i++){
            int prod = 1;
            for(int j=i; j<nums.size(); j++){
                prod *= nums[j];                        // product will always be incremented 
                maxProd = max(prod, maxProd);           // only update if getting more than prev value
            }
        }
        return maxProd;
    }
}; */



//  OPTIMAL :           PREFIX & SUFFIX                     T - O(N)          S - O(1)
/* class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = nums[0];
        int prefix = 1;
        int suffix = 1;
        for(int i=0; i<nums.size(); i++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;

            prefix *= nums[i];
            suffix *=  nums[n-1-i];
            
            maxP = max(maxP, max(prefix, suffix));
        }
        return maxP;
    }
}; */




// OPTIMAL- II                                       T - O(N)          S - O(1)    

/* class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = nums[0];
        int minP = nums[0];
        int ans  = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i]<0) swap(maxP,minP);

            maxP = max(nums[i], maxP*nums[i]);
            minP = min(nums[i], minP*nums[i]);

            ans = max(maxP, ans);
        }
        return ans;

    }
}; */




                                        // ALgoMaster-259. 3Sum Smaller   T - O(n^2)
/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n - 2; i++) {

        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if(sum < target) {

                // all elements from left+1 to right work
                count += (right - left);

                left++;
            }
            else {
                right--;
            }
        }
    }
    return count;
}

int main() {

    int target;
    cin >> target;

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << threeSumSmaller(nums, target);

    return 0;
} */