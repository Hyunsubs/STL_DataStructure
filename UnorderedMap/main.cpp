#include <iostream>
#include <unordered_map>

class GameCharacter
{
public:
	GameCharacter() = default;
	GameCharacter(int code, int level, int money)
		: code(code), level(level), money(money)
	{

	}


	// Getter
	inline const int Code() { return code; }
	inline const int Level() { return level; }
	inline const int Money() { return money; }

	// 출력을 위한 연산자 오버로딩
	friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character)
	{
		return os << "코드: " << character.code
			<< " | 레벨: " << character.level
			<< " | 돈: " << character.money << "\n";
	}

private:
	int code = 0;
	int level = 0;
	int money = 0;
};


int main()
{
	// 해시 테이블 선언
	std::unordered_map<int, GameCharacter> characters;

	GameCharacter character1(10, 1, 3000);
	characters.insert(std::make_pair(character1.Code(), character1));

	GameCharacter character2(15, 3, 20000);
	characters.insert(std::make_pair(character2.Code(), character2));

	// 출력
	for (auto& pair : characters)
	{
		std::cout << pair.second;
	}

	// 검색
	auto search = characters.find(20);
	
	// 검색에 성공했는지 확인
	if (search != characters.end())
	{
		std::cout << search->second;
	}
	else
	{
		std::cout << "Error : 검색 실패.\n";
	}

	// 추가
	characters[20] = GameCharacter(20, 5, 50000);

	// 검색 2
	auto result = characters[20];
	std::cout << result;

	std::cin.get();
}