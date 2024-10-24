#include <iostream>
#include <stack>
using namespace std;

void displayNGE(int arr[], int a)
{
    stack<int> s;

    int nge[a]; 
    
    for (int i = a - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int j = 0; j < a; j++)
    {
        cout << arr[j] << " --> " << nge[j] << endl;
    }
}

int main()
{
    int arr[] = {4, 5, 2, 25};
    int a = sizeof(arr) / sizeof(arr[0]);

    displayNGE(arr, a);

    return 0;
}
