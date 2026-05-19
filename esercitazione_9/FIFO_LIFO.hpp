#pragma once

#include <queue>
#include <stack>

/* Implementazione contenitore con politica FIFO */
template <typename T = int>
class fifo 
{
private:
    std::queue<T> queue;
	
public:
	/* costruttore di default */
	fifo() {};

	/* put() */
	void put(const T& elem) {
		queue.push(elem);
	}
	
	/* get() */
	T get() {
		T elem = queue.front();
		queue.pop();
		return elem;
	}
	
	/* empty() */
	bool empty() const {
		return queue.empty();
	}
};
	
/* Implementazione contenitore con politica LIFO */
template <typename T = int>
class lifo 
{
private:
    std::stack<T> stack;
	
public:
	/* costruttore di default */
	lifo() {};

	/* put() */
	void put(const T& elem) {
		stack.push(elem);
	}
	
	/* get() */
	T get() {
		T elem = stack.top();
		stack.pop();
		return elem;
	}
	
	/* empty() */
	bool empty() const {
		return stack.empty();
	}
};

