#include <iostream>
#include <string>
#include <map>
#include <windows.h>
using namespace std;

// Map (Key, Value)
// ����ü
struct Item
{
	wstring name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

// ����� ���� ������ �����ε�
wostream& operator<<(wostream& os, const Item& item)
{
	return os << TEXT("�̸� : ") << item.name << TEXT(", ����: ") << item.price << TEXT(", �ڵ�: ") << item.code;
}

int main()
{
	wcout.imbue(std::locale("korean"));
	// �ʻ���
	map<wstring, Item, greater<wstring>> items;

	// ������ �߰�
	items.insert({ TEXT("���"), {TEXT("���"), 1, 200, 0}});
	items.insert({ TEXT("�ظ�"), {TEXT("�ظ�"), 1, 1000, 4}});
	items.insert({ TEXT("����"), {TEXT("����"), 2, 500, 3}});

	// ���� Ȯ�� �� ���
	if (!items.empty())
	{
		wcout << TEXT("����� ������ ��: ") << items.size() << "\n";
	}

	// ���
	for (auto& pair : items)
	{
		wcout << pair.second << "\n";
	}

	// �˻�
	auto it = items.find(TEXT("�ظ�"));
	if (it != items.end())
	{
		wcout << TEXT("�ظ� �������� �ֽ��ϴ�. �ظ��� ������ ") << it->second.price << TEXT("�Դϴ�.\n");
	}

	// ����
	if (it != items.end())
	{
		items.erase(it);

		wcout << TEXT("�ظ� ������ ���� �� ���\n");
		for (auto& pair : items)
		{
			wcout << pair.second << "\n";
		}
	}

	return 0;
}