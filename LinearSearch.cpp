#include <iostream>

//Linear Search Implementation; recursively




using namespace std;

int fnLinearSearch(int [], int, int);

int main(void)
{
       int iaArr[20], iNum, iKey;

       int i, iPos=0;

       cout<<"\n"<<"Enter the size of the array: "<<endl;
       cin>>iNum;

       cout<<"\n"<<"Enter the elemnents of the array: "<<endl;
       for(i=0; i<iNum; i++){
             cin>>iaArr[i];
       }

     cout<<"\n"<<"Enter the key element: "<<endl;
       cin>>iKey;

       iPos = fnLinearSearch(iaArr, iKey, iNum);


     if(iPos == -1){
       cout<<"\n"<<"Element not found"<<endl;
     }else{
        cout<<"\n"<<"Element found at Position: "<<iPos;
        }

    return 0;
}


int fnLinearSearch(int A[], int k, int iN){

     if(iN==0){
       return -1;
     }else if(k == A[iN-1]){
       return iN;
     }else{
       return fnLinearSearch(A, k, iN-1);
     }

}

