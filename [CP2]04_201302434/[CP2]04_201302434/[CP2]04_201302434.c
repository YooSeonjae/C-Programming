#include <stdio.h>

int main()
{	
	//����
	int i = 0; //�ǽ�1
	int j = 0; //�ǽ�1
	int sum = 0; //�ǽ�1
	int answer; //�ǽ�2
	int a, b; //�ǽ�3
	int n = 0, sum2 = 0; //�ǽ�4
	int h, t, e, s, hhalf; //�߰� ����

	//�ǽ�1
	printf("���������� n��° ���� �� ���ϱ�, n�� �� �Է��ϱ� : ");
	scanf("%d",&i);

	for(j=0;j<i;j++)
	{
		sum = 2 + 5 * j;
	}
	printf("sum = %d\n\n", sum);

	//�ǽ�2
	printf("1+5�� ���� ���Դϱ�?\n");
	scanf_s("%d", &answer);

	switch (answer) {
	case 6:
		printf("�¾ҽ��ϴ�.\n");
		break;

	default:
		printf("Ʋ�Ƚ��ϴ�.\n");
		break;
	}

	//�ǽ�3
	printf("\n���� �Է��ϰ� ���͸� ġ�ÿ�. ==>");
	scanf_s("%d",&b);
	for (a = 1; a < 10;a ++) {
		printf("%d * %d  = %d\n", b, a, b * a);
	}

	//�ǽ�4
	printf("\n");
	while (1) {
		printf("���� �� �Է� : ");
		scanf_s("%d", &n);
		if (n == 0) {
			break;
		}
		else 
			sum2 += n;
		printf("���ݱ��� �Է��� ���� ���� %d�Դϴ�. \n", sum2);
	}
	printf("���α׷� ����\n\n");

	//�߰� ����
	while(1){
		printf("����� �Է��ϼ��� : \n"); //�� ��� �� �Է�
		scanf("%d", &h);
		if(h>20){ //20���� ū�� �Է� �� �ٽ� �Է�
			printf("�ٽ� �Է����ּ���! \n\n");
			continue;
		}
		
		else if(h>0 && h<21){ //1~20���� �Է� ��
			hhalf = h/2; //�Է��� ��
			h = h-hhalf; //������ ���� ������
			for (t = 0; t <= hhalf; t++) //�Է��� ���� �ݸ�ŭ ����
			{
				for (e = 0; e < h - t; e++)	//h-t��ŭ ��ĭ���
				{
					putchar(' '); // ��ĭ���
				}
				for (s = 0; s < (2*t) - 1; s++)	//��ĭ���� ���� ����(2*hhalf)-1��ŭ
				{									   
					putchar('*'); // *���
				}
				printf("\n");
			}
			for (t = 0; t <= h; t++) //���� �Է� ����ŭ ����
			{
				for (s = 0; s < t; s++)		//t��ŭ ��ĭ���   
				{									   
					putchar(' '); // ��ĭ���
				}
				for (e = t; e < (2*h)-t-1; e++)	//(2*h)-t-1��ŭ ��ĭ��� 	
				{
					putchar('*'); // *���
				}
				printf("\n");
			}
		}
		return 0;
	}
}