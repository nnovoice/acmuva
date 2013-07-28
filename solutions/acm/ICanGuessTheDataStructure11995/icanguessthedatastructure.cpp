/* UVa 11995 - I can guess the Data Structure */
#include <iostream>
#include <queue>
#include <stack>
#include <functional>
using namespace std;

void makeEmpty(stack<int>& lifoStack, queue<int>& fifoQueue,
               priority_queue<int, vector<int>, std::less<int> >& priorityQueue)
{
    while (lifoStack.empty() == false)
            lifoStack.pop();
    while (fifoQueue.empty() == false)
        fifoQueue.pop();
    while (priorityQueue.empty() == false)
        priorityQueue.pop();
}

int main()
{
    stack<int> lifoStack;
    queue<int> fifoQueue;
    priority_queue<int, vector<int>, std::less<int> > priorityQueue;

    int numOps = 0;
    int op = 0;
    int num = 0;
    bool isStack = false;
    bool isQueue = false;
    bool isPriorityQueue = false;
    bool isMultipleDataStructure = false;

    while (cin >> numOps) {
        isStack = true;
        isQueue = true;
        isPriorityQueue = true;

//        lifoStack = stack<int>();
//        fifoQueue = queue<int>();
//        priorityQueue = priority_queue<int, vector<int>, std::less<int> >();
        makeEmpty(lifoStack, fifoQueue, priorityQueue);

        for (int i = 0; i < numOps; ++i) {
            cin >> op >> num;
            switch (op) {
                case 1: {
                    fifoQueue.push(num);
                    lifoStack.push(num);
                    priorityQueue.push(num);
                }
                    break;
                case 2: {
                    if (fifoQueue.empty() == false && isQueue)
                        isQueue = (fifoQueue.front() == num) ? true : false;
                    if (lifoStack.empty() == false && isStack)
                        isStack = (lifoStack.top() == num) ? true : false;
                    if (priorityQueue.empty() == false && isPriorityQueue)
                        isPriorityQueue = (priorityQueue.top() == num) ? true : false;

                    /*cout << "Debug: " << "Queue front= " << fifoQueue.front() << \
                        " Stack front= " << lifoStack.top() << " PQ top= " << priorityQueue.top() << endl; */

                    if (fifoQueue.empty() == false)
                        fifoQueue.pop();
                    if (lifoStack.empty() == false)
                        lifoStack.pop();
                    if (priorityQueue.empty() == false)
                        priorityQueue.pop();

                }
                    break;
                default:
                    break;
            };
        }

        //cout << "Debug: " << "isQueue= " << isQueue << " iStack= " << isStack << " is PQ= " << isPriorityQueue << endl;
        isMultipleDataStructure = (isQueue & isStack) | (isQueue & isPriorityQueue) | (isStack & isPriorityQueue);

        if (isMultipleDataStructure)
            cout << "not sure";
        else if (isQueue == false && isStack == false && isPriorityQueue == false)
            cout << "impossible";
        else if (isQueue)
            cout << "queue";
        else if (isStack)
            cout << "stack";
        else if (isPriorityQueue)
            cout << "priority queue";
        else
            cout << "impossible";

        cout << endl;
    }
    return 0;
}
