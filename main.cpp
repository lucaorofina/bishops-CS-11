#include<iostream>
#include<cmath>
using namespace std;
/*
 x
        x
    x
 
 c  0 1 2 3 4
 q [4,3,0,1,5]
 */

bool ok(int q[],int c, int n){
    //diagonal test
    for (int i=0; i<c; i++){
       //(q[i]/n=row)(q[i]%n=column)
        //q[c]/n)= (q[c]%n) = q[c]=where the bishop is on the board/n
       if(((q[i]/n)+(q[i]%n))==((q[c]/n)+(q[c]%n))) return false; //
       if(((q[i]/n)-(q[i]%n))==((q[c]/n)-(q[c]%n))) return false;
    }
    return true;
}

int factorial(int n){
    if (n==1) return n;
    return n*factorial(n-1);
}
void backtrack(int &c, int q[], int count, int n, int k){
    c--;
    if(c==-1){
        cout<<"bishops: "<<k<<"\n board: "<<n<<"\n solutions: "<<count/factorial(k)<<endl;
        delete []q;
        exit(1);
    }
}

int main(){
    int k,n;
    //ask user for number of bishops
    cout<<"Enter the number of bishops: ";
    cin>>k;//k=bishop
    cout<<"Enter a value for n as the size of your n x n board: ";
    cin>>n;
    while(n<k){
        cout<<"sorry, please enter a number bigger than the number of bishops: ";
        cin>>n;
    }
    //bishop solution code
    //sets the new array size.
    int *q=new int[k]; //pointer to q adress = bishop
    q[0]=0;//q[c]=where the bishop is on the board
    int count=0;//keeps count
    int c=0;//c=which # bishop
    bool from_backtrack=false;
    while(1){
        while(c<k){ //while we have more bishops to place
            if(!from_backtrack) //if we are coming from a backtrack, reset value of the bishop
                q[c]=-1;
            from_backtrack=false;
            //while we have not reached the ned of the board
            while(q[c]<n*n){//n*n because there are n*n spaces(boxes)on the board
                q[c]++; //place bishop on c column
                while(q[c]==n*n){ //
                    backtrack(c,q,count,n,k);
                    q[c]++;
                }
                if(ok(q,c,n)){ //if it is okay to put the bishop then put him, then ge the next bishop
                    c++;//next bishop
                    break;
                }
            }
        }
        count++;
        backtrack(c,q,count,n,k);
        from_backtrack=true;
    }
    return 0;
}
