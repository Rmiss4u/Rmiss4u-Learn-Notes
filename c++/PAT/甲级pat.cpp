//PAT (Basic Level) Practice �����ģ�

//1002 д������� ��20 �֣�
/*
����һ�������� n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�
�����ʽ��
ÿ������������� 1 ��������������������Ȼ�� n ��ֵ�����ﱣ֤ n С�� 10
100
��
�����ʽ��
��һ������� n �ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ��� 1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
����������
1234567890987654321123456789
���������
yi san wu
*/
/*#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main (){
	char a[200];
	int i=0,m=0,sum=0;
	int t,p;
	cin>>a;
	while(a[i]!='\0')
	{
		sum+=a[i]-48;
		i++;
	}
	p=sum;
	if(sum==0)printf("ling");
	while(sum!=0)
	{
	t=sum%10;
	sum/=10;
	m=m*10+t;	
	}
	while(m>0)
	{
		t=m%10;
		m/=10;
		switch(t)
		{
		case 0:cout<<"ling";break;
		case 1:cout<<"yi";break;
		case 2:cout<<"er";break;
		case 3:cout<<"san";break;
		case 4:cout<<"si";break;
		case 5:cout<<"wu";break;
		case 6:cout<<"liu";break;
		case 7:cout<<"qi";break;
		case 8:cout<<"ba";break;
		case 9:cout<<"jiu";
		}
		if(m!=0)printf(" ");
	}
	if(p>0)
	{
		while(p%10==0)
		{
			p/=10;
			cout<<" "<<"ling";
		}
	}
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
	char n;
	int sum=0,i=0;
	while((n=getchar())!='\n'&&i<101)
		{
		sum+=(n-'0');
		i++;
		}
	char shu[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int s1,s2,s3;
	s1=sum/100;
	s2=(sum/10)%10;
	s3=sum%10;
	if(s1)
		printf("%s ",shu[s1]);
	if(s1!=0||(s1==0&&s2!=0))
		printf("%s ",shu[s2]);
	printf("%s",shu[s3]);
	return 0;
}
*/
//1004 �ɼ����� ��20 �֣�
/*
���� n�� > 0����ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
�����ʽ��
ÿ������������� 1 ��������������ʽΪ
�� 1 �У������� n
�� 2 �У��� 1 ��ѧ�������� ѧ�� �ɼ�
�� 3 �У��� 2 ��ѧ�������� ѧ�� �ɼ�
... ... ...
�� n + 1 �У��� n ��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������ 10 ���ַ����ַ������ɼ�Ϊ 0 �� 100 ֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ��
��ÿ������������� 2 �У��� 1 ���ǳɼ����ѧ����������ѧ�ţ��� 2 ���ǳɼ����ѧ����������ѧ�ţ��ַ������� 1 �ո�
����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
*/
/*
#include <iostream>
#include <string>
using namespace std; 
int main() {
	int n(0); // ѧ������
	cin >> n;
	string max_name(""), max_id(""),min_name(""), min_id("");
	int max(0), min(101);  //��¼�����С����
	for(int i=0;i<n;i++) {
	    string temp1, temp2;
	    int temp3;
	    cin >> temp1 >> temp2>>temp3;
	    if(temp3>max){
	    	max =temp3;
	    	max_name=temp1;
	    	max_id = temp2;
		}
		if(temp3<min){
			min = temp3;
			min_name=temp1;
			min_id=temp2;
		}
	}
	cout << max_name << " " << max_id<<endl;
	cout << min_name << " "<< min_id; 
	return 0;
}
*/
//1008 ����Ԫ��ѭ���������� ��20 �֣�
/*
һ������A�д���N�� > 0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M����0����λ�ã�����A�е������ɣ�A
0
A
1
?A
N?1
���任Ϊ��A
N?M
?A
N?1
A
0
A
1
?A
N?M?1
�������M����ѭ��������ǰ���M��λ�ã��������Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����
�����ʽ :
ÿ���������һ��������������1������N��1��N��100����M����0������2������N��������֮���ÿո�ָ���
�����ʽ :
��һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�
�������� :
6 2
1 2 3 4 5 6
������� :
	5 6 1 2 3 4
	*/
