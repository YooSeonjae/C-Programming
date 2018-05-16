#include <stdio.h>

//�Լ�����
void practice1(double calTime); //�ǽ� 1
void homework1(double distance, double speed); //���� 1
int disp_menu(void); //���� 2
void enter_park(int (*park_space)[2][5], int (*reserved)[3]); //���� 2
int find_space(int (*park_space)[2][5], int (*reserved)[3]);//���� 2
void print_basement(int (*park_space)[2][5], int floor, int (*reserved)[3]);//���� 2
void exit_park(int (*park_space)[2][5]); //���� 2
void print_park(int (*park_space)[2][5], int (*reserved)[3]);//���� 2
int check_reservation(int (*reserved)[3], int basement, int num);//���� 2 -3������ ���µ�

int main(){
	//���� ����
	double calTime;//�ǽ� 1
	int distance, speed; //���� 1
	int park_space[3][2][5]={0}; //���� 2
	int reserved[10][3]={0}; //���� 2
	int type;//���� 2

	//�ǽ�1
	printf("<���� 1>\n");
	scanf("%lf",&calTime);
	practice1(calTime);


	//����1
	printf("<���� 1>\n");
	printf("�Ÿ��� �ӷ� �Է� : ");
	scanf("%d",&distance); //�Ÿ� �Է�
	scanf("%d",&speed); //�ӷ� �Է�
	homework1(distance, speed);  //�ð� ���ϱ�

	//���� 2
	printf("<���� 2>\n");
	while(1){
		type = disp_menu(); //�޴��� ����ϰ� ������ �޴� ��ȯ

		if(type==1){// ���� ���
			enter_park(park_space , reserved);
		}
		else if(type==2){ // ���� ���
			exit_park(park_space);
		}
		else if(type==3){ // �������� ���

		}
		else if(type==4){ // ���� ��Ȳ ���
			print_park(park_space , reserved);
		}
		else if(type==0){ //����
			printf("���α׷��� �����մϴ�.\n\n");
			return 0;
		}
		else{ //�߸� �Է��� ���
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			printf("�ٽ� �Է��ϼ���.\n\n");
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

	time = (double)distance/(double)speed;//��ü �ð� ���ϱ�
	hours = (int)time; //�ð� ���ϱ�
	time -= hours;
	time *= 60.0;
	minutes = (int)time; //�� ���ϱ�
	time -= minutes;
	time *= 60.0;
	seconds = time; //�� ���ϱ�
	printf("�ҿ�ð��� %d�ð� %d�� %.3lf���Դϴ�. \n\n",hours,minutes,seconds);//���

}

//���� 2
int disp_menu(void){
	int type;

	printf("1. ����\n2. ����\n3. �������� ���\n4. ������Ȳ ���\n0. ����\n"); //�޴� ���
	printf("> ��ȣ ���� : ");//�޴� ����
	scanf("%d",&type);
	printf("\n");
	return type;//������ �޴� ��ȯ
}

void enter_park(int (*park_space)[2][5], int (*reserved)[3]){
	int carNum;//���� ��ȣ
	int i,j,k;
	int check = 0;//�ߺ� ���� üũ
	int num;//���� �ѱ��

	printf("> ���� �Է�(���� 4�ڸ�) : ");
	scanf("%d",&carNum);

	for(i = 0;i < 3;i++){
		for(j = 0;j < 2;j++){
			for(k = 0;k < 5;k++){
				if(park_space[i][j][k]==carNum){
					check++; //�̹� ��ϵ� ����ȣ�� �ִ��� Ȯ��
				}
			}
		}
	}

	if(check!=0){ //�̹� ���� ���
		printf("@ �ش� ��ȣ ������ �̹� �����մϴ�.\n\n");
	}else{

		find_space(park_space,reserved);// �� ������ �� �ִ��� Ȯ��

		i=0;
		j=0;
		while(1){
			print_basement(park_space,i,reserved);
			printf("> ���� ��ȣ �Է�(�ٸ��� 0, ��� -1) : ");
			scanf("%d",&num);
			printf("\n");
			if(num==0){//���� ���� �� ���
				if(j!=0){//3������ 1������ ��������
					i--;
					if(i==0){
						j=0;
					}
				}else{//1������ 3������ �ö� ��
					i++;
					if(i==2){
						j++;
					}
				}
				continue;
			}else if(num==-1){ //���
				printf("@ ��ҵǾ����ϴ�!\n\n");
				break;
			}else if(num>0||num<11){ //���� ��ȣ �Է��� ���
				if(num<6){
					park_space[i][0][num-1] = carNum;
				}
				else{
					park_space[i][1][num-6] = carNum;
				}
				printf("@ �����Ǿ����ϴ�!\n\n");
				break;
			}

		}
	}
}

int find_space(int (*park_space)[2][5], int floor, int (*reserved)[3]){
	int i,j,k;
	int freeSpace[3]={0};

	for(i = 0;i < 3;i++){
		for(j = 0;j < 2;j++){
			for(k = 0;k < 5;k++){
				if(i==0 && park_space[i][j][k]==0){//1�� ���� ����
					freeSpace[0]++;
				}else if(i==1 && park_space[i][j][k]==0){//2�� ���� ����
					freeSpace[1]++;
				}else if(i==2 && park_space[i][j][k]==0){//3�� ���� ����
					freeSpace[2]++;
				}
			}
		}
	}

	printf("@ ���� ���� ���� :  1��[%d��]  2��[%d��]  3��[%d��]\n\n",freeSpace[0],freeSpace[1],freeSpace[2]);
}
void print_basement(int (*park_space)[2][5], int floor, int (*reserved)[3]){
	int i,j;

	printf("[ %d�� ]===========================\n",floor+1);//���� ���
	for(i=0;i<2;i++){
		for(j=0;j<5;j++){
			if(park_space[floor][i][j]==0){// ������� ���
				if(i==0){ //1~5
					printf("[%4d] ",j+1);
				}
				else{ //6~10
					printf("[%4d] ",j+6);
				}
			}
			else{//���� �� ���
				printf("[%4d] ",park_space[floor][i][j]); //��ȣ ���
			}
		}
		printf("\n");
	}
	printf("\n");

}

void exit_park(int (*park_space)[2][5]){ //���� ���
	int i,j,k;
	int carNum;
	int check=0;

	printf("> ���� �Է�(���� 4�ڸ�) : "); //���� ��ȣ �Է�
	scanf("%d",&carNum);

	for(i = 0;i < 3;i++){
		for(j = 0;j < 2;j++){
			for(k = 0;k < 5;k++){
				if(park_space[i][j][k]==carNum){ //��ϵ� ���� ���� ���
					check++;
					park_space[i][j][k]=0; //����
				}
			}
		}
	}

	if(check==0){ // �Է� ��ȣ ������ ���� ���
		printf("@ �ش� ������ �����ϴ�.\n\n");
	}else{
		printf("@ �����Ǿ����ϴ�.\n\n");
	}
}

void print_park(int (*park_space)[2][5], int (*reserved)[3]){//���� ��Ȳ ���
	int i, j, k;

	for(i = 0;i < 3;i++){
		printf("[ %d�� ]===========================\n",i+1); //�� ��
		for(j=0;j < 2;j++){
			for(k=0;k<5;k++){
				if(park_space[i][j][k]==0){// ������� ���
					if(j==0){ //1~5
						printf("[%4d] ",k+1);
					}
					else{ //6~10
						printf("[%4d] ",k+6);
					}
				}
				else{ //��� ���� ���� ���
					printf("[%4d] ",park_space[i][j][k]);//������ȣ ���
				}
			}
			printf("\n");
		}
		printf("\n");
	}

}