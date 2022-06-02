// 헤더 선언
#include <iostream>
#include <string>
#include <fstream>
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
	int id = withdraw->deleteMember();
	fout << "1.2 회원탈퇴" << endl;
	fout << "> " << id << endl << endl;
}

// Function : Withdraw::deleteMember()
// Description : delete member from memberList
// Return Value : int
// Created : 2022/6/2 2:26 pm
// Author : Hoseok Lee
int Withdraw::deleteMember() {
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
	fout << "2.1 로그인" << endl;
	if (login->checkMemberInfo(id, password))
		fout << "> " << id << password << endl << endl;
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
	fout << "2.2 로그아웃" << endl;
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
				// search();
				break;
			case 2:
				// buy();
				break;
			case 3:
				// checkBuyList();
				break;
			}
			break;
		case 6:
			switch (menu_level_2) {
			case 1:   // "6.1. 종료“ 메뉴 부분

				// ..
				// program_exit();
				is_program_exit = 1;
				break;

				// .......
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

}

void program_exit() {
	fin.close();
	fout.close();
}