#include <iostream>
#include <queue>
using namespace std;
void interleaveQueue(queue<int> &q)
{
    if (q.size() % 2 != 0)
    {
        cout <<"Cannot interleave.\n";
        return;
    }
    int halfSize = q.size() / 2;
    queue<int> Half;
    for (int i = 0;i<halfSize; i++)
    {
        Half.push(q.front());
        q.pop();
    }
    while (!Half.empty())
    {
        q.push(Half.front());
        Half.pop();
      
        q.push(q.front());
        q.pop();
    }
}
void display(queue<int> q)
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
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    cout <<"Original Queue: ";
    display(q);
    interleaveQueue(q);
    cout << "Interleaved Queue: ";
    display(q);
    return 0;
}
