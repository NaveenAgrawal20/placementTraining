#include<iostream>
using namespace std;

template <class T>
class minElement
{
    // Complete the class.Make a private variable,constructors and method called
    // check() which takes one parameter and prints the output in new line. 
    private:
    T y;
    public:
    
        minElement(T elem){
            this->y = elem;
        }
        void check(T x){
            if (y > x){
                cout<<x<<"\n";
            }else{
                cout<<y<<"\n";
            }
        }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int c;
       cin>>c;
       if(c == 1){
           string a,b;
           cin>>a>>b;
           minElement<string> obj1(a);
           obj1.check(b);
       }else if(c==2){
           int a,b;
           cin>>a>>b;
           minElement<int> obj1(a);
           obj1.check(b);
       }
       else{
           char a,b;
           cin>>a>>b;
           minElement<char> obj1(a);
           obj1.check(b);
       }
   }
}