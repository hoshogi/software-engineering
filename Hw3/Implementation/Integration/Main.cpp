// 헤더 선언
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include "Shopping.h"
using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void doSignup();
void doWithdraw();
void doLogin();
void doLogout();
void doRegisterItem();
void doSearch();
void doBuy();
void doCheckBuyList();
void doRate();
void program_exit();

// 변수 선언
ifstream fin;
ofstream fout;
MemberList* memberList;
ItemList* itemList;

// Function : compare(Item* prev, Item* next)
// Description : a function uses when sorting
// Parameters : two Item to compare
// Return value : bool
// Created : 2022/6/2 17:09 pm
// Author : 김준모
bool compare(Item* prev, Item* next) {
	return prev->getItemName() < next->getItemName();
}

// Function : SignUpUI::createNewMember(SignUp* signUp)
// Description : file read and write Member's Info
// Return Value : void
// Created : 2022/6/2 1:08 pm
// Author : Hoseok Lee
void SignUpUI::createNewMember(SignUp* signUp) {
	string name, residentNumber, id, password;

	fin >> name >> residentNumber >> id >> password;
	signUp->addNewMember(name, residentNumber, id, password);
	fout << "1.1. 회원가입" << endl;
	fout << "> " << name << ' ' << residentNumber << ' ' << id << ' ' << password << ' ' << endl << endl;
}

// Function : SignUp::Member:addNewMember(string name, string residentNumber, string id, string password)
// Description : add new member into memberList
// Return Value : void
// Created : 2022/6/2 1:10 pm
// Author : Hoseok Lee
void SignUp::addNewMember(string name, string residentNumber, string id, string password) {
	memberList->addNewMember(name, residentNumber, id, password);
}

// Function : WithdrawUI::withdrawMember(Withdraw* withdraw)
// Description : file write withdraw member's id
// Return Value : void
// Created : 2022/6/2 2:25 pm
// Author : Hoseok Lee
void WithdrawUI::withdrawMember(Withdraw* withdraw) {
	string id = withdraw->deleteMember();
	fout << "1.2. 회원탈퇴" << endl;
	fout << "> " << id << endl << endl;
}

// Function : Withdraw::deleteMember()
// Description : delete member from memberList
// Return Value : int
// Created : 2022/6/2 2:26 pm
// Author : Hoseok Lee
string Withdraw::deleteMember() {
	return memberList->deleteMember();
}

// Function : LoginUI::loginMember(Login* login)
// Description : file write withdraw member's id, password
// Return Value : void
// Created : 2022/6/2 2:57 pm
// Author : Hoseok Lee
void LoginUI::loginMember(Login* login) {
	string id, password;
	fin >> id >> password;
	fout << "2.1. 로그인" << endl;
	if (login->checkMemberInfo(id, password))
		fout << "> " << id << ' ' << password << endl << endl;
	else
		fout << "Wrong id or password" << endl << endl;
}

// Function : Login::checkMemberInfo(string id, string password)
// Description : check member's id, password correctly
// Return Value : bool
// Created : 2022/6/2 2:57 pm
// Author : Hoseok Lee
bool Login::checkMemberInfo(string id, string password) {
	return memberList->checkMemberInfo(id, password);
}

// Function : LogoutUI::logoutMember(Logout* logout)
// Description : file write member's id
// Return Value : void
// Created : 2022/6/2 3:09 pm
// Author : Hoseok Lee
void LogoutUI::logoutMember(Logout* logout) {
	string id = logout->logoutMember();
	fout << "2.2. 로그아웃" << endl;
	fout << id << endl << endl;
}

// Function : Logout::logoutMember()
// Description : logout member
// Return Value : string
// Created : 2022/6/2 2:57 pm
// Author : Hoseok Lee
string Logout::logoutMember() {
	return memberList->setNowLoginMemberIndexMinusOne();
}

// Function : RegisterItemUI::registerNewItem(RegisterItem* registerItem)
// Description : read and write item's info
// Return Value : void
// Created : 2022/6/2 6:09 pm
// Author : Hoseok Lee
void RegisterItemUI::registerNewItem(RegisterItem* registerItem) {
	int numberOfItem, price;
	string itemName, companyName;
	fin >> itemName >> companyName >> price >> numberOfItem;
	registerItem->addNewItem(itemName, companyName, price, numberOfItem);
	fout << "3.1. 판매 의류 등록" << endl;
	fout << itemName << ' ' << companyName << ' ' << price << ' ' << numberOfItem << endl << endl;
}

// Function : RegisterItem::addNewItem(string itemName, string companyName, int price, int numberOfItem)
// Description : add new item
// Return Value : void
// Created : 2022/6/2 6:10 pm
// Author : Hoseok Lee
void RegisterItem::addNewItem(string itemName, string companyName, int price, int numberOfItem) {
	string sellerId = memberList->getNowLoginMemberId();
	itemList->addNewItem(sellerId, itemName, companyName, price, numberOfItem);
}

// Function : SearchItem::showItemInfo(string itemName)
// Description : searchItem from itemlist and returns item
// Parameters : itemName
// Return Value : Item pointer
// Created : 2022/6/2 02:14 am
// Author : 김준모
Item* SearchItem::showItemInfo(string itemName) {
	Item* item = itemList->searchItem(itemName);
	return item;
}

