#include <iostream>
#include <thread>


using std::cin;
using std::cout;
using std::endl;
using std::thread;
using namespace std;

const int number_of_threads = 4;

void functionPointer(int thread_number)
{
	for (int i = 0; i < thread_number; ++i)
	{
		cout << "Function Pointer Thread \n";
	}
}

class functionObject {
public:
	void operator()(int thread_number)
	{
		for (int i = 0; i < thread_number; ++i)
		{
			cout << "Function Object Thread \n";
		}
	}
};

int main()
{
	auto lambdaExp = [](int thread_number)
	{
		for (int i = 0; i < thread_number; ++i)
		{
			cout << "Lambda Expression Thread \n";
		}
	};

	thread thread1(functionPointer, number_of_threads);

	thread thread2(functionObject(), number_of_threads);

	thread thread3(lambdaExp, number_of_threads);

	thread1.join();

	thread2.join();

	thread3.join();

	return 0;
}