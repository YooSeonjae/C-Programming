#include <stdio.h>

//함수선언
void practice1(double calTime); //실습 1
void homework1(double distance, double speed); //과제 1
int disp_menu(void); //과제 2
void enter_park(int (*park_space)[2][5], int (*reserved)[3]); //과제 2

int main(){
	//변수 선언
	double calTime;//실습 1
	int distance, speed; //과제 1
	int park_space[3][2][5]; //과제 2
	int type;

	//실습1
	printf("<과제 1>\n");
	scanf("%lf",&calTime);
	practice1(calTime);


	//과제1
	printf("<과제 1>\n");
	printf("거리와 속력 입력 : ");
	scanf("%d",&distance);
	scanf("%d",&speed);
	homework1(distance, speed);

	//과제 2
	printf("<과제 2>\n");
	while(1){
		type = disp_menu(); //메뉴를 출력하고 선택한 메뉴 반환

		if(type==1){
			enter_park(park_space , int (*reserved)[3]);
		}
		else if(type==2){

		}
		else if(type==3){

		}
		else if(type==4){

		}
		else if(type==0){
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
		else{

		}
	}
}

//함수 정의
//실습 1
void practice1(double calTime){
	int hour, min, sec;
	double getTime;

	getTime = calTime;

	hour = (int)calTime;
	calTime -= hour;
	calTime *= 60.0;
	min = (int)calTime;
	calTime -= min;
	calTime *= 60.0;
	sec = (int)calTime;
	printf("%.2lf시간은 %d시간 %d분 %d초입니다. \n\n",getTime,hour,min,sec);

}

//과제 1
void homework1(double distance, double speed){
	int hours, minutes;
	double time, seconds;

	time = (double)distance/(double)speed;
	hours = (int)time;
	time -= hours;
	time *= 60.0;
	minutes = (int)time;
	time -= minutes;
	time *= 60.0;
	seconds = time;
	printf("소요시간은 %d시간 %d분 %.3lf초입니다. \n\n",hours,minutes,seconds);

}

//과제 2
int disp_menu(void){
	int type;

	printf("1. 주차\n2. 출차\n3. 지정차량 등록\n4. 주차현황 출력\n0. 종료\n");
	printf("> 번호 선택 : ");
	scanf("%d",&type);

	return type;
}

void enter_park(int (*park_space)[2][5], int (*reserved)[3]){
	int carNum;

	printf("> 차번 입력(숫자 4자리) : ");
	scanf("%d",&carNum);
}