// Function : SearchItemUI::searchItemByName()
// Description : input and output when search item
// Parameters : searchItem pointer
// Created : 2022/6/2 02:25 am
// Author : 김준모
void SearchItemUI::searchItemByName(SearchItem* searchItem) {
	string itemName;
	fin >> itemName;
	Item* item = searchItem->showItemInfo(itemName);
	fout << "4.1. 상품 정보 검색" << endl;
	fout << "> " << item->getSellerId() << ' ' << item->getItemName() << ' ' << item->getCompanyName() << ' ' << item->getPrice() << ' ' << item->getNumberOfItem() << ' ' << item->getRating() << endl << endl;
}

// Function : BuyItem::buyItem()
// Description : buyItem from itemlist and returns item
// Return Value : Item pointer
// Created : 2022/6/2 03:15 am
// Author : 김준모
Item* BuyItem::buyItem() {
	Item* item = itemList->buyItem();
	BuyItemList* nowBuyItemList = memberList->getNowLoginBuyList();
	nowBuyItemList->addBuyItemList(item->getItemName());
	return item;
}

// Function : BuyItemUI::buyItem()
// Description : input and output when buy item
// Parameters : buyItem pointer
// Created : 2022/6/2 03:14 am
// Author : 김준모
void BuyItemUI::buyItem(BuyItem* buyItem) {
	Item* item = buyItem->buyItem();
	fout << "4.2. 상품 구매" << endl;
	fout << "> " << item->getSellerId() << ' ' << item->getItemName() << endl << endl;
}

// Function : BuyItemCheck::getBuyItemList()
// Description : get Buy Item object as array
// Return value : Item object list
// Parameter : nowBuyItemList array
// Created : 2022/6/2 16:47 pm
// Author : 김준모
list<Item*> BuyItemCheck::getBuyItemList(string* nowBuyItemList) {
	list<Item*> buyItemList;
	for (int i = 0; nowBuyItemList[i] != ""; i++) {
		buyItemList.push_back(itemList->searchItem(nowBuyItemList[i]));
	}
	buyItemList.sort(compare);
	//sort(buyItemList.begin(), buyItemList.end(), compare);
	return buyItemList;
}

// Function : BuyItemCheck::showBuyItemList()
// Description : return buyItemList
// Return value : buyItemList array pointer
// Created : 2022/6/2 17:32 pm
// Author : 김준모
string* BuyItemCheck::showBuyItemList() {
	BuyItemList* nowBuyItemList = memberList->getNowLoginBuyList();
	return nowBuyItemList->getBuyItemList();
}

// Function : BuyItemCheckUI::checkBuyItemList()
// Description : input and output when buy item check
// Parameters : buyItemCheck pointer
// Created : 2022/6/2 03:27 am
// Author : 김준모
void BuyItemCheckUI::checkBuyItemList(BuyItemCheck* buyItemCheck) {
	fout << "4.3. 상품 구매 내역 조회" << endl;
	string* nowBuyItemList = buyItemCheck->showBuyItemList();
	list<Item*> buyItemList = buyItemCheck->getBuyItemList(nowBuyItemList);
	list<Item*>::iterator iter;
	for (iter = buyItemList.begin(); iter != buyItemList.end(); iter++) {
		fout << "> " << (*iter)->getSellerId() << " " << (*iter)->getItemName() << " " << (*iter)->getCompanyName() << " " << (*iter)->getPrice() << " " << (*iter)->getNumberOfItem() << " " << (*iter)->getRating() << endl;
	}
	fout << endl;
}

Item* RateItem::rateItem(string itemName, int myRating) {
	Item* item = itemList->searchItem(itemName);
	item->rateItem(myRating);
	return item;
}

void RateItemUI::rateItem(RateItem* rateItem) {
	string itemName;
	int myRating;
	fin >> itemName >> myRating;
	Item* item = rateItem->rateItem(itemName, myRating);
	fout << "> " << item->getSellerId() << " " << item->getItemName() << " " << item->getRating() << endl << endl;
}

int main() {
	// 파일 입출력을 위한 초기화
	fin.open("input.txt");
	fout.open("output.txt");

	memberList = new MemberList();
	itemList = new ItemList();

	doTask();

	return 0;
}

void doTask() {
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit) {
		// 입력파일에서 메뉴 숫자 2개를 읽기
		fin >> menu_level_1 >> menu_level_2;


		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
		case 1:
			switch (menu_level_2) {
			case 1:   // "1.1. 회원가입“ 메뉴 부분
				doSignup();
				break;
			case 2:
				doWithdraw();
				break;
			}
			break;
		case 2:
			switch (menu_level_2) {
			case 1:
				doLogin();
				break;
			case 2:
				doLogout();
				break;
			}
			break;
		case 3:
			switch (menu_level_2) {
			case 1:
				doRegisterItem();
				break;
			}
			break;
		case 4:
			switch (menu_level_2) {
			case 1:
				doSearch();
				break;
			case 2:
				doBuy();
				break;
			case 3:
				doCheckBuyList();
				break;
			}
			break;
		case 6:
			switch (menu_level_2) {
			case 1:   // "6.1. 종료“ 메뉴 부분
				program_exit();
				is_program_exit = 1;
				break;
			}
			return;
		}
	}
}

void doSignup() {
	SignUp signUp;
}

void doWithdraw() {
	Withdraw witdraw;
}

void doLogin() {
	Login login;
}

void doLogout() {
	Logout logout;
}

void doRegisterItem() {
	RegisterItem registerItem;
}

void doSearch() {
	SearchItem searchItem;
}

void doBuy() {
	BuyItem buyitem;
}

void doCheckBuyList() {
	BuyItemCheck buyItemCheck;
}

void doRate() {
	RateItem rateItem;
}

void program_exit() {
	fin.close();
	fout.close();
}