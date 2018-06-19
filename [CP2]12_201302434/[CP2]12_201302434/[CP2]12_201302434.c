#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

//컬러 사용하기 Define 값
#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) //콘솔창의 핸들정보 받기
#define BLACK SetConsoleTextAttribute(colorHandle, 0x0000); //검정색
#define GRAY SetConsoleTextAttribute(colorHandle, 0x0007); //밝은 회색
#define RED SetConsoleTextAttribute(colorHandle, 0x000c); //빨간색
#define BLUE SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008); //파란색
#define WHITE SetConsoleTextAttribute(colorHandle, 0x000f); //하얀색
#define YEL SetConsoleTextAttribute(colorHandle, 0x000e); //노란색
#define GREEN SetConsoleTextAttribute(colorHandle, 0x0002); //녹색
#define VIO SetConsoleTextAttribute(colorHandle, 0x0001 | 0x0008 | 0x000c); //보라색

// 커서 숨기기 매크로
enum {HIDDEN, SHOW};

// 미로함수 방향키 아스키코드 값
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define Enter 13 //엔터 값
#define ESC 27

//System 함수
void gotoxy(int , int );// x축 y축 이동시켜주는 함수
void delay(clock_t wait); //딜레이 함수 시간 몇초를 대기
void color(unsigned short color); // 랜덤 컬러를 주기 위한 함수
void viewCursor(char show); // 커서를 숨기거나 보여줌

//미로탈출 게임 함수
void miro(); //미로게임 메인함수
int miroGame();

int main()
{
	miro();
	return 0;
}

void miro()
{
	int n;
	n = miroGame();
}

void gotoxy(int x, int y) //x축 y축 이동시켜주는 함수
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void color(unsigned short color) // 무작위 컬러 만들기위한 함수
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void viewCursor(char show) // 커서 숨기기 /  보이기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void delay(clock_t wait)
{
	//wait ms 만큼 대기 1
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}

