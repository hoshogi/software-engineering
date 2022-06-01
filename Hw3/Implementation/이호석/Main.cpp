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
void join();
void withdraw();
void login();
void logout();
void registerItem();
void search();
void buy();
void checkBuyList();
void rate();
void program_exit();

// 변수 선언
ifstream fin;
ofstream fout;
MemberList* memberList;
ItemList* itemList;

void SignUpUI::createNewMember(SignUp* signUp) {
	string name, residentNumber, id, password;

	fin >> name >> residentNumber >> id >> password;
	signUp->addNewMember(name, residentNumber, id, password);
	fout << "1.1. 회원가입" << endl;
	fout << name << ' ' << residentNumber << ' ' << id << ' ' << password << ' ' << endl << endl;
}

int main() {
	// 파일 입출력을 위한 초기화
	fin.open("input.txt");
	fout.open("output.txt");

	memberList = new MemberList();
	itemList = new ItemList();

	doTask();

	// ...

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
				join();
				break;
			case 2:
				// withdraw();
				break;

			}
			break;
		case 2:
			switch (menu_level_2) {
			case 1:
				// login();
				break;
			case 2:
				// logout();
				break;
			}
			break;
		case 3:
			switch (menu_level_2) {
			case 1:
				// registerItem();
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

void SignUp::addNewMember(string name, string residentNumber, string id, string password) {
	memberList->addNewMember(name, residentNumber, id, password);
}

void join() {
	SignUp signUp;
	
}

//void example() {
//	char user_type[MAX_STRING], name[MAX_STRING], SSN [MAX_STRING],
//		address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
//
//	// 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
//	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);
//
//	// 해당 기능 수행  
//	// ...
//
//		// 출력 형식
//	fprintf(out_fp, "1.1. 회원가입\n");
//	fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
//
//
//}

//void program_exit() {
//	fin.close();
//	fout.close();
//	// ....
//}