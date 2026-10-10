                                // BASIC OPERATIONS

                        // Traverse LinkedList & Length of LL
/*
#include <vector>
#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* next;

    public:
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }


    public:
    static Node* getHead(vector<int> &arr){     // This function will create links between elements of vector & return HEAD of LL      
        Node* head = new Node(arr[0]);          // HEAD node will point 1st element
        Node* iterator = head;                  // iterator (initially at HEAD)

        for(int i=1; i<arr.size(); i++){        // start from 1st element as 0th already stored in head
            Node* temp = new Node(arr[i]);
            iterator->next = temp;              // store address of 1st element in iterator(0th element)
            iterator = temp;                    // iterate to next element 
        
            // iterator = iterator->next            // merged above 2 lines into single
        }

        return head;
    }

    // Function to print whole LL (Traversal) & (Length)
    public:
    static void traverse(Node* head){
        Node* temp = head;                      // never tamper head so store it in Temp  
        int cnt = 0;                    
        while(temp){                            // until temp != null
            cnt++;
            cout<<temp->data<<" ";              // print data of temp node (element data)
            temp = temp->next;                  // move temp to next node (every next node address is stored in "next" of temp)
        }
        cout<<"\n"<<cnt;
    }
};

int main(){
    vector<int> arr = {12,5,8,0};
    Node* head = Node :: getHead(arr);
    Node :: traverse(head);

}
*/

// Here we didn't create any object of Node class in main function,
// So Need to add static key word & use scope resolution operator "::" to call methods like getHead & traverse
// :: means "call getHead function from the Node class", and we have to mention getHead function as static then only we can call it without creating object of Node class



                                    // SEARCH ELEMENT
/*                                    
#include<vector>
#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }


    static Node* getHead(vector<int> &arr){
        Node* head = new Node(arr[0]);

        Node* iterator = head;

        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            iterator->next = temp;
            iterator = temp;
        }
        return head;
    }


    static bool searchEle(Node* head, int ele){
        Node* temp = head;
        while(temp){
            if(temp->data == ele){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main(){
    vector<int> arr = {12,5,0,9};
    int ele;
    cin>>ele;

    Node* head = Node::getHead(arr);
    cout << Node::searchEle(head, ele);         // True - 1         False - 0
}
*/


                                // DELETION : HEAD
/*
#include<vector>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    static Node* getHead(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* iter = head;

        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            iter->next = temp;
            iter = temp;
        }
        return head;
    }

    static Node* removeHead(Node* head){            // Return new head after deleting old one
                                
        if(head == NULL) return head;               // 0 element in linked list
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
                                                    // code aligning below this column are just for showcase (to make output look clean & clear)
    static void traverse(Node* head){
        Node* temp = head;
        int cnt = 0;
                                                    cout<<"      LL : ";
        while(temp){
            cnt++;
            cout << temp->data <<" ";
            temp = temp->next;
        }
                                                    cout<<"      Length = "<<cnt<<"\n\n\n";
    }
};

int main(){
    vector<int> arr = {12,3,4,7,9,0,1};
    Node* head = Node::getHead(arr);

                                                    cout<<"\nBefore deletion: \n";
                                                    cout<<"HEAD = ";
    cout<<head->data;
    Node::traverse(head);

    head = Node::removeHead(head);
                                                    cout<<"After deletion: \n";
                                                    cout<<"NEW HEAD = ";
    cout<<head->data;
    Node::traverse(head);
}
*/


// Function : 
    /* static Node* removeHead(Node* head){         // Return new head after deleting old one

        if(head == NULL) return head;               // 0 element in linked list
        Node* temp = head;
        head = head->next;
        delete temp;                                // in C++, we need to free-up the space manually but in JAVA there's a garbage collector so no need of this line in JAVA
        return head;

    } */

// Call : 
    /* int main(){
        vector<int> arr = {12,3,4,7,9,0,1};
        Node* head = Node::getHead(arr);
        head = Node::removeHead(head);
    } */

//  IMP :  getHead Fn will be written in all codes & will be called first then head obtained from that Fn will be passed to any other Fn (removeHead in this case)
//  IMP : getHead will create link between element (convert array into LL) & return a Head so this function will be called first then only will do rest any operations





                                // DELETION : TAIL
// Function : 

    /*  static Node* removeTail(Node* head){                // Head will be passsed into every function

        if(head == NULL || head->next == NULL){             // if LL have 0 or just 1 element,  if just 1 element is there Tail = Head so deleting tail means 0 element so return null
            return NULL;
        }

        Node* temp = head;                                  // At 1st iter:   temp = 12, temp->next = 3  & temp->next->next = 4

        while(temp->next->next != nullptr){                 // 12 -> 3 -> 4 -> 0 -> 1  : while loop will run upto temp = 4 so after final iter   temp = 4,  temp->next = 0   &   temp->next->next = 1
            temp = temp->next;                              // temp = temp->next       : so upgrade temp from 4 to 0
        }

        delete temp->next;                                  // temp = 0  temp->next = 1,   1(Tail) will get deleted
        temp->next = nullptr;                               // temp->next will now point to null, initially it was pointing to 1 (tail)

        return head;                                        // finally head = 12   temp = 0    temp->next = null   TAIL upgraded from 1 to 0
    } */


