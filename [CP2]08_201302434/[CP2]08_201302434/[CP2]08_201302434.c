#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//함수 선언
void homework1(); //과제 1
int cmpString(const void * a, const void * b); //과제 1
void makeLottoNumber(int * lottoNums); //과제 2
void swap(int * x, int * y);//과제2
void sortArray(int *intArray, int inputSize);//과제2
int checkLottoNumber(int * lottoNums); //과제 2
void makeBingo(int (*bingoArray)[20], int inputSize); //과제 3
void printBingo (int (*bingoArray)[20], int inputSize); //과제 3
int checkBingo(int (*bingoArray)[20], int inputSize); //과제 3
int getRandomNumber(int (*bingoArray)[20],int * prevNumberList, int inputSize); //과제 3
int getUserSelectNumber(int (*bingoArray)[20],int * prevNumberList, int inputSize); //과제 3

int main(void){
	//변수
	char animal[20];//실습 1
	char why[80];//실습 1
	char str[16];//실습 2
	char res_str[16];//실습 2
	char *star = "**********";//실습 2
	int len;//실습 2
	int lottoNums[6];//과제 2
	int inputSize; //과제 3
	int bingoArray[20][20];
	int prevNumberList[401]={0};
	int randomNumber,userNumber;
	int type;

	//실습 1
	printf("<실습 1>\n");
	printf("좋아하는 동물 : ");
	scanf("%s", animal);
	//gets(animal); //버퍼출력

	//getchar();//ppt09 32p
	//scanf("%*c");
	//fgetc(stdin);
	fflush(stdin);//버퍼 비우기

	printf("좋아하는 이유 : ");
	fgets(why,sizeof(why),stdin);
	printf("%s is %s\n", animal, why);


	//실습 2
	printf("<실습 2>\n");
	printf("단어 입력 : ");
	scanf("%s",str);
	len = (int)strlen(str);
	if(len <= 5)
		strcpy(res_str,str);
	else {
		strncpy(res_str,str,5);
		res_str[5] = '\0';
		strncat(res_str, star, len-5);
	}
	printf("입력한 단어 : %s, 생략한 단어 : %s\n\n",str,res_str);

	//과제 1
	printf("<과제 1>");
	homework1();


	//과제 2
	printf("<과제 2>");
	makeLottoNumber(lottoNums);
	checkLottoNumber(lottoNums);

	//과제 3
	printf("<과제 3>");
	printf("\n빙고판 사이즈를 입력하세요 : "); //번호 입력
	scanf("%d", &inputSize);
	makeBingo(bingoArray,inputSize);
	printf("빙고판 생성\n");
	printBingo (bingoArray, inputSize);
	while(1){
		printf("\n숫자 추출 방법을 선택[1:랜덤][2:사용자입력] : ");
		scanf("%d", &type);
		if(type == 1) {
			printf("랜덤 숫자를 추출 : ");
			randomNumber = getRandomNumber(bingoArray,prevNumberList, inputSize);
			printf("%d\n",randomNumber);
		} else if(type == 2) {
			printf("사용자 선택 숫자 입력 : ");
			userNumber = getUserSelectNumber(bingoArray, prevNumberList, inputSize);
			if(userNumber==-1){
				printf("존재하는 숫자입니다. 다시 입력하세요.\n");
				continue;
			}
		}else{
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
			continue;
		}
		if(checkBingo(bingoArray, inputSize)){
			printf("\n빙고!\n");
			printBingo (bingoArray, inputSize);
			break;
		}
	}


	return 0;
}
//함수 정의
//과제 1
void homework1(void){
	char totalString[200][16];//전체 문자열
	char tempString[30];//임시 저장 배열
	int sum = 0;//전체 길이를 위한 변수
	int index =  0; //단어들을 보관하는 배열 index
	int i;

	while(1){
		printf("\n단어 입력 : ");
		scanf("%s", tempString);
		if(strcmp(tempString,"end")==0){ //end를 입력한 경우
			printf("end를 입력하셨습니다. 프로그램 종료.\n\n");
			return ;//종료
		}
		else if(sum+strlen(tempString)>200){ //전체 문자열이 200를 넘은 경우
			printf("※전체 문자열의 길이가 200이 넘었습니다.\n");
			printf("더이상 입력 받을 수 없습니다. 프로그램 종료.\n\n");
			return ;//종료
		}

		if(strlen(tempString)>15){//단어의 길이가 15가 넘을 경우
			printf("※문자열의 길이가 15가 넘습니다. 다시 입력해주세요.\n");
			continue;//다시 입력
		}
		else{//정상 입력
			strcpy(totalString[index],tempString);//전체 문자열에 넣기
			qsort(totalString, index+1, sizeof(totalString[0]), cmpString); //정렬

			printf("현재까지 문자열 : ");//출력
			for(i=0; i<index+1 ; i++)
			{
				printf("%s ", totalString[i]);
			}

			sum = sum + strlen(tempString);//전체 문자길이 증가
			index++;//인덱스 증가
		}
	}
	printf("\n\n");
}

int cmpString(const void * a, const void * b)
{
	return (strcmp((char *)a,(char *)b));//a와b를 비교
}

