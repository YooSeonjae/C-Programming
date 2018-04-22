#include <stdio.h>

#define MAX 5

int main(void)
{	// 실습,과제의 변수들
	int a = 10, b = 20, c = 30 ; //실습 1
	int number = 0;				 //실습 2
	int point = 0;				 //실습 3
	int year = 0, month = 0, maxDay = 0, validinput = 0; //실습 4
	int i, j;					 //실습 5
	int h, t, e ,s;              //과제

	//실습 1번
	printf("\n================= 실습 1 =================\n");
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + b++ 의 결과 = %5d\n\n", a + b++);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + ++b %% 3 의 결과 = %5d\n\n", a + ++b % 3);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\t++a / 2 + c++ 의 결과 = %5d\n\n", ++a / 2 + c++);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta++ + ++b + ++c 의 결과 = %5d\n\n", a++ + ++b + ++c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	printf("==========================================\n");

	//실습 2번
	printf("\n================= 실습 2 =================\n");
	printf("양의 정수 하나를 입력하세요. ");
	scanf("%d", &number);
	printf("---> 입력한 수 %d 는(은) ",number);

	if(number % 2 == 0){
		printf("짝수 입니다.\n");
	}else{
		printf("홀수 입니다.\n");
	}

	printf("==========================================\n");

	//실습 3번
	printf("\n================= 실습 3 =================\n");
	printf("프로그래밍 언어 점수를 입력하세요. --> ");
	scanf("%d",&point);

	if( point >= 90 )
	{
		printf("프로그래밍 언어 학점이 A입니다.\n");
	}
	else if( point >= 80 )
	{
		printf("프로그래밍 언어 학점이 B입니다.\n");
	}
	else if( point >= 70 )
	{
		printf("프로그래밍 언어 학점이 C입니다.\n");
	}
	else if( point >= 60 )
	{
		printf("프로그래밍 언어 학점이 D입니다.\n");
	}
	else
	{
		printf("프로그래밍 언어 학점이 F입니다.\n");
	}

	printf("==========================================\n");

	//실습 4번
	printf("\n================= 실습 4 =================\n");
	printf("년과 월을 다음과 같이 입력하면 그 달의 말일을 알려드립니다. \n");
	printf("2003 2 : 입력 > ");
	scanf("%d %d", &year, &month);

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxDay = 31;
		validinput = 1;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		maxDay = 30;
		validinput = 1;
		break;

	case 2:
		if ((year%4 == 0) && (year%100 != 0) || (year%400 == 0))
			maxDay = 29;
		else
			maxDay = 28;
		validinput = 1;
		break;

	default:
		validinput = 0;
	}

	if (validinput)
		printf("%d년 %d월의 말일은 %d일 입니다.\n", year, month, maxDay);
	else
		printf("입력이 잘못되었습니다.\n");

	printf("==========================================\n");

	//실습 5번
	printf("\n================= 실습 5 =================\n");
	for( i = 0; i <= MAX; i++)
	{
		for(j = MAX; j >= 0; j--)
		{
			if(j > i) putchar(' ');
			else printf("%d", j);
		}
		putchar('\n');
	}

	printf("==========================================\n");

	//과제
	printf("\n★☆★☆★☆★☆ 과 제 ★☆★☆★☆★☆\n");
	while(1){
		printf("개수를 입력해 주세요 : [종료 : 0]\n"); //총 출력 줄 입력
		scanf("%d", &h);
		if(h==0){									   //0 입력 시 종료
			return 0;
			printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
		}
		else if(h>10){								   //10이 넘는 수 입력 시 재입력
			printf("다시 입력해주세요! \n\n");
			continue;
		}
		else{										   //조건 만족 시
			for (t = 0; t <= h; t++)				   //입력한 수만큼 수행
			{
				for (e = 0; e < h - t; e++)			   //줄수-t만큼 빈칸출력
				{
					putchar(' ');
				}
				for (s = 0; s < (2*t) - 1; s++)		   //빈칸이후 남은 곳을(2*입력줄수)-1만큼
				{									   // *출력
					putchar('*');
				}
				printf("\n");
			}
		}
	}

}