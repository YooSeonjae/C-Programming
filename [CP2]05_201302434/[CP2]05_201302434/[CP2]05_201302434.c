#include <stdio.h>
// �Լ� ����
int aaa(int su1,int su2); // �ǽ� 1
int add(int a, int b); // �ǽ� 2
int subtract(int a, int b); // �ǽ� 2
int getArea(int x, int y); //�ǽ� 3
int sum(int x); //�ǽ� 4
int prime_check(int checkNum); //���� 1
int rabbit_num(int num);//���� 2

int main(void)
{	
	//�ǽ�, ���� ����
	int result; //�ǽ� 1
	int v1, v2, m=10, n=20; //�ǽ� 2
	int a, b, result2; //�ǽ� 3
	int k, result3; //�ǽ� 4
	int inputNum, i, check; //���� 1
	int count = 0; //���� 1
	int total_num,num; //���� 2

	//�ǽ� 1
	result = aaa(5, 3);//aaa()�Լ� ȣ���ϸ鼭 �ΰ��� ���� ����, ������� result�� ����
	printf("aaa()�Լ��� ȣ���ϸ鼭 ���ڷ� 5�� 3 �����ؼ� ����� %d�� �˴ϴ�.\n\n", result); 
	//��ȯ�Ǿ� ���ƿ� int�� ����� ���

	//�ǽ� 2
	v1 = add(m,n);
	v2 = subtract(15,3) + 2;
	printf("%d %d %d \n\n",v1, v2, add(2,6) );

	//�ǽ� 3
	printf("�غ� ���� : ");
	scanf("%d", &a);
	printf("���� : ");
	scanf("%d", &b);
	result2 = getArea(a, b);
	printf("�簢���� ���̴� %d�Դϴ�. \n\n", result2);

	//�ǽ� 4
	printf("input your number = ");
	scanf("%d",&k);
	result3=sum(k);
	printf("1���� %d������ �� : %d \n\n", k, result3);

	//���� 1
	printf("N������ �Ҽ� ���ϱ�. N�� �Է����ּ��� : ");
	scanf("%d",&inputNum);
	for(i=2;i<=inputNum;i++) //�Ҽ��� 2���� �̹Ƿ� 2���� �Է��� ������ ����
	{
		check = prime_check(i); //2���� �ش� ������ �Ҽ����� Ȯ��
		if(check==1) //1�� ���� �� �Ҽ�
		{
			printf("%3d ", i);
			count++; //3���� ����ϱ� ���� �ϳ� ��´� count 1����
		}
		if(count==3) // 3�� �Է��� ������
		{
			printf("\n"); //�ٹٲٰ�
			count = 0; //�ʱ�ȭ
		}
	}
	printf("\n\n");

	//���� 2
	printf("1�� �Ŀ� ��ü �䳢�� ����?\n");
	for(num=0; num<12;num++){ //�Ŵ� �䳢�� ���� �˱� ���� 12�� ����
		printf("%d ",rabbit_num(num));//�ش� �޿� �䳢�� ��
	}
	printf("\n\n");
	return 0;
}

//�Լ� ����
// �ǽ� 1
int aaa(int su1, int su2) {//�Ű������� �ΰ��� int�� ����

	int hap; //��ȯ�� �� int�� hap
	hap = su1 + su2; //�μ��� ��
	return hap; //ȣ���� ������ ��ȯ�� int�� return��
}

// �ǽ� 2
int add(int a, int b) { //�Լ� add����      
	return(a + b);
}
int subtract(int a, int b) { //�Լ� subtract ����
	int diff;
	diff = a - b;                       
	return diff;
}

//�ǽ� 3
int getArea(int x, int y){
	return x * y;
}

//�ǽ� 4
int sum(int x){
	if(x<=1){
		return 1;
	}
	else{
		return x + sum(x-1);
	}
}

//���� 1
int prime_check(int checkNum){ //�Ҽ����� �Ǵ��ϴ� �޼ҵ�
	int i;
	int a; //������ �������� Ȯ���ϴ� ����
	int count = 0; //������ ������ ���� ���� ����

	for(i=2;i<=checkNum;i++){
		if(count >=2) //1�� �ڽ��� �ƴ� �ٸ� ���ε� �������� ���
		{
			break;
		}
		a = checkNum%i; 
		if(a==0) //������ ��������
		{
			count++; //count 1����
		}
	}
	if(count < 2){ //count�� 2���ϸ� �ڽŸ� ������ ������
		return 1;
	}
	else{ //�Ҽ��� �ƴ�
		return 0;
	}
}

//���� 2
int rabbit_num(int n){
	if(n==0||n==1){ //ù��° �ް� �ι�° ���� 1���� �䳢
		return 1;
	}
	else{ //�Ǻ���ġ ������ ���·� �䳢�� �����Ͽ� ��ͷ� ����
		return rabbit_num(n-1) + rabbit_num(n-2);
	}
}