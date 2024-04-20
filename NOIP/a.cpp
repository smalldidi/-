#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005], c[1000005],mmax;

int main(){
    
    
    for (int i = 0; i < s1.size(); i++){
        for(int k = 0; k < s2.size(); k++)
        c[i+k] += a[i] * b[k];
    }
    for (int i = 0; i <= s1.size()+s2.size()-2; i++){
            c[i + 1]+=c[i]/10;
            c[i] %= 10;
    }

    int n = 999;
    while (c[n] == 0){
        n--;
    }

    for (int i = n; i >= 0; i--)
        cout << c[i];
}