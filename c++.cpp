#include<bits/stdc++.h>
using namespace std;
 //pass by value
void doSomething(int num){
    cout<<num<<endl;
    num+= 5;
    cout<<num<<endl;
}
//pass by reference
void doSomething( int &num){
    cout<<num<<endl;
    num+= 5;
    cout<<num<<endl;
}
int main(){
    char a;
    cin>>a;
    cout<< "Keep it up"<< a <<endl;
    //If_else 
    int age; 
    cin>>age;
    if(age>=18){
        cout<<"you are an adult"<<endl;
    }
    else {
        cout<< "you are not an adult" <<endl;
    }
    /*Take age fromthe user and decide accodingly
    1. if age <18
        print "not eligible for job"
    2. if age >= 18 and < 54
        print " eligible for job"
    3. if age>=54 and <=57 
        print "eligible for job, but retirement soon"
    4. if age>57
        print "retirement soon" */
    int AGE;
    cin>> AGE;
    if(AGE<18){
        cout<< "not eligible for job"<< endl;}
    //else if (AGE>=18 && AGE< 54) -> we can write this but if it is coming under
    // else part then for sure it is >18 
    else if( AGE> 54){
        cout<<"eligible for job";
        if(AGE<=57){
            cout<<", but retirement soon"<<endl;
        }
    }
    else if(AGE>57){
        cout<<"retirement time";
    }
    //FUNCTIONS: Functionis a set of codes which performs smthng for u
    // Functions are used to modularise code
    // Functions are used to increase readability
    //Functions are used to use same code multiple time
    // types: void- doesn't return anything
    // return, parametrized , non-parameterized

    //pass by value 
   // int num;
    //num=10;
    //doSomething(num);
    //cout << num<< endl;

    //pass by refrence
    //doSomething(num);
    //cout<< num<< endl;
   
    //return 0;
    //}
    
    
