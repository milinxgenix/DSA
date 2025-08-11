                                        // 1. Selection Sort  :- Pull minimest at begining, (No Adjacent Swapping)
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

    for(int i=0; i<=n-2; i++){
        int min = i;
        for(int j=i; j<=n-1; j++){
            if(arr[min]>arr[j]){
                //swap(arr[min],arr[i]);      :- this leads to adjacent swapping don't do this
                min = j;                      // find the minimest element first
            }
        }
        swap(arr[min],arr[i]);                // then do the final swapping 
        // int temp = arr[i];
        // arr[i] = arr[min];
        // arr[min] = temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} */

// Time Comp :- O(n^2)
// Space Comp :- O(1)




                                            //2. Bubble Sort :- Push Max at the last using Adjacent Swapping
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

    for(int i=n-1; i>=1; i--){
        for(int j=0; j<=i-1; j++){             // j<=i is replaced by j<=i-1 to avoid runtime OUT OF BOUND error
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);         // Swapping inside the loop leads to swapping of every adjacent element iteratively
            }
        }
        cout<<"run"<<endl;                    // count the loop :- this unoptimize form, runs the loop 4 time for sorted data also 
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} */

// Time Comp :- O(n^2)  :- worst & Avg case        
// Space Comp :- O(1)



                                    //Optimization of Bubble Sort :- To avoid uncessary looping if data already sorted 
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

    for(int i=n-1; i>=1; i--){
        bool didSwap = false;                   // Added a flag to track whether swapping is performed or not
        for(int j=0; j<=i-1; j++){              // j<=i is replaced by j<=i-1 to avoid runtime out of bound error
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);          // Swapping inside the loop leads to swapping of every adjacent element iteratively
                didSwap = true;                 // Turn flag true after swapping is done inside inner loop
            }
        }
        if(!didSwap){
            break;                              // Quit out of loop to stop further iterations if no swapping is performed in prev iteration
        }
        cout<<"Runs"<<endl;                     // Track how many times the loop runs (Cross verify by taking ASC order input and DSC order input)
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 
*/

// Time Comp :- O(n) :- Best Case




                                        // Recursive Bubble Sort :- Bubble sort using recursion instead of iteration
/*
#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n) {

    if (n == 1) return;                             // Call break : stop recursion when one 1 element got left in array after multiple recusive calls 

    bool didSwap = false; 
    for (int j = 0; j <= n - 2; j++) {              // reference from iteration method :- "i = n-1" so "i-1 = n-2"  ;   j<=n-2
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;

            didSwap = true;
        }
    }
    if(!didSwap) return;

    bubble_sort(arr, n - 1);                        // Reducing N by 1 at each subsequent recursive call
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
*/





                                        // 3. Insertion Sort :- Select every element and place them at their best position
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

    for(int i=0; i<=n-1; i++){
        int j = i;                              // Only the (i)th Element will be compared and swapped at every (i)th iteration 

        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);              // will be compared and swappped with adjacent element on it's left
            j--;                                // Element is swapped and shifted left 
            cout<<"Run"<<" ";
        }                                       // this one method is optimised & will give O(n) for sorted/best case


        // while(j>0){                          // If done like this more loops will go unnecessarily, In above we have bounded the while loop with this condition :- "arr[j-1]>arr[j]" to avoid further unnecessary loops
        //     if(arr[j-1]>arr[j]){
        //         swap(arr[j-1],arr[j]);              
        //     }
        //         j--;  
        //         cout<<"Run"<<" ";                            
        // }                                    // this one will give O(n^2) for best case also
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
        
    return 0;
}     
 */


// Time Comp :- O(n^2)  ---> worst and avg case         Best Case ---> O(n)
// Space Comp :- O(1)



                                            //   Recursive Insertion Sort
/* 
#include <iostream>
using namespace std;

void insertion_sort(int arr[], int i, int n) {

    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort(arr, i + 1, n);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertion_sort(arr, 0, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
} 
*/





                                                // Merge sort
/*
#include<iostream>
#include<vector>
using namespace std;
  
    void Merge(int arr[], int low, int high){                  //Call by value -  modifies copy of an array
        vector<int> temp;
        int mid = (low+high)/2;
        int left = low;
        int right = mid+1;

        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

    // If Left elements still remaining and right exhausted :-
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }

    // If Right elements still remaining and left exhausted :-
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low; i<=high; i++){                               // Tranfering sorted temp elements to original array
            arr[i] = temp[i-low];
        }
    }

    void DivSort(int arr[], int low, int high){
        if(low>=high) return;                                       // Call break : Single element

        int mid = (low+high)/2;                                     // mid will be the index of last element of 1st part of array 

        DivSort(arr, low, mid);                                     // 1st recursion for left part from low to mid
        DivSort(arr, mid+1, high);                                  // 2nd recursion for Right part from mid+1 to high

        Merge(arr, low, high);                                 // function called to merge after sorting 1st half and 2nd half
    }

    void MergeSort(int arr[], int n){                               // Passing vector using 'call by reference' in the function
        DivSort(arr, 0, n-1);                                       // Passed 0 as Low and n-1 as high index of array to be sorted   
    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    MergeSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
 */


                                            // Merge Sort :- LeetC version using call by reference function
