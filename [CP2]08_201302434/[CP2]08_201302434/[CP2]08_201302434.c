#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ����
void homework1(); //���� 1
int cmpString(const void * a, const void * b); //���� 1
void makeLottoNumber(int * lottoNums); //���� 2
void swap(int * x, int * y);//����2
void sortArray(int *intArray, int inputSize);//����2
int checkLottoNumber(int * lottoNums); //���� 2
void makeBingo(int (*bingoArray)[20], int inputSize); //���� 3
void printBingo (int (*bingoArray)[20], int inputSize); //���� 3
int checkBingo(int (*bingoArray)[20], int inputSize); //���� 3
int getRandomNumber(int (*bingoArray)[20],int * prevNumberList, int inputSize); //���� 3
int getUserSelectNumber(int (*bingoArray)[20],int * prevNumberList, int inputSize); //���� 3

int main(void){
	//����
	char animal[20];//�ǽ� 1
	char why[80];//�ǽ� 1
	char str[16];//�ǽ� 2
	char res_str[16];//�ǽ� 2
	char *star = "**********";//�ǽ� 2
	int len;//�ǽ� 2
	int lottoNums[6];//���� 2
	int inputSize; //���� 3
	int bingoArray[20][20];
	int prevNumberList[401]={0};
	int randomNumber,userNumber;
	int type;

	//�ǽ� 1
	printf("<�ǽ� 1>\n");
	printf("�����ϴ� ���� : ");
	scanf("%s", animal);
	//gets(animal); //�������

	//getchar();//ppt09 32p
	//scanf("%*c");
	//fgetc(stdin);
	fflush(stdin);//���� ����

	printf("�����ϴ� ���� : ");
	fgets(why,sizeof(why),stdin);
	printf("%s is %s\n", animal, why);


	//�ǽ� 2
	printf("<�ǽ� 2>\n");
	printf("�ܾ� �Է� : ");
	scanf("%s",str);
	len = (int)strlen(str);
	if(len <= 5)
		strcpy(res_str,str);
	else {
		strncpy(res_str,str,5);
		res_str[5] = '\0';
		strncat(res_str, star, len-5);
	}
	printf("�Է��� �ܾ� : %s, ������ �ܾ� : %s\n\n",str,res_str);

	//���� 1
	printf("<���� 1>");
	homework1();


	//���� 2
	printf("<���� 2>");
	makeLottoNumber(lottoNums);
	checkLottoNumber(lottoNums);

	//���� 3
	printf("<���� 3>");
	printf("\n������ ����� �Է��ϼ��� : "); //��ȣ �Է�
	scanf("%d", &inputSize);
	makeBingo(bingoArray,inputSize);
	printf("������ ����\n");
	printBingo (bingoArray, inputSize);
	while(1){
		printf("\n���� ���� ����� ����[1:����][2:������Է�] : ");
		scanf("%d", &type);
		if(type == 1) {
			printf("���� ���ڸ� ���� : ");
			randomNumber = getRandomNumber(bingoArray,prevNumberList, inputSize);
			printf("%d\n",randomNumber);
		} else if(type == 2) {
			printf("����� ���� ���� �Է� : ");
			userNumber = getUserSelectNumber(bingoArray, prevNumberList, inputSize);
			if(userNumber==-1){
				printf("�����ϴ� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
				continue;
			}
		}else{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}
		if(checkBingo(bingoArray, inputSize)){
			printf("\n����!\n");
			printBingo (bingoArray, inputSize);
			break;
		}
	}


	return 0;
}
//�Լ� ����
//���� 1
void homework1(void){
	char totalString[200][16];//��ü ���ڿ�
	char tempString[30];//�ӽ� ���� �迭
	int sum = 0;//��ü ���̸� ���� ����
	int index =  0; //�ܾ���� �����ϴ� �迭 index
	int i;

	while(1){
		printf("\n�ܾ� �Է� : ");
		scanf("%s", tempString);
		if(strcmp(tempString,"end")==0){ //end�� �Է��� ���
			printf("end�� �Է��ϼ̽��ϴ�. ���α׷� ����.\n\n");
			return ;//����
		}
		else if(sum+strlen(tempString)>200){ //��ü ���ڿ��� 200�� ���� ���
			printf("����ü ���ڿ��� ���̰� 200�� �Ѿ����ϴ�.\n");
			printf("���̻� �Է� ���� �� �����ϴ�. ���α׷� ����.\n\n");
			return ;//����
		}

		if(strlen(tempString)>15){//�ܾ��� ���̰� 15�� ���� ���
			printf("�ع��ڿ��� ���̰� 15�� �ѽ��ϴ�. �ٽ� �Է����ּ���.\n");
			continue;//�ٽ� �Է�
		}
		else{//���� �Է�
			strcpy(totalString[index],tempString);//��ü ���ڿ��� �ֱ�
			qsort(totalString, index+1, sizeof(totalString[0]), cmpString); //����

			printf("������� ���ڿ� : ");//���
			for(i=0; i<index+1 ; i++)
			{
				printf("%s ", totalString[i]);
			}

			sum = sum + strlen(tempString);//��ü ���ڱ��� ����
			index++;//�ε��� ����
		}
	}
	printf("\n\n");
}

int cmpString(const void * a, const void * b)
{
	return (strcmp((char *)a,(char *)b));//a��b�� ��
}

//���� 2
void makeLottoNumber(int * lottoNums){//�迭 �ߺ� ���°� ���� ���� �� �ֱ�
	int i, a;
	int numberCheck[46] = {0}; // �ߺ� �Ǿ����� Ȯ���ϴ� �迭

	srand((unsigned int)time((time_t*)NULL));

	for(i = 0;i < 6;){
		lottoNums[i] = rand()%45+1; //������ �Է�(1~45)
		if(numberCheck[lottoNums[i]] == 0){ //�ߺ�Ȯ��
			numberCheck[lottoNums[i]] = 1;
			i++;
		}
	}
	sortArray(lottoNums, 6);
	printf("\n");
}
void swap(int *x, int *y){ //���� ��������ִ� �Լ�
	int temp = 0;
	 
	temp = *x;//�ӽ� ������ ���� x�� ���� 
	//printf("temp->%d\n",temp);
	*x = *y;//x�� y�� ����
	*y = temp;//y�� �ӽ÷� �����س��� x�� ����
	//printf("y->%d\n",temp);
}
void sortArray(int *intArray, int inputSize){
	int i,j;
	int minNumIndex;//�ּ� ���� ������ �ִ� �ε���

	for(i=0;i<inputSize;i++){//ó������ ������ ����
		minNumIndex=i;
		for(j=i+1;j<inputSize;j++){//�ش� �ڸ� �������� ����
			if(intArray[minNumIndex]>intArray[j]){//���� ������ ã��
				minNumIndex = j;//���� ���� ���� �ε��� ����
				//printf("���� �ε���->%d\n",j);
			}
		}
		if(i!=minNumIndex){//���� ���� ���� �ٸ� ��ġ�� �ִٸ�
			swap(&intArray[i],&intArray[minNumIndex]);//�� ����
		}
	}
}
int checkLottoNumber(int * lottoNums){
	int i, j;
	int tempNum;
	int myLotto[6] = {0};//���� �Է��� ��ȣ �迭
	int check = 0; //���� ��ȣ �ִ��� Ȯ��
	int count = 0; //��¥ �ζ� ��ȣ�� ���� ���� ������ üũ

	for(i=0;i<6;){
		printf("��ȣ �Է� : "); //��ȣ �Է�
		scanf("%d", &tempNum);

		for(j=0;j<6;j++){
			if(tempNum==myLotto[j]){ //���� ���� ��ȣ�� �Է��ߴ��� Ȯ��
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				check++;//���� ��� check = 1;
				continue;
			}
		}

		if(check == 0){ // �ߺ� �ȵǾ��� ���
			myLotto[i] = tempNum; // �� �ζ� ��ȣ �Է¹迭�� ����
			for(j=0;j<6;j++){ // ��¥ �ζ� ��ȣ�� ��
				if(myLotto[i]==lottoNums[j]){
					count++; //���� �� ���� 1�����ش�.
					continue;
				}
			}
			i++;
		}
		check = 0;//�ٽ� �˻縦 ���� �ʱ�ȭ
	}


	printf("�ζǹ�ȣ : ");//�ζǹ�ȣ ���
	for(i=0;i<6;i++){
		printf("%d ", lottoNums[i]);
	}
	printf("\n�� %d���� �´� ���ڰ� �ֽ��ϴ�.\n\n",count);//��� ���
}

//���� 3
void makeBingo(int (*bingoArray)[20], int inputSize){
	int i, j, a;

	int numberCheck[401] = {0}; // �ߺ� �Ǿ��� �� Ȯ���ϴ� �迭

	srand((unsigned int)time((time_t*)NULL));

	for(i = 0;i < inputSize;i++){
		for(j = 0;j < inputSize;){
			bingoArray[i][j] = (rand()%(inputSize*inputSize))+1; //������ �Է�
			if(numberCheck[bingoArray[i][j]] == 0){ //�ߺ�Ȯ��
				numberCheck[bingoArray[i][j]] = 1;
				j++;
			}
		}
	}
}

void printBingo (int (*bingoArray)[20], int inputSize){
	int i,j;
	char check = '*';

	for(i = 0;i < inputSize;i++){
		for(j = 0;j < inputSize;j++){
			if(bingoArray[i][j]==0){//���� üũ�� ���
				printf("%3c ",check);//*���
			}
			else{
				printf("%3d ",bingoArray[i][j]);//���
			}
		}
		printf("\n");
	}

}

int checkBingo(int (*bingoArray)[20], int inputSize){
	int i,j;
	int colCheck = 1;
	int rowCheck = 1;
	int crossCheck1 = 1;
	int crossCheck2 = 1;

	for(i = 0;i < inputSize;i++){//���ο� ����Ȯ��
		for(j = 0;j < inputSize;j++){
			if(bingoArray[i][j]==0){//����üũ�� �Ȱ��
				if(j==inputSize-1){
					rowCheck = 0;
				}
				continue;
			}else{ //���� üũ�� �ȵȰ��
				rowCheck=1;
				break;
			}
		}
		if(rowCheck==0){//��� ���� üũ�� �Ǿ�������
			return 1;//1����
		}
	}

	for(i = 0;i < inputSize;i++){//���ο� ����Ȯ��
		for(j = 0;j < inputSize;j++){
			if(bingoArray[j][i]==0){//����üũ�� �Ȱ��
				if(j==inputSize-1){
					colCheck = 0;
				}
				continue;
			}else{//���� üũ�� �ȵȰ��
				colCheck=1;
				break;
			}
		}
		if(colCheck==0){//��� ���� üũ�� �Ǿ�������
			return 1;//1����
		}
	}

	for(i = 0;i < inputSize;i++){//�밢�� ����Ȯ��
		if(bingoArray[i][i]==0){//����üũ�� �Ȱ��
			if(i==inputSize-1){
				crossCheck1 = 0;
			}
			continue;
		}else{//���� üũ�� �ȵȰ��
			crossCheck1=1;
			break;
		}
	}
	if(crossCheck1==0){//��� ���� üũ�� �Ǿ�������
			return 1;//1����
		}

	for(i = 0;i < inputSize;i++){//�밢�� ����Ȯ��
		if(bingoArray[i][inputSize-i-1]==0){//����üũ�� �Ȱ��
			if(i==inputSize-1){
				crossCheck2 = 0;
			}
			continue;
		}else{//���� üũ�� �ȵȰ��
			crossCheck2=1;
			break;
		}
	}
	if(crossCheck2==0){//��� ���� üũ�� �Ǿ�������
			return 1;//1����
		}

	return 0;
}
int getRandomNumber(int (*bingoArray)[20], int * prevNumberList, int inputSize){
	int i,j;
	int randomNum;

	srand((unsigned int)time((time_t*)NULL));

	while(1){
		randomNum = (rand()%(inputSize*inputSize))+1; //������ �Է�
		if(prevNumberList[randomNum] == 0){ //�ߺ�Ȯ��
			prevNumberList[randomNum] = 1;
			for(i = 0;i < inputSize;i++){
				for(j = 0;j < inputSize;j++){
					if(bingoArray[i][j] == randomNum){//�����ǿ� üũ
						bingoArray[i][j] = 0;
					}
				}
			}
			return randomNum;//�����Է� �� ������ ����
		}
	}

}


int getUserSelectNumber(int (*bingoArray)[20],int * prevNumberList, int inputSize){
	int i,j;
	int userNum;

	while(1){
		scanf("%d",&userNum);//����� �Է�
		if(prevNumberList[userNum] == 0){ //�ߺ�Ȯ��
			prevNumberList[userNum] = 1;
			for(i = 0;i < inputSize;i++){
				for(j = 0;j < inputSize;j++){
					if(bingoArray[i][j] == userNum){//�����ǿ� üũ
						bingoArray[i][j] = 0;
					}
				}
			}
			return userNum;//�����Է½� ����ڰ� �Է��� ������
		}
		else{
			return -1;//������ ���� ���� ��ȣ�� ���
		}
	}
}
