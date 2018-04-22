#include <stdio.h>

#define MAX 5

int main(void)
{	// �ǽ�,������ ������
	int a = 10, b = 20, c = 30 ; //�ǽ� 1
	int number = 0;				 //�ǽ� 2
	int point = 0;				 //�ǽ� 3
	int year = 0, month = 0, maxDay = 0, validinput = 0; //�ǽ� 4
	int i, j;					 //�ǽ� 5
	int h, t, e ,s;              //����

	//�ǽ� 1��
	printf("\n================= �ǽ� 1 =================\n");
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + b++ �� ��� = %5d\n\n", a + b++);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta + ++b %% 3 �� ��� = %5d\n\n", a + ++b % 3);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\t++a / 2 + c++ �� ��� = %5d\n\n", ++a / 2 + c++);

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("\ta++ + ++b + ++c �� ��� = %5d\n\n", a++ + ++b + ++c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	printf("==========================================\n");

	//�ǽ� 2��
	printf("\n================= �ǽ� 2 =================\n");
	printf("���� ���� �ϳ��� �Է��ϼ���. ");
	scanf("%d", &number);
	printf("---> �Է��� �� %d ��(��) ",number);

	if(number % 2 == 0){
		printf("¦�� �Դϴ�.\n");
	}else{
		printf("Ȧ�� �Դϴ�.\n");
	}

	printf("==========================================\n");

	//�ǽ� 3��
	printf("\n================= �ǽ� 3 =================\n");
	printf("���α׷��� ��� ������ �Է��ϼ���. --> ");
	scanf("%d",&point);

	if( point >= 90 )
	{
		printf("���α׷��� ��� ������ A�Դϴ�.\n");
	}
	else if( point >= 80 )
	{
		printf("���α׷��� ��� ������ B�Դϴ�.\n");
	}
	else if( point >= 70 )
	{
		printf("���α׷��� ��� ������ C�Դϴ�.\n");
	}
	else if( point >= 60 )
	{
		printf("���α׷��� ��� ������ D�Դϴ�.\n");
	}
	else
	{
		printf("���α׷��� ��� ������ F�Դϴ�.\n");
	}

	printf("==========================================\n");

	//�ǽ� 4��
	printf("\n================= �ǽ� 4 =================\n");
	printf("��� ���� ������ ���� �Է��ϸ� �� ���� ������ �˷��帳�ϴ�. \n");
	printf("2003 2 : �Է� > ");
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
		printf("%d�� %d���� ������ %d�� �Դϴ�.\n", year, month, maxDay);
	else
		printf("�Է��� �߸��Ǿ����ϴ�.\n");

	printf("==========================================\n");

	//�ǽ� 5��
	printf("\n================= �ǽ� 5 =================\n");
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

	//����
	printf("\n�ڡ١ڡ١ڡ١ڡ� �� �� �ڡ١ڡ١ڡ١ڡ�\n");
	while(1){
		printf("������ �Է��� �ּ��� : [���� : 0]\n"); //�� ��� �� �Է�
		scanf("%d", &h);
		if(h==0){									   //0 �Է� �� ����
			return 0;
			printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
		}
		else if(h>10){								   //10�� �Ѵ� �� �Է� �� ���Է�
			printf("�ٽ� �Է����ּ���! \n\n");
			continue;
		}
		else{										   //���� ���� ��
			for (t = 0; t <= h; t++)				   //�Է��� ����ŭ ����
			{
				for (e = 0; e < h - t; e++)			   //�ټ�-t��ŭ ��ĭ���
				{
					putchar(' ');
				}
				for (s = 0; s < (2*t) - 1; s++)		   //��ĭ���� ���� ����(2*�Է��ټ�)-1��ŭ
				{									   // *���
					putchar('*');
				}
				printf("\n");
			}
		}
	}

}