// Call : 

    /* int main(){

        vector<int> arr = {12,3,4,7,9,0,1};
        Node* head = Node::getHead(arr);
        head = Node::removeTail(head);

    } */

//  IMP : getHead Fn will be written in all codes & will be called first then head obtained from that Fn will be passed to any other Fn (removeTail in this case)
//  IMP : getHead will create link between element (convert array into LL) & return a Head so this function will be called first then only will do rest any operations




                                // DELETION : Kth Element
/*                                
#include<vector>                                
#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    static Node* getHead(vector<int> arr){
        Node* head = new Node(arr[0]);
        Node* iter = head;

        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            iter->next = temp;
            iter = temp;
        }
        return head;
    }

    static void traverse(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

// Main Deletion Function : 
    static Node* del(Node* head, int k){

        if(head == NULL) return head;

        if(k==1){                                   // this will also handle if there's just 1 element in LL
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        Node* temp = head;
        Node* prev;
        int cnt = 0;

        while(temp){
            cnt++;
            if(cnt == k){
                prev->next = prev->next->next;
                delete temp;
                break;
                //return head;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;

    }
};

int main(){
    vector<int> vec = {12,3,4,6,8,9,0,11};

    int k;
    cin>>k;

    Node* head = Node::getHead(vec);
    Node::traverse(head);

    cout<<"\n";

    head = Node::del(head,k);
    Node::traverse(head);
}
*/


// Main Deletion Function : 
    /* static Node* del(Node* head, int k){

        if(head == NULL) return head;

        if(k==1){                                   // this will also handle if there's just 1 element in LL
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        Node* temp = head;
        Node* prev;
        int cnt = 0;

        while(temp){
            cnt++;
            if(cnt == k){
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;

    } */





                                // DELETION : Particular VALUE 

// Main Fn : (same like above one with minimal changes)

    /* static Node* delEle(Node* head, int ele){

        if(head == NULL) return head;

        if(head->data == ele){
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            if(temp->data == ele){
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next
        }
        return head;

    } */  







                                                // Insertion : Head
/*                                                
#include<vector>                                                
#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    static Node* getHead(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* iter = head;

        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            iter->next = temp;
            iter = temp;
        }
        return head;
    }

    static void traverse(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    static Node* insertHead(Node* head, int val){
        return new Node(val, head);                                 // return a new node with "data" = val and "next" pointing to head of linked list so it will attached to head of LL forming a new HEAD
    }
};

int main(){
    vector<int> vec = {12,3,6,4,0};
    Node* head = Node::getHead(vec);
    Node::traverse(head);

    cout<<"\n";

    head = Node::insertHead(head,100);
    Node::traverse(head);
}
*/


// Main Fn:

    /* static Node* insertHead(Node* head, int val){
        return new Node(val, head);                                
    } */


    


                                            // INSERT : TAIL

// MAIN Fn :
    /* static Node* insertTail(Node* head, int val){

        if(head == NULL){
            return new Node(val);                       // if LL is empty then insert a newly created node with data = val  & next = null
        }

        Node* temp = head;

        while(temp->next != NULL){                      // stop at last element
            temp = temp->next;
        }

        Node* newNode = new Node(val);                  // Create a new node with data = val & next = null
        temp->next = newNode;                           // last element will point to newly created node  
        return head;
    } */




                                        // INSERT : Kth Position
//  Main Fn :

    /* static Node* insertPos(Node* head, int ele, int k){

        if(head == NULL) return new Node(ele);                  // Inserting in empty LL 

        if(k == 1) return new Node(ele, head);                  // same as inserting at HEAD

        int cnt = 0;
        Node* prev = NULL;
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt == k){
                Node* x = new Node(ele, temp);
                prev->next = x;
                break;                                          // Exits the loop 
            }
            prev = temp;
            temp = temp->next;
        } 
        return head;
    } */


    
//  Main Fn :   2nd method (without using prev)

    /* static Node* insertPos(Node* head, int ele, int k){

        if(head == NULL) return new Node(ele);                  // Inserting in empty LL 

        if(k == 1) return new Node(ele, head);                  // same as inserting at HEAD

        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt == k-1){
                Node* x = new Node(ele, temp->next);            // create a new node pointing to next node of temp
                temp->next = x;                                 // now temp will point to X  so series will change from "temp -> (next of temp)"  to   "temp -> X -> (next of temp)"
                break;                                          // Exits the loop 
            }
            temp = temp->next;
        } 
        return head;
    } */




                                    // INSERT : Before Any Value
//  Main Fn:

    /* static Node* insertBeforeVal(Node* head, int ele, int val){

        if(head == NULL) return NULL;                                   // in Empty LL we won't find the val before which we have to enter the new element so return NULL 

        if(head->data == val) return new Node(ele, head);               // Data at HEAD is equal to Val so add new node before head so it will act as new HEAD

        Node* prev = NULL;
        Node* temp = head;

        while(temp != NULL){                                     
            
            if(temp->data == val){
                Node* x = new Node(ele, temp);
                prev->next = x;
                break;                                                  // Exits the loop 
            }
            prev = temp;
            temp = temp->next;
        } 
        return head;
    } */



