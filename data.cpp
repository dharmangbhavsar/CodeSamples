//templates??
#include <iostream>
using namespace std;
class number
{
  public:
    number() {cout<<"initialising number";} 
    virtual void comp()= 0;
    template <typename T> inline T const& min(T const& a, T const &b) 
    {
      return a>b ? b:a;
    }
};
class doubleNumber : public number
{
  public:
    doubleNumber(double a, double b) { f(a,b); cout<<"Initialising doubleNumber\n";}
    double a;
    double b;
    void f( double a, double b)
    {
      this->a = a;
      this->b = b;
    }
    void comp()
    {
      //return (this->a>this->b ? this->b:this->a);
      cout<<this->template min(this->a, this->b)<<endl;
    }
};
class integerNumber : public number
{
  private:
    int a;
    int b;
  public:
    integerNumber(int a, int b){ f(a,b); cout<<"initialising Integer Number\n";}
    void f(int a, int b)
    {
      this->a = a;
      this->b = b;
    }
    void comp()
    {
      //return double(this->a>this->b ? this->b:this->a);
      cout<<this->template min(this->a, this->b)<<endl;
    }
};
template <typename T>
inline T const& min(T const& a, T const &b)
{
  return a>b ? b:a;
}

template <typename T>
inline const T min(T const *a, T const *b)
{
  return *a>*b ? *b:*a;
}

using namespace std;

int main() {
  double a = 7.8, b = 8.9; int c = 13, d = 12; float  e = 10.5, f = 11.1;
  const double * pa = &a, *pb = &b;
  const int *pc = &c, *pd = &d;
  const float * pe = &e, *pf = &f;
  cout<<::min(a,b)<<endl;
  cout<<::min(c,d)<<endl;
  cout<<::min(e,f)<<endl;
  cout<<::min(pa,pb)<<endl;
  cout<<::min(pc,pd)<<endl;
  cout<<::min(pe,pf)<<endl;
  
  //number n;
  doubleNumber num1(1.5, 3.4);
  integerNumber num2(10,15);
  num1.comp();
  num2.comp();
  return 0;
}
