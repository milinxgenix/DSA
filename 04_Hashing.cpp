                                            //HASH ARRAYS
                        // Counting freq of elements of an array {Integer Hashing}
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of number list: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the numbers to be stored in the list:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

// pre-Storing & computation:
    int hash[15] = {0};             //Creating a fixed size hash array of size 15 which will count freq. of numbers from 0 to 14
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    int q;
    cout<<"how many times u want to fetch frequencies: ";
    cin>>q;
    while(q--){
        int numb;
        cout<<"Enter the number whose occurance u want to find: ";
        cin>>numb;

        //fetching 
        cout<<"Frequency of this number is: "<< hash[numb] <<endl;
    }
    return 0;
}
*/



                                        //Character Hashing

// If lower_case & upper_Case mentioned explicitly in Qs
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);

//Pre-computation:-
    int hash[27] = {0};                         //there's 26 letters in alphabets
    for(int i=0; i<s.size(); i++){
        hash[s[i]-'a']++;                       //hash[s[i]] for 'a' will be 97 but a is placed at 0th index.
    }

//fetch
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    return 0;
} 
*/



// If lower_case & upper_Case all are included   :- hash array will have bigger size and occupy more memory space
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);

//Pre-computation:-
    int hash[257] = {0};                    //there's 256 ASCII characters 
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;                       //No need to subtract like above as 'a' will be at 96th index only having 97 as ascii value
    }

    // for(char c : s){                     //Better to do looping like this instead
    //     hash[c]++;
    // }

//fetch
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
    return 0;
} 
*/




                                                    //HASHMAPS

                            //Counting the frequency of each letters in a word/sentence 
//using Iterations:-
/*
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(int i=0; i<s.length(); i++){
        int count=0;
        int flag=0;
        for(int j=0; j<s.length(); j++){
            if(s[i]==s[j]){
                count++;
            }
        }

        for(int k=i-1; k>=0; k--){
            if(s[i]==s[k]){
                flag++;
            }
        }

        if(flag==0){
            cout<<s[i]<<" is occuring "<<count<<" times "<<endl;
        }
    }
}
*/      
// Total Time Complexity=  O(n) × {O(n) + O(n)} = O(n×2n) = O(2n^2) ~ O(n^2)
// Time comp :- O(n^2)   &   Space compl :- O(1)





                // We use HASHMAP/Unordered_map to optimise the above code so need to do CHARACTER HASHING
/*
#include<iostream>
#include <cctype>                           //Included this to use "isalpha()"
#include<unordered_map>
using namespace std;
int main()
{
    string s;
    getline(cin,s);

    string cleaned = "";                    //Removing Spaces
    for(char c : s){
        if(isalpha(c)){
            cleaned += tolower(c);
    }
    }

// Pre Computation:-
    unordered_map<char, int> F;             //Creating an unordered map instead of hash array
    for(char c : cleaned){
        F[c]++;                          
    }

// Fetching :- 
    for(auto p : F){                       
        cout << p.first << " is occurring " << p.second << " times\n";
    }
    return 0;
}
*/

// Time Comp :- O(n)   &    Space comp :- O(n)
// Time Comp :- 
    // iteration :-         O(n^2)
    // Map :-               O(logn) in all the cases
    // Unordered Map :-     O(1) in best and avg cases   &&  O(n) in worst case during internal collision
// O(n^2) >> O(n) >> O(logn) >> O(1)   ;  O(n^2) is worst and O(1) is best

// if we don't clean to remove spaces then Space comp :- O(1)

// Here in above code we don't need to store MAP keys and values using 'INSERT' function of MAP,   this "F[c]++"  automatically insert the key 'c' with value as '0' and increments the value of the key 'C' on further occurance of 'C'.
// freq[c]++ both inserts and updates the map key and their respective value pairs, all in one line.

//Note: Our first priority will be always to use unordered_map and then map. If unordered_map gives a time limit exceeded error(TLE), we will then use the map.



                                    // Unordered map for Q1
