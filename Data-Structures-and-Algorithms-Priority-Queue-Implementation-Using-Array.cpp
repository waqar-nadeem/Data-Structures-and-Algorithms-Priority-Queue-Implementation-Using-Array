#include <iostream>
using namespace std;

#define SIZE 5

class PriorityQueue {
    int value[SIZE];
    int priority[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void insert(int val, int prio) {
        if (count == SIZE) {
            cout << "Queue Overflow\n";
            return;
        }

        int i;
        for (i = count - 1; i >= 0 && priority[i] > prio; i--) {
            value[i + 1] = value[i];
            priority[i + 1] = priority[i];
        }

        value[i + 1] = val;
        priority[i + 1] = prio;
        count++;

        cout << "Inserted: " << val << " with priority " << prio << endl;
    }

    void deleteHighestPriority() {
        if (count == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << value[0] << " with priority " << priority[0] << endl;

        for (int i = 1; i < count; i++) {
            value[i - 1] = value[i];
            priority[i - 1] = priority[i];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Priority Queue: ";
        for (int i = 0; i < count; i++) {
            cout << "[" << value[i] << ", P=" << priority[i] << "] ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30, 3);
    pq.insert(10, 1);
    pq.insert(20, 2);
    pq.display();

    pq.deleteHighestPriority();
    pq.display();

    pq.insert(40, 0);
    pq.insert(50, 2);
    pq.insert(60, 1);
    pq.display();

    return 0;
}
