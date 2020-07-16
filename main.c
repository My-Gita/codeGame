#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
//const int Over = 7;

int Over();
void user();
int map[10][10] = {	//地图原形
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
void inmap()	//打印地图	//遍历地图打印图形
{
	int  _Number = 0;
	int i, j;	//遍历地图打印图形
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			switch (map[i][j])
			{
			case 0:printf("  "); break;	//路
			case 1:printf("█"); break;	//墙
			case 3:printf("△"); break;	//目的地
			case 4:printf("▲"); break;	//箱子
			case 5:
			case 8:printf("☆"); break;	//人
			case 7:printf("●"); break;	//进洞
			}
		}
			printf("\n");
	}
}

void playgame()
{
	/*
	操作人物移动
	*/
	int i, j;	//遍历/找出人的位置
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
	case 'W'://人物移动

		if (map[i - 1][j] == 0 || map[i - 1][j] == 3){	//人物移动
			map[i][j] -= 5;
			map[i - 1][j] += 5;
		}
		if (map[i - 1][j] == 4 || map[i - 1][j] == 7){	//是否是以经进洞的箱子还是空箱子
			if (map[i - 2][j] == 0 || map[i - 2][j] == 3){	//判断前面是空地还是目的地
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
	int over = 7;	//进洞
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