#include<iostream>
#include<algorithm> //this has the sort function
using namespace std;


//sort function uses a combination of insertion sort, quicksort, heapsort
//O(nlog(n))

//it takes in 3 arguments, first two are definitely pointers

//1st & 2nd Argument
//first argument is the pointer from where it has to start sorting and the second argument is till which pointer it has to sort
//make sure to arr+n where n is position and NOT index

//3rd Argument
//third argument can be any from the below 2
//a) function name ONLY and returns bool (no parenthesis even if it takes in arguments, except greater() function) 
//b) a lambda expression as demonstrated below

//5 ways to sort
//1) Ascending order, return a<b;
//2) Descending order, return a>b; greater<int>(); (3rd argument directly)
//3) Reverse the vector, return true;
//4) No sort, return false;
//5) above type but for user defined data types (ex: complex), then create a lambda expression or a function where it accesses the parameters of your user defined data type and returns any of the above 4 possibilities 



class box{
    public:
    int dim;
    box(int a):dim(a){}
};

//ascending order
//it swaps a and b if this funciton returns true, hence swap if first number is smaller than the second one for an ascending order sort
bool compare(int a, int b){return a<b;}

int main(){
    //sort user defined data types
    box warehouse[]={box(10),box(2),box(50),};
    sort(warehouse,warehouse +3,[](auto a, auto b){return a.dim>b.dim;}); //lambda expression
    for(auto i: warehouse){
        cout<<i.dim<<" ";
    }
    cout<<endl;

    //sort array
    int arrs[5]={5,4,3,2,1};
    sort(arrs,arrs+5,compare); //just function name
    cout<<"Sorted array: "<<endl;
    for(auto i:arrs){cout<<i<<" ";}
    return 0;
}
 