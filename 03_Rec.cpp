                                                    //Recurrsion
                                                    
                                                    
                                                //Reverse Count (n to 1)
/* 
#include<iostream>
using namespace std;

void printt(int n){
    if(n<1) return;
    cout<<n<<endl;                      // Cout is used before calling the recursive function :- Forward Recursion
    printt(n-1);
}

int main(){
    int n;
    cin>>n;
    printt(n);
}
*/


                                                    //Straight count (1 to n)
/* 
#include<iostream>
using namespace std;

void printt(int n){
    if(n<1) return;
    printt(n-1);
    cout<<n<<endl;                          // Cout is used after calling the function :- BACK TRACKING
}

int main(){
    int n;
    cin>>n;
    printt(n);
}
 */



                                                    //Count between 2 integers
/* 
#include<iostream>
using namespace std;

void func(int i, int n){ 
   // Base Condition.
   if(i>n) return;
   cout<<i<<endl;

   // Function call to print i till i increments to n.
   func(i+1,n);
}

int main(){
    int i,n;
    cin>>i>>n;
    func(i,n);
    return 0;

} */



                                                        //Count between 2 integers (BACK TRACKING)
/*
#include<iostream>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i<1) return;
   
   // Function call to print (n-1) integers.
   func(i-1,n);
   cout<<i<<endl;

}

int main(){
  int n;
  cin>>n;
  func(n,n);
  return 0;
}
*/



// Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

// Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.




                                            //Sum of 1st N natural numbers
/* 
#include<iostream>
using namespace std;
int sum(int n){
    if(n==0) return 0;                      //At sum(2) it will gives 2 + sum(1)  similarly  At sum(1) it gives 2+1+sum(0)  but At Sum(0) it directly returns 0 and stop calling the Sum() funt and recursion stops 
    return n + sum(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
}
 */

// using loop :- Time comp = O(N) & Space comp = O(1)
// using formula :- Time comp = O(1) & Space comp = O(1)     {N = N * (N+1) / 2}
// using recursion :- Time comp = O(N) & Space comp = O(N)




                                            //Factorial
// Parameterized way
/* 
#include<iostream>
using namespace std;
void fact(int i, int n){
    if(i<1){                       //Base Condition tells if i gets less than 1 then terminate the recursive function and print fact
        cout<<n;
        return;                    // if not return it will continue into loop again & again
    }
    fact(i-1,n*i);
}

int main(){
    int a;
    cin>>a;
    fact(a,1);
} 
 */



//Fuctional way
/*
#include<iostream>
using namespace std;
int fact(int n){
    if (n<1) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}
*/


// Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
// Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
// Iterative approach :- Time compl = O(n)  &   Space Complexity = O(1)






                                                        //Reverse Array

// without creating auxilary array using Recursion (RAW code, don't use)
/* 
#include<iostream>
using namespace std;
void rev(int n, int arr[]){
    if(n<1) return;
    cout<<arr[n-1]<<" ";
    rev(n-1,arr);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    rev(n,arr);
} 
*/



// Creating new auxilary array to store elements in reversed order :- ITERATION
/* 
#include<iostream>
using namespace std;
void rev(int n, int arr[]){
    int rev[n];
    for(int i=0; i<n; i++){
        rev[n-1-i] = arr[i];
    }
    for(int i=0; i<n; i++){
        cout<<rev[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    rev(n, arr);
}
 */



// Optimising above using "TWO POINTER" method             #BEST METHOD for Array Reversal
/* 
#include<iostream>
using namespace std;
void rev(int n, int arr[]){
    int start = 0;
    int last = n-1;
    while(start<last)                               // Terminating point :- will allow to iterate only up to half 
    {
        swap(arr[start],arr[last]);
        start++;
        last--;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    rev(n, arr);
}
 */



// Applying above optimised soln under recursive manner
//1st way :-
/* 
#include<iostream>
using namespace std;
void rev(int i, int n, int arr[]) {
    if (i >= n / 2) return;              // stop when i reaches middle
    swap(arr[i], arr[n - 1 - i]);
    rev(i + 1, n, arr);
}
int main(){
    int i=0;                            //indexing will start from 0 always
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    rev(i,n, arr);    

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
 */



