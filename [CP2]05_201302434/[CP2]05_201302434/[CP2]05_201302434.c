#include <stdio.h>
// 함수 선언
int aaa(int su1,int su2); // 실습 1
int add(int a, int b); // 실습 2
int subtract(int a, int b); // 실습 2
int getArea(int x, int y); //실습 3
int sum(int x); //실습 4
int prime_check(int checkNum); //과제 1
int rabbit_num(int num);//과제 2

int main(void)
{	
	//실습, 과제 변수
	int result; //실습 1
	int v1, v2, m=10, n=20; //실습 2
	int a, b, result2; //실습 3
	int k, result3; //실습 4
	int inputNum, i, check; //과제 1
	int count = 0; //과제 1
	int total_num,num; //과제 2

	//실습 1
	result = aaa(5, 3);//aaa()함수 호출하면서 두개의 인자 전달, 결과값은 result에 저장
	printf("aaa()함수를 호출하면서 인자로 5와 3 전달해서 결과는 %d이 됩니다.\n\n", result); 
	//반환되어 돌아온 int형 결과값 출력

	//실습 2
	v1 = add(m,n);
	v2 = subtract(15,3) + 2;
	printf("%d %d %d \n\n",v1, v2, add(2,6) );

	//실습 3
	printf("밑변 길이 : ");
	scanf("%d", &a);
	printf("높이 : ");
	scanf("%d", &b);
	result2 = getArea(a, b);
	printf("사각형의 넓이는 %d입니다. \n\n", result2);

	//실습 4
	printf("input your number = ");
	scanf("%d",&k);
	result3=sum(k);
	printf("1부터 %d까지의 합 : %d \n\n", k, result3);

	//과제 1
	printf("N까지의 소수 구하기. N을 입력해주세요 : ");
	scanf("%d",&inputNum);
	for(i=2;i<=inputNum;i++) //소수는 2부터 이므로 2부터 입력한 수까지 수행
	{
		check = prime_check(i); //2부터 해당 수까지 소수인지 확인
		if(check==1) //1이 리턴 시 소수
		{
			printf("%3d ", i);
			count++; //3개씩 출력하기 위해 하나 출력당 count 1증가
		}
		if(count==3) // 3개 입력이 끝나면
		{
			printf("\n"); //줄바꾸고
			count = 0; //초기화
		}
	}
	printf("\n\n");

	//과제 2
	printf("1년 후에 전체 토끼의 수는?\n");
	for(num=0; num<12;num++){ //매달 토끼의 수를 알기 위해 12번 수행
		printf("%d ",rabbit_num(num));//해당 달에 토끼의 수
	}
	printf("\n\n");
	return 0;
}

//함수 내용
// 실습 1
int aaa(int su1, int su2) {//매개변수로 두개의 int값 받음

	int hap; //반환할 값 int형 hap
	hap = su1 + su2; //두수의 합
	return hap; //호출할 곳으로 반환할 int형 return값
}

// 실습 2
int add(int a, int b) { //함수 add정의      
	return(a + b);
}
int subtract(int a, int b) { //함수 subtract 정의
	int diff;
	diff = a - b;                       
	return diff;
}

//실습 3
int getArea(int x, int y){
	return x * y;
}

//실습 4
int sum(int x){
	if(x<=1){
		return 1;
	}
	else{
		return x + sum(x-1);
	}
}

//과제 1
int prime_check(int checkNum){ //소수인지 판단하는 메소드
	int i;
	int a; //나누어 떨어지는 확인하는 변수
	int count = 0; //나누어 떨어진 수를 세는 변수

	for(i=2;i<=checkNum;i++){
		if(count >=2) //1과 자신이 아닌 다른 수로도 나누어질 경우
		{
			break;
		}
		a = checkNum%i; 
		if(a==0) //나누어 떨어지면
		{
			count++; //count 1증가
		}
	}
	if(count < 2){ //count가 2이하면 자신만 나누어 떨어짐
		return 1;
	}
	else{ //소수가 아님
		return 0;
	}
}

//과제 2
int rabbit_num(int n){
	if(n==0||n==1){ //첫번째 달과 두번째 달은 1쌍의 토끼
		return 1;
	}
	else{ //피보나치 수열의 형태로 토끼가 증가하여 재귀로 리턴
		return rabbit_num(n-1) + rabbit_num(n-2);
	}
}