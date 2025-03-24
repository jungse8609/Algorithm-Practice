#include <iostream>
#include <tuple>
#include "twofakes.h"
using namespace std;

int balance_a_a(int l[],int r[],int sz){
	int a1[11]={},a2[11]={};
	for(int i=0;i<sz;++i) a1[l[i]]=a2[r[i]]=1;
	return balance(a1,a2);
}

int balance_in(int arr[],int sz){
	int a1[11]={},a2[11]={};
	a1[arr[0]]=1;a2[arr[1]]=1;
	int res=balance(a1,a2);
	if(sz==2) return res==-1?arr[0]:arr[1];
	return res==-1?arr[0]:res==1?arr[1]:arr[2];
}

int main(){
	int fake1,fake2;
	load_coins();
	int a1[3]={1,2,3},a2[3]={4,5,6},a3[3]={7,8,9};
	int onetwo=balance_a_a(a1,a2,3),onethr=balance_a_a(a1,a3,3);

	if(onetwo==1){
		if(onethr==1) fake1=balance_in(a2,3),fake2=balance_in(a3,3); // a2 1, a3 1
		else if(onethr==0){ // a2, r 중 존재
			int a4[2]={4,5},a5[2]={6,10},res=balance_a_a(a4,a5,2);
			if(res==-1) fake1=a4[0],fake2=a4[1];
			else if(res==1) fake1=a5[0],fake2=a5[1];
			else fake1=balance_in(a4,2),fake2=balance_in(a5,2);
		}
	}
	else if(onetwo==-1){
		if(onethr==-1){ // a1, r 중 존재
			int a4[2]={1,2},a5[2]={3,10},res=balance_a_a(a4,a5,2);
			if(res==-1) fake1=a4[0],fake2=a4[1];
			else if(res==1) fake1=a5[0],fake2=a5[1];
			else fake1=balance_in(a4,2),fake2=balance_in(a5,2);
		}
		else if(onethr==0) fake1=balance_in(a1,3),fake2=balance_in(a3,3); // a1 1, a3 1
	}
	else{
		if(onethr==1){ // a3, r 중 존재
			int a4[2]={7,8},a5[2]={9,10},res=balance_a_a(a4,a5,2);
			if(res==-1) fake1=a4[0],fake2=a4[1];
			else if(res==1) fake1=a5[0],fake2=a5[1];
			else fake1=balance_in(a4,2),fake2=balance_in(a5,2);
		}
		else if(onethr==-1) fake1=balance_in(a1,3),fake2=balance_in(a2,3); // a1 1, a2 1
	}

	//cout<<"fake1 = "<<fake1<<", fake2 = "<<fake2;
	two_fakes(fake1,fake2);
}
