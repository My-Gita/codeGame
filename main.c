#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
//const int Over = 7;

int Over();
void user();
int map[10][10] = {	//��ͼԭ��
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 3, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 1, 1, 1, 1, 0, 0,
	1, 1, 1, 4, 0, 4, 3, 1, 0, 0,
	1, 3, 0, 4, 5, 1, 1, 1, 0, 0,
	1, 1, 1, 1, 4, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 3, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0,

	//1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
	//1, 0, 0, 0, 1, 0, 0, 1, 0, 1,
	//1, 0, 0, 0, 1, 0, 0, 1, 0, 1,
	//1, 0, 0, 0, 1, 0, 0, 1, 0, 1,
	//1, 0, 4, 0, 1, 0, 0, 1, 0, 1,
	//1, 1, 1, 5, 1, 1, 1, 1, 0, 1,
	//0, 1, 1, 4, 0, 0, 0, 0, 0, 1,
	//0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
	//0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
	//0, 1, 1, 1, 1, 1, 0, 0, 0, 0,

};
void inmap()	//��ӡ��ͼ	//������ͼ��ӡͼ��
{
	int  _Number = 0;
	int i, j;	//������ͼ��ӡͼ��
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			switch (map[i][j])
			{
			case 0:printf("  "); break;	//·
			case 1:printf("��"); break;	//ǽ
			case 3:printf("��"); break;	//Ŀ�ĵ�
			case 4:printf("��"); break;	//����
			case 5:
			case 8:printf("��"); break;	//��
			case 7:printf("��"); break;	//����
			}
		}
			printf("\n");
	}
}

void playgame()
{
	/*
	���������ƶ�
	*/
	int i, j;	//����/�ҳ��˵�λ��
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			if (map[i][j] == 5||map[i][j]==8)
				break;
		}
		if (map[i][j] == 5 || map[i][j] == 8)
			break;
	}
	char ch = _getch();
	switch (ch)
	{
	case 'w':
	case 'W'://�����ƶ�

		if (map[i - 1][j] == 0 || map[i - 1][j] == 3){	//�����ƶ�
			map[i][j] -= 5;
			map[i - 1][j] += 5;
		}
		if (map[i - 1][j] == 4 || map[i - 1][j] == 7){	//�Ƿ����Ծ����������ӻ��ǿ�����
			if (map[i - 2][j] == 0 || map[i - 2][j] == 3){	//�ж�ǰ���ǿյػ���Ŀ�ĵ�
				map[i][j] -= 5;
				map[i - 1][j] += 5;
				map[i - 1][j] -= 4;
				map[i - 2][j] += 4;
			}
		}
			 break;
	case 's':
	case 'S':

		if (map[i + 1][j] == 0 || map[i + 1][j] == 3){
			map[i][j] -= 5;
			map[i + 1][j] += 5;
		}
		if (map[i + 1][j] == 4 || map[i + 1][j] == 7){
			if (map[i + 2][j] == 0 || map[i + 2][j] == 3){
				map[i][j] -= 5;
				map[i + 1][j] += 5;
				map[i + 1][j] -= 4;
				map[i + 2][j] += 4;
			}
		}
			break;
	case 'a':
	case 'A':
		if (map[i][j - 1] == 0 || map[i][j - 1] == 3){
			map[i][j] -= 5;
			map[i][j - 1] += 5;
		}
		if (map[i][j - 1] == 4 || map[i][j - 1] == 7){
			if (map[i][j - 2] == 0 || map[i][j - 2] == 3){
				map[i][j] -= 5;
				map[i][j - 1] += 5;
				map[i][j - 1] -= 4;
				map[i][j - 2] += 4;
			}
		}
		break;
	case 'd':
	case 'D':

		if (map[i][j + 1] == 0 || map[i][j + 1] == 3){
			map[i][j] -= 5;
			map[i][j + 1] += 5;
		}
		if (map[i][j + 1] == 4 || map[i][j + 1] == 7){
			if (map[i][j + 2] == 0 || map[i][j + 2] == 3){
				map[i][j] -= 5;
				map[i][j + 1] += 5;
				map[i][j + 1] -= 4;
				map[i][j + 2] += 4;
			}
		}
		break;

	}

}

int main()
{
	while ( Over() )
	{
		inmap();
		playgame();
		Over();
		system("cls");
	}
	inmap();
	printf("\nGAMEOVER!\n\n");
	system("pause");
	return 0;
}

void user()
{
	int over = 7;	//����
	int a[4] = { 0 };
	int count = 0;
	int i, j;
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if (map[i][j] == over){
				if (a[4] == 7){
					break;
				}
				a[count++] += over;
			}
		}
		if (a[4] == 7){
			break;
		}
	}
}

int Over()
{
	int count = 0;
	int i, j;
	bool a = true;;
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			if (map[i][j] == 7){
				count++;
			}
			if (count == 4){
				a = false;
				break;
			}
		}
	}
		printf("%d\n", count);
	
	return a;
}