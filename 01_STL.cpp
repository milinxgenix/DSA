// * 2D Vectors :- vector of vectors( syntax:- vector<vector<int>> Lvec(vec1,vec2);)   --> See GFG
      
//Refer APNA COLLEGE ONE SHOT (1hr) as referal vid

                        
                                                
                                                
                                                //STL Array :- all methods of vector works here 
/*
#include<iostream>
#include<array>
using namespace std;
int main()
{
        int arr[4] = {1,2,3,4};                 //Basic method of initializing array
        array<int, 4> a = {0,1,2,3};            // STL Array 
        return 0;
}
*/                                             
                        
       
                        
                        
                                                //Sequence Containers :- Stores Data sequentially in continugous manner 
                        //1. Vector
/*
#include<iostream>
#include<vector>
using namespace std;

int main(){

//ways to create vector
    vector<int> vec;
    vector<int> vec1 = {9,7,8,0,3};
    vector<int> vec2(5,-9);               // vector of size 5 will be created with all elements as -9
    vector<int> vec3(vec1);               // make a copy of vec 1 as vec 3
    

//Methods in Vector :-  urVectorName.method()

        //1. .size()  &  .capacity()
            cout<<vec.size()<<endl;             //size  is no of element present in vector
            cout<<vec.capacity()<<endl;         // Capacity is no of element that a vector can hold
    
        //2. .push_back()  :- Add element at last
                vec.push_back(3);
                vec.push_back(1);
                vec.push_back(2); 
                vec.push_back(5); 
                vec.push_back(4); 
                vec.push_back(9); 

        //3. emplace_back()   :- similar to push back but it reads emplace objects also, it construct and append new element directly 
                vec.emplace_back(6);
                vec.emplace_back(0);

        //4. pop_back() :- delete last element 
                vec.pop_back();

        //5. indexing :-
                cout<< "value at index 2 is "<<vec[2]<<endl;
                cout<< "value at index 3 is "<<vec.at(3)<<endl;
                cout<< "Front Element "<<vec.front()<<endl;
                cout<< "last Element "<<vec.back()<<endl;

        //6. Erase :-  //can't pass index
                // vec.erase(vec.front());                            // Invalid as vec.front() is not a pointer/iterator instead it returns element directly
                vec.erase(vec.begin());                              
                vec.erase(vec.begin()+3);                             //delete the element at index 3
                vec.erase(vec.end());                                 //Not Valid as vec.end() points to garbage value
                vec.erase(vec.end()-1);
                vec.erase(vec.begin() + 1, vec.begin() + 4);          //will erase a range of elements
                //vec.erase(vec.at(3));                               //Don't works like this anyhow we will be using iterator as we have done in abv example
        
        //7. Insert :-
                vec.insert(vec.begin()+2, 100);                       //will insert 100 at given index, here iterator is pointing at 2nd Index

        // Taking user input:- 
                int a;
                cin >> a;
                vec.push_back(a);


//printing elem of vector using for-each loop (for-in & for-of don't work in C++)
        for(int val : vec){
            cout << val <<" ";
        } 
        cout<<endl;


        //8. Clear :-
                vec.clear();            //will clear the whole vector but capicity will remained same 


        for(int val : vec){
            cout << val <<" ";
        } 
        cout<<"Vector cleared"<<endl;
        cout<<vec.size()<<endl;
        cout<<vec.capacity()<<endl;          //this will not change even after deleting elements or clearing the whole vector

    
        //9. Empty :- Boolean 
                cout<<vec.empty();         //Returns 1 for empty vector & 0 for non-empty vector

    return 0;
}
*/

                                        //Iterators :- works as pointer
