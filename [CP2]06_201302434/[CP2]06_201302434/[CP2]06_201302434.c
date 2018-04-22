#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeArray(int *intArray, int inputSize);
int calSum(int * intArray, int arraySize);
int calAvg(int * intArray, int arraySize);
int findMin(int * intArray, int arraySize);
int findMax(int * intArray, int firstIndex, int lastIndex);

int main(){
	int arr1[4];//�ǽ�1
	int arr2[5];//�ǽ�2
	int i, sum = 0;
	int array[20]; //���� 1,2
	int num, totalSum, average, minNum, maxNum;

	//�ǽ�1
	printf("���� ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &arr1[0]);
	printf("���� ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &arr1[1]);
	printf("���� ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &arr1[2]);

	arr1[3] = arr1[0] + arr1[1] + arr1[2];
	printf("\n");
	printf("���� : %d\n", arr1[0]);
	printf("���� : %d\n", arr1[1]);
	printf("���� : %d\n", arr1[2]);
	printf("���� : %d\n", arr1[3]);
	printf("��� : %.2f\n\n", arr1[3]/3.0);

	//�ǽ� 2
	for (i = 1; i <= 5; i++) {
		printf("%d��° �л��� ���� : ", i);
		scanf_s("%d", &arr2[i-1]);

	}
	printf("<< �Է��� �л����� ���� >> \n");
	for (i = 0; i < 5; i++) {
		printf("%d  ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++) {
		sum += arr2[i];
	}
	printf("�л�����  ��  �հ� : %d\n", sum);
	printf("�л����� ��� ���� : %.2f\n\n", sum / 5.0);


	//���� 1,2
	printf("Size�� 20�� �迭�� ���� �������� �� �Է� : "); 
	scanf("%d",&num); //��� �����͸� ������ �Է�
	makeArray(array, num); //�迭 �ȿ� ������ ���� num�� ����
	totalSum = calSum(array, num); //����
	average = calAvg(array, num); //���
	minNum = findMin(array, num); //�ּҰ�
	maxNum = findMax(array, 0, num-1); //�ִ밪
	//���
	printf("\n\n���� : %d\n", totalSum);
	printf("��� : %d\n", average);
	printf("�ּ� �� : %d\n", minNum);
	printf("�ִ� �� : %d\n", maxNum);
}
int makeArray(int *intArray, int inputSize){
	int i;
	srand((unsigned int)time((time_t*)NULL)); //�����Լ�

	for(i = 0;i<inputSize;i++){
		intArray[i]=rand()%1000;//�迭�� ���� ������ ����
		printf("%d ", intArray[i]);
	}

}
int calSum(int * intArray, int arraySize){
	int i, sum=0;

	for(i = 0;i<arraySize;i++){ //���� ���
		sum=sum+intArray[i];
	}
	return sum;
}
int calAvg(int * intArray, int arraySize){
	int i, totalSum, average=0;

	totalSum = calSum(intArray, arraySize);//����� ���� ���� �����Լ� ȣ��.

	average = totalSum/arraySize;// ����/�����ͼ�

	return average;
}
int findMin(int * intArray, int arraySize){
	int i, maxIndexValue, minNum;

	if(arraySize==1){//����� 1�϶��� ���� ù��°�� Min
		return intArray[0];
	}

	maxIndexValue = intArray[arraySize-1];//maxIndexValue�� ���� ������ �迭 �� ����
	minNum = findMin(intArray, arraySize-1);//����� -1�� ������ ��ͷ� ����� 1�� �� ������ ���� �ּҰ� ����

	if(maxIndexValue<minNum){//���� �迭���� ������ �迭 ���� ���������� �ּҰ� ��
		minNum=maxIndexValue;
	}
	return minNum;
}
int findMax(int * intArray, int firstIndex, int lastIndex){
	int middleIndex = (firstIndex+lastIndex) / 2; //��� �ε���
	int leftMaxNum,rightMaxNum; //�����ִ밪,�������ִ밪

	if(firstIndex == lastIndex){//�� divide�Ǿ� 1���� ������ ��� 
		return intArray[firstIndex]; //�� ���� �ε����� �ִ밪
	}
	else{
		leftMaxNum = findMax(intArray, firstIndex, middleIndex); //�������� divide
		rightMaxNum = findMax(intArray, (firstIndex + lastIndex)/2+1, lastIndex);//���������� divide
		if(leftMaxNum > rightMaxNum){//���� �ִ밪�� ��Ŭ��
			return leftMaxNum;
		}
		else{//������ �ִ밪�� ��Ŭ��
			return rightMaxNum;
		}
	}

}