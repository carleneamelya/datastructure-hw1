#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int element)
{
    if (stack.empty())
    {
        stack.push(element);
    }
    else
    {
        int topElement = stack.top();
        stack.pop();
        insertAtBottom(stack, element);
        stack.push(topElement);
    }
}

void reversestack(stack<int> &stack)
{
    if (!stack.empty())
    {
        int topElement = stack.top();
        stack.pop();
        reversestack(stack);
        insertAtBottom(stack, topElement);
    }
}

void displaystack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stack;

    stack.push(31);
    stack.push(30);
    stack.push(29);
    stack.push(28);

    cout << "the original stack (from top to bottom): ";
    displaystack(stack);

    reversestack(stack);

    cout << "the reversed stack (from top to bottom): ";
    displaystack(stack);

    return 0;
}