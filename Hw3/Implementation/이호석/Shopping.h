#pragma once
#include <string>
using namespace std;

// Class : BuyItemList
// Description : list contains item
// Created : 2022/6/1 23:07 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItemList {
private:
    string buyItemNames[50];
    int numberOfBuyItem;
public:
    BuyItemList();
    void addBuyItemList(string itemName);
    string* getBuyItemList();
};

// Class : Member
// Description : store member info
// Created : 2022/6/1 9:42 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class Member {
private:
    string name;
    string residentNumber;
    string id;
    string password;
    BuyItemList* buyItemList;

public:
    Member(string name, string residentNumber, string id, string password);
    string getId();
    string getPassword();
    string getName();
};

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

// Class : Item
// Description : item class
// Created : 2022/6/1 21:36 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class Item
{
private:
    string sellerName;
    string itemName;
    string companyName;
    int price;
    int numberOfItem;
    int totalRating = 0;
    int numberOfRating = 0;
public:
    Item(string sellerName, string itemName, string companyName, int price, int numberOfItem);
    string getSellerName();
    string getItemName();
    string getCompanyName();
    int getPrice();
    int getNumberOfItem();
    int getRating();
    void buyItem();
    void rateItem(int myRating);
};

// Class : ItemList
// Description : list contains item
// Created : 2022/6/1 23:07 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class ItemList {
private:
    Item* itemList[50];
    int nowSearchItemIndex;
    int numberOfItem;
public:
    ItemList();
    Item* searchItem(string itemName);
    Item* rateItem(string itemName, int myRating);
    Item* buyItem();
    void addNewItem(string sellerName, string itemName, string companyName, int price, int numberOfItem);
};

class SignUp {
public:
    SignUp();
    void addNewMember(string name, string residentNumber, string id, string password);
};

class SignUpUI {
public:
    void createNewMember(SignUp* signUp);
};