#include <iostream>

template<typename T>
void Stack<T>::push(T data) {
    arr[++_top] = data;
}

template<typename T>
T Stack<T>::pop() {
    return arr[_top--];
}

template<typename T>
T Stack<T>::top() {
    return arr[_top];
}

template<typename T>
bool Stack<T>::isEmpty() {
    return _top < 0;
}

template<typename T>
T Stack<T>::prec(char c) {
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else
        return -1; 
}

template<typename T>
bool Stack<T>::isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

template<typename T>
std::string Stack<T>::infixToPostfix(std::string exp) {
    Stack<char> st;
    std::string post;

    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] >= 48 && exp[i] <= 57) 
            post += exp[i];
        else if(exp[i] == '(')
            st.push(exp[i]);
        else if(exp[i] == ')') {
            while((st.top() != '(') && (!st.isEmpty())) {
                char temp = st.top();
                post += temp;
                st.pop();
            }

            if(st.top() == '(')
                st.pop();
        } else if(isOperator(exp[i])) {
            if(st.isEmpty())
                st.push(exp[i]);
            else {
                if(prec(exp[i]) > prec(st.top()))
                    st.push(exp[i]);
                else if(prec(exp[i]) == prec(st.top()) && exp[i] == '^')
                    st.push(exp[i]);
            }
        } else {
            while(!st.isEmpty() && prec(exp[i]) <= prec(st.top())) {
                post += st.top();
                st.pop();
            }
        }
    }

    while(!st.isEmpty()) {
        post += st.top();
        st.pop();
    }

    return post;
}

template<typename T>
T Stack<T>::evaluatePostfix(std::string exp) {
    Stack<char> st;
    int i, n, a, b, c;

    for (i = 0; exp[i] != exp.length(); i++) {
        if (isdigit(exp[i])) {
            st.push(exp[i]);
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            a = st.pop();
            b = st.pop();

            switch (exp[i]) {
                case '*':
                    c = b * a;
                    st.push(c);
                    break;
                case '/':
                    c = b / a;
                    st.push(c);
                    break;
                case '+':
                    c = b + a;
                    st.push(c);
                    break;
                case '-':
                    c = b - a;
                    st.push(c);
                    break;
            }
        }
    }

    return st.pop();
}