/*

https://leetcode.com/problems/reveal-cards-in-increasing-order/

*/

#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.begin(), deck.end());
        vector<int> sol(deck.size());
        queue<int> q;
        
        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }

        for(int i = 0; i < deck.size(); i++) {
            int index = q.front();
            q.pop();
            q.push(q.front());
            q.pop();

            sol[index] = deck[i];
        }

        return sol;
    }
};

int main() {
    return 0;
}