#include <iostream>
using namespace std;

int s[10000]; //문제 조건에서 n<=10,000
int tp=-1;

bool isFull() {
    if(tp>=10000)
        return true;
    else
        return false;
}

int isEmpty() {
    if(tp==-1)
        return 1;
    else
        return 0;
}

void push() {
    int i;
    cin >> i;
    if(!isFull())
        s[++tp] = i;
    //cout << s[tp] << endl;
}

int pop() {
    if(!isEmpty()) {
        return s[tp--];
    }
    else
        return -1;
}

int size() {
    return tp+1;
}

int top() {
    if(tp != -1)
        return s[tp];
    else
        return -1;
}



int main() {
    int n;
    string cmd;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        if(cmd == "push")
            push();
        else if(cmd =="pop")
            cout << pop() << endl;
        else if(cmd == "size")
            cout << size() << endl;
        else if(cmd == "empty")
            cout << isEmpty() << endl;
        else if(cmd == "top")
            cout << top() << endl;
    }
}