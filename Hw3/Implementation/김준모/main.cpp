#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "shopping.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

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

FILE* in_fp, * out_fp;

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	return 0;
}

void doTask()
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// 입력 파일에서 메뉴 숫자 2개를 읽기
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // "1.1. 회원가입" 메뉴 부분
			{
				// join() 함수에서 해당 기능 수행
				join();

				break;
			}
			case 2:
			{
				withdraw();

				break;
			}
			}
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				login();

				break;
			}
			case 2:
			{
				logout();

				break;
			}
			}
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				registerItem();

				break;
			}
			}
		}

		case 4:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				search();

				break;
			}
			case 2:
			{
				buy();

				break;
			}
			case 3:
			{
				checkBuyList();

				break;
			}
			case 4:
			{
				rate();

				break;
			}
			}
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				program_exit();
				is_program_exit = 1;
				break;
			}
			}
		}
		}
	}
}

void join()
{}
void withdraw()
{}
void login()
{}
void logout()
{}
void registerItem()
{}



void search()
{

	char itemName[MAX_STRING];

	fscanf(in_fp, "%s", itemName);



	fprintf(out_fp, "4.1. 상품 정보 검색\n");
	fprintf(out_fp, "%s\n", itemName);
}

void buy()
{

}
void checkBuyList()
{

}
void rate()
{

}


void program_exit()
{
	fprintf(out_fp, "6.1. 종료\n");
}