#include <iostream>
#include <vector>

int main()
{
	// vector 변수 선언
	std::vector<int> vector1;

	// 비었는지 확인하는 방법 두가지
	// if(vector1.size() == 0)
	// Effective STL에 따르면 size를 0과 비교하기보다 empty를 사용하는게 낫다고 함
	if (vector1.empty())
	{
		// 비어 있으면 true 아니면 false
		std::cout << "vector가 비었음.\n";
	}

	// 자료 삽입
	for (int ix = 0; ix < 1000; ix++)
	{
		// 현재는 push_back과 emplace_back이
		// 동일하게 동작함 R Value Ref에 대한 처리가 돼 있음
		// 이전 c++ 에선 차이가 있기 때문에 emplace_back이 효율적일수 있음
		// vector1.push_back(ix + 1);
		vector1.emplace_back(ix + 1);
	}

	// 요소 삭제
	//for (int ix = 0; ix < 1000; ix += 10)
	//{
	//	// 삭제를 원하는 위치의 반복자(iterator)를 활용해 배열 원소 삭제
	//	// erase후 반복자가 다시 반환되는데 이것을 활용하거나 다른 방식으로 삭제해야함
	//	vector1.erase(vector1.begin() + ix);
	//}

	// 요소 삭제 2
	for (auto iter = vector1.begin(); iter != vector1.end(); )
	{
		iter = vector1.erase(iter);
		if (iter != vector1.end())
		{
			iter++;
		}
	}

	// 모두 소거
	// clear해도 capacity는 그대로 유지됨
	// 내부 저장 변수가 포인터인 경우에는 delete를 해야한다(주의 사항)
	vector1.clear();

	// 비었는지 확인
	if (vector1.empty())
	{
		std::cout << "vector가 비었음.\n";
	}

	// 크기 조정
	vector1.resize(0);

	// 공간 확보
	// 크기가 가늠이 갈때 재할당을 방지하기 위해 미리 공간을 예약
	vector1.reserve(0);

	// 자료 size에 맞게 capacity를 줄여줌
	vector1.shrink_to_fit();

	std::cin.get();
	return 0;
}