/*

https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

*/
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>* q = new queue<int>();

        for(int& student: students) {
            q->push(student);
        }

        int sandwichIndex = 0;

        while(true) {
            int queueSize = q->size();
            queue<int>* queue2 = new queue<int>();
            
            while(!q->empty() && sandwichIndex < sandwiches.size()) {
                if(q->front() == sandwiches[sandwichIndex]) {
                    sandwichIndex++;
                } else {
                    queue2->push(q->front());
                }
                q->pop();
            }

            if(queue2->size() == 0) {
                return 0;
            }

            if(queueSize == queue2->size()) {
                return queue2->size();
            }

            queue<int>* temp = q;
            q = queue2;
            queue2 = temp;
        }

        return 0;
    }
};

int main() {
    return 0;
}