int miroGame() {
	struct MIRO
	{
		int x, y;
		int PlayN;
	};
	struct MIRO Me, Mon[20], Pre[10];//본인 , 몬스터, 하트
	static int Stage = 1, PreNum;
	static int i, j, k = 0, T = 0, b, c[20][2] = { 0 }, d[30] = { 0 };
	static int Screen[18][28] = { 0 };
	int randNum[2] = { 0 };
	char ch;
	int Life = 3, LifeN, GameOver = 0;

	srand(time(NULL));

	system("mode con lines = 20 cols  = 58"); //창크기 line = y축, cols = x축, line은 -1 크기 출력
	system("cls");
	viewCursor(HIDDEN);
	system("cls");

	while (1) {
		randNum[0] = 0;
		randNum[1] = 0;

		gotoxy(22, 9);
		printf("S t a g e %d", Stage); //스테이지 시작
		Sleep(3000);
		system("cls");

		b = rand() % 14 + 2;

		for (i = 0; i < Stage * 2; i++) {
			c[i][0] = rand() % 14 + 2; //랜덤 좌표 설정
			c[i][1] = rand() % 22 + 3;
		}
		for (i = 0; i < 35; i++) {
			d[i] = rand() % 26 + 1;
		}
		Me.x = 7;//시작 좌표
		Me.y = 1;
		Me.PlayN = 1;//플레이어는 1

		for (i = 0; i < Stage * 2; i++) {//몬스터의 좌표
			Mon[i].x = c[i][0];
			Mon[i].y = c[i][1];
			Mon[i].PlayN = 10;//몬스터의 자리는 10
		}
		for (i = 0; i < Stage; i++) { //하트의 좌표
			Pre[i].x = c[i][0]; 
			Pre[i].y = c[i][1] + 1;
			Pre[i].PlayN = 7; //하트는 7
		}
		for (i = 0; i < 18; i++) {
			for (j = 0; j < 28; j++) {
				Screen[i][j] = 0;//전체 다른 공간은 0
			}
		}
		k = 0;
		for (i = 0; i < 18; i++) { //벽 생성
			for (j = 0; j < 28; j++) {
				if (i == 0 || i == 17)//테두리
					Screen[i][j] = 9; //9는 벽
				else if (j == 0 || j == 27)
					Screen[i][j] = 9;
			}
		}
		for (i = 0; i < 18; i++) {//안에 벽은 랜덤 위치에 생성
			for (j = 0; j < 28; j++) {
				if (d[k] == j) {
					Screen[i][j] = 9;
					k++;
				}
			}
		}
		Screen[b][26] = 0;
		Screen[b][27] = 0;
		Screen[7][1] = 1; //초기화
		Screen[6][1] = 0;

		//몬스터 좌표에 몬스터 값 넣기
		//몬스터의 수는 스테이지의 2배
		for (i = 0; i < Stage * 2; i++) {
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
		}
		//하트 좌표에 하트 값 넣기
		//하트의 수는 스테이지와 같음
		for (i = 0; i < Stage; i++) {
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN;
		}
		while (1) {
			PreNum = 0;
			//몬스터 움직임
			for (i = 0; i < Stage * 2; i++) {
				randNum[0] = rand() % 15;
				if (randNum[0] == 0) {
					randNum[1] = rand() % 4;
					switch (randNum[1]) {
					case 0://왼쪽 : 움직이려는 좌표에 벽, 하트, 플레이어가 없을 경우 움직임
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].y -= 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //플레이어와 만나게 된다면
								Me.PlayN = 99;//life-1
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break;
					case 1://오른쪽 : 움직이려는 좌표에 벽, 하트, 플레이어가 없을 경우 움직임
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].y += 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//플레이어와 만나게 된다면
								Me.PlayN = 99;//life-1
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break;
					case 2://위 : 움직이려는 좌표에 벽, 하트, 플레이어가 없을 경우 움직임
						if (Screen[Mon[i].x - 1][Mon[i].y] != 9 && Screen[Mon[i].x - 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x - 1][Mon[i].y] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].x -= 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//플레이어와 만나게 된다면
								Me.PlayN = 99;//life-1
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break;
					case 3://아래 : 움직이려는 좌표에 벽, 하트, 플레이어가 없을 경우 움직임
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) {
							Screen[Mon[i].x][Mon[i].y] = 0;
							Mon[i].x += 1;
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN)//플레이어와 만나게 된다면
								Me.PlayN = 99;//life-1
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
						break;   
					}

				}

			}
			//해당 좌표당 표식
			for (i = 0; i < 18; i++) {
				gotoxy(1, i + 1);
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == 0) {//그냥 맵일 경우
						BLACK;
						printf("★");
					}
					else if (Screen[i][j] == Me.PlayN) {//플레이어
						RED;
						printf("☆");
					}
					else if (Screen[i][j] == 9) {//벽일 경우
						WHITE;
						printf("■");
					}
					else if (Screen[i][j] == Mon[0].PlayN) {//몬스터
						VIO;
						printf("◆");
					}
					else if (Screen[i][j] == Pre[0].PlayN) {//하트
						YEL;
						printf("♡");
					}
				}
				printf("\n");
			}
			if (kbhit()) {
				ch = getch();
				switch (ch) {
				case 75 : //왼쪽
					// 적합한 내용 추가
					if(Screen[Me.x][Me.y-1]!=9){ //이동하는 곳이 벽이 아닐때
						if(Screen[Me.x][Me.y-1]==10){ //몬스터 만나면 99로 변환
							Me.PlayN = 99; //99가 될 경우 life가 하나 깎임
						}
						Screen[Me.x][Me.y] = 0; //현재 위치를 그냥 맵으로 바꾸기
						Me.y--;//플레이어 위치 이동
						Screen[Me.x][Me.y] = Me.PlayN;//이동한 위치를 현재 플레이어로 설정
					}
					break;
				case 77 ://오른쪽
					// 적합한 내용 추가
					if(Screen[Me.x][Me.y+1]!=9){//이동하는 곳이 벽이 아닐때
						if(Screen[Me.x][Me.y+1]==10){//몬스터 만나면 99로 변환
							Me.PlayN = 99; //99가 될 경우 life가 하나 깎임
						}
						Screen[Me.x][Me.y] = 0;//현재 위치를 그냥 맵으로 바꾸기
						Me.y++; //플레이어 위치 이동
						Screen[Me.x][Me.y] = Me.PlayN;//이동한 위치를 현재 플레이어로 설정
					}
					break;
				case 72 ://위쪽
					// 적합한 내용 추가
					if(Screen[Me.x-1][Me.y]!=9){//이동하는 곳이 벽이 아닐때
						if(Screen[Me.x-1][Me.y]==10){//몬스터 만나면 99로 변환
							Me.PlayN = 99; //99가 될 경우 life가 하나 깎임
						}
						Screen[Me.x][Me.y] = 0;//현재 위치를 그냥 맵으로 바꾸기
						Me.x--; //플레이어 위치 이동
						Screen[Me.x][Me.y] = Me.PlayN;//이동한 위치를 현재 플레이어로 설정
					}
					break;
				case 80 ://아래쪽
					// 적합한 내용 추가
					if(Screen[Me.x+1][Me.y]!=9){//이동하는 곳이 벽이 아닐때
						if(Screen[Me.x+1][Me.y]==10){//몬스터 만나면 99로 변환
							Me.PlayN = 99; //99가 될 경우 life가 하나 깎임
						}
						Screen[Me.x][Me.y] = 0;//현재 위치를 그냥 맵으로 바꾸기
						Me.x++; //플레이어 위치 이동
						Screen[Me.x][Me.y] = Me.PlayN;//이동한 위치를 현재 플레이어로 설정
					}
					break;

				case ESC: break;//ESC입력 시 종료
				}
			}
			if (ch == ESC) break;

			LifeN = Life;
			if (Me.PlayN == 99) { //몬스터와 만나서 99일 경우 Life-1
				Life -= 1;
				break;
			}
			for (i = 0; i < 18; i++) {
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == Pre[0].PlayN){//전체 맵에서 하트가 위치할 경우
						PreNum++;//하트 수 체크
					}
				}
			}
			if (PreNum == 0) {//전체 하트 수가 0이고
				if (Me.y == 27) break;//도착하면 클리어
			}
		}
		if (ch == ESC) break;
		if(Life!=0&&Stage!=11){//끝탄이 아니고 라이프가 남아있을 경우
			if(LifeN == Life){
				Stage+=1;//다음 스테이지
				system("cls");
				gotoxy(16,9);
				printf("S t a g e  C l e a r ! !");//클리어
				Sleep(3000);
				system("cls");
			}else{
				gotoxy(19,10);
				printf("G a m e o v e R ! !");//종료
				Sleep(3000);
				system("cls");
				gotoxy(22,9);
				RED;
				printf("☆");
				gotoxy(26,9);
				WHITE;
				printf(" = %d",Life);//현재 남은 라이프의 수
				Sleep(3000);
				system("cls");
				GRAY;
			}
		}
		if(Life==0){//라이프가 0이 되면 게임 오버
			gotoxy(19,9);
			printf("G a M e o V e R ! !");
			Sleep(3000);
			system("cls");
			break;
		}
		else if(Stage == 11){//끝탄까지 갔을 경우 종료
			system("cls");
			WHITE;
			gotoxy(14,9);
			printf("C o n g r a t u l a t i o n");
			Sleep(3000);
			system("cls");
			gotoxy(19,9);
			printf("T h e E n d ! !");
			Sleep(4000);
			GRAY;
			break;
		}
	}
	return 0;

}