#include <stdio.h>

//�Լ�����
void practice1(double calTime); //�ǽ� 1
void homework1(double distance, double speed); //���� 1
int disp_menu(void); //���� 2
void enter_park(int (*park_space)[2][5], int (*reserved)[3]); //���� 2

int main(){
	//���� ����
	double calTime;//�ǽ� 1
	int distance, speed; //���� 1
	int park_space[3][2][5]; //���� 2
	int type;

	//�ǽ�1
	printf("<���� 1>\n");
	scanf("%lf",&calTime);
	practice1(calTime);


	//����1
	printf("<���� 1>\n");
	printf("�Ÿ��� �ӷ� �Է� : ");
	scanf("%d",&distance);
	scanf("%d",&speed);
	homework1(distance, speed);

	//���� 2
	printf("<���� 2>\n");
	while(1){
		type = disp_menu(); //�޴��� ����ϰ� ������ �޴� ��ȯ

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
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		else{

		}
	}
}

//�Լ� ����
//�ǽ� 1
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
	printf("%.2lf�ð��� %d�ð� %d�� %d���Դϴ�. \n\n",getTime,hour,min,sec);

}

//���� 1
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
	printf("�ҿ�ð��� %d�ð� %d�� %.3lf���Դϴ�. \n\n",hours,minutes,seconds);

}

//���� 2
int disp_menu(void){
	int type;

	printf("1. ����\n2. ����\n3. �������� ���\n4. ������Ȳ ���\n0. ����\n");
	printf("> ��ȣ ���� : ");
	scanf("%d",&type);

	return type;
}

void enter_park(int (*park_space)[2][5], int (*reserved)[3]){
	int carNum;

	printf("> ���� �Է�(���� 4�ڸ�) : ");
	scanf("%d",&carNum);
}