#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <future>
#include <list>

int calc(int x)
{
	std::this_thread::sleep_for(
		std::chrono::milliseconds(rand() % 1000));

	return x * 2;
}

int main()
{
	srand(time(NULL));

	std::list<std::future<int>> pool;
	for (int i = 0; i < 10; ++i)
		pool.push_back(std::async(std::launch::async, &calc, i));

	for (auto &it : pool)
		std::cout << it.get() << std::endl;

	return 0;
}
