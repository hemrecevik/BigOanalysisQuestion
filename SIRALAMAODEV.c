#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys/time.h>



void Rastgele_Olustur(int dizi[],int n)
{
	int i=0;
	for(i;i<n;i++){
		dizi[i]=rand();
	}
}
void Sirali_Olustur(int dizi[],int n)
{
	int i=0;
	for( i;i<n;i++){
		dizi[i]=i+1;
	}
}
void TersSirali_Olustur(int dizi[],int n)
{
	int k=n;
	for(int i=0;i<n;i++){
		dizi[i]=k;
		k--;
	}
}

void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(int dizi[],int ilk,int son)
{
	if(ilk<son)
	{
		int orta=(ilk+son)/2;
		Mergesort(dizi,ilk,orta);
		Mergesort(dizi,orta+1,son);
		Merge(dizi,ilk,orta,son);
	}
	
}

int Partition(int dizi[],int alt_indis,int ust_indis)
{
	int i,j,pivot_degeri,pivot_indisi,gecici;
	pivot_degeri=dizi[alt_indis];
	j=alt_indis;
	for(i=alt_indis+1;i<=ust_indis;i++)
	if(dizi[i]<pivot_degeri)
	{
		j++;
		gecici=dizi[i];
		dizi[i]=dizi[j];
		dizi[j]=gecici;
	}
	pivot_indisi=j;
	gecici=dizi[alt_indis];
	dizi[alt_indis]=dizi[pivot_indisi];
	dizi[pivot_indisi]=gecici;
	return pivot_indisi;
}

void Quicksort(int dizi[],int alt,int ust)
{
	int pivot_indisi;
	if(ust>alt)
	{
		pivot_indisi=Partition(dizi,alt,ust);
		Quicksort(dizi,alt,pivot_indisi-1);
		Quicksort(dizi,pivot_indisi+1,ust);
	}
}

void insertion(int dizi[],int n)
{
	int i,j,mevcut;
	for(i=1;i<n;i++)
	{
		mevcut=dizi[i];
		j=i;
		while(j>0&&mevcut<dizi[j-1])
		{
			dizi[j]=dizi[j-1];
			j--;
		}
		dizi[j]=mevcut;
	}
	
}

void bubble(int dizi[],int n)
{
	int i,takas_oldu=0,gecici;
	while(takas_oldu==0)
	{
		takas_oldu=1;
		for(i=0;i<n-1;i++)
		{
			if(dizi[i]>dizi[i+1])
			{
				gecici=dizi[i];
				dizi[i]=dizi[i+1];
				dizi[i+1]=gecici;
				takas_oldu=0;
			}
		}
		n=n-1;
	}
	
}

void Selection(int dizi[],int n)
{
	int i,j,min,gecici;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		if(dizi[j]<dizi[min])min=j;
		
			gecici=dizi[min];
			dizi[min]=dizi[i];
			dizi[i]=gecici;
		
	}
	
}

main()
{
int dizi[10000],dizi2[50000],dizi3[100000],secim,secim2;
printf(" 1-RASTGELE OLUSTUR \n 2-SIRALI OLUSTUR \n 3-TERS SIRALI OLUSTUR \n");
scanf("%d",&secim);
switch(secim){
	case 1: Rastgele_Olustur(dizi,10000);
			Rastgele_Olustur(dizi2,50000);
			Rastgele_Olustur(dizi3,100000);
			break;
	case 2: Sirali_Olustur(dizi,10000);
			Sirali_Olustur(dizi2,50000);
			Sirali_Olustur(dizi3,100000);
			break;
	case 3: TersSirali_Olustur(dizi,10000);
			TersSirali_Olustur(dizi2,50000);
			TersSirali_Olustur(dizi3,100000);
			break;
	default:
			printf("HATA: Bilinmeyen bir deðer girdiniz!\n");
}
clock_t start, end;

printf("1-BUBBLE SORT \n 2-INSERTION SORT \n 3-MERGESORT \n 4-QUICKSORT \n 5-SELECTION SORT \n ");
scanf("%d",&secim2);
switch(secim2)
{
	case 1:
		printf("BUBBLE SORT SIRALAMA ALGORITMASINA GORE :\n");
			start=clock();
bubble(dizi,10000);
end = clock();
printf("10000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
bubble(dizi2,50000);
end = clock();
printf("50000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
bubble(dizi3,100000);
end = clock();
printf("100000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));
			break;
	case 2:printf("INSERTION SORT SIRALAMA ALGORITMASINA GORE :\n");
		start=clock();
insertion(dizi,10000);
end = clock();
printf("10000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
insertion(dizi2,50000);
end = clock();
printf("50000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
insertion(dizi3,100000);
end = clock();
printf("100000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));
		break;
	case 3:printf("MERGESORT SIRALAMA ALGORITMASINA GORE :\n");
		start=clock();
Mergesort(dizi,0,10000);
end = clock();
printf("10000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
Mergesort(dizi2,0,50000);
end = clock();
printf("50000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
Mergesort(dizi3,0,100000);
end = clock();
printf("100000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));
		break;
	case 4:printf("QUICKSORT SIRALAMA ALGORITMASINA GORE :\n");
		start=clock();
Quicksort(dizi,0,10000);
end = clock();
printf("10000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
Quicksort(dizi2,0,50000);
end = clock();
printf("50000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
Quicksort(dizi3,0,100000);
end = clock();
printf("100000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));
		break;
	case 5:printf("SELECTION SORT SIRALAMA ALGORITMASINA GORE :\n");
		start=clock();
Selection(dizi,10000);
end = clock();
printf("10000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
Selection(dizi2,50000);
end = clock();
printf("50000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));

start=clock();
Selection(dizi3,100000);
end = clock();
printf("100000 Elemanli Dizinin Maliyeti : %.2f\n",float(end-start));
		break;
	default:printf("HATA: Bilinmeyen bir deðer girdiniz!\n");	
}
	
}
