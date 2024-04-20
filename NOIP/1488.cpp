#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m,fu[100005],fz[20005][20005],sm[100005][2];
long long sum, mins = 1e16;
struct st{int a,b,v;}s[300005];
bool bmp(st a,st b){return a.v<b.v;}

void read(){
	int g1,g2,g3;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&g1,&g2,&g3);
		s[i].a=g1;s[i].b=g2;s[i].v=g3;
	}
}

void fjd(){
	for(int i=2;i<=n;i++){
		int fq=fu[i];
		while (fq){
			fz[fq][i]=1;
			fq=fu[fq];
		}
		fz[i][i]=1;
	}
}

int prim(){
	int sss=0;bool z[200005]={0,1};
	for(int i=1;i<n;i++){
		for(int k=1;k<=m;k++){
			if(z[s[k].a]+z[s[k].b]==1&& s[i].v <= 1e9){
				sss+=s[k].v;
				sm[i][0] = k;
                sm[i][1] = s[k].v;

				if(z[s[k].a]){
					z[s[k].b]=1;
					fu[s[k].b] =s[k].a;
				}
				else{
					z[s[k].a]=1;
					fu[s[k].a] =s[k].b;
					
				}
				//j=0;
				break;
			}
		}
	}
	return sss;
}

int prim2(){ // 更换第i条边，且能将两片节点连接在一起的最短边。按最小值模板记录。
    for (int i = 1; i < n; i++){ // 依次更换边共n-1边。
        int jie; // 被断开的节点。
        if (fu[s[sm[i][0]].a] == s[sm[i][0]].b)
            jie = s[sm[i][0]].a;
        else
            jie = s[sm[i][0]].b;
        for (int j = sm[i][0] + 1; j <= m; j++){ // 遍历所有边，（从替换边后开始。）
            if (fz[jie][s[j].b] + fz[jie][s[j].a] == 1 && s[j].v > sm[i][1]){
                if (s[j].v - sm[i][1] < mins)
                    mins = s[j].v - sm[i][1];
                break;
            }
        }
    }
    return mins;
}

int main(){
	read();
	sort(s+1,s+1+m,bmp);
	
	sum=prim();
	fjd();//printf("1111111");
	
	printf("%d",sum+prim2());
	return 0;
}