/*
#include<iostream>
#include<vector>
using namespace std;
int main(){
        vector<int> v={0,1,2,3,4,5};

        for(int val:v){
                cout<<val<<" ";
        }
        cout<<endl;

//1  .begin() :-
        cout<< *(v.begin()) <<endl;    //returns the value at index 0 on derefrencing

//2  .end()   :- 
        cout<< *(v.end()-1) <<endl;    //v.end() gives garbage value as it points value at index n not (n-1)

//3  .rbegin()  :-  
        cout<< *(v.rbegin()) <<endl;   //this will point (n-1) so won't through garbage

//4  .rend()    :-
        cout<< *(v.rend()) <<endl;     //reverse end won't points 1st element but a garbage value coming just before the 1st element         


//Creating a loop through iterator
        vector<int> :: iterator it;                     //created an iterator it 

        for(it = v.begin(); it!=v.end(); it++){        //here also we can use "auto" keyword to skip the initialization of iterator
                cout<< *(it) <<" ";
        }
        cout<<endl;

//Creating a reverse loop through iterator
        //vector<int> :: reverse_iterator it;           //instead of initializing it here we can put this into the bracket below where loop is created
        
        //for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        //        cout<< *(it) <<" ";
        //}
        
        for(auto it=v.rbegin(); it!=v.rend(); it++){      //whole above thing can be sorted into a keyword auto
                cout<< *(it) <<" ";                       //Instead of  "it!=v.rend()"  we can also use  "it<v.rend()"
        }
}
*/                   







                        //2. Lists :- Doubly Linked List        (Forward list :- Singly linked list)

//          * Also Sequential Container like vector   
//          * Implemented & work as Doubly Linked List
//          * Can be push & pop from front & back both
//          * Iterator works here too
//          * .size(), .erase(), .clear(), begin, end, rbegin, rend(), insert, front, back    all these methods are also defined
//          * can't use random accessing methods like l.at(4) or l[4] like we use to do in vectors as it's a linked list not an array.

/*
#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    list<int> l2 = {0,12,3,21,56};

    l.push_back(2);
    l.push_back(1);
    l.push_back(0);
    l.push_front(9);
    l.push_front(3);
    l.push_front(5);

    l.emplace_back(8);
    l.emplace_front(7);

    l2.pop_back();
    l2.pop_front();

    //cout<<l[3];         //Random Access is not possible here
     
    for(int val : l){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int val : l2){
        cout<<val<<" ";
    }
    return 0;
}
*/




                        //3. Deque :- Double Ended Queue

// * Deque :- means double ended queue works totally same as list
// * Dequeue :- method to pop an element from a queue
// * All methods from list works here also
// * List is internally a doubly linked list :- Random Access is not possible.
// * Deque is internally implemented with help of dynamic Array :- so Random Access is possible here

/*
#include<iostream>
#include<deque>
using namespace std;

int main(){
        deque<int> d={1,2,6,4};

        for(int val : d){
             cout<<val<<" ";
        }
        cout<<endl;

//Indexing possible in Deque & Vector but not in List
        cout<<d[3]<<endl;
        cout<<d.at(3)<<endl;
}
*/



                                //Pairs :- part of c++ utility library
/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
        pair<int, int> p = {3,4};                         //Similary Pairs of Array or vector can also be created, Just pass array data type inside the PAIR
        pair<char, int> p2 = {'a',2};                    
        pair<string, float> p3 = {"mili",0.1};
        pair<char, string> p4 = {'K',"Mili"};

        cout<<p.first<<endl;
        cout<<p.second<<endl;
        cout<<p2.first<<endl;
        cout<<p2.second<<endl;
        cout<<p3.first<<endl;
        cout<<p3.second<<endl;
        cout<<p4.first<<" ";
        cout<<p4.second<<endl;

cout<<endl;

        pair<int, pair<int,char>> p5 = {1, {2,'m'}};
        cout<<p5.first<<endl;
      // cout<<p5.second<<endl;                //will throw error
        cout<<p5.second.first<<" ";
        cout<<p5.second.second<<endl;



                                                        // VECTOR of PAIRs :-

        vector<pair<int,int>> vec = {{1,2}, {2,3}, {5,6}};

//Push_Back VS Emplace_Back
        vec.push_back({8,9});
        vec.emplace_back(8,9);          //create in-place objects so no need to define the inputs in pair it will create them in paired object automatically


//Taking User Input
        int a,b;
        cout<<"enter 1st no of pair: ";
        cin>>a;
        cout<<"enter 2nd no of pair: ";
        cin>>b;
        vec.push_back({a,b});
        // vec.emplace_back(a,b);     //this too will work


        // for(pair val : vec){          //can't print like this 
        //         cout<<val<<" ";
        // }
        // cout<<endl;


        for(pair<int,int> val : vec){
                cout<<val.first<<" "<<val.second<<endl;
        }
        cout<<endl;



                                                        // ARRAY of PAIRs:-

pair<int, int> arr[] = {{1,2},{2,3},{3,4},{8,9}};

cout<<"array pairs:\n";
s
for(auto val : arr){
        cout<<val.first<<" "<<val.second<<endl;     
}

}
*/









                                        //Non-Sequential Containers
                        //1. STACK:- LIFO :--  element added at the last will be popped out first
