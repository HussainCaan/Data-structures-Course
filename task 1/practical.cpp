// #include <iostream>
// using namespace std;
// void mul(int a, int b, int *c)
// {
//     cout << a * b * (*c);
// }
// int main()
// {
//     int num = 20;
//     int *ptrnum = &num;
//     // int **dptr = &ptr;

//     // cout<<**dptr<<endl;
//     // cout<<ptr<<endl;
//     // cout<<*dptr<<endl;
//     // cout<<dptr<<endl;

//     void (*ptr)(int, int,int *);
//     ptr = &mul;
//     ptr(3,3,ptrnum);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void add(int *a,int *b,int *c);
// void r(int *a,int *b,int *d);
// int main(){
//     int a,b,c=0,d=0;
//     cin>>a>>b;
//     add(&a,&b,&c);
//     r(&a,&b,&d);
//     cout<<c<<d;
    

//     return 0;
// }

// void add(int *a,int *b,int *c){
    
//     *c=*a+*b;
    
// }
// void r(int *a,int *b,int *d){
    
//     *d=*a-*b;

// }