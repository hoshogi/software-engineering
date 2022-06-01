#include <string>
#include "Member.h"
using namespace std;

// Class : MemberList
// Description : mamge member list
// Created : 2022/6/1 9:56 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class MemberList {
private:
    Member* memberList[50];
    int numberOfMembers;
    int nowLoginMemberIndex;

public: 
    MemberList();
    void addNewMember(string name, string residentNumber, string id, string password);
    void deleteMember();
    void setNowLoginMemberIndexMinusOne();
    bool checkMemberInfo(string id, string password);
    string getNowLoginMemberName();
};