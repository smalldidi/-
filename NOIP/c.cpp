#include<iostream>
using namespace std;
int a[100000]={1},N,n=0,k=0;
int main(){
    scanf("%d",&N);
    for(int j=2;j<=N;j++){
        for(int i=0;i<=k;i++){
            a[i]*=j;
        }
        for(int i=0;i<=k;i++){
            if(a[i]>9){
                a[i+1]+=a[i]/10;
                a[i]%=10;
                if(i==k)k++;
            }
        }
	}
	if(a[n+1]>0){
        n++;
    }

    for(int i=k;i>=0;i--)cout<<a[i];

}

