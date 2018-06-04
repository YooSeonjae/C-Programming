#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker {
	int price;
	int calories;
};
typedef struct Student {
	int studentNum;//�й�
	char name[20];//�̸�
	int englishScore;//����
	int koreanScore;//����
	int mathScore;//����
	int totalScore;//����
	double averageScore;//���
	char grade;//����
}Student;

void practice1();
void practice2();
void homework1();
void homework2();
int dup_check(char **sp, char *temp, int cnt);
void input_data(Student *pary, int inputSize);
void calc_data(Student *pary, int inputSize);
void sort_data(Student *pary, int inputSize);
void print_data(Student *pary, int inputSize);

int main(void){

	//�ǽ�1
	printf("< �ǽ� 1 >\n");
	practice1();

	//�ǽ�2
	printf("< �ǽ� 2 >\n");
	practice2();
	fflush(stdin);

	//����1
	printf("< ���� 1 >\n");
	homework1();

	//����2
	printf("< ���� 2 >\n");
	homework2();


	return 0;
}

void practice1(){ //��͵� �ּ��ޱ�
	char temp[32];
	char *ps, *pt;
	int len = 1;
	ps = (char *)calloc(1,1); //1byte 1�� �迭 

	while(1){
		printf("�޸��Է� : ");
		fgets(temp, sizeof(temp), stdin);
		temp[strlen(temp) - 1] = '\0';
		if(strcmp(temp,"end") == 0) break;
		len += strlen(temp) + 1;
		pt = (char*)realloc(ps, len); //ps�� ũ�⸦ len���� �ٲٰ� pt�� ����
		if(pt == NULL){
			printf("�޸� ����....\n");
			break;
		}
		ps = pt;
		strcat(ps, temp);
		strcat(ps, " ");
	}
	printf("%s\n", ps);
	free(ps);

	return;
}

void practice2(){
	struct cracker basasak;
	printf("�ٻ���� ���ݰ� ������ �Է��ϼ��� : ");
	scanf("%d %d", &basasak.price, &basasak.calories);
	printf("�ٻ���� ���� : %d��\n", basasak.price);
	printf("�ٻ���� ���� : %dkcal\n\n", basasak.calories);

	return ;
}

void homework1(){
	char * sp[100];
	char temp[100];
	int cnt = 0;
	int check = 0;
	char checkWord;
	int i;

	while(1){
		printf("�ܾ��Է� : ");
		fgets(temp, sizeof(temp), stdin);
		temp[strlen(temp) - 1] = '\0';
		if(strcmp(temp,"end") == 0){
			break;
		}
		check = dup_check(sp, temp, cnt);
		if(check == 1){
			printf("> �̹� �����ϴ� �ܾ��Դϴ�!\n");
			continue;
		}
		//printf("%c\n",checkWord);
		//printf("%c\n",temp[0]);
		if(cnt>0){
			if(checkWord!=temp[0]){
				printf("> �ܾ� �ձⰡ �Ұ����մϴ�!\n");
				continue;
			}
		}
		sp[cnt] = (char *)malloc(strlen(temp)+1);// ���ڿ��� ���̸� ����Ͽ� ũ�⿡ �°� �������� �����Ҵ�
		if(sp[cnt] == NULL){
			printf("�޸� ����....\n");
			break;
		}
	
		strcpy(sp[cnt], temp);// ���ڿ��� ����
		checkWord = temp[strlen(temp)-1];
		cnt++;
	}

	for(i=0;i<cnt;i++){
		printf("%s ",sp[i]);
	}

	for(i=0;i<cnt;i++){
		free(sp[i]);
	}

	printf("\n\n");
	return;
}

int dup_check(char **sp, char *temp, int cnt){
	int i;
	for(i=0;i<cnt;i++){
		if(strcmp(sp[i],temp) == 0){
			return 1;
		}
	}
	return 0;
}

void homework2(){
	int inputSize;
	Student pary[100];

	printf(">�л��� �Է� : ");
	scanf("%d",&inputSize);
	
	input_data(pary, inputSize);
	calc_data(pary, inputSize);
	printf("���� �� ������...\n");
	print_data(pary, inputSize);
	sort_data(pary, inputSize);
	printf("#���� �� ������...\n");
	print_data(pary, inputSize);

}
void input_data(Student *pary, int inputSize){
	int i;

	for(i=0;i<inputSize;i++){
		printf(">�й� : ");
		scanf("%d",&pary[i].studentNum);
		printf(">�̸� : ");
		scanf("%s",&pary[i].name);
		printf(">����, ����, ���� ���� : ");
		scanf("%d",&pary[i].koreanScore);
		scanf("%d",&pary[i].englishScore);
		scanf("%d",&pary[i].mathScore);		
	}
}

void calc_data(Student *pary, int inputSize){
	int i;

	for(i=0;i<inputSize;i++){
		pary[i].totalScore = pary[i].koreanScore + pary[i].englishScore + pary[i].mathScore;
		pary[i].averageScore = ((double)pary[i].totalScore)/3;
		if(pary[i].averageScore>=90){
			pary[i].grade = 'A';
		}
		else if(pary[i].averageScore>=80){
			pary[i].grade = 'B';
		}
		else if(pary[i].averageScore>=70){
			pary[i].grade = 'C';
		}
		else{
			pary[i].grade = 'F';
		}
	}
}
void sort_data(Student *pary, int inputSize){
	int i;
	int j;
	Student temp;

	for(i=0;i<inputSize;i++){
		for(j=i+1;j<inputSize;j++){
			if(pary[i].totalScore < pary[j].totalScore){
				temp = pary[i];
				pary[i] = pary[j];
				pary[j] = temp;
			}
		}
	}

}
void print_data(Student *pary, int inputSize){
	int i;

	printf("\n");
	for(i=0;i<inputSize;i++){
		printf("%3d %s %3d %3d %3d %3d %0.1lf %c\n",pary[i].studentNum, pary[i].name, pary[i].koreanScore, pary[i].englishScore, pary[i].mathScore, pary[i].totalScore, pary[i].averageScore, pary[i].grade);
	}
	
}