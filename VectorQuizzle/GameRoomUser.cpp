#include "GameRoomUser.h"


GameRoomUser::GameRoomUser() 
{
    none = new UserInfo("NotFound", -1, -1);
}

GameRoomUser::~GameRoomUser()
{
    if (none)
    {
        delete none;
        none = nullptr;
    }
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    if (users.size() >= 6)
        return false;

    users.emplace_back(userInfo);
    return true;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
    for (auto iter = users.begin(); iter != users.end();)
    {
        if (iter->userName == userName)
        {
            users.erase(iter);
            if(!users.empty())
                masterUserName = users.begin()->userName;
            return true;
        }
        iter++;
    }
    return false;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() == 6;
}

UserInfo& GameRoomUser::GetUserOfName(const char* userName)
{
    for (auto iter = users.begin(); iter != users.end();)
    {
        if ((*iter).userName == userName)
        {
            return *iter;
        }
        iter++;
    }

    cout << userName << " 유저를 찾지 못했습니다.\n";
    return *none;
}

UserInfo& GameRoomUser::GetMasterUser()
{
    if (!users.empty())
    {
        return *(users.begin());
    }
    else
    {
        cout << "방장이 없습니다.\n";
        return *none;
    }
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    if (!users.empty())
    {
        return *(users.end() - 1);
    }

    else
    {
        cout << "마지막으로 들어온 유저를 찾을 수 없습니다.\n";
        return *none;
    }

}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.empty() || orderNum > users.size())
        return false;
    users.erase(users.begin() + orderNum - 1);
    return true;
}

void GameRoomUser::Clear()
{
    users.clear();
}
