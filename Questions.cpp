                                    // Merge Sort


                    // Algo Monster - 759    Employee free time

// 1st Approach :             
/*
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


vector<vector<int>> employeeFreeTime(vector<vector<int>> &task){
    
    vector<vector<int>> ans;
    vector<vector<int>> temp;

// Put all intervals into one vector
    for (auto employee : task) {
        for (auto interval : employee) {
            temp.push_back(interval);
        }
    }


// Sort according to start time
    sort(temp.begin(), temp.end(), [](vector<int>& a, vector<int>& b) {
             return a[0] < b[0];
        });


    //  int start = temp[0][0];                 No use of this
        int end = temp[0][1];                // Just keep track of end pointer


    for (int i = 1; i < temp.size(); i++) {

    // There is a free time
        if (temp[i][0] > end) {                       // new task getting start after 1 task is finished(end)
            ans.push_back({end, temp[i][0]});         // free time slot : from "end" of last task to "start" of new task
        }

    // Extend working time
        end = max(end, temp[i][1]);                   // update end

    }

    return ans;
}
*/
// TIME : O(N log N) 
// SPACE : O(N) 


// 2nd Approach :   Using MIN HEAP  --->   Check Gpt






                                                // GFG -  Maximum CPU Load
//  MIN HEAP Approach                                                
/*
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int cpuLoad(vector<vector<int>>& task) {

    int maxL = 0;
    int load = 0;

    // {endTime, cpuLoad}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Sort according to start time
    sort(task.begin(), task.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0];
         });

    for (int i = 0; i < task.size(); i++) {

        // Remove all tasks that have finished
        while (!pq.empty() && pq.top().first <= task[i][0]) {

            load -= pq.top().second;
            pq.pop();
        }

        // Add current task's CPU load
        load += task[i][2];

        // Store {end time, CPU load}
        pq.push({task[i][1], task[i][2]});

        // Update maximum
        maxL = max(maxL, load);
    }

    return maxL;
}
*/

// T - O(N log N)
// S - O(N)



// Approach 2: Sweep Line       {EASY}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cpuLoad(vector<vector<int>>& task) {

    vector<pair<int, int>> events;

    // Create start and end events
    for (auto t : task) {

        int start = t[0];
        int end = t[1];
        int load = t[2];

        events.push_back({start, load});  // add load
        events.push_back({end, -load});    // remove load
    }

    // Sort by time
    sort(events.begin(), events.end());

    int load = 0;
    int maxLoad = 0;

    // Process events
    for (auto event : events) {

        load += event.second;

        maxLoad = max(maxLoad, load);
    }

    return maxLoad;
}
*/

// Time: O(N log N)
// Space: O(N)