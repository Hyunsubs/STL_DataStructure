#include <iostream>
#include <vector>

int main()
{
	// vector ���� ����
	std::vector<int> vector1;

	// ������� Ȯ���ϴ� ��� �ΰ���
	// if(vector1.size() == 0)
	// Effective STL�� ������ size�� 0�� ���ϱ⺸�� empty�� ����ϴ°� ���ٰ� ��
	if (vector1.empty())
	{
		// ��� ������ true �ƴϸ� false
		std::cout << "vector�� �����.\n";
	}

	// �ڷ� ����
	for (int ix = 0; ix < 1000; ix++)
	{
		// ����� push_back�� emplace_back��
		// �����ϰ� ������ R Value Ref�� ���� ó���� �� ����
		// ���� c++ ���� ���̰� �ֱ� ������ emplace_back�� ȿ�����ϼ� ����
		// vector1.push_back(ix + 1);
		vector1.emplace_back(ix + 1);
	}

	// ��� ����
	//for (int ix = 0; ix < 1000; ix += 10)
	//{
	//	// ������ ���ϴ� ��ġ�� �ݺ���(iterator)�� Ȱ���� �迭 ���� ����
	//	// erase�� �ݺ��ڰ� �ٽ� ��ȯ�Ǵµ� �̰��� Ȱ���ϰų� �ٸ� ������� �����ؾ���
	//	vector1.erase(vector1.begin() + ix);
	//}

	// ��� ���� 2
	for (auto iter = vector1.begin(); iter != vector1.end(); )
	{
		iter = vector1.erase(iter);
		if (iter != vector1.end())
		{
			iter++;
		}
	}

	// ��� �Ұ�
	// clear�ص� capacity�� �״�� ������
	// ���� ���� ������ �������� ��쿡�� delete�� �ؾ��Ѵ�(���� ����)
	vector1.clear();

	// ������� Ȯ��
	if (vector1.empty())
	{
		std::cout << "vector�� �����.\n";
	}

	// ũ�� ����
	vector1.resize(0);

	// ���� Ȯ��
	// ũ�Ⱑ ������ ���� ���Ҵ��� �����ϱ� ���� �̸� ������ ����
	vector1.reserve(0);

	// �ڷ� size�� �°� capacity�� �ٿ���
	vector1.shrink_to_fit();

	std::cin.get();
	return 0;
}