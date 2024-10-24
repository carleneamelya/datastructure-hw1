#include <iostream>
#include <queue>
using namespace std;

void firstnegativeint(int arr[], int a, int k)
{
    queue<int> negatives;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push(i); 
        }
    }

    for (int i = 0; i <= a - k; i++)
    {
        if (!negatives.empty())
        {
            cout << arr[negatives.front()] << " ";
        }
        else
        {
            cout << "0 ";
        }

        if (!negatives.empty() && negatives.front() == i)
        {
            negatives.pop(); 
        }

        if (i + k < a && arr[i + k] < 0)
        {
            negatives.push(i + k); 
        }
    }
}

int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    int a = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    
    

    firstnegativeint(arr, a, k);

    return 0;
}