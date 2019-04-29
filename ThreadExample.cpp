#include <iostream>
#include <thread>


using std::cin;
using std::cout;
using std::endl;
using std::thread;
using namespace std;

const int number_of_threads = 20;

void thread_call(int thread_number) {

	cout << "Run by thread: " << thread_number << endl;
}

int main() {

	thread thread1[number_of_threads];

	for (int i = 0; i < number_of_threads; ++i)
	{
		thread1[i] = thread(thread_call, i);
	}

	cout << "Run by main thread\n";

	for (int i = 0; i < number_of_threads; ++i)
	{
		thread1[i].join();
	}

	return 0;
}