/*                        
#include<iostream>
#include<stack>
using namespace std;

int main(){
        stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.emplace(4);
        s.emplace(5);

        cout<<"initial size of S= "<<s.size()<<endl;

        cout<<"top = "<<s.top()<<endl;                  //returns the topmost i.e lastly added element
        s.pop();                                        //top most element added at last will be removed

        stack<int> s2;
        cout<<"initial size of S2: "<<s2.size()<<endl;

//SWAP :- Swap elements of 2 stacks
        s2.swap(s);                        //all element of S will be swapped with S2

        cout<<"Updated size of S: "<<s.size()<<endl;
        cout<<"Updated size of S2: "<<s2.size()<<endl;


        stack<int> s3;
        s3.push(0);
        s3.push(9);
        s3.push(7);
        cout<<"initial size of S3: "<<s3.size()<<endl;
        s3.swap(s2);
        cout<<"Updated size of S2: "<<s2.size()<<endl;
        cout<<"Updated size of S3: "<<s3.size()<<endl;


//Imp Loop used in Qs:-
        while(!s2.empty()){               //while stack is not empty
                cout<<s2.top()<<endl;     //Print the topmost element i.e the element which was added at last
                s2.pop();                 //And pop them out sequentially
        }

}
*/



                        //2. Queue:- FIFO   :- element added at the begining will be popped out first

//      * push, emplace, front, pop, size, empty, swap
//      * Every thing same as stack just we have "front" here instead of top
/*
#include<iostream>
#include<queue>
using namespace std;

int main(){
        queue<int> q;

        q.push(1);
        q.push(2);
        q.push(3);
        q.emplace(4);
        q.emplace(5);

        cout<<q.front()<<endl;
        cout<<q.size()<<endl;


//Imp Loop used in Qs:-
        while(!q.empty()){               //while queue is not empty
                cout<<q.front()<<" ";     //Print the front element i.e the element which was added 1st 
                q.pop();                 //And pop them out sequentially
        }
}
*/



                                                                //3. Priority Queue
//      * push, emplace, top, pop, size, empty
/*
#include<iostream>
#include<queue>
using namespace std;

int main(){
        priority_queue<int> q;                  //MAX HEAP

        q.push(4);
        q.push(10);
        q.push(2);
        q.emplace(19);

        while(!q.empty()){
                cout<<q.top()<<" ";     //largest will be at the top of priority stack/queue
                q.pop();                            
        }
cout<<endl;

// Reverse Priority Queue to place shortest element at the top of the stack
        priority_queue<int, vector<int>, greater<int>> rq;                              //MIN HEAP

        rq.push(4);
        rq.push(10);
        rq.push(2);
        rq.emplace(19);

        while(!rq.empty()){
                cout<<rq.top()<<" ";     //largest will be at the top of priority stack/queue
                rq.pop();                            
        }
}
*/


 

                        //4. MAP :- stores (key, value) pairs  :- KEY will be unique
/*
#include<iostream>
#include<map>
using namespace std;

int main(){
        map<string, int> m;

        m["tv"] = 100;
        m["laptop"] = 100;
        m["headphones"] = 50;
        m["tablet"] = 120;
        m["watch"] = 50;

//Insert :-
        m.insert({"camera", 25});
        //m.insert({"camera", 25},{"lens", 8});         //can't pass mustiple keys & value like this

//Emplace :-
        m.emplace("toolkit", 90);

//count :-
        cout<<"count = "<<m.count("laptop")<<endl;      //returns 1 if the key exist and 0 if it doesn't
        cout<<"laptop = " << m["laptop"]<<endl;         //return the value of this key "laptop"

//Erase :- 
        m.erase("tv");

//Find :-   
        // m.find(key)  :- Returns iterator to key or m.end() if key not found     {m.end() is a garbage value}
        // *(m.find(key)) :- Dereferences the iterator (gives key-value pair)

        if(m.find("camera") != m.end()){
                cout<<"found\n";
        }
        else{
                cout<<"not found\n";
        }

//since it pair kind of data so we can use auto keyword here
        for(auto p: m){
                cout << p.first << " " << p.second <<endl;
        }
//Here it will be sorted according to KEY like in above case output thrown will be sorted in ascending order of alphabetical order of keys
}
*/


