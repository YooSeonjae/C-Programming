#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker {
	int price;
	int calories;
};
typedef struct Student {
	int studentNum;//학번
	char name[20];//이름
	int englishScore;//영어
	int koreanScore;//국어
	int mathScore;//수학
	int totalScore;//총점
	double averageScore;//평균
	char grade;//학점
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

	//실습1
	printf("< 실습 1 >\n");
	practice1();

	//실습2
	printf("< 실습 2 >\n");
	practice2();
	fflush(stdin);

	//과제1
	printf("< 과제 1 >\n");
	homework1();

	//과제2
	printf("< 과제 2 >\n");
	homework2();


	return 0;
}

void practice1(){ //요것도 주석달기
	char temp[32];
	char *ps, *pt;
	int len = 1;
	ps = (char *)calloc(1,1); //1byte 1개 배열 

	while(1){
		printf("메모입력 : ");
		fgets(temp, sizeof(temp), stdin);
		temp[strlen(temp) - 1] = '\0';
		if(strcmp(temp,"end") == 0) break;
		len += strlen(temp) + 1;
		pt = (char*)realloc(ps, len); //ps의 크기를 len으로 바꾸고 pt로 복사
		if(pt == NULL){
			printf("메모리 부족....\n");
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
	printf("바사삭의 가격과 열량을 입력하세요 : ");
	scanf("%d %d", &basasak.price, &basasak.calories);
	printf("바사삭의 가격 : %d원\n", basasak.price);
	printf("바사삭의 열량 : %dkcal\n\n", basasak.calories);

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
		printf("단어입력 : ");
		fgets(temp, sizeof(temp), stdin);
		temp[strlen(temp) - 1] = '\0';
		if(strcmp(temp,"end") == 0){
			break;
		}
		check = dup_check(sp, temp, cnt);
		if(check == 1){
			printf("> 이미 존재하는 단어입니다!\n");
			continue;
		}
		//printf("%c\n",checkWord);
		//printf("%c\n",temp[0]);
		if(cnt>0){
			if(checkWord!=temp[0]){
				printf("> 단어 잇기가 불가능합니다!\n");
				continue;
			}
		}
		sp[cnt] = (char *)malloc(strlen(temp)+1);// 문자열의 길이를 계산하여 크기에 맞게 기억공간을 동적할당
		if(sp[cnt] == NULL){
			printf("메모리 부족....\n");
			break;
		}
	
		strcpy(sp[cnt], temp);// 문자열을 복사
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

	printf(">학생수 입력 : ");
	scanf("%d",&inputSize);
	
	input_data(pary, inputSize);
	calc_data(pary, inputSize);
	printf("정렬 전 데이터...\n");
	print_data(pary, inputSize);
	sort_data(pary, inputSize);
	printf("#정렬 후 데이터...\n");
	print_data(pary, inputSize);

}
void input_data(Student *pary, int inputSize){
	int i;

	for(i=0;i<inputSize;i++){
		printf(">학번 : ");
		scanf("%d",&pary[i].studentNum);
		printf(">이름 : ");
		scanf("%s",&pary[i].name);
		printf(">국어, 영어, 수학 점수 : ");
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