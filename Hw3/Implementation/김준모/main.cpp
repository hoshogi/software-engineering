#include <stdio.h>
#include <string.h>
#include "shopping.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void join();
void program_exit();

FILE* in_fp, * out_fp;

int main()
{
	// ���� ������� ���� �ʱ�ȭ
	FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
	FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

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
						break;
					}
				}
			}
		}
	}
}