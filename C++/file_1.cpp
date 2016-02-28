#include <iostream>
#include <assert.h>
#define Length 7
//using namespace std;

class Stack 
{
	public:
		int size_;
		int array_[Length];
		
		Stack();
		~Stack();
		Stack_Ok();
		int Push(int a);
		int Pop();
};

Stack::Stack() : 
	array_ {0},
	size_(0)
{}

Stack::~Stack()
{}

Stack::Stack_Ok()
{
	if ((size_ <= Length) && (size_ >= 0)) return 1;
	return 0;
}

int Stack::Push(int a)
{
	assert(Stack_Ok());
	array_[size_] = a;
	size_ ++;
	return a;
}

int Stack::Pop()
{
	assert(Stack_Ok());
	size_--;
	return array_[size_];
}

int main()
{
	int num;
	std::cout << "Hello!\n" ;
	std::cin >> num;
	Stack st;
	st.Push(num);
	std::cout << st.Pop();
	return 0;
}
