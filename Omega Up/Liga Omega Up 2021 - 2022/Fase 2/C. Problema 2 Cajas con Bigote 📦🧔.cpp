#include<bits/stdc++.h>
#define MAX 1005

using namespace std;

double nums[MAX];

int main(){
	int n, i, cMen, cMay;
	double q1,q2,q3, j, d, iqr, li, ls, men, may, cajaU, cajaD, bigU, bigD;
	
	cin >> n;
	
	for(int k=0; k<n; k++){
		cin >> nums[k];
	}
	
	sort(nums, nums + n);
	
	if((n + 1) % 4 == 0){
		q1 = nums[(n + 1) / 4 - 1];
		q3 = nums[3 * (n+1) / 4 - 1];
	}
	else{
		j = (double) (n + 1) / 4;
		i = (int) j;
		d = j - (double) i;
		q1 = nums[i - 1] + d * (nums[i] - nums[i - 1]);
		
		j *= 3;
		i = (int) j;
		d = j - (double) i;
		q3 = nums[i - 1] + d * (nums[i] - nums[i - 1]);
	}
	
	if( n % 2 == 0){
		q2 = (nums[n / 2 - 1] + nums[n / 2]) / 2;
	}
	else
	{
		q2 = nums[(n + 1) / 2 - 1];
	}
	
	iqr = q3 - q1;
	
	
	li = q1 - iqr * 1.5;
	ls = q3 + iqr * 1.5;
	
	cMen = 0;
	while(nums[cMen] < li){
		cMen++;
	}
	men = nums[cMen];
	
	cMay = n - 1;
	while(nums[cMay] > ls){
		cMay--;
	}
	may = nums[cMay];
	
	cajaU = q3 - q2;
	cajaD = q2 - q1;
	
	bigU = may - q3;
	bigD = q1 - men;
	
	printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n", men, q1, q2, q3, may);
	
	if(cMen > 0){
		printf("%.0lf", nums[0]);
		for(int k = 1; k < cMen; k++){
			printf(" %.0lf", nums[k]);
		}
	}
	
	if(cMay < n - 1 && cMen <= 0){
		printf("%.0lf", nums[cMay + 1]);
		for(int k = cMay + 2; k < n; k++){
			printf(" %.0lf", nums[k]);
		}
	}
	else if(cMay < n - 1){
		for(int k = cMay + 1; k < n; k++){
			printf(" %.0lf", nums[k]);
		}
	}
	
	if(cMay >= n - 1 && cMen <= 0){
		cout << "No tiene";
	}
	cout << "\n";
	
	if(cajaU > cajaD){
		cout << "Caja Arriba\n";
	}
	else if(cajaU == cajaD){
		cout << "Nice Box!\n";
	}
	else{
		cout << "Caja Abajo\n";
	}
	
	if(bigU > bigD){
		cout << "Bigote Arriba\n";
	}
	else if(bigU == bigD){
		cout << "Bigotazo!\n";
	}
	else{
		cout << "Bigote Abajo\n";
	}
	
	printf("El IQR es: %.2lf", iqr);
	
	return 0;
}
