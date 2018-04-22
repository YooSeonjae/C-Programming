#include<stdio.h>

int main(void)
{
	int grade = 4;
	int student_number = 201302434;

	int front = 10;
	int rear = 5;
	
	int frontInt = 10;
	int rearInt = 15;
	
	float frontFloat = 10;
	float rearFloat = 15;

	int a = 20, b = 30;
	float p = 3.14F, q = 4.2F; //float은 뒤에 f,F를 붙임.
	double m = 7.23, n = 1.2;

	int x = 0;
	//\n을 이용하여 출력.
	printf("나는 컴퓨터공학과 4학년이고\n");
	printf("학번은 201302434이다.\n\n");
	//int형 변수 사용하여 출력.
	printf("나는 컴퓨터공학과 %d학년이고\n",grade);
	printf("학번은 %d이다.\n\n",student_number);
	//int형 변수 사칙연산 %d로 출력.
	printf("%d + %d = %d\n", front, rear, front+rear); 
	printf("%d - %d = %d\n", front, rear, front-rear);
	printf("%d * %d = %d\n", front, rear, front*rear);
	printf("%d / %d = %d\n\n", front, rear, front/rear);
	//int형 변수와 float형 변수를 비교하여 %d, %f로 출력.
	printf("%d + %d = %d\n",frontInt,rearInt,frontInt+rearInt);
	printf("%d - %d = %d\n",frontInt,rearInt,frontInt-rearInt);
	printf("%d * %d = %d\n",frontInt,rearInt,frontInt*rearInt);
	printf("%d / %d = %d\n\n",frontInt,rearInt,frontInt/rearInt);
	printf("%f + %f = %f\n",frontFloat,rearFloat,frontFloat+rearFloat);
	printf("%f - %f = %f\n",frontFloat,rearFloat,frontFloat-rearFloat);
	printf("%f * %f = %f\n",frontFloat,rearFloat,frontFloat*rearFloat);
	printf("%f / %f = %f\n\n",frontFloat,rearFloat,frontFloat/rearFloat);

	x = x + 10;
	printf(" x = %d\n", x );// int형 변수 x값 출력.
	printf(" a = %d 이고 b = %d : \n", a, b); //int형 변수 a, b의 값 출력->출력에 %d사용.
	printf(" p = %f 이고 q = %f : \n", p, q); //float형 변수 p, q의 값 출력->출력에 %f사용.
	printf(" m = %lf 이고 n = %lf : \n\n", m, n); //double형 변수 m, n의 값 출력->출력에 %lf사용.
	printf("\tb / a -> %d\n", b/a);//\t을 이용하여 한Tab를 띄워서 출력.//int형 나누기 연산 출력->출력에 %d사용.
	printf("\tb / a -> %f\n", b/a); //출력 시 0으로 나옴. int형 변수를 사용하지만 출력은 %f를 사용.
									//출력 값을 float형으로 해주기 위해서는 casting을 해서 정상적인 출력 가능.
	printf("\tp - q -> %f\n", p-q);//float형 빼기 연산 출력->출력에 %f를 사용. 
	printf("\tm * n -> %lf\n\n", m*n);//double형 곱셈 연산 출력->출력에 %lf를 사용.

	return 0;
}