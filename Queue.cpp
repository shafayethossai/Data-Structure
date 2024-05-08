#include <iostream>
using namespace std;

#define MAX_SIZE 20

int arr[MAX_SIZE];
int front = -1;
int back = -1;

void push(int x) {
    if (back == MAX_SIZE - 1) {
        cout << "Queue overflow" << endl;
        return;
    }
    back++;
    arr[back] = x;

    if (front == -1) {
        front++;
    }
}

void pop() {
    if (front == -1 || front > back) {
        cout << "No elements in queue" << endl;
        return;
    }
    front++;
}

int peek() {
    if (front == -1 || front > back) {
        cout << "No elements in queue" << endl;
        return -1;
    }
    return arr[front];
}

bool empty() {
    if (front == -1 || front > back) {
        return true;
    }
    return false;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);

    cout << peek() << endl;
    pop();

    cout << peek() << endl;
    pop();

    cout << peek() << endl;
    pop();

    cout << peek() << endl;
    pop();

    cout << empty() << endl;

    return 0;
}

