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
	float p = 3.14F, q = 4.2F; //float�� �ڿ� f,F�� ����.
	double m = 7.23, n = 1.2;

	int x = 0;
	//\n�� �̿��Ͽ� ���.
	printf("���� ��ǻ�Ͱ��а� 4�г��̰�\n");
	printf("�й��� 201302434�̴�.\n\n");
	//int�� ���� ����Ͽ� ���.
	printf("���� ��ǻ�Ͱ��а� %d�г��̰�\n",grade);
	printf("�й��� %d�̴�.\n\n",student_number);
	//int�� ���� ��Ģ���� %d�� ���.
	printf("%d + %d = %d\n", front, rear, front+rear); 
	printf("%d - %d = %d\n", front, rear, front-rear);
	printf("%d * %d = %d\n", front, rear, front*rear);
	printf("%d / %d = %d\n\n", front, rear, front/rear);
	//int�� ������ float�� ������ ���Ͽ� %d, %f�� ���.
	printf("%d + %d = %d\n",frontInt,rearInt,frontInt+rearInt);
	printf("%d - %d = %d\n",frontInt,rearInt,frontInt-rearInt);
	printf("%d * %d = %d\n",frontInt,rearInt,frontInt*rearInt);
	printf("%d / %d = %d\n\n",frontInt,rearInt,frontInt/rearInt);
	printf("%f + %f = %f\n",frontFloat,rearFloat,frontFloat+rearFloat);
	printf("%f - %f = %f\n",frontFloat,rearFloat,frontFloat-rearFloat);
	printf("%f * %f = %f\n",frontFloat,rearFloat,frontFloat*rearFloat);
	printf("%f / %f = %f\n\n",frontFloat,rearFloat,frontFloat/rearFloat);

	x = x + 10;
	printf(" x = %d\n", x );// int�� ���� x�� ���.
	printf(" a = %d �̰� b = %d : \n", a, b); //int�� ���� a, b�� �� ���->��¿� %d���.
	printf(" p = %f �̰� q = %f : \n", p, q); //float�� ���� p, q�� �� ���->��¿� %f���.
	printf(" m = %lf �̰� n = %lf : \n\n", m, n); //double�� ���� m, n�� �� ���->��¿� %lf���.
	printf("\tb / a -> %d\n", b/a);//\t�� �̿��Ͽ� ��Tab�� ����� ���.//int�� ������ ���� ���->��¿� %d���.
	printf("\tb / a -> %f\n", b/a); //��� �� 0���� ����. int�� ������ ��������� ����� %f�� ���.
									//��� ���� float������ ���ֱ� ���ؼ��� casting�� �ؼ� �������� ��� ����.
	printf("\tp - q -> %f\n", p-q);//float�� ���� ���� ���->��¿� %f�� ���. 
	printf("\tm * n -> %lf\n\n", m*n);//double�� ���� ���� ���->��¿� %lf�� ���.

	return 0;
}