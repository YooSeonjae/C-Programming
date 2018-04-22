#include <stdio.h>

int main()
{	
	//변수
	int i = 0; //실습1
	int j = 0; //실습1
	int sum = 0; //실습1
	int answer; //실습2
	int a, b; //실습3
	int n = 0, sum2 = 0; //실습4
	int h, t, e, s, hhalf; //추가 과제

	//실습1
	printf("등차수열의 n번째 항의 값 구하기, n의 값 입력하기 : ");
	scanf("%d",&i);

	for(j=0;j<i;j++)
	{
		sum = 2 + 5 * j;
	}
	printf("sum = %d\n\n", sum);

	//실습2
	printf("1+5의 값은 얼마입니까?\n");
	scanf_s("%d", &answer);

	switch (answer) {
	case 6:
		printf("맞았습니다.\n");
		break;

	default:
		printf("틀렸습니다.\n");
		break;
	}

	//실습3
	printf("\n단을 입력하고 엔터를 치시오. ==>");
	scanf_s("%d",&b);
	for (a = 1; a < 10;a ++) {
		printf("%d * %d  = %d\n", b, a, b * a);
	}

	//실습4
	printf("\n");
	while (1) {
		printf("더할 수 입력 : ");
		scanf_s("%d", &n);
		if (n == 0) {
			break;
		}
		else 
			sum2 += n;
		printf("지금까지 입력한 수의 합은 %d입니다. \n", sum2);
	}
	printf("프로그램 종료\n\n");

	//추가 과제
	while(1){
		printf("사이즈를 입력하세요 : \n"); //총 출력 줄 입력
		scanf("%d", &h);
		if(h>20){ //20보다 큰수 입력 시 다시 입력
			printf("다시 입력해주세요! \n\n");
			continue;
		}
		
		else if(h>0 && h<21){ //1~20까지 입력 시
			hhalf = h/2; //입력의 반
			h = h-hhalf; //반으로 나눈 나머지
			for (t = 0; t <= hhalf; t++) //입력한 수의 반만큼 수행
			{
				for (e = 0; e < h - t; e++)	//h-t만큼 빈칸출력
				{
					putchar(' '); // 빈칸출력
				}
				for (s = 0; s < (2*t) - 1; s++)	//빈칸이후 남은 곳을(2*hhalf)-1만큼
				{									   
					putchar('*'); // *출력
				}
				printf("\n");
			}
			for (t = 0; t <= h; t++) //남은 입력 수만큼 수행
			{
				for (s = 0; s < t; s++)		//t만큼 빈칸출력   
				{									   
					putchar(' '); // 빈칸출력
				}
				for (e = t; e < (2*h)-t-1; e++)	//(2*h)-t-1만큼 빈칸출력 	
				{
					putchar('*'); // *출력
				}
				printf("\n");
			}
		}
		return 0;
	}
}