#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//����
void inputScore(int *scoreArray, int inputIndex);//�ǽ�2
void printScore(int *scoreArray,int index);//�ǽ�2
int printSum(int *scoreArray, int inputIndex);//����1
int printAvg(int *scoreArray,int inputIndex);//����1
void invertedOutput(char str[]);//����2
int* makeArray(int *intArray, int inputSize);//����3
void swap(int * x, int * y);//����3
void sortArray(int *intArray, int inputSize);//����3

int main(void){

	// ����
	int array[3][3];//�ǽ� 1
	int rowIndex, colIndex;//�ǽ� 1
	int scoreArray[20][3];//�ǽ� 2
	int inputStudentSize;//�ǽ� 2
	int studentIndex;//�ǽ� 2
	char stringArray[100];//���� 2
	int num;//���� 3
	int array2[20];

	//�ǽ� 1
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
	
	//�ǽ� 2
	printf("�Է� ���� �л����� �Է��ϼ��� : ");
	scanf("%d", &inputStudentSize);

	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){
		inputScore((int*)&(scoreArray[studentIndex]),inputStudentSize);
	}
	printf("\n");
	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){
		printScore((int*)&(scoreArray[studentIndex]),studentIndex);
	}
	//���� 1
	printf("\n");
	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){
		printSum((int*)&(scoreArray[studentIndex]),studentIndex);
	}
	printf("\n");
	for(studentIndex = 0; studentIndex < inputStudentSize;studentIndex++){
		printAvg((int*)&(scoreArray[studentIndex]),studentIndex);
	}
	printf("\n");
	getchar();
	//scanf�Լ��� ����� �� ���� �Է��ѵ� enter�� ������ �Ǵµ� ���� �Ѿ��
	//���๮�ڴ� �Է¹��ۿ� �����ְԵǾ� ������ gets �Լ��� ����ϴµ� ���ۿ�
	//�����ִ� ���๮�ڸ� �������Եȴ�. �׸��� �� ���๮�ڸ�'����� �Է��� ��'
	//���� �ν��ϱ� ������ gets �Լ��� �������� �ʰ� �Ѿ�� �Ǵ� ���̴�.
	//���� getchar()���

	//���� 2
	printf("\n�� ���� �Է��ϼ���. >>\n");
	gets(stringArray);
	printf("\n������ �Է��� ���ڿ��� �Ųٷ� ����մϴ�.\n");
	invertedOutput(stringArray);
	
	//���� 3
	printf("\nSize�� 20�� �迭�� ���� �������� �� �Է� : "); 
	scanf("%d",&num); //��� �����͸� ������ �Է�
	makeArray(array2, num); //�迭 �ȿ� ������ ���� num�� ����
	printf("������������ ����(��������)\n");
	sortArray(array2, num);
	return 0;
}

//�Լ�����
//�ǽ� 2
void inputScore(int *scoreArray, int inputIndex){
	printf("\n���� ���� �Է� : ");
	scanf("%d", &scoreArray[0]);
	printf("���� ���� �Է� : ");
	scanf("%d", &scoreArray[1]);
	printf("���� ���� �Է� : ");
	scanf("%d", &scoreArray[2]);
}
void printScore(int *scoreArray,int index){
	printf("[%d] %d, %d, %d\n", index, scoreArray[0], scoreArray[1], scoreArray[2]);
}

//���� 1
int printSum(int *scoreArray, int inputIndex){
	printf("[%d] ���� : %d\n", inputIndex, scoreArray[0]+scoreArray[1]+scoreArray[2]);
	return 0;
}
int printAvg(int *scoreArray,int inputIndex){
	printf("[%d] ��� : %d\n", inputIndex, (scoreArray[0]+scoreArray[1]+scoreArray[2])/3);
	return 0;
}

//���� 2
void invertedOutput(char str[]){
	puts(strrev(str));
}

//���� 3
int* makeArray(int *intArray, int inputSize){
	int i;
	srand((unsigned int)time((time_t*)NULL)); //�����Լ�

	for(i = 0;i<inputSize;i++){
		intArray[i]=rand()%1000;//�迭�� ���� ������ ����
		printf("%d ", intArray[i]);
	}
	printf("\n\n");
	return 0;
}
void swap(int *x, int *y){
	int temp = 0;

	temp = *x;
	//printf("temp->%d\n",temp);
	*x = *y;
	*y = temp;
	//printf("y->%d\n",temp);
}
void sortArray(int *intArray, int inputSize){
	int i,j;
	int minNumIndex;

	for(i=0;i<inputSize;i++){
		minNumIndex=i;
		for(j=i+1;j<inputSize;j++){
			if(intArray[minNumIndex]>intArray[j]){
				minNumIndex = j;
				//printf("���� �ε���->%d\n",j);
			}
		}
		if(i!=minNumIndex){
			swap(&intArray[i],&intArray[minNumIndex]);
		}
	}

	for(i = 0;i<inputSize;i++){
		printf("%d ", intArray[i]);
	}
	printf("\n\n");
}
