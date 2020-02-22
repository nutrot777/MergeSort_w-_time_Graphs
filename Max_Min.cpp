#include <iostream>

using namespace std;

// Program to find the maximum and mininum in a given lis
// of n elements using divide and conquer approach.

void fnRecMaxMin(int [], int, int, int*, int*);

int main(int argc, char **argv)
{
    int iaArr[500000], iNum, i;
      int iMax = 0;
      int iMin = 0;

      cout<<"\n"<<"Enter the size of the array: "<<endl;
      cin>>iNum;

      cout<<"\n"<<"Enter the elements of the array: "<<endl;
        for(i=0; i<iNum; i++){
            cin>>iaArr[i];
        }
    fnRecMaxMin(iaArr, 0, iNum-1, &iMax, &iMin);

    cout<<"\n"<<"Max Element = "<<iMax;
    cout<< "\n"<< "Min Element = "<<iMin;




    return 0;
}

// Max and Min Function

void fnRecMaxMin(int a[], int low, int high, int *max, int *min){
    int mid, max1, max2, min1, min2;

      if(high-low == 1){
           if(a[low]>a[high])
           {
              *max = a[low];
              *min = a[high];
           }
           else{
             *max = a[high];
             *min = a[low];
           }
      }
      else if(low == high)
      {
          *min = *max = a[low];
      }
      else if(low<high)
      {

      mid=(low+high)/2;

        fnRecMaxMin(a, low, mid, &max1, &min1);

        fnRecMaxMin(a, mid+1, high, &max2, &min2);
        if(max1>max2)
        {
        *max = max1;
        }else{
           *max = max2;
        }

        if(min1< min2){
           *min = min1;
        }else{
          *min = min2;
        }
      }

}

