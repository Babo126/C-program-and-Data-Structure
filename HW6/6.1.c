#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//函數先宣告
int isPrime(int); 
int isCirPrime(int);

int main(){
	int i, j;
	int count = 0;
	printf("Please input a range[i, j]: ");
	//重複輸入
	while(scanf("%d %d", &i, &j) != EOF){
		//錯誤值處理
		if(i<10 || j>200000){
			printf("Wrong Input.\n");
			continue;
		}

		//在[i, j]範圍中，若k為質數則繼續檢查k的循環數是否皆為質數
		int k;
		for(k=i;k<j;k++){
			if(isPrime(k)){
				if(isCirPrime(k)){
					count++;
				}
			}
		}

		//輸出
		if(count == 0){
			printf("No Circular Primes.\n");
		}
		else{
			printf("%d Circular Primes.\n", count);
		}
		
		printf("Please input a range[i, j]: ");
	}
} 

//質數檢查函數
int isPrime(int n){
	int i;
	if(n == 1){
		return 0;
	}	
	for(i=2;i*i<=n;i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}

//循環數質數檢查函數
int isCirPrime(int n){
	//計算有幾位數
	int i = n; //替身 
	int num = 0; //位數 
	while(i > 0){
		num++;
		i/=10;
	} 
	
	//若有n位數，則會循環n次 
	int j;
	int k = n;
	for(j=0;j<num;j++){
		//變成下一個循環數 
		int tmp = k % 10;
		k = k/10 + tmp * pow(10, num-1);
		
		//若有循環數非質數，則回傳false 
		if(!isPrime(k)){
			return 0;
		} 
	}
	return 1;
}
