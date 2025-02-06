#include <iostream>
#include <string>
#include <map>
#include <windows.h>
using namespace std;

// Map (Key, Value)
// 구조체
struct Item
{
	wstring name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

// 출력을 위한 연산자 오버로딩
wostream& operator<<(wostream& os, const Item& item)
{
	return os << TEXT("이름 : ") << item.name << TEXT(", 가격: ") << item.price << TEXT(", 코드: ") << item.code;
}

int main()
{
	wcout.imbue(std::locale("korean"));
	// 맵생성
	map<wstring, Item, greater<wstring>> items;

	// 데이터 추가
	items.insert({ TEXT("장검"), {TEXT("장검"), 1, 200, 0}});
	items.insert({ TEXT("해머"), {TEXT("해머"), 1, 1000, 4}});
	items.insert({ TEXT("방패"), {TEXT("방패"), 2, 500, 3}});

	// 개수 확인 및 출력
	if (!items.empty())
	{
		wcout << TEXT("저장된 아이템 수: ") << items.size() << "\n";
	}

	// 출력
	for (auto& pair : items)
	{
		wcout << pair.second << "\n";
	}

	// 검색
	auto it = items.find(TEXT("해머"));
	if (it != items.end())
	{
		wcout << TEXT("해머 아이템이 있습니다. 해머의 가격은 ") << it->second.price << TEXT("입니다.\n");
	}

	// 삭제
	if (it != items.end())
	{
		items.erase(it);

		wcout << TEXT("해머 아이템 삭제 후 출력\n");
		for (auto& pair : items)
		{
			wcout << pair.second << "\n";
		}
	}

	return 0;
}