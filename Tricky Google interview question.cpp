/*
A friend of mine is interviewing for a job. One of the interview questions got me thinking, just wanted some feedback.
There are 2 non-negative integers: i and j. Given the following equation, find an (optimal) solution to iterate over i and j in such a way that the output is sorted.
2^i * 5^j
So the first few rounds would look like this:
2^0 * 5^0 = 1
2^1 * 5^0 = 2
2^2 * 5^0 = 4
2^0 * 5^1 = 5
2^3 * 5^0 = 8
2^1 * 5^1 = 10
2^4 * 5^0 = 16
2^2 * 5^1 = 20
2^0 * 5^2 = 25
Try as I might, I can't see a pattern. Your thoughts?


来自 <http://stackoverflow.com/questions/5505894/tricky-google-interview-question> 
*/

#include <iostream>
#include <queue>

using namespace std;

queue<int> que1, que2;

int main()
{
    que1.push(1);
    que2.push(1);  

    int last = 1;
    int current = 1;
    cout << 1<<endl;
    for( int i = 0 ;i < 200 ;)
    {
        if(que1.front() * 2  <  que2.front() * 5) 
        {
		current = que1.front() * 2;		
		  if(current  == last )
		{
		     que1.pop();
		     continue;
		}
		cout << current<<endl;		
		que1.pop();
	}
        else 
	{
		current = que2.front() * 5;
		  if(current == last )
		{
		     que2.pop();
		     continue;
		}
		cout << current<<endl;		
		que2.pop();		
	}
	i++;
	que1.push(current);
	que2.push(current);
	last  = current;
    } 
}
