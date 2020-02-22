#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <cstdlib>
//Merge Sort
using namespace std;

void fnGenRandInput(int[], int);
void fnDispArray(int [], int);
void fnMerge(int [], int, int, int);
void fnMergeSort(int[], int, int);






int main( int argc, char **argv)
{



     FILE *fp;
     struct timeval tv;
     double dStart, dEnd;
     int iaArr[500000], iNum, iKey, i, iChoice;

     for(;;){


     cout<<"\n"<<"1.Plot the Graph"<<endl;
     cout<<"\n"<<"2.MergeSort"<<endl;
     cout<<"\n"<<"3.Exit"<<endl;
     cout<<"\n"<<"Enter your choice"<<endl;
     cin>> iChoice;

     switch(iChoice){

       case 1:
       fp=fopen("MergePlot.dat", "w");
       for(i=100; i<100000; i+=100)
         {
            fnGenRandInput(iaArr, i);

            gettimeofday(&tv, NULL);
            dStart = tv.tv_sec + (tv.tv_usec/1000000.0);
            fnMergeSort(iaArr, 0, i-1);
            gettimeofday(&tv, NULL);
            dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);
            fprintf(fp, "%d\t%lf\n", i, dEnd-dStart);
         }
            fclose(fp);


            cout<<"\n"<<"Data File generated and stored in file <MergePlot.dat>"<<"\n"<<"Use a plotting utility"<<endl;
             break;

        case 2:
        cout<<"\n"<<"Enter the number of elements to sort."<<endl;
        cin>>iNum;
        cout<<"\n"<<"Unsorted Array."<<endl;
        fnGenRandInput(iaArr, iNum);
        fnDispArray(iaArr, iNum-1);
        fnMergeSort(iaArr, 0, iNum-1);
        cout<<"\n"<<"Sorted Array."<<endl;
        fnDispArray(iaArr,iNum);
        break;

        case 3:
        exit(0);
     }






     }




    return 0;
}

//Merge
void fnMerge(int a[], int low, int mid, int high){

     int i, k, j, b[500000];
     i=k=low;
     j = mid + 1;

     while(i<=mid &&j<=high){
        if(a[i]<a[j]){
          b[k++] = a[i++];

        }else{
            b[k++] = a[j++];
        }

     }
     while(i<=mid){

         b[k++]=a[i++];
     }
     while(j<high){
        b[k++] = a[j++];
     }
     for (i=low; i<k; i++){
        a[i]=b[i];
     }
}

//MergeSort

void fnMergeSort(int a[], int low, int high){
    int mid;
    if(low<high){
      mid=(low+high)/2;
      fnMergeSort(a,low,mid);
      fnMergeSort(a, mid+1, high);
      fnMerge(a, low, mid, high);
    }
}

void fnGenRandInput(int X[], int n){

   int i;
   srand(time(NULL));
   for(i=0; i<n; i++){
      X[i] = rand()%10000;
   }
}


void fnDispArray(int X[], int n){
  int i;

  for(i=0; i<n; i++){
     cout<<"\n"<<X[i];
  }
}







