#include <bits/stdc++.h>
#include <initializer_list>
#include <unordered_map>
#include <bits/stdc++.h>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <memory>
#include <string>
#include <ctime>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <cctype>

using namespace std;

/*
B3601 [ͼ��������ṹ 201] ���·����_1

��Ŀ����

����һ�� nnn ���㡢mmm ���ߵ�����ͼ���� 111 �ŵ㵽ÿ��������·�����ȡ�

ע�⣬ͼ���ܴ����رߺ��Ի�����֤�����ڸ�����
�����ʽ

��һ���������� n,mn, mn,m��

������ mmm �У�ÿ���������� ui,vi,wiu_i, v_i, w_iui?,vi?,wi?����ʾһ���� uiu_iui? �� viv_ivi? ����Ϊ wiw_iwi? ������ߡ�
�����ʽ

һ�� nnn ���������� iii ��������ʾ 111 �� iii �����·�����ȣ���������ڴ� 111 �� iii ��·����� iii �������� ?1-1?1 �����
�����������
���� #1

4 5
1 2 1
2 3 4
1 3 3
4 1 5
3 1 2

��� #1

0 1 3 -1

���� #2

10 50
5 9 6
1 3 10
3 1 1
10 2 5
8 5 1
10 10 6
6 5 2
1 5 10
2 5 5
10 1 4
1 5 2
8 8 7
7 2 7
9 2 8
3 1 4
6 2 5
3 9 9
4 9 5
5 10 9
10 1 9
5 4 5
9 1 2
5 10 6
3 8 7
10 3 7
5 8 8
9 2 6
9 8 6
3 2 8
1 3 8
1 10 1
7 8 4
9 4 5
4 6 2
2 7 6
10 1 5
9 9 7
6 7 4
1 1 7
8 3 10
8 3 9
10 9 8
3 9 1
7 4 8
1 5 4
8 4 4
3 4 4
9 9 2
2 10 4
8 9 6

��� #2

0 6 8 7 2 9 12 10 8 1

˵��/��ʾ

����û�в��ַ֡�

�����������ݣ�1��n,m��2��1031\leq n,m \leq 2\times 10^31��n,m��2��103��?109��wi��109-10^9\leq w_i\leq 10^9?109��wi?��109��

��ע����Ͻ�Ĵ�С��������Ҫʹ�� C++ �е� long long int ���͡�

code:
int n, m;
long long dis[2001];
struct P {
	int x, y, z;
} a[2001];
int main() {//����ͼ ������-�����㷨 Bellman_Ford
    cin>>n>>m;
	for (int i = 1; i <= n; ++i) 
        dis[i] = 1e18;
	dis[1] = 0;
	for (int i = 1; i <= m; ++i) 
        cin>>a[i].x>>a[i].y>>a[i].z;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			if (dis[a[j].y] > dis[a[j].x] + a[j].z) 
                dis[a[j].y] = dis[a[j].x] + a[j].z;
	}
	for (int i = 1; i <= n; ++i)
        dis[i]==1e18?cout<<-1<<" ":cout<<dis[i]<<" "; 
    return 0;
}

*/

