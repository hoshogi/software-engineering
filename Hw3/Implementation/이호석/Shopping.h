#pragma once
#include <string>
using namespace std;

// Class : BuyItemList
// Description : list contains item
// Created : 2022/6/1 23:07 pm
// Author : ���ظ�
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
    string deleteMember();
    string setNowLoginMemberIndexMinusOne();
    bool checkMemberInfo(string id, string password);
    string getNowLoginMemberId();
};

// Class : Item
// Description : item class
// Created : 2022/6/1 21:36 pm
// Author : ���ظ�
// mail : a00700c@g.hongik.ac.kr
class Item
{
private:
    string sellerId;
    string itemName;
    string companyName;
    int price;
    int numberOfItem;
    int totalRating = 0;
    int numberOfRating = 0;
public:
    Item(string sellerName, string itemName, string companyName, int price, int numberOfItem);
    string getSellerId();
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
// Author : ���ظ�
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
    void addNewItem(string sellerId, string itemName, string companyName, int price, int numberOfItem);
};

// Class : SignUp
// Description : SignUp control class
// Created : 2022/6/2 1:22 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class SignUp {
public:
    SignUp();
    void addNewMember(string name, string residentNumber, string id, string password);
};

// Class : SignUpUI
// Description : SignUpUI boundary class
// Created : 2022/6/2 1:22 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class SignUpUI {
public:
    void createNewMember(SignUp* signUp);
};

// Class : Withdraw
// Description : Withdraw control class
// Created : 2022/6/2 2:21 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class Withdraw {
public:
    Withdraw();
    string deleteMember();
};

// Class : WithdrawUI
// Description : WithdrawUI boundary class
// Created : 2022/6/2 2:22 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class WithdrawUI {
public:
    void withdrawMember(Withdraw* withdraw);
};

// Class : Login
// Description : Login control class
// Created : 2022/6/2 2:55 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class Login {
public:
    Login();
    bool checkMemberInfo(string id, string password);
};

// Class : LoginUI
// Description : LoginUI boundary class
// Created : 2022/6/2 2:55 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class LoginUI {
public:
    void loginMember(Login* login);
};

// Class : Logout
// Description : Logout control class
// Created : 2022/6/2 2:55 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class Logout {
public:
    Logout();
    string logoutMember();
};

// Class : LogoutUI
// Description : LogoutUI boundary class
// Created : 2022/6/2 3:01 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class LogoutUI {
public:
    void logoutMember(Logout* logout);
};

// Class : RegisterItem
// Description : RegisterItem control class
// Created : 2022/6/2 4:00 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class RegisterItem {
public:
    RegisterItem();
    void addNewItem(string itemName, string companyName, int price, int numberOfItem);
};

// Class : RegisterItemUI
// Description : RegisterItemUI boundary class
// Created : 2022/6/2 4:01 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class RegisterItemUI {
public:
    void registerNewItem(RegisterItem* registerItem);
};