// using find method of map data structure 
/* 
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> map1;
    map1[1] = "one";
    map1[2] = "two";

    auto it = map1.find(1);             // iterator of key "1" will be stored in 'it'
    if (it != map1.end()) {
        auto pair = *it;                // dereferencing the iterator 'it'
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
 */




                               // 4A. Multi Map  :- Can have multiple keys
/*
#include<iostream>
#include<map>
using namespace std;

int main(){
        multimap<string, int> m;

        m.emplace("tv",100);                    // m["tv"] = 100; :- can't be done like this
        m.emplace("remote",1000);
        m.emplace("watch",10);
        m.insert({"laptop",50});
        m.insert({"AC",5});
        m.insert({"AC",5});
        m.insert({"AC",5});
        m.emplace("tv",100);
        m.emplace("tv",80);

        for(auto p: m){
                cout << p.first << " " << p.second <<endl;
        }
cout<<endl<<endl;

        m.erase("tv");     //will erase all TV keys
        for(auto p: m){
                cout << p.first << " " << p.second <<endl;
        }
cout<<endl<<endl;

//To erase single key from the grp of similar keys
        m.erase(m.find("AC"));                          //m.find("AC") will return the iterator(memory location) of 1st AC key which will delete the 1st AC key
        for(auto p: m){
                cout << p.first << " " << p.second <<endl;
        }
}
*/



        // Erasing all the similar keys with specific value
/* 
#include<iostream>
#include<map>
using namespace std;
int main()
{
        multimap<string, int> m;
        m.emplace("remote",1000);
        m.insert({"AC",5});
        m.insert({"AC",5});
        m.insert({"tv",80});
        m.emplace("tv",100);
        m.emplace("tv",80);


        auto rangeAC = m.equal_range("AC");              // Get all elements with key "AC"

        for (auto it = rangeAC.first; it != rangeAC.second; ++it) {
                if (it->second == 5) {
                        m.erase(it);
                        break;                  // Only erase the first 1st matching
                } 
        }


    // If you want to erase all entries with "TV" and value 80, use:
        auto rangeTV = m.equal_range("tv");                                     // Get range of all elements with key "tv"

        for (auto it = rangeTV.first; it != rangeTV.second; ) {
                if (it->second == 80){                                          // it->second throws the value of "tv" key and check whether it's 80 or not               
                        it = m.erase(it); // returns next valid iterator
                }
                else{
                        ++it;
                }
        }
// (it->second) throws the 2nd element of pair('it') using iterator,   it's iterator not value so can't use DOT(.) have to use arrow (->) 

// Printing the map entities
        for(auto p: m){
                cout << p.first << " " << p.second <<endl;                     // p is not an iterator so using DOT(.)
        }

}
 */





                                //4B. UnOrdered MAP :- Unlike MAP it throws output in random order not in ASC order of Keys      (Use mostly in DSA)
/*
#include<iostream>
#include<unordered_map>       //can't take duplicate Keys
using namespace std;

int main(){
        unordered_map<string, int> m;

        m["tv"] = 100;
        m["tv"] = 100;
        m["tv"] = 100;
        m["tv"] = 100;
        m["laptop"] = 100;
        m["headphones"] = 50;
        m["tablet"] = 120;
        m["watch"] = 50;

        for(auto p: m){
                cout << p.first << " " << p.second <<endl;
        }
}
*/




                                //5. SET
//      * It also works as Tree internally similar to MAP
//      * Insert, Emplace, Count, Erase    :- O(log n) complexity
//      * Find, Size, Empty, Erase
/*
#include<iostream>
#include<set>
using namespace std;

int main(){
        set<int> s;

        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(5);
        s.insert(4);
        s.insert(8);

          s.insert(1);              //Don't take duplicate values  
          s.insert(2);
          s.insert(3);

        cout<<s.size()<<endl;

        for(int val : s){            //here instead of "int" we can also put "auto"
                cout<<val<<" ";
        }
        cout<<endl;

//Lower Bound
        cout<< "lower bound for 4 = "<< *(s.lower_bound(4)) <<endl;        //returns same number as given as input if that number exist in SET
        cout<< "lower bound for 6 = "<< *(s.lower_bound(6)) <<endl;        // Or will returns slight greater number available in the SET if inputted number is not there in the SET
        cout<< "lower bound for 7 = "<< *(s.lower_bound(7)) <<endl;
        cout<< "lower bound for 9 = "<< *(s.lower_bound(9)) <<endl;        // If no value in the SET is either equal to or greater than given Input then it will return   "s.end();"
cout<<endl;
//Upper Bound
        cout<< "upper bound for 4 = "<< *(s.upper_bound(4)) <<endl;        //Will always return a greater value to our input (not same not small always greater)
        cout<< "upper bound for 6 = "<< *(s.upper_bound(6)) <<endl;
        cout<< "upper bound for 8 = "<< *(s.upper_bound(8)) <<endl;        //if greater value doesn't exist it will return  "s.end();"
        cout<< "upper bound for 9 = "<< *(s.upper_bound(9)) <<endl;
        cout<< "upper bound for 0 = "<< *(s.upper_bound(0)) <<endl;        //Even if the input value is not in the SET it will return a value greater than this
}
*/



                                //5B. Multi SET
