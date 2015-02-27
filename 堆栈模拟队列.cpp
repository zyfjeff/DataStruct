/*
 =====================================================================================
        Filename:  堆栈模拟队列.cpp
     	Description:  使用两个堆栈模拟队列
        Version:  1.0
        Created:  27/02/15 16:32:18
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

template<typename T>
class MyQueue
{
public:
//构造和析构
	MyQueue();
	~MyQueue();
	void enqueue(T data); //入队
	T dequeue(); //出队
	bool IsEmpty();
	void Move();//stackA-->stackB
private:
stack<T> stackA;
stack<T> stackB;
};

template<typename T>
MyQueue<T>::MyQueue()
{
	
}

template<typename T>
MyQueue<T>::~MyQueue()
{

}
/*
template<typename T>
void MyQueue<T>::Move()
{
	while(!stackA.empty())
	{
		stackB.push(stackA.top());
		stackA.pop();
	}
}
*/

template<typename T>
void MyQueue<T>::enqueue(T data)
{
	stackA.push(data);
}

template<typename T>
T MyQueue<T>::dequeue()
{
	if (!stackB.empty()) {
		T data = stackB.top();
		stackB.pop();
		return data;
	} else {
		Move();
		assert(!stackB.empty());
		dequeue();
	}
}

template<typename T>
bool MyQueue<T>::IsEmpty()
{
	if (stackA.empty() && stackB.empty())
		return true;
	else 
		return false;
}

template<typename T>
void MyQueue<T>::Move()
{
	while(!stackA.empty())
	{
		stackB.push(stackA.top());
		stackA.pop();
	}
}

int main()
{
	MyQueue<int> queue;
	queue.enqueue(5);
	queue.enqueue(6);
	queue.enqueue(7);
	queue.enqueue(8);
	queue.enqueue(9);
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
}
