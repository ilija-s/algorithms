#include <iostream>
#include <cctype>
#include <stack>

using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int min(int a, int b){
    return (a < b) ? a : b;
}

int main(){
    stack<int> val;
    stack<char> op;
    string str;

    cin >> str;

    for (char c : str) {
        if (isdigit(c)) {
            val.push(c - '0');
        } else if (c == 'm' || c == 'M') {
            op.push(c);
        } else if (c == ')') {
            int new_val;
            if (op.top() == 'm'){
                int tmp = val.top();
                val.pop();
                new_val = min(tmp, val.top());
                val.pop();
                val.push(new_val);
                op.pop();
            } else if (op.top() == 'M') {
                int tmp = val.top();
                val.pop();
                new_val = max(tmp, val.top());
                val.pop();
                val.push(new_val);
                op.pop();
            }
        }
    }

    cout << val.top() << '\n';

    return 0;
}
