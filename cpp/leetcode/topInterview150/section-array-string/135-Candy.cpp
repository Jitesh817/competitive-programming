/*

https://leetcode.com/problems/candy/

*/

#include<vector>
#include<queue>

using namespace std;

struct Compare {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {

        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }

        return p1.first > p2.first;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> candies(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for(int i = 0; i < n; i++) {
            pq.push({ratings[i], i});
        }

        int totalCandies = 0;
        
        while(!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int index = p.second;

            int minLeftCandies = index > 0 ? (ratings[index] > ratings[index-1] ? candies[index-1]+1 : 1) : 1;
            int minRightCandies = index < n-1 ? (ratings[index] > ratings[index+1] ? candies[index+1]+1 : 1) : 1;

            candies[index] = minLeftCandies > minRightCandies ? minLeftCandies : minRightCandies;
            totalCandies += candies[index];
        }

        return totalCandies;
    }
};