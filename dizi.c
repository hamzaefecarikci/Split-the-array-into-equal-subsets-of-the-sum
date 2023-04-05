#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

bool diziBol(int dizi[], int n)//Dizi iki alt kumeye bolunur ve toplamlari kontrol edilir.
{
    int toplam_genel = 0;
    int i,j;
	
	for (i = 0; i < n; i++) 
	{
        toplam_genel += dizi[i];//dizinin elemanlari toplanir.
    }
    
	if (toplam_genel % 2 != 0) 
	{
        return false;
    }
    
	int toplam = toplam_genel / 2;
    
	bool dp[toplam + 1];
    
	for (i = 0; i <= toplam; i++) 
	{
        dp[i] = false;
    }
    dp[0] = true;
    
	for (i = 0; i < n; i++) 
	{
        for (j = toplam; j >= dizi[i]; j--) 
		{
            dp[j] = dp[j] || dp[j - dizi[i]];
        }
    }
    return dp[toplam];
}

int main() 
{
	int i;
	int n;
	
	printf("Dizinin eleman sayisini giriniz:\n");//Dizinin eleman sayisi kullanicidan istenir.
	scanf("%d",&n);
	
    int dizi[n];
    
    printf("Dizinin elemanlarini giriniz:\n");//Dizinin elemanlari kullanicidan istenir.
    for(i = 0; i < n; i++)
    {
    	scanf("%d",&dizi[i]);
	}
    
    if (diziBol(dizi, n)) //Veriler fonksiyona gonderilir.
	{
        printf("Dizi, toplamlari esit olan iki alt kumeye bolunebilir.\n");
    }
    else 
	{
        printf("Dizi, toplamlari esit olan iki alt kumeye bolunemez.\n");
    }
    return 0;
}