//과제 2
void makeLottoNumber(int * lottoNums){//배열 중복 들어가는거 막고 랜덤 수 넣기
	int i, a;
	int numberCheck[46] = {0}; // 중복 되었는지 확인하는 배열

	srand((unsigned int)time((time_t*)NULL));

	for(i = 0;i < 6;){
		lottoNums[i] = rand()%45+1; //랜덤수 입력(1~45)
		if(numberCheck[lottoNums[i]] == 0){ //중복확인
			numberCheck[lottoNums[i]] = 1;
			i++;
		}
	}
	sortArray(lottoNums, 6);
	printf("\n");
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
}
int checkLottoNumber(int * lottoNums){
	int i, j;
	int tempNum;
	int myLotto[6] = {0};//내가 입력할 번호 배열
	int check = 0; //같은 번호 있는지 확인
	int count = 0; //진짜 로또 번호와 같은 수의 개수를 체크

	for(i=0;i<6;){
		printf("번호 입력 : "); //번호 입력
		scanf("%d", &tempNum);

		for(j=0;j<6;j++){
			if(tempNum==myLotto[j]){ //내가 같은 번호를 입력했는지 확인
				printf("같은 번호가 있습니다!\n");
				check++;//있을 경우 check = 1;
				continue;
			}
		}

		if(check == 0){ // 중복 안되었을 경우
			myLotto[i] = tempNum; // 내 로또 번호 입력배열에 저장
			for(j=0;j<6;j++){ // 진짜 로또 번호와 비교
				if(myLotto[i]==lottoNums[j]){
					count++; //같을 때 마다 1더해준다.
					continue;
				}
			}
			i++;
		}
		check = 0;//다시 검사를 위해 초기화
	}


	printf("로또번호 : ");//로또번호 출력
	for(i=0;i<6;i++){
		printf("%d ", lottoNums[i]);
	}
	printf("\n총 %d개의 맞는 숫자가 있습니다.\n\n",count);//결과 출력
}

//과제 3
void makeBingo(int (*bingoArray)[20], int inputSize){
	int i, j, a;

	int numberCheck[401] = {0}; // 중복 되었는 지 확인하는 배열

	srand((unsigned int)time((time_t*)NULL));

	for(i = 0;i < inputSize;i++){
		for(j = 0;j < inputSize;){
			bingoArray[i][j] = (rand()%(inputSize*inputSize))+1; //랜덤수 입력
			if(numberCheck[bingoArray[i][j]] == 0){ //중복확인
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
			if(bingoArray[i][j]==0){//빙고가 체크된 경우
				printf("%3c ",check);//*출력
			}
			else{
				printf("%3d ",bingoArray[i][j]);//출력
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

	for(i = 0;i < inputSize;i++){//가로열 빙고확인
		for(j = 0;j < inputSize;j++){
			if(bingoArray[i][j]==0){//빙고체크가 된경우
				if(j==inputSize-1){
					rowCheck = 0;
				}
				continue;
			}else{ //빙고 체크가 안된경우
				rowCheck=1;
				break;
			}
		}
		if(rowCheck==0){//모두 빙고 체크가 되어있으면
			return 1;//1리턴
		}
	}

	for(i = 0;i < inputSize;i++){//세로열 빙고확인
		for(j = 0;j < inputSize;j++){
			if(bingoArray[j][i]==0){//빙고체크가 된경우
				if(j==inputSize-1){
					colCheck = 0;
				}
				continue;
			}else{//빙고 체크가 안된경우
				colCheck=1;
				break;
			}
		}
		if(colCheck==0){//모두 빙고 체크가 되어있으면
			return 1;//1리턴
		}
	}

	for(i = 0;i < inputSize;i++){//대각선 빙고확인
		if(bingoArray[i][i]==0){//빙고체크가 된경우
			if(i==inputSize-1){
				crossCheck1 = 0;
			}
			continue;
		}else{//빙고 체크가 안된경우
			crossCheck1=1;
			break;
		}
	}
	if(crossCheck1==0){//모두 빙고 체크가 되어있으면
			return 1;//1리턴
		}

	for(i = 0;i < inputSize;i++){//대각선 빙고확인
		if(bingoArray[i][inputSize-i-1]==0){//빙고체크가 된경우
			if(i==inputSize-1){
				crossCheck2 = 0;
			}
			continue;
		}else{//빙고 체크가 안된경우
			crossCheck2=1;
			break;
		}
	}
	if(crossCheck2==0){//모두 빙고 체크가 되어있으면
			return 1;//1리턴
		}

	return 0;
}
int getRandomNumber(int (*bingoArray)[20], int * prevNumberList, int inputSize){
	int i,j;
	int randomNum;

	srand((unsigned int)time((time_t*)NULL));

	while(1){
		randomNum = (rand()%(inputSize*inputSize))+1; //랜덤수 입력
		if(prevNumberList[randomNum] == 0){ //중복확인
			prevNumberList[randomNum] = 1;
			for(i = 0;i < inputSize;i++){
				for(j = 0;j < inputSize;j++){
					if(bingoArray[i][j] == randomNum){//빙고판에 체크
						bingoArray[i][j] = 0;
					}
				}
			}
			return randomNum;//정상입력 시 랜덤값 리턴
		}
	}

}


int getUserSelectNumber(int (*bingoArray)[20],int * prevNumberList, int inputSize){
	int i,j;
	int userNum;

	while(1){
		scanf("%d",&userNum);//사용자 입력
		if(prevNumberList[userNum] == 0){ //중복확인
			prevNumberList[userNum] = 1;
			for(i = 0;i < inputSize;i++){
				for(j = 0;j < inputSize;j++){
					if(bingoArray[i][j] == userNum){//빙고판에 체크
						bingoArray[i][j] = 0;
					}
				}
			}
			return userNum;//정상입력시 사용자가 입력한 값리턴
		}
		else{
			return -1;//기존에 나온 빙고 번호일 경우
		}
	}
}