/*
B3603 [ͼ��������ṹ 301] ���������_1

��Ŀ����

����ɢ��ѧ�γ̵�ѧϰ�У����ѧϰ���������ص�֪ʶ�����������һ�´�ҵ�ѧϰ�����

����һ�� nnn ���� mmm ���ߵĴ�Ȩ��ͨ����ͼ����ı�Ŵ� 111 �� nnn�����ܴ����رߺ��Ի������ڣ������������ͼ�ܱ�Ȩ����С��֧��������������ı�Ȩ֮�͡������ҵ�һ��֧����������ѡ�ñߵı�Ȩ����С����������Ȩ�͡�
�����ʽ

��һ������������ n,mn, mn,m ���ֱ��ʾ��������ͼ�ĵ����ͱ�����

������ mmm �У�ÿ�������Ǹ����� u,v,wu, v, wu,v,w ��ʾһ������ uuu �� vvv �������������ߺ������ߵı�Ȩ www��
�����ʽ

�����һ��һ���Ǹ���������ʾ������ı�Ȩ֮�͡�
�����������
���� #1

4 5
1 3 1
1 2 2
2 3 0
3 4 3
1 4 8

��� #1

4

˵��/��ʾ

���������͡�

ѡ�� (1,3)(1,3)(1,3)��(2,3)(2,3)(2,3) �� (3,4)(3,4)(3,4) �������߹���һ��֧������

�����ݷ�Χ��

�����������ݣ����� 1��n��20001\leq n \leq 20001��n��2000��1��m��30001 \leq m \leq 30001��m��3000����Ȩ���� [0,109][0, {10}^9][0,109] �е���������֤�����ͼ�Ϸ���������Ŀ�е�����������

��ע����Ͻ�Ĵ�С��������Ҫʹ�� C++ �е� long long int ���͡�

code:
int fa[5001],n,m,sum,cnt;
struct Edge{
	int u,v,value;
	bool operator < (const Edge rhs)const{
		return value<rhs.value;
	}
}edge[3001];
int find_root(int x){ //���鼯
	return x==fa[x]?x:fa[x]=find_root(fa[x]);
}
int main(){//����ͼ ��С������ ��³˹���� Kruskal + ���鼯 + ����
	cin>>n>>m;
	for(int i=0;i<m;++i)
		cin>>edge[i].u>>edge[i].v>>edge[i].value;
	for(int i=0;i<=n;++i)
		fa[i]=i;
	sort(edge,edge+m);
    cnt=n;
	for(int i=0;i<=m;++i){
		int a=find_root(edge[i].u),b=find_root(edge[i].v);
		if(a!=b){
			fa[a]=b;
			cnt--;
			sum+=edge[i].value;
		}
	}
	cout<<sum;
	return 0;
}

*/

/*
B3604 [ͼ��������ṹ 302] ���������_2

��Ŀ����

����ɢ��ѧ�γ̵�ѧϰ�У����ѧϰ���������ص�֪ʶ�����������һ�´�ҵ�ѧϰ�����

����һ�� nnn ���� mmm ���ߵĴ�Ȩ��ͨ����ͼ����ı�Ŵ� 111 �� nnn�����ܴ����رߺ��Ի������ڣ������������ͼ�ܱ�Ȩ����С��֧��������������ı�Ȩ֮�͡������ҵ�һ��֧����������ѡ�ñߵı�Ȩ����С����������Ȩ�͡�
�����ʽ

��һ������������ n,mn, mn,m ���ֱ��ʾ��������ͼ�ĵ����ͱ�����

������ mmm �У�ÿ�������Ǹ����� u,v,wu, v, wu,v,w ��ʾһ������ uuu �� vvv �������������ߺ������ߵı�Ȩ www��
�����ʽ

�����һ��һ���Ǹ���������ʾ������ı�Ȩ֮�͡�
�����������
���� #1

4 5
1 3 1
1 2 2
2 3 0
3 4 3
1 4 8

��� #1

4

˵��/��ʾ

�����������ݣ����� 1��n��1000001\leq n \leq 1000001��n��100000��1��m��3000001 \leq m \leq 3000001��m��300000����Ȩ���� [0,109][0, {10}^9][0,109] �е���������֤�����ͼ�Ϸ���������Ŀ�е�����������

��ע����Ͻ�Ĵ�С��������Ҫʹ�� C++ �е� long long int ���͡�

code:
struct Edge{
    int from,to,w;
}edge[300001];
int n,m,num,num_edge,u,v,w,f[100001];
long long ans;
void add_edge(int from,int to,int w){
	edge[++num_edge]=(Edge){from,to,w};
}
bool cmp(Edge a,Edge b){return a.w<b.w;}
int findf(int u){return f[u]==u?u:f[u]=findf(f[u]);}
int main(){//����ͼ ��С������ ��³˹���� Kruskal + ���鼯 + ���� + �Ż�
    cin>>n>>m;
	for(int i=1;i<=n;i++)
        f[i]=i;
	for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
		add_edge(u,v,w);
	}
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(num==n-1)break;
        int from=edge[i].from,to=edge[i].to,w=edge[i].w,from_father=findf(from),to_father=findf(to);
        if(from_father==to_father)continue;
        f[from_father]=to_father;
        ans+=w;
        num++;
    }
    cout<<ans;
	return 0;
}

*/