/*
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of number list: ";
    cin >> n;


// PRESTORING the Array list and PRECOMPUTATION of unordered map in the same loop :-
    int arr[n];
    unordered_map<int, int> U;
    cout << "Enter the numbers to be stored in the list:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        U[arr[i]]++;
    }

// ITERATING THE MAP (not required here)       it won't be having any order it will print randomly, for ordered manner we have to use map which sorts it's elements by default
    for(auto p : U){                       
        cout << p.first << " is occurring " << p.second << " times\n";
    }

// FETCHING :-  
    string s;
    while (true) {
        int i;
        cout << "\nEnter number to search frequency of: ";
        cin >> i;

        cout << i << " is occurring " << U[i] << " times\n";

        cout << "Do you want to add more numbers? (Yes/No): ";
        cin >> s;
        if (s == "No" || s == "no" || s == "NO" || s == "nO") {
            break;
        }
    }

    return 0;
}
*/

// Hash[n+1] = {0}  this can't be done so we need to use either hash vector instead of this hash array which would be very complicated
// Else we can use Unordered maps(C++) or Hash maps(java) to fix this issue as they have no predefined size limits



// MAPS :- Can have pairs as their keys ;  map<pair<int,int> , char> m  i.e;  map[(2,3),a] => (2,3) -> a
// Unordered Maps :- can't have pairs as their key only individial single datatypes are allowed



// To prevent collision we do DIVISION HASHING as:- 
//      * Pre storing: hash[arr[i]%10] += 1;
//      * Fetching: hash[number%10];




                            // Use a Hash Table with Buckets (Chaining):  to perform linear chaining while in case of collision
// const int SIZE = 10;
// vector<vector<int>> hash(SIZE);     // each index is a bucket

// // Insertion
// for (int i = 0; i < arr.size(); i++) {
//     int key = arr[i] % SIZE;
//     hash[key].push_back(arr[i]);
// }

// // Searching
// int num = 129;
// int key = num % SIZE;
// bool found = find(hash[key].begin(), hash[key].end(), num) != hash[key].end();


// using this numbers like 139,129,89 will be collected into same bucked using modulo hashing so we can find the element of array list from that bucket





                                // Q Find the highest/lowest frequency element
/* 
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
void find(int n, int arr[]){
    unordered_map<int,int> u;

// Pre Compute :- 
    for(int i=0; i<n; i++){
        u[arr[i]]++;
    }

// Iteration to find max freq & min freq      
    int max_key;
    int max_value = INT_MIN;        // INT_MIN is the builtin method to denoting the minimest integer available
    int min_key;
    int min_value = INT_MAX;        // INT_MAX is the builtin method to denoting the max integer available

    for(auto p : u){
        if(p.second>max_value){
            max_value = p.second;
            max_key = p.first;
        }
        if(p.second<min_value){
            min_value = p.second;
            min_key = p.first;
        }
    }
    cout<<"Element with max freq is: "<<max_key<<" with occurence of "<<max_value<<" times"<<endl;
    cout<<"Element with min freq is: "<<min_key<<" with occurence of "<<min_value<<" times"<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    find(n,arr);
    return 0;
} */





                                                            //  LEET CODES 




                                                            // LEET-C Q1 (TWO SUM)
/*
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> two_sum(vector<int>& nums, int target){

    unordered_map<int,int> m;               // stores value -> index
    
    for(int i=0; i<nums.size(); i++){
        int comp = target - nums[i];

        if(m.find(comp) != m.end()){
            return {m[comp],i};             // Found the two indices,  will be returned as elements of vector so putted in curly braces {}.
        }
        m[nums[i]]=i;                       // Store value and its index to match with upcoming array elements


        // if(m.count(comp)){               // same thing can be done using count() method instead of find() method
        //     return {m[comp], i};
        // }

    }

    return {}; // if No solution found (must need to be added or will throw error)
}
*/

