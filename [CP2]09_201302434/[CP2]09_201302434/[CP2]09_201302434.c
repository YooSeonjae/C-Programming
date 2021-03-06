#include <stdio.h>

//함수선언
void practice1(double calTime); //실습 1
void homework1(int distance, int speed); //과제 1
int disp_menu(void); //과제 2
void enter_park(int (*park_space)[2][5], int (*reserved)[3]); //과제 2
int find_space(int (*park_space)[2][5], int (*reserved)[3]);//과제 2
void print_basement(int (*park_space)[2][5], int floor, int (*reserved)[3]);//과제 2
void exit_park(int (*park_space)[2][5]); //과제 2
void reserve_park(int (*reserved)[3]);//과제 2
int check_reservation(int (*reserved)[3], int basement, int num);//과제 2
int check_reserved_num(int (*reserved)[3], int car_num, int*floor, int *resv_num);//과제 2
void print_park(int (*park_space)[2][5], int (*reserved)[3]);//과제 2

int main(){
	//변수 선언
	double calTime;//실습 1
	int distance, speed; //과제 1
	int park_space[3][2][5]={0}; //과제 2
	int reserved[10][3]={0}; //과제 2
	int type;//과제 2

	//실습1
	printf("<실습 1>\n");
	scanf("%lf",&calTime);
	practice1(calTime);


	//과제1
	printf("<과제 1>\n");
	printf("거리와 속력 입력 : ");
	scanf("%d",&distance); //거리 입력
	scanf("%d",&speed); //속력 입력
	homework1(distance, speed);  //시간 구하기

	//과제 2
	printf("<과제 2>\n");
	while(1){
		type = disp_menu(); //메뉴를 출력하고 선택한 메뉴 반환

		if(type==1){// 주차 기능
			enter_park(park_space , reserved);
		}
		else if(type==2){ // 출차 기능
			exit_park(park_space);
		}
		else if(type==3){ // 지정차량 등록
			reserve_park(reserved);
		}
		else if(type==4){ // 주차 현황 출력
			print_park(park_space , reserved);
		}
		else if(type==0){ //종료
			printf("프로그램을 종료합니다.\n\n");
			return 0;
		}
		else{ //잘못 입력할 경우
			printf("잘못 입력하셨습니다.\n");
			printf("다시 입력하세요.\n\n");
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
void homework1(int distance, int speed){
	int hours, minutes;
	double time, seconds;

	time = (double)distance/(double)speed;//전체 시간 구하기
	hours = (int)time; //시간 구하기
	time -= hours;
	time *= 60.0;
	minutes = (int)time; //분 구하기
	time -= minutes;
	time *= 60.0;
	seconds = time; //초 구하기
	printf("소요시간은 %d시간 %d분 %.3lf초입니다. \n\n",hours,minutes,seconds);//출력

}

//과제 2
int disp_menu(void){
	int type;

	printf("1. 주차\n2. 출차\n3. 지정차량 등록\n4. 주차현황 출력\n0. 종료\n"); //메뉴 출력
	printf("> 번호 선택 : ");//메뉴 선택
	scanf("%d",&type);
	printf("\n");
	return type;//선택한 메뉴 반환
}

void enter_park(int (*park_space)[2][5], int (*reserved)[3]){
	int carNum;//차량 번호
	int i,j,k,a;
	int check = 0;//중복 차량 체크
	int num;//층수 넘기기
	int *floorP; //지정차량 층
	int floor=0; //지정차량 층
	int *resv_numP; //지정차량 번호
	int resv_num=0; //지정차량 번호

	//포인터로 연결
	floorP =&floor;
	resv_numP=&resv_num;

	printf("> 차번 입력(숫자 4자리) : "); //차번호 입력
	scanf("%d",&carNum);

	for(i = 0;i < 3;i++){
		for(j = 0;j < 2;j++){
			for(k = 0;k < 5;k++){
				if(park_space[i][j][k]==carNum){
					check++; //이미 등록된 차번호가 있는지 확인
				}
			}
		}
	}
	if(check!=0){ //이미 있을 경우
		printf("@ 해당 번호 차량이 이미 존재합니다.\n\n");
	}else{
		a=check_reserved_num(reserved,carNum,floorP,resv_numP); //입력 차량이 지정차량인 경우
		if(a==1){
			printf("@ 지정차량 : %d층 %d번 주차했습니다.\n\n",*floorP,*resv_numP);
			park_space[*floorP-1][(*resv_numP-1)/5][(*resv_numP-1)%5]=carNum;
			return;
		}
		find_space(park_space,reserved);// 빈 공간이 얼마 있는지 확인

		i=0;
		j=0;
		while(1){
			print_basement(park_space,i,reserved); //한 층만 출력
			printf("> 주차 번호 입력(다른층 0, 취소 -1) : ");
			scanf("%d",&num);
			printf("\n");
			if(num==0){//다음 층을 볼 경우
				if(j!=0){//3층에서 1층으로 내려갈때
					i--;
					if(i==0){
						j=0;
					}
				}else{//1층에서 3층으로 올라갈 때
					i++;
					if(i==2){
						j++;
					}
				}
				continue;
			}else if(num==-1){ //취소
				printf("@ 취소되었습니다!\n\n");
				break;
			}else if(num>0||num<11){ //주차 번호 입력한 경우
				if(num<6){
					park_space[i][0][num-1] = carNum;
				}
				else{
					park_space[i][1][num-6] = carNum;
				}
				printf("@ 주차되었습니다!\n\n");
				break;
			}

		}
	}
}

int find_space(int (*park_space)[2][5], int (*reserved)[3]){
	int i,j,k;
	int freeSpace[3]={0};//주차공간

	for(i = 0;i < 3;i++){
		for(j = 0;j < 2;j++){
			for(k = 0;k < 5;k++){
				if(i==0 && park_space[i][j][k]==0){//1층 주차 공간
					if(reserved[(j*5)+k][i]==0){
						freeSpace[0]++;
					}
				}else if(i==1 && park_space[i][j][k]==0){//2층 주차 공간
					if(reserved[(j*5)+k][i]==0){
						freeSpace[1]++;
					}
				}else if(i==2 && park_space[i][j][k]==0){//3층 주차 공간
					if(reserved[(j*5)+k][i]==0){
						freeSpace[2]++;
					}
				}
			}
		}
	}

	printf("@ 주차 가능 공간 :  1층[%d대]  2층[%d대]  3층[%d대]\n\n",freeSpace[0],freeSpace[1],freeSpace[2]);
	return 0;
}
void print_basement(int (*park_space)[2][5], int floor, int (*reserved)[3]){
	int i,j;

	printf("[ %d층 ]===========================\n",floor+1);//층수 출력
	for(i=0;i<2;i++){
		for(j=0;j<5;j++){
			if(park_space[floor][i][j]==0){// 비어있을 경우
				if(reserved[(i*5)+j][floor]!=0){
					printf("[resv] ");
					continue;
				}

				if(i==0){ //1~5
					printf("[%4d] ",j+1);
				}
				else{ //6~10
					printf("[%4d] ",j+6);
				}
			}
			else{//주차 된 경우
				printf("[%4d] ",park_space[floor][i][j]); //번호 출력
			}
		}
		printf("\n");
	}
	printf("\n");

}

void exit_park(int (*park_space)[2][5]){ //출차 기능
	int i,j,k;
	int carNum;
	int check=0;

	printf("> 차번 입력(숫자 4자리) : "); //차량 번호 입력
	scanf("%d",&carNum);

	for(i = 0;i < 3;i++){
		for(j = 0;j < 2;j++){
			for(k = 0;k < 5;k++){
				if(park_space[i][j][k]==carNum){ //등록된 차가 있을 경우
					check++;
					park_space[i][j][k]=0; //출차
				}
			}
		}
	}

	if(check==0){ // 입력 번호 차량이 없을 경우
		printf("@ 해당 차량이 없습니다.\n\n");
	}else{
		printf("@ 출차되었습니다.\n\n");
	}
}
void reserve_park(int (*reserved)[3]){//지정 차량 등록
	int floor;
	int parkingNum;
	int carNum;
	int check;

	while(1){
		printf("> 층과 번호 입력(종료 0) : "); //층과 주차장 번호 입력
		scanf("%d",&floor);
		if(floor==0){ //0입력 시 종료
			return;
		}
		scanf("%d",&parkingNum);
		check = check_reservation(reserved, floor, parkingNum);//지정차량이 있는지 확인

		if(check==1){
			printf("> 입력하신 층과 번호에 지정 차량이 존재합니다.\n\n");
			continue;
		}
		printf("> 등록차량 번호 입력 : "); //차량 번호 입력
		scanf("%d",&carNum);
		reserved[parkingNum-1][floor-1]=carNum; //주차
		printf("@ 등록되었습니다.\n\n");
	}

}
int check_reservation(int (*reserved)[3], int basement, int num){

	if(reserved[num-1][basement-1]!=0){//지정차량이 있을 경우
		return 1;
	}else{
		return 0;
	}

}
int check_reserved_num(int (*reserved)[3], int car_num, int*floor, int *resv_num){//입력 차량이 지정 차량인지 확인
	int i, j;
	int check=0;
	for(i=0;i<10;i++){
		for(j=0;j<3;j++){
			if(reserved[i][j]==car_num){//지정차량일 경우
				*floor = j+1;//층수 저장
				*resv_num = i+1;//번호 저장
				check++;
			}
		}
	}
	if(check!=0){//지정차량일 경우
		return 1;
	}else{
		return 0;
	}
}
void print_park(int (*park_space)[2][5], int (*reserved)[3]){//주차 현황 출력
	int i, j, k;

	for(i = 0;i < 3;i++){
		printf("[ %d층 ]===========================\n",i+1); //층 수
		for(j=0;j < 2;j++){
			for(k=0;k<5;k++){
				if(park_space[i][j][k]==0){// 비어있을 경우
					if(reserved[(j*5)+k][i]!=0){
						printf("[resv] ");
						continue;
					}
					if(j==0){ //1~5
						printf("[%4d] ",k+1);
					}
					else{ //6~10
						printf("[%4d] ",k+6);
					}
				}
				else{ //비어 있지 않을 경우
					printf("[%4d] ",park_space[i][j][k]);//차량번호 출력
				}
			}
			printf("\n");
		}
		printf("\n");
	}

}