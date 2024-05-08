#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5

int top = -1;
int arr[MAX_SIZE];

void push(int val) {
    if (top == MAX_SIZE-1) {
        cout << "stack overflow" << endl;
    }
    else {
        top++;
        arr[top] = val;
    }
}

int pop() {
    if (top == -1) {
        cout << "stack underflow" << endl;
        return 0;
    }
    else {
        int popValue = arr[top];
        arr[top] = 0;
        top--;
        return popValue;
    }
}

int peek(int pos) {
    if (top == -1) {
        cout << "stack underflow" << endl;
        return 0;
    }
    else {
        return arr[pos];
    }
}

void display() {
    cout << "All values in the Stack are " << endl;

    for (int i = top; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  display();

  pop();
  display();

  cout << "value at "<< 2 << " position is : " << peek(2) << endl<<endl;

  return 0;
}

