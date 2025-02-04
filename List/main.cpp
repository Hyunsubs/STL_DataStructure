#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// ������ ����ü
struct Item
{
	Item(int code = 0, int price = 0)
		: code(code), price(price)
	{

	}
	~Item() = default;

	int code = 0;  // ������ �ڵ�
	int price = 0; // ������ ����
};

// ������ ��¿� ������ �����ε�
ostream& operator<<(ostream& os, const Item& item)
{
	return os << "�ڵ�: " << item.code << ", ����: " << item.price;
}


int main()
{
	// ����Ʈ ����
	list<Item> itemList;

	// ������ �߰�
	itemList.emplace_front(Item(2, 1000));
	itemList.emplace_front(Item(1, 200));

	// �ڿ� �߰�
	itemList.emplace_back(Item(4, 4500));
	itemList.emplace_back(Item(3, 3000));


	itemList.emplace_back(Item(5, 5000));
	itemList.emplace_back(Item(6, 6500));
	itemList.emplace_back(Item(7, 8000));
	itemList.emplace_back(Item(8, 10500));

	// ���
	for (auto iter = itemList.begin();
		 iter != itemList.end();
		 ++iter)
	{
		// �ݺ���(Iterator)�� �������̱� ������ �����͸� ���� ���� *�� �ٿ��� ��
		cout << *iter << "\n";
	}

	cout << "�Ѱ� ����\n";
	// ����
	itemList.pop_front();

	// �� �տ� �ִ� ������ �б�
	cout << "�� �տ� �ִ� ������ ";
	Item frontItem = itemList.front();

	// ���
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

	// ���� �� ���
	cout << "���� �� ���� �� ���\n";
	for (auto iter = itemList.begin();
		iter != itemList.end();
		++iter)
	{
		// �ݺ���(Iterator)�� �������̱� ������ �����͸� ���� ���� *�� �ٿ��� ��
		cout << *iter << "\n";
	}

	itemList.sort
	(
		[](const Item& first, const Item& second)
		{
			return first.code > second.code;
		}
	);

	cout << "������ �� ���\n";
	for (auto iter = itemList.begin();
		iter != itemList.end();
		++iter)
	{
		// �ݺ���(Iterator)�� �������̱� ������ �����͸� ���� ���� *�� �ٿ��� ��
		cout << *iter << "\n";
	}



	// �� ���� list�� std sort�� �Ұ�����
	//sort(itemList.begin(), itemList.end(),
	//	[](const Item& left, const Item& right)
	//	{
	//		return left.code > right.code;
	//	});

	cin.get();


	return 0;
}