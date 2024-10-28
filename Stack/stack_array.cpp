#include <bits/stdc++.h>
using namespace std;

class Stack {
    int size;
    int *arr;
    int top;
    public:
        Stack() {
            top = -1;
            size = 1000;
            arr = new int[size];
        }
    
    void push(int x) {
        top++;
        arr[top] = x;
    }

    int pop() {
        int x = arr[top];
        top--;
        return x;
    }

    int Top() {
        return arr[top];
    }

    int Size() {
        return top + 1;
    }
};

int main() {
    Stack st;
    st.push(2);
    st.push(3);
    st.push(5);
    cout<<"Top of the stack: "<<st.Top()<<endl;
    cout<<"Size of the stack: "<<st.Size()<<endl;
    cout<<"Deleted element: "<<st.pop()<<endl;
    cout<<"Top after deleting an element: "<<st.Top()<<endl;
    cout<<"Size of the stack: "<<st.Size()<<endl; 
    return 0;
}