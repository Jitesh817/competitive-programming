/*

https://leetcode.com/problems/time-needed-to-buy-tickets/

*/
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<pair<int,int>> q;
        int timeTaken = 0;

        for(int i = 0; i < tickets.size(); i++) {
            q.push(make_pair(tickets[i], i));
        }
        
        while(true) {
            pair<int, int> p = q.front();
            q.pop();

            p.first--;
            timeTaken++;

            if(p.first == 0) {
                if(p.second == k) {
                    break;
                }
            } else {
                q.push(p);
            }
        }

        return timeTaken;
    }

    //approach 2
    int timeRequiredToBuyII(vector<int>& tickets, int k) {
        
        int ticketsRequired = tickets[k];
        int totalTime = ticketsRequired;

        for(int i = 0; i < k; i++) {
            totalTime += ticketsRequired < tickets[i] ? ticketsRequired : tickets[i];
        }
        
        ticketsRequired--;
        for(int i = k+1; i < tickets.size(); i++) {
            totalTime += ticketsRequired < tickets[i] ? ticketsRequired : tickets[i];
        }

        return totalTime;
    }
};

int main() {
    return 0;
}