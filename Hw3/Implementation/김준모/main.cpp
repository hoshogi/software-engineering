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
	// ���� ������� ���� �ʱ�ȭ
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	return 0;
}

void doTask()
{
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// �Է� ���Ͽ��� �޴� ���� 2���� �б�
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // "1.1. ȸ������" �޴� �κ�
			{
				// join() �Լ����� �ش� ��� ����
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



	fprintf(out_fp, "4.1. ��ǰ ���� �˻�\n");
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
	fprintf(out_fp, "6.1. ����\n");
}