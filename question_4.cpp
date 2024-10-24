#include <iostream>
#include <queue>
using namespace std;

void interleavequeue(queue<int> &q)
{
    int n = q.size();
    int half = n / 2;

    queue<int> firstHalf;
    queue<int> secondHalf;

    for (int i = 0; i < half; i++)
    {
        firstHalf.push(q.front());
        q.pop(); 
    }

    for (int i = 0; i < half; i++)
    {
        secondHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty() || !secondHalf.empty())
    {
        if (!firstHalf.empty())
        {
            q.push(firstHalf.front()); 
            firstHalf.pop();           
        }
        if (!secondHalf.empty())
        {
            q.push(secondHalf.front());
            secondHalf.pop();           
        }
    }
}

void displayqueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " "; 
        q.pop();                  
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "the original queue: ";
    displayqueue(q);

    interleavequeue(q);

    cout << "the interleaved queue: ";
    displayqueue(q);

    return 0;
}