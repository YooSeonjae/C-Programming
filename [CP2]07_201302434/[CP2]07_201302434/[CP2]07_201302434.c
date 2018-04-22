#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//선언
void inputScore(int *scoreArray, int inputIndex);//실습2
void printScore(int *scoreArray,int index);//실습2
int printSum(int *scoreArray, int inputIndex);//과제1
int printAvg(int *scoreArray,int inputIndex);//과제1
void invertedOutput(char str[]);//과제2
int* makeArray(int *intArray, int inputSize);//과제3
void swap(int * x, int * y);//과제3
void sortArray(int *intArray, int inputSize);//과제3

int main(void){

	// 변수
	int array[3][3];//실습 1
	int rowIndex, colIndex;//실습 1
	int scoreArray[20][3];//실습 2,  과제 1
	int inputStudentSize;//실습 2,  과제 1
	int studentIndex;//실습 2,  과제 1
	char stringArray[100];//과제 2
	int num;//과제 3
	int array2[20];//과제 3

	//실습 1
	for(rowIndex=0;rowIndex<3;rowIndex++){
		for(colIndex=0;colIndex<3;colIndex++){
			scanf("%d",&array[rowIndex][colIndex]);
		}
	}
	printf("\n");
	for(rowIndex=0;rowIndex<3;rowIndex++){
		for(colIndex=0;colIndex<3;colIndex++){
			printf("%d",array[rowIndex][colIndex]);
		}
		printf("\n");
	}
	printf("\n");
	
	//실습 2
	printf("입력 받을 학생수를 입력하세요 : ");
	scanf("%d", &inputStudentSize);

	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){
		inputScore((int*)&(scoreArray[studentIndex]),inputStudentSize);
	}
	printf("\n");
	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){
		printScore((int*)&(scoreArray[studentIndex]),studentIndex);
	}
	//과제 1
	printf("\n");
	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){//학생 수만큼
		printSum((int*)&(scoreArray[studentIndex]),studentIndex); //printSum함수 실행
	}
	printf("\n");
	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){//학생 수만큼
		printAvg((int*)&(scoreArray[studentIndex]),studentIndex);//printAvg함수 실행
	}
	printf("\n");
	getchar();
	//scanf함수를 사용할 때 값을 입력한뒤 enter를 누르게 되는데 값은 넘어가고
	//개행문자는 입력버퍼에 남아있게되어 다음에 gets 함수를 사용하는데 버퍼에
	//남아있는 개행문자를 꺼내오게된다. 그리고 이 개행문자를'사용자 입력의 끝'
	//으로 인식하기 때문에 gets 함수가 동작하지 않고 넘어가게 되는 것이다.
	//따라서 getchar()사용

	//과제 2
	printf("\n한 줄을 입력하세요. >>\n");
	gets(stringArray);//문자열 입력
	printf("\n위에서 입력한 문자열을 거꾸로 출력합니다.\n");
	invertedOutput(stringArray);//invertedOutput()함수실행
	
	//과제 3
	printf("\nSize가 20인 배열에 넣을 데이터의 수 입력 : "); 
	scanf("%d",&num); //몇개의 데이터를 넣을지 입력
	makeArray(array2, num); //배열 안에 랜덤한 수를 num개 넣음
	printf("오름차순으로 정렬(선택정렬)\n");
	sortArray(array2, num); //배열 안에 랜덤한 수를 오름차순으로 정렬
	return 0;
}

//함수정의
//실습 2
void inputScore(int *scoreArray, int inputIndex){
	printf("\n국어 성적 입력 : ");
	scanf("%d", &scoreArray[0]);
	printf("영어 성적 입력 : ");
	scanf("%d", &scoreArray[1]);
	printf("수학 성적 입력 : ");
	scanf("%d", &scoreArray[2]);
}
void printScore(int *scoreArray,int index){
	printf("[%d] %d, %d, %d\n", index, scoreArray[0], scoreArray[1], scoreArray[2]);
}

//과제 1
int printSum(int *scoreArray, int inputIndex){//한 배열의 합을 구해서 출력.
	printf("[%d] 총점 : %d\n", inputIndex, scoreArray[0]+scoreArray[1]+scoreArray[2]);
	return 0;
}
int printAvg(int *scoreArray,int inputIndex){//한 배열의 합을 구해서 3으로 나눠 평균을 출력.
	printf("[%d] 평균 : %d\n", inputIndex, (scoreArray[0]+scoreArray[1]+scoreArray[2])/3);
	return 0;
}

//과제 2
void invertedOutput(char str[]){//문자열을 strrev()함수를 이용해서 거꾸로 출력.
	puts(strrev(str));
}

//과제 3
int* makeArray(int *intArray, int inputSize){
	int i;
	srand((unsigned int)time((time_t*)NULL)); //랜덤함수

	for(i = 0;i<inputSize;i++){
		intArray[i]=rand()%1000;//배열에 랜덤 데이터 저장
		printf("%d ", intArray[i]);//배열 값 출력
	}
	printf("\n\n");
	return 0;
}
void swap(int *x, int *y){ //값을 변경시켜주는 함수
	int temp = 0;
	 
	temp = *x;//임시 저장할 곳에 x값 저장 
	//printf("temp->%d\n",temp);
	*x = *y;//x에 y값 저장
	*y = temp;//y에 임시로 저장해놓은 x값 저장
	//printf("y->%d\n",temp);
}
void sortArray(int *intArray, int inputSize){
	int i,j;
	int minNumIndex;//최소 값을 가지고 있는 인덱스

	for(i=0;i<inputSize;i++){//처음부터 끝까지 정렬
		minNumIndex=i;
		for(j=i+1;j<inputSize;j++){//해당 자리 다음부터 조사
			if(intArray[minNumIndex]>intArray[j]){//가장 작은값 찾기
				minNumIndex = j;//가장 값이 작은 인덱스 저장
				//printf("작은 인덱스->%d\n",j);
			}
		}
		if(i!=minNumIndex){//가장 작은 값이 다른 위치에 있다면
			swap(&intArray[i],&intArray[minNumIndex]);//값 변경
		}
	}

	for(i = 0;i<inputSize;i++){ //배열 값 출력
		printf("%d ", intArray[i]);
	}
	printf("\n\n");
}