//2nd way :-
/* 
#include <iostream>
using namespace std;

void rev(int arr[], int start, int end) {
    if (start < end) {
        swap(arr[start], arr[end]);
        rev(arr, start + 1, end - 1);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];  // Variable-Length Array (OK in GCC)
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rev(arr, 0, n - 1);   // reverse array in-place
    printArray(arr, n);   // print only once after complete reversal
}
 */



// Using library function (New Approach)
/*
#include <iostream>
#include<algorithm>
using namespace std;

//Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

//Reverse array using library function
void reverseArray(int arr[], int n) {
   //Reversing elements from index 0 to n-1 
   reverse(arr, arr + n);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

   reverseArray(arr, n);
   printArray(arr, n);
   return 0;
} 
*/



                                                    //Time-Space Complexity for Array Reversal

// ITERATION   :-   Time comp = O(n)    &    Space Comp = O(n)
// Two Pointer :-   Time comp = O(n)    &    Space Comp = O(1)
// Recursion   :-   Time comp = O(n)    &    Space Comp = O(n)
// Libr. Funt  :-   Time comp = O(n)    &    Space Comp = O(1)




                                                // Palindrome
// Functional Approach
/* 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool pal(string s) {
    string st = s;
    reverse(st.begin(), st.end());
    return s == st;
}

int main() {
    string s;
    getline(cin, s);
    if (pal(s)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
 */



// Iterative Approach
/* 
#include<iostream>
using namespace std;
bool pal(string s){
    int n = s.length();
    for(int i=0; i<n/2; i++){
        if(s[i] != s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    getline(cin,s);
    if(pal(s)){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
} 
*/



//To ignore spaces and case, modify the function like this:             //(LEET-C Q 125) :- Valid Palindrome
/* 
#include<iostream>
#include<cctype>
using namespace std; 

bool pal(string s){
    string cleaned = "";
    for(char c : s){
        if(isalnum(c))                  // keep only letters and digits
            cleaned += tolower(c);
    }
    
    int n = cleaned.length();
    for(int i = 0; i < n / 2; i++){
        if(cleaned[i] != cleaned[n - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    getline(cin,s);
    if(pal(s)){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
} 
 */



// Recursion
/* 
#include<iostream>
#include<cctype>
using namespace std;

bool pal(int i, string s){
// To Remove spaces and cases :- 
    string cleaned = "";
    for(char c : s){
        if(isalnum(c))                  //keep only letters and digits
            cleaned += tolower(c);
    }

    int n = cleaned.length();
    if(i>=n/2) return true;      // Base Condition :- If i exceeds half of the string means all the elements are compared, we return true.

    if(cleaned[i] != cleaned[n - 1 - i]){
        return false;
    }

    return pal(i+1,cleaned);
}

int main(){
    string s;
    getline(cin,s);
    if(pal(0,s)){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
} 
*/


// Functional Approach :-    Time Comp = O(n)    &    Space Comp = O(n)
// Iterative Approach  :-    Time Comp = O(n)    &    Space Comp = O(1)
// Recursive Approach  :-    Time Comp = O(n)    &    Space Comp = O(n)





                                                        //Fibonnaci

//Iterative Approach            Time comp = O(n)  &  Space comp = O(1)                                            
/* 
#include<iostream>
#include<string>
using namespace std;
void fib(int n){
    int a=0, b=1;
    cout<<a<<" "<<b<<" ";
    int temp;
    for(int i=0; i<n-1; i++){
        cout<<a+b<<" ";
        temp = b;
        b = a+b;
        a = temp;
    }
}
int main()
{
    int n;
    cin>>n;
    fib(n);
    return 0;
} 
*/


//Recursive Approach        Time comp = O(2^n)  &  Space comp = O(n)
/* 
#include<iostream>
#include<string>
using namespace std;
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<=n; i++){
        cout<<fib(i)<<" ";  
    }
    return 0;
}
*/





// vid lect from 3,4,5  to analysis the time space comp
// revise recursion & Maths







