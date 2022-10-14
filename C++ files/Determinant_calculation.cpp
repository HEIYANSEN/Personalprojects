#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
double a[701][701];
int n;
double ans=1;
int special=99;
void test()
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int row(int i)//to inspect if there is column with all 0 elements
{
	for(int j=1;j<=n;j++) 
		if(a[i][j]!=0) return 1;
	return 0;
}
int column(int i)//to inspect if there is column with all 0 elements
{
	for(int j=1;j<=n;j++)
		if(a[j][i]!=0) return 1;
	return 0;
}
//For the lateset edit,these two steps are useless
 
void gauss(int k){
//	cout<<k<<endl;
	
	// to see if a[k][k] is 0,if so exchange the row,if not jump the step
	if(a[k][k]==0){
		int sign=-1;
		for(int i=k+1;i<=n;i++)
			if(a[i][k]!=0) {
				sign=i;
				break;
			}
		if(sign==-1) {
			special=1;
			return;
		}
		for(int i=1;i<=n;i++)
		{
			double temp;
			temp=a[sign][i];
			a[sign][i]=a[k][i];
			a[k][i]=temp;
			//swap the row
		}
		ans*=-1.0;
	}
	
	//the main step of gauss elimination
	for(int i=k+1;i<=n;i++){
		double t=a[i][k];
		for(int j=k;j<=n;j++)
		{
			a[i][j]=a[i][j]-((t*a[k][j])/a[k][k]);
		}
	}
	
//	test();
}
int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&a[i][j]);
	cout<<endl;
	//input all the elements
	
//	for(int i=1;i<=n;i++) 
//	{
//		if(row(i)==0){
//			printf(0);
//			return 0;
//		}
//		if(column(i)==0){
//			printf(0);
//			return 0;
//		}
//	}
	
	
	
	for(int i=1;i<n;i++) 
	{
		gauss(i);
		if(special==1){
			printf("0.000000");
			return 0;
		}
	}
	for(int i=1;i<=n;i++) ans*=a[i][i];
	
	if(abs(ans)<0.000001){
		printf("0.000000");
		return 0;
		//to prevent -0.000000 exsits
	}
	printf("%lf",ans);
	return 0;
}