/*
#include<iostream>
#include<string>
using namespace std;
  
    void Merge(vector<int> &vec, int low, int mid, int high){                   //Call by reference modifies original vector
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while(left<=mid && right<=high){
            if(vec[left]<=vec[right]){
                temp.push_back(vec[left]);
                left++;
            }
            else{
                temp.push_back(vec[right]);
                right++;
            }
        }

    // If Left elements still remaining and right exhausted :-
        while(left<=mid){
            temp.push_back(vec[left]);
            left++;
        }

    // If Right elements still remaining and left exhausted :-
        while(right<=high){
            temp.push_back(vec[right]);
            right++;
        }

        for(int i=low; i<=high; i++){                               // Tranfering sorted temp elements to original array
            vec[i] = temp[i-low];
        }
    }

    void DivSort(vector<int> &vec, int low, int high){
        if(low>=high) return;                                       // Call break

        int mid = (low+high)/2;                                     // mid will be the index of last element of 1st part of array 

        DivSort(vec, low, mid);                                     // 1st recursion for left part from low to mid
        DivSort(vec, mid+1, high);                                  // 2nd recursion for Right part from mid+1 to high

        Merge(vec, low, mid, high);                                 // function called to merge after sorting 1st half and 2nd half
    }

    void MergeSort(vector<int> &vec, int n){                               // Passing vector using 'call by reference' in the function
        DivSort(vec, 0, n-1);                                       // Passed 0 as Low and n-1 as high index of array to be sorted   
    }

int main(){
    int n;
    cin>>n;
    vector<int> vec;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    MergeSort(vec,n);
    for(auto i : vec){
        cout<<i<<" ";
    }
    return 0;
}
 */        

// Time complexity: O(nlogn) 
// Space complexity: O(n)  




                                            // Quick Sort
/*                         
#include<iostream>
#include<string>
using namespace std;

// Conquering function:
int Con(int arr[], int low, int high){
    int pivot = low;
    int i=low;
    int j=high;

    while (i < j)
    {
        while (arr[i] <= arr[pivot] && i < high-1)                      // Pivot = arr[low]  :- 1st element choosed as pivot
        { 
            i++;
        }
        while (arr[j] > arr[pivot] && j > low+1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}

// Division function:
void DivSort(int arr[], int low, int high){
    if(low<high){                                                   //Call break when low = high means single element left    
        int part_ind = Con(arr, low, high);
        DivSort(arr, low, part_ind - 1);
        DivSort(arr, part_ind+1, high);
    }
}

void QS(int arr[], int n){
    DivSort(arr,0,n-1);
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
    QS(arr,n);
    return 0;
}
*/




                                    // Quick Sort :- LeetC version using call by reference function
/*
#include<iostream>
#include<vector>
using namespace std;

// Conquering function:
int Con(vector<int> &vec, int low, int high){
    int pivot = low;                                        //Pivot is index of element chooosed as pivot to placed at correct position 
    int i = low;
    int j = high;

    while(i<j){
        while(vec[i]<vec[pivot] && i<high-1){
            i++;
        }

        while(vec[j]>vec[pivot] && j>low+1){
            j--;
        }

        if(i<j){
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[pivot], vec[j]);                               // Instead of vec[pivot] we can also take vec[low]
    return j;
}

// Division function:
void DivSort(vector<int> &vec, int low, int high){
    if(low>=high) return;                                   //Call Break when low = high means single element left to be sorted
    int part_ind = Con(vec, low, high);
    DivSort(vec, low, part_ind-1);
    DivSort(vec, part_ind+1, high);
}

// Main Quick Sort (calling function)
void QS(vector<int> &vec){
    DivSort(vec,0,vec.size()-1);                                       // '0' as Low (starting index) and 'n-1' as High (last index)
    for(auto v:vec){
        cout<<v<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    QS(vec,n);
    return 0;
}
*/


// Time Complexity :- O(Nlog(N))        worst case :- O(n^2)                                       Read Striver sheet   
// Space Complexity :- O(1) + O(n)      O(n) for stack space (recursion)










                                // LeetC Q-4 (Median of 2 sorted Array)   :- Similar to merging function of merge sort
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i = 0, j = 0;                               // Don't take i = nums[0] or j = nums[0] as it could be empty array also

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]) temp.push_back(nums1[i++]);         
            else temp.push_back(nums2[j++]);
        }

        while(i < nums1.size()) temp.push_back(nums1[i++]);
        while(j < nums2.size()) temp.push_back(nums2[j++]);

        int k = temp.size();
        if(k == 0) return 0.0;                          // if both r Empty array

        if(k % 2 == 0)
            return (temp[k / 2 - 1] + temp[k / 2]) / 2.0;
        else
            return temp[k / 2];
    }
};
*/                                                      // Refer Mergesort code for merging function 