/*                                
#include<iostream>
#include<set>
using namespace std;

int main(){
        multiset<int> s;

        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(5);
        s.insert(4);
        s.insert(8);

          s.insert(1);       // Will take duplicates also
          s.insert(2);
          s.insert(3);

        for(auto val : s){            
                cout<<val<<" ";
        }
}
*/



                                //5C. Unordered SET :- As it's not sorted so LOWER_Bound & UPPPER_Bound doesn't exist here
/*                             
#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
        unordered_set<int> s;

        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(5);
        s.insert(4);
        s.insert(8);

          s.insert(1);       // Won't take duplicates also
          s.insert(2);
          s.insert(3);

        for(auto val : s){              //will return in random order 
                cout<<val<<" ";
        }
}
*/






                                                        // Algorithms
                                
                                //   1. SORTING :- by default it sorts in ascending order
//Array
/*
#include<iostream>
using namespace std;

int main(){
        int arr[8] = {3,2,5,8,0,9,1,1};
        for(auto val: arr){
                cout<<val<<" ";
        }
        cout<<endl;        

        sort(arr, arr+4);              //will sort these indices :- 0,1,2,3
        for(auto val: arr){
                cout<<val<<" ";
        }
        cout<<endl;

        sort(arr, arr+8);               //need to pass iterator(pointer) only, here arr is pointer of 1st element  
        for(auto val: arr){
                cout<<val<<" ";
        }
        cout<<endl;
}
*/


// Vector
/*
#include<iostream>
using namespace std;

int main(){
        vector<int> vec = {3,5,1,8,2};

        sort(vec.begin(), vec.end());

        for(auto val:vec){
                cout<<val<<" ";
        }
        cout<<endl;
}
*/


                                                                //SORTING

//      * Sorting function is based on intro sort :- combination of 3 sorting techniques (Quick Sort, Heap Sort, Insertion Sort)
//      * Comparator is a function that tells the logic of comparision  
//      * In Descending Order, we pass a comparator or functor
//      * need to pass iterator(pointer) only
/*
#include<iostream>
using namespace std;

int main(){
        vector<int> vec = {3,5,1,8,2};

        sort(vec.begin(), vec.end(), greater<int>());          //this comparator tells which number is greater and data will be sorted accordingly

        for(auto val:vec){
                cout<<val<<" ";
        }
        cout<<endl;
}
*/

//Pairs
/*
#include<iostream>
using namespace std;

int main(){
        vector<pair<int, int>> vec = {{3,5},{1,8},{2,0},{5,3}};

        sort(vec.begin(), vec.end());       //will sort pairs accoring to 1st value, won't sort the element within the pair

        for(auto val:vec){
                cout<<val.first<<" "<<val.second<<endl; 
        }
}
*/




                                        //Custom Comparators :- Boolean values Returns True/False on basic of certain comparisions
//Pairs :- To sort accoring to 2nd values we will need to define custom comparators 
/*
#include<iostream>
#include<vector>
using namespace std;

//Create a comparator of any name and pass DATA Type need to be compared as argument,  HERE 2 pairs need to be compared so we passed 2 pairs data types as argument
bool comp(pair<int,int> p1, pair<int,int> p2){                  

        if(p1.second < p2.second) return true;
        else return false;
}

int main(){
        vector<pair<int,int>> v = {{3,5},{1,8},{2,0},{5,3}};

        sort(v.begin(), v.end(), comp);

        for(auto val:v){
                cout<<val.first<<" "<<val.second<<endl; 
        }

}
*/