/*
#include<iostream>
#include<stdio.h>
using namespace std;
void Change(int *Ary,int M,int N);
int main()
{
    int M,N;
    cin>>M;
    cin>>N;
    int NumAry[220]={0};
    for(int i=0;i<M;i++)
    {
        cin>>NumAry[i];
        NumAry[i+M]=NumAry[i];
    }
    Change(NumAry,M,N);
    for(int i=0;i<M;i++)
    {
        if(i!=0)
        printf(" "); 
        cout<<NumAry[i];    
    }
}
void Change(int *Ary,int M,int N)
{
    int index=M-N;
    int count=N;
    if(N>=M)
    {       
        index=M-(N-M);
        count=N-M;
    }
    for(int i=0;i<M;i++)
    {
        if(i<count)
        {   
            Ary[i]=Ary[i+M+index];
            continue;
        }   
        Ary[i]=Ary[i+index];
    }
}
*/
/*
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main (){
	char a[200];
	int n,m,i,j,t;
	cin>>n>>m;
	gets(a);
	for(i=0;a[i]!='0';i++) ;
	a[i]=' ';
	j=i;
	for(i++,t=0;i<=2*j-1;i++,t++)
		a[i]=a[t];
	for(i=n+m;i<=3*n+m-2;i++)
		cout<<a[i];	
	return 0;	
}
*/
/*
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main (){
	char a[200];
	char b[200];
	int n,m,i,j;
	cin>>n>>m;
	gets(a);
	for(i=0,j=0;a[i]='\0';i++)
		if(a[i]!=' ')	
		{
		b[j]=a[i];
		j++;
		}
	for(i=n,j=0;i<=2*n-m;i++,j++)
		b[i]=b[j];
	for(i=0;i<n;i++)
		cout<<b[i]<<' ';
	cout<<b[n];
	return 0;	
} 
*/
//1009 ˵���� ��20 �֣�
/*
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������
�����ʽ��
�����������һ��������������һ���ڸ����ܳ��Ȳ����� 80 ���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮���� 1 ���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�
�����ʽ��
ÿ���������������ռһ�У���������ľ��ӡ�
����������
Hello World Here I Come
���������
Come I Here World Hello
*/
/*
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int i, l, j, k;
	int flag = 0;
	string s;
	getline(cin, s);
	s = ' ' + s;
	l = s.length();
	j = l - 1;
	for (i = l - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			if (flag == 1)
				cout << ' ';
			else
				flag = 1;
			for (k = i + 1; k <= j; k++)
				cout << s[k];
			j = i - 1;
		}
	}
	return 0;
}
*/
//1011 A + B �� C ��15 �֣�
/*
��������[?2
31
, 2
31
] �ڵ� 3 ������ A��B �� C�����ж� A + B �Ƿ���� C��
�����ʽ��
����� 1 �и��������� T(��10)���ǲ��������ĸ����������� T �����������ÿ��ռһ�У�˳����� A��B �� C���������Կո�ָ���
�����ʽ��
��ÿ�������������һ������� Case #X: true ��� A + B > C��������� Case #X: false������ X �ǲ��������ı�ţ��� 1 ��ʼ����
����������
4
1 2 3
2 3 4
2147483647 0 2147483646
0 - 2147483648 - 2147483647
���������
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
/*
#include <iostream>
using namespace std;
int main()
{
	int n, i;
	double a, b, c;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		if (a + b > c)
			cout << "Case #" << i + 1 << ": true" << endl;
		else
			cout << "Case #" << i + 1 << ": false" << endl;
	}
	return 0;
}
*/
//1016 ����A + B ��15 �֣�
/*
������ A �ġ�D
A
��Ϊ 1 λ���������֡�����Ϊ�� A ������ D
A
��ɵ������� P
A
�����磺���� A = 3862767��D
A
= 6���� A �ġ�6 ���֡�P
A
�� 66����Ϊ A ���� 2 �� 6��
�ָ��� A��D
A
��B��D
B
�����д������� P
A
+ P
B
��
�����ʽ��
������һ�������θ��� A��D
A
��B��D
B
���м��Կո�ָ������� 0 < A, B < 10
	10
	��
	�����ʽ��
	��һ������� P
	A
	+ P
	B
	��ֵ��
	�������� 1��
	3862767 6 13530293 3
	������� 1��
	399
	�������� 2��
	3862767 1 13530293 8
	������� 2��
	0
	*/
