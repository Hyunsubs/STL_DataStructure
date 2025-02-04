#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 아이템 구조체
struct Item
{
	Item(int code = 0, int price = 0)
		: code(code), price(price)
	{

	}
	~Item() = default;

	int code = 0;  // 아이템 코드
	int price = 0; // 아이템 가격
};

// 데이터 출력용 연산자 오버로딩
ostream& operator<<(ostream& os, const Item& item)
{
	return os << "코드: " << item.code << ", 가격: " << item.price;
}


int main()
{
	// 리스트 생성
	list<Item> itemList;

	// 데이터 추가
	itemList.emplace_front(Item(2, 1000));
	itemList.emplace_front(Item(1, 200));

	// 뒤에 추가
	itemList.emplace_back(Item(4, 4500));
	itemList.emplace_back(Item(3, 3000));


	itemList.emplace_back(Item(5, 5000));
	itemList.emplace_back(Item(6, 6500));
	itemList.emplace_back(Item(7, 8000));
	itemList.emplace_back(Item(8, 10500));

	// 출력
	for (auto iter = itemList.begin();
		 iter != itemList.end();
		 ++iter)
	{
		// 반복자(Iterator)는 포인터이기 때문에 데이터를 읽을 때는 *을 붙여야 함
		cout << *iter << "\n";
	}

	cout << "한개 삭제\n";
	// 삭제
	itemList.pop_front();

	// 맨 앞에 있는 데이터 읽기
	cout << "맨 앞에 있는 아이템 ";
	Item frontItem = itemList.front();

	// 출력
	cout << frontItem << "\n";

	itemList.sort
	(
		[](const Item& first, const Item& second) 
		{ 
			return first.code < second.code;
		}
	);

	itemList.remove_if
	(
		[](const Item& self)
		{
			return self.code > 5;
		}
	);

	// 정렬 후 출력
	cout << "정렬 및 삭제 후 출력\n";
	for (auto iter = itemList.begin();
		iter != itemList.end();
		++iter)
	{
		// 반복자(Iterator)는 포인터이기 때문에 데이터를 읽을 때는 *을 붙여야 함
		cout << *iter << "\n";
	}

	itemList.sort
	(
		[](const Item& first, const Item& second)
		{
			return first.code > second.code;
		}
	);

	cout << "역정렬 후 출력\n";
	for (auto iter = itemList.begin();
		iter != itemList.end();
		++iter)
	{
		// 반복자(Iterator)는 포인터이기 때문에 데이터를 읽을 때는 *을 붙여야 함
		cout << *iter << "\n";
	}



	// 역 정렬 list는 std sort로 불가능함
	//sort(itemList.begin(), itemList.end(),
	//	[](const Item& left, const Item& right)
	//	{
	//		return left.code > right.code;
	//	});

	cin.get();


	return 0;
}