#include <iostream>
#include <deque> // �� ����� ���� ���


int main()
{
	// �� ����
	std::deque<int> deque;
	
	// ������ �߰�
	deque.emplace_back(100);
	deque.emplace_front(200);

	// ���
	for (int ix = 0; ix < deque.size(); ix++)
	{
		std::cout << deque[ix] << "\n";
	}

	// ���
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

	// ������ ���� �� ����
	int data = deque.back();
	deque.pop_back();

	std::cout << "\n";
	std::cout << data << "\n";

	deque.clear();
	// ������� Ȯ��
	if (deque.empty())
	{
		std::cout << "���� ������ϴ�.\n";
	}

	std::cin.get();

	return 0;
}