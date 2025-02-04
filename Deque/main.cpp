#include <iostream>
#include <deque> // 덱 사용을 위한 헤더


int main()
{
	// 덱 선언
	std::deque<int> deque;
	
	// 데이터 추가
	deque.emplace_back(100);
	deque.emplace_front(200);

	// 출력
	for (int ix = 0; ix < deque.size(); ix++)
	{
		std::cout << deque[ix] << "\n";
	}

	// 출력
	std::cout << "\n";
	for (auto it = deque.begin(); it < deque.end(); it++)
	{
		std::cout << *it << "\n";
	}

	// ranged loop
	std::cout << "\n";
	for (auto& data : deque)
	{
		std::cout << data << "\n";
	}

	// 데이터 추출 후 제거
	int data = deque.back();
	deque.pop_back();

	std::cout << "\n";
	std::cout << data << "\n";

	deque.clear();
	// 비었는지 확인
	if (deque.empty())
	{
		std::cout << "덱이 비었습니다.\n";
	}

	std::cin.get();

	return 0;
}