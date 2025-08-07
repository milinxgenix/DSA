                                        // 1. Largest Element in Array

// Optimized: Iteration (Linear Scan)     Time : O(N)      Space : O(1)       ✅ better than sorting
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

// unique() removes duplicates and moves unique elements to front
    auto it = unique(v.begin(), v.end());

// Erase the trailing duplicates
    v.erase(it, v.end());

    cout<<"2nd largest: "<<*(v.end()-2)<<endl;
    cout<<"2nd smallest: "<<*(v.begin()+1);
}
   */                              




// Slight better :              Time : O(N)  Traversed Twice         Space : O(1)
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
    if(arr[0]<arr[1]){
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                isSorted = false;
                break;
            }
        }
    }

    else{
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
//             if (nums[min1] > nums[i]) min1 = i;
//         }

//         for (int i = 0; i < n; i++) {
//             if (nums[min2] >= nums[i]) min2 = i;
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
//  Below one is correct as we are rotating for all minimum positions 
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
        int min = *min_element(nums.begin(), nums.end());       // Built-In func to find minimest element in array 

        for(int i=0; i<nums.size(); i++){                       // Finding all minimum values at diff index and rotating for each of them
            if(nums[i] == min){
                vector<int> arr(nums);                              // Copy constructor to copy elements of one vector to another
                rotate(arr.begin(), arr.begin()+i, arr.end());
                if(isSorted(arr)){
                    return true;                                   // Don't directly return isSorted(arr) as it will check for 1st min rotation only
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
    
// Also check the "wrap-around" drop: last -> first
        if(nums[n-1]>nums[0]){                                // nums[n-1] is the last element 
            cnt++;
        }
        return cnt<=1;                                        // Return true only if count is equal or smaller than 1
    }
};
 */


// check for number of rotations and wrap-around condition
// There should be single rotation (one 1 drop so count<=1) and also do wrap around to check below testcase conditions
// count <=1 as [3,4,5,2,1]  one drop is allowed "5>2" -- "{nums[i-1]>nums[i]}" in sorted array this thing can be occur for atmost 1 time it there's some rotation
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







                                // 4. Remove Duplicates in-place from Sorted Array

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



// Using In-Place  :-   Using Hash-Set as it's doesn't stores duplicate elements   (In-Place tech but need to create a extra data structure)
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
    for (int x: s) {                //placing the set elements into array and replacing old array elements
      arr[j++] = x;
    }

    n = s.size();               // Redefined the size of array equvalence to set size garbage duplicate values will be trimmed out
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
    int temp[n];                   // Created extra array (don't create vector as "temp[i-1] = v[0]" not possible in vector)
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
    int temp = v[0];                                // assigning temp as 1st element to switch with last 

    int i = 0;
    for(int j=1; j<n; j++){
        v[i] = v[j];
        i++;
    }
    
    // for (int i = 0; i < n - 1; i++) {            // instead of 2 pointer can be done like this also
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
// Bruteforce :- T - O(n^2)     S - O(1)
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



                                        // Brute Force :-   T-O(n)    S-O(1)
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

    for(int i=k; i<n; i++){             // Left Shifting elements by 'K'
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