#include <stdio.h>
#include <string.h>

void practice1(void);// �ǽ� 1

void homework1(void);// ���� 1

int count_num(int (*ary1)[4], int (*ary2)[4], int (*same_num)[2]);// ���� 2
int assign02(void);// ���� 2
void func(void(*fp)(double *a, double *b),double c, double d);// ���� 2
void exchange(double *a,double *b);// ���� 2

void init_intro(char (*intro)[80], char **intp);// ���� 3
int input_intro(char (*intro)[80]);// ���� 3
void sort_intro(char **intp, int cnt);// ���� 3
void print_intro(int mode, void *vp, int cnt);// ���� 3
int assign03(void);// ���� 3

int main(int argc, const char * argv[]) {

	//�ǽ� 1
	printf("< �ǽ� 1 >\n");
	practice1();

	//���� 1
	printf("< ���� 1 >\n");
	homework1();

	//���� 2
	printf("< ���� 2 >\n");
	assign02();

	//���� 3
	printf("< ���� 3 >\n");
	assign03();
	return 0;

}
//�ǽ� 1
void practice1(void){
	int a = 10, b = 20;
	int *pa = &a, *pb = &b;
	int **ppa = &pa, **ppb = &pb;
	int *pt;


	pt = *ppa;//&pa
	*ppa = *ppb;//&pb
	*ppb = pt;//&pa

	printf("a:%d, b:%d\n",a,b);
	printf("*pd:%d. *pb:%d\n\n",*pa,*pb);

}

//���� 1
void homework1(void){

	int ary1[3][4] = {
		{15, 3, 9, 11},
		{23, 7, 10, 12},
		{0, 17, 55, 24}
	};
	int ary2[3][4] = {
		{13, 8, 9, 15},
		{23, 0, 10, 11},
		{29, 17, 43, 3}
	};
	int same_num[12][2];
	int i, cnt;

	cnt = count_num(ary1, ary2, same_num);
	printf("��ġ�ϴ� ��ȣ�� �� : %d\n", cnt);
	printf("�迭������ ��ġ(��, ��)...\n");

	for(i=0; i < cnt; i++){
		printf("(%d, %d)\n",same_num[i][0],same_num[i][1]);
	}
	printf("\n");
}

//���� 2
int count_num(int (*ary1)[4], int (*ary2)[4], int (*same_num)[2]){
	int i, j;
	int count = 0;
	int index = 0;
	for(i = 0;i < 3;i++){
		for(j = 0;j < 4;j++){
			if(ary1[i][j]==ary2[i][j]){
				count++;
				same_num[index][0] = i;
				same_num[index][1] = j;
				index++;
			}
		}
	}

	return count;
}
int assign02(){
	double a = 10, b= 20;
	func(exchange, a, b);
	return 0;
}
void func(void(*fp)(double *a, double *b),double c, double d){

	printf("[���� ���]\n");
	printf("a:%.lf, b:%.lf\n",c,d);
	fp(&c,&d);
	printf("a:%.lf, b:%.lf\n\n",c,d);

}
void exchange(double *a,double *b){
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//���� 3
int assign03(){
	char intro[10][80];
	char *intp[10];
	int cnt;

	init_intro(intro, intp);
	cnt = input_intro(intro);
	sort_intro(intp, cnt);
	print_intro(1, intp, cnt);
	print_intro(0, intro, cnt);

	return 0;
}
int input_intro(char (*intro)[80]){
	char tempString[80];
	int i;
	int index = 0;

	while(1){
		printf(">���� �Է� : ");
		scanf("%s", tempString);
		if(strcmp(tempString,"end")==0){ //end�� �Է��� ���
			break;//����
		}
		strcpy(intro[index],tempString);//��ü ���ڿ��� �ֱ�
		index++;//�ε��� ����
	}

	return index;
}

void init_intro(char (*intro)[80], char **intp){
	int i;

	for(i=0;i<10;i++){
		intp[i]= intro[i];
	}

}

void sort_intro(char **intp, int cnt){
	int i,j;
	char *temp = intp[0]; //�ʱ�ȭ���ϸ� ������ �ʱ�ȭ

	for (i=0;i<cnt;i++)
	{
		for (j=0;j<cnt-i;j++)
		{
			if (strcmp(intp[j], intp[j + 1]) > 0) //strcmp�� ����Ͽ� ���ڿ� ��
			{ //������ 0 ������ ũ�� 1 ������ ũ�� -1
				temp = intp[j];
				intp[j] = intp[j + 1];
				intp[j + 1] = temp;
			}
		}
	}

}


void print_intro(int mode, void *vp, int cnt){
	int i;

	printf("\n");
	if(mode==1){
		printf("���������� ���...\n");
		for(i=0;i<cnt;i++){
			printf("%s\n",*((char**)vp+i));
		}
	}
	else{
		//intro = (char*)vp;
		printf("�Է¼����� ���...\n");
		for(i=0;i<cnt;i++){
			printf("%s\n",((char *)vp)+80*i);
		}
	}
	printf("\n");
}