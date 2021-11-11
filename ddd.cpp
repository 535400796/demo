#include<iostream>
using namespace std;
int input[22][100002];
int res[3];
int lin[100002];
void maxsub(int *a){                                      //接收一维int数组，求出新的一维int数组dp, 
  lin[0]=0;                                               //dp[i]则假设为以a[i]为结尾的所有子序列中拥有最大和的那个和
  int max=INT_MIN,start=0,end=0;                          //因为dp[i]以a[i]为结尾，所以dp[i]中必有a[i]被加上
  for(int i=1;i<=a[0];i++){                              //则此时分dp[i-1]为正或为负两种情况，dp[i] = max( dp[i-1]+a[i]    ,  a[i]   )
      if(lin[i-1]+a[i]>a[i]){                               //111111111111111111111111
         lin[i]=lin[i-1]+a[i];
      }else{
          lin[i]=a[i];
      }
  }                                                               //22222222222222222222222222222
  for(int i=1;i<=a[0];i++){
      if(lin[i]>max){
          max=lin[i];
          end=i;
      }
  }
  for(int i=1;i<=end;i++){
      int s=0;
      for(int j=i;j<=end;j++){
         s+=a[j];
      }
      if(s==max){
          start=i;
          break;
      }
  }
  res[0]=max;
  res[1]=start;
  res[2]=end;
}


int main(){                           //主函数中只有获取出入，实现输出
    int T,n;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
       scanf("%d",&n);
       input[i-1][0]=n;
       for(int j=1;j<=n;j++){
           scanf("%d",&(input[i-1][j]));
       }
       
    }
     for(int i=1;i<=T;i++){
       maxsub(input[i-1]);
       printf("Case %d:\n",i);
       printf("%d %d %d\n",res[0],res[1],res[2]);
       if(i!=T){
           printf("\n");
       }
    }
}
