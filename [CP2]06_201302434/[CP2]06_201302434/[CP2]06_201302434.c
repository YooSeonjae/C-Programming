#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeArray(int *intArray, int inputSize);
int calSum(int * intArray, int arraySize);
int calAvg(int * intArray, int arraySize);
int findMin(int * intArray, int arraySize);
int findMax(int * intArray, int firstIndex, int lastIndex);

int main(){
	int arr1[4];//실습1
	int arr2[5];//실습2
	int i, sum = 0;
	int array[20]; //과제 1,2
	int num, totalSum, average, minNum, maxNum;

	//실습1
	printf("수학 점수를 입력하시오 : ");
	scanf_s("%d", &arr1[0]);
	printf("영어 점수를 입력하시오 : ");
	scanf_s("%d", &arr1[1]);
	printf("국어 점수를 입력하시오 : ");
	scanf_s("%d", &arr1[2]);

	arr1[3] = arr1[0] + arr1[1] + arr1[2];
	printf("\n");
	printf("수학 : %d\n", arr1[0]);
	printf("영어 : %d\n", arr1[1]);
	printf("국어 : %d\n", arr1[2]);
	printf("총합 : %d\n", arr1[3]);
	printf("평균 : %.2f\n\n", arr1[3]/3.0);

	//실습 2
	for (i = 1; i <= 5; i++) {
		printf("%d번째 학생의 성적 : ", i);
		scanf_s("%d", &arr2[i-1]);

	}
	printf("<< 입력한 학생들의 성적 >> \n");
	for (i = 0; i < 5; i++) {
		printf("%d  ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++) {
		sum += arr2[i];
	}
	printf("학생들의  총  합계 : %d\n", sum);
	printf("학생들의 평균 점수 : %.2f\n\n", sum / 5.0);


	//과제 1,2
	printf("Size가 20인 배열에 넣을 데이터의 수 입력 : "); 
	scanf("%d",&num); //몇개의 데이터를 넣을지 입력
	makeArray(array, num); //배열 안에 랜덤한 수를 num개 넣음
	totalSum = calSum(array, num); //총합
	average = calAvg(array, num); //평균
	minNum = findMin(array, num); //최소값
	maxNum = findMax(array, 0, num-1); //최대값
	//출력
	printf("\n\n총합 : %d\n", totalSum);
	printf("평균 : %d\n", average);
	printf("최소 값 : %d\n", minNum);
	printf("최대 값 : %d\n", maxNum);
}
int makeArray(int *intArray, int inputSize){
	int i;
	srand((unsigned int)time((time_t*)NULL)); //랜덤함수

	for(i = 0;i<inputSize;i++){
		intArray[i]=rand()%1000;//배열에 랜덤 데이터 저장
		printf("%d ", intArray[i]);
	}

}
int calSum(int * intArray, int arraySize){
	int i, sum=0;

	for(i = 0;i<arraySize;i++){ //총합 계산
		sum=sum+intArray[i];
	}
	return sum;
}
int calAvg(int * intArray, int arraySize){
	int i, totalSum, average=0;

	totalSum = calSum(intArray, arraySize);//평균을 내기 위해 총합함수 호출.

	average = totalSum/arraySize;// 총합/데이터수

	return average;
}
int findMin(int * intArray, int arraySize){
	int i, maxIndexValue, minNum;

	if(arraySize==1){//사이즈가 1일때는 제일 첫번째가 Min
		return intArray[0];
	}

	maxIndexValue = intArray[arraySize-1];//maxIndexValue에 제일 마지막 배열 값 저장
	minNum = findMin(intArray, arraySize-1);//사이즈를 -1한 값으로 재귀로 사이즈가 1이 될 때까지 가서 최소값 저장

	if(maxIndexValue<minNum){//현재 배열에서 마지막 배열 값과 이전까지의 최소값 비교
		minNum=maxIndexValue;
	}
	return minNum;
}
int findMax(int * intArray, int firstIndex, int lastIndex){
	int middleIndex = (firstIndex+lastIndex) / 2; //가운데 인덱스
	int leftMaxNum,rightMaxNum; //왼쪽최대값,오른쪽최대값

	if(firstIndex == lastIndex){//다 divide되어 1개만 남앗을 경우 
		return intArray[firstIndex]; //그 때의 인덱스가 최대값
	}
	else{
		leftMaxNum = findMax(intArray, firstIndex, middleIndex); //왼쪽으로 divide
		rightMaxNum = findMax(intArray, (firstIndex + lastIndex)/2+1, lastIndex);//오른쪽으로 divide
		if(leftMaxNum > rightMaxNum){//왼쪽 최대값이 더클때
			return leftMaxNum;
		}
		else{//오른쪽 최대값이 더클때
			return rightMaxNum;
		}
	}

}