// Logic to sort the pair accoring to 2nd element of pair but if 2nd element is same thn sort according to 1st pair
/*
#include<iostream>
#include<vector>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){                  

        // if(p1.second < p2.second){
        //         return true;
        // }
        // else if(p1.second = p2.second){
        //         if(p1.first < p2.first) return true;
        //         else return false;                
        // }
        // else return false;

//In shorter way :-
        if(p1.second < p2.second) return true;     //these two conditions will be checked 1st
        if(p1.second > p2.second) return false;

        if(p1.first < p2.first) return true;       //if it does fall under any of two above conditions this condition will be check so for  "p1.second = p2.second" this condition will be checked
        else return false;
}

int main(){
        vector<pair<int,int>> v = {{3,5},{1,8},{2,0},{5,3},{4,3},{4,2},{7,8}};

        sort(v.begin(), v.end(), comp);

        for(auto val:v){
                cout<<val.first<<" "<<val.second<<endl; 
        }

}
*/



                                        // 2. REVERSE & ROTATE
/*
#include<iostream>
using namespace std;

int main(){
        vector<int> vec = {3,5,1,8,2,4,5,7,0};
        for(auto val:vec){
                cout<<val<<" ";
        }
        cout<<endl;


        reverse(vec.begin()+1, vec.begin()+4);
        for(auto val:vec){
                cout<<val<<" ";
        }
        cout<<endl;


        reverse(vec.begin(), vec.end());
        for(auto val:vec){
                cout<<val<<" ";
        }
        cout<<endl;

        rotate(vec.begin(), vec.begin()+3, vec.end());      //will place starting 3 elements at last,   if we do as "vec.begin()+4" then starting 4 elements will be placed at end 
        cout<<"after rotate: ";
        for(auto val:vec){
                cout<<val<<" ";
        }


        rotate(vec.begin(), vec.begin()+3, vec.end()-2);      //will place starting 3 elements before the 2nd last element{vec.end()-2}
        cout<<"after rotate: ";
        for(auto val:vec){
                cout<<val<<" ";
        }
}
*/



                                        // 3. Next/Prev Permutation
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

//count total permutation & print them all 
    sort(s.begin(), s.end());                   // Start with the first lexicographic permutation  {resets s back to "abc"}
    int count = 0;

    do {
        cout << s << endl;
        count++;
    } while (next_permutation(s.begin(), s.end()) && s != "abc");

    cout << "Total permutations: " << count << endl;
}
*/




                                // Max Element & Min Element
/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
        vector<int> vec = {1,2,3,4,5,6};
        cout << *(max_element(vec.begin(), vec.end()))<<endl;
        cout << *(min_element(vec.begin(), vec.end()))<<endl;

        return 0;
}
*/




                                        // Binary Search
/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
        vector<int> vec = {1,2,3,4,5,6};
        cout << binary_search(vec.begin(), vec.end(), 4)<<endl;         //Returns 1 if found (true)
        cout << binary_search(vec.begin(), vec.end(), 10)<<endl;         //Returns 0 if not found (false)

        return 0;
}
*/





                                                        //Upper_Bound & Lower Bound

//The upper bound function returns an iterator that points to the first value that is greater than a specified value. 
//The lower bound function returns an iterator that points to the first value that is equal to or greater than a specified value. 

//lower_bound(v.begin(), v.end(), 4) returns an iterator pointing to the first element in the range [v.begin(), v.end()) that is not less than 4(can be equal).
//Subtracting v.begin() from this iterator gives the index of the first element that satisfies the condition.

//upper_bound(v.begin(), v.end(), 4) returns an iterator pointing to the first element in the range [v.begin(), v.end()) that is greater than 4.
//Again, subtracting v.begin() provides the index.

/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
        vector<int> v = {1,2,3,4,5,6};                                                  //it returns output according to sorted data
        cout<<"Lower Bound: "<<lower_bound(v.begin(),v.end(),4)-v.begin()<<endl;      
        cout<<"Upper Bound: "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;       
        return 0;
}
*/





                                                                // Count SET Bits
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
        int n = 15;
        cout<< __builtin_popcount(n) << endl;

        long int n2 = 15;
        cout<< __builtin_popcountl(n2) << endl;

        long long int n3 = 15;
        cout<< __builtin_popcountll(n3) << endl;

        return 0;
}
*/





                                // SWAP, MIN, MAX
/*                                
#include<iostream>
#include<string>
using namespace std;
int main()
{
        cout<<min(4,5)<<" "<<max(2,10)<<endl;
        int a=10;
        int b=20;
        swap(a,b);
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        return 0;
}
*/