//Notes :- 
/*
    * created a hashmap to store the elements of array as key of map and their indexes as value
    * uniform initialization (also called brace initialization '{}') in C++. It initializes a vector<int>
    *           vector<int> result;
                result.push_back(m[complement]);
                result.push_back(i);
                return result;                    could be done like this also

    * Loop → O(n) &  unordered_map → O(1) (constant time), due to hashing
                    ➡️ Total Time Complexity: O(n)
    * n entries in the map ➡️ Total Space Complexity: O(n)
*/






                                                            //LeetC - 41

// Note :
/*
    * Hashmap can't be used it requires const space O(1)
    * Time - O(n) so can't do sorting but can do linear search
    * Unsorted - can't use binary search to find max element
    * Space - O(1) const space so can't use any data structure or recursion to store elements
*/


            // Brute Force:   Time = O(n^2)  and  Space = O(1) 
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int Max = nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]>Max){
        //         Max = nums[i];
        //     }
        // }

        int Max = *max_element(nums.begin(), nums.end());

        for (int i = 1; i <= Max + 1; i++) {
        bool found = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) return i;
        }
        return -1;
    }
};
*/




            // HashMAP :     Time : O(n)  &  Space : O(n)
/*
class Solution {
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


// No Need to use max key we can iterate through the map in above mentioned manner also 
        // int max_key = 0;
        // for(auto p : m){
        //     if(p.first>max_key){
        //         max_key = p.first;
        //     }
        // }

        // for(int i=1; i<max_key; i++){
        //     if(m.find(i) == m.end()){
        //         return i;
        //     }
        // }
        // return max_key + 1;
    }
};
*/



    //  INDEX REPLACEMENT METHOD (In-Place method for const space use)    
// Optimal Soln :     Time = O(n)   space = O(1)        
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            int i = 0;

            while (i < n) {     
                if (nums[i] > 0 && nums[i] <= n) {                      // Only swap if nums[i] is in the range [1, n]
                    int correctIndex = nums[i] - 1;                     // Only compute correctIndex if nums[i] is in range
                    if (nums[i] != nums[correctIndex]) {                // Don't swap if already in correct position
                        swap(nums[i], nums[correctIndex]);
                        continue;
                    }
                }
                i++;                                                    // iterate i if any of the conditions is voilated
            }

            // Find first index where value is not index+1
            for (int i = 0; i < n; i++) {
                if (nums[i] != i + 1) return i + 1;
            }
 
            return n + 1;

    }
};
*/





                                        //    LEET-C -> 2367 (Sum of 3riplets)   :- similar to LeetC-1 (2 sum)

// Brute Force :              Time - O(n^3)   space - O(1)               As per given contraints, brute force is also applicable
/*
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] - nums[i] == diff) {
                    for(int k = j + 1; k < n; k++) {
                        if(nums[k] - nums[j] == diff) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;

    }
};
*/



            // Unordered HashMap      Time - O(log(n))    space - O(n)
/* 
#include<unordered_map>
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        unordered_map<int,int> m;

        for(int v : nums){
            m[v]++;
        }

        for(int i=0; i<n; i++){
            int x = nums[i] + diff;
            int y = nums[i] + (2*diff);

            if(m.find(x) != m.end() && m.find(y) != m.end()){
                count++;
            }
        }

        return count;
    }
};
*/




            // Hash Set :-              Time - O(log(n))   Space - O(n)
            
// * No need to track index value so better to use HashSet rather than HashMap
// * More space efficient than HashMap as it stores key only and map stores key,value pair 
// * In Q1 (2-Sum) we need to return incides so we tracked it using Hash-Map but here we just asked to find the counts so no need to track indices so using Hash-Set
/* 
#include<unordered_set>
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int countt = 0;
        unordered_set<int> S(nums.begin(), nums.end());

        for (int num : nums) {
            if (S.count(num + diff) && S.count(num + 2 * diff)) {
                countt++;
            }
        }

        return countt;

    }
};
 */




