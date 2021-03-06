#include "Shopping.h"

// Function : MemberList()
// Description : MemberList Constructor
// Return Value : void
// Created : 2022/6/1 10:06pm
// Author : Hoseok Lee
MemberList::MemberList() {
    numberOfMembers = 0;
    nowLoginMemberIndex = -1;
}

// Function : addNewMember(string sellerName, string itemName, string companyName, int price, int numberOfItem)
// Description : add new Member into memberList
// Return Value : void
// Created : 2022/6/1 10:06pm
// Author : Hoseok Lee
void MemberList::addNewMember(string name, string residentNumber, string id, string password) {
    memberList[numberOfMembers++] = new Member(name, residentNumber, id, password);
}

// Function : deleteMember()
// Description : deallocate member
// Return Value : int
// Created : 2022/6/1 10:17pm
// Author : Hoseok Lee
string MemberList::deleteMember() {
    string id = memberList[nowLoginMemberIndex]->getId();
    delete memberList[nowLoginMemberIndex];
    nowLoginMemberIndex = -1;
    return id;
}

// Function : checkMemberInfo()
// Description : check member's id, password
// Return Value : bool
// Created : 2022/6/1 10:21pm
// Author : Hoseok Lee
bool MemberList::checkMemberInfo(string id, string password) {
    for (int i = 0; i < numberOfMembers; i++) {
        if (memberList[i]->getId() == id) {
            if (memberList[i]->getPassword() == password) {                
                nowLoginMemberIndex = i;
                return true;
            }
            else
                return false;
        }
    }
    return false;
}

// Function : setNowLoginMemberIndex()
// Description : set now login member index
// Return Value : string
// Created : 2022/6/1 10:21pm
// Author : Hoseok Lee
string MemberList::setNowLoginMemberIndexMinusOne() {
    string id = memberList[nowLoginMemberIndex]->getId();
    nowLoginMemberIndex = -1;
    return id;
}

// Function : getNowLoginMemberName()
// Description : return now login member's name
// Return Value : string
// Created : 2022/6/1 10:45pm
// Author : Hoseok Lee
string MemberList::getNowLoginMemberId() {
    return memberList[nowLoginMemberIndex]->getId();
}