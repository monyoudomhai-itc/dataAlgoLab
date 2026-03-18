#include <iostream>
#include <cmath>
using namespace std;

void converttoF()
{
    float c;
    cout<<"Enter temperature in Celcius :";
    cin>>c;
    cout<<"Fahrenheit : "<<((c*9.0/5.0)+32)<<endl;
}
void converttoC()
{
    float f;
    cout<<"Enter temperature in Fahrenheit :";
    cin>>f;
    cout<<"Celcius : "<<((f-32)*50/9.0)<<endl;
}
void root()
{
   int a,b,c;
    float x,y;

    cout<<"Find root of quadratic equation aX^2 + bX + c = 0"<<endl;
    cout<<"Enter numbers"<<endl;

    cout<<"a : "; cin>>a;
    cout<<"b : "; cin>>b;
    cout<<"c : "; cin>>c;

    float theda = sqrt(b*b - 4*a*c);

    x = (-b - theda) / (2*a);
    y = (-b + theda) / (2*a);

    cout<<"x1 = "<<x<<endl;
    cout<<"x2 = "<<y<<endl;
}
void bmi()
{
    cout<<"Enter your name : ";
    string name;
    cin>>name;
    cout<<"Enter your wieght : ";
    float w;
    cin>>w;
    cout<<"Enter your hieght(cm): ";
    float h;
    cin>>h;
    float bmi = w*(h/w);
    string result;
    if (bmi<18.5){result = "under wieght";}
    else if(bmi<25){result ="normal wieght";}
    else if (bmi<30){result = "over wieght";}
    else{result ="obese";}
    cout<<"hello , "<<name<<"You are "<<result<<endl;

}
void  sum()
{
    int n;
    int total;
    cout<<"Sum number from 1 to n except number that are divisible by 3"<<endl;
    cout<<"Enter number n: ";
    cin>>n;
    for (int i =0 ; i<=n;i++)
    {   
        if (i % 3 == 0)
        {
            total = total;
        }
        else{
        total = total + i;
        }
    }
    cout<<"Total : "<<total<<endl;
}
int main()
{
    while (true){
    cout <<" 5 function defferently \n";
    cout<<"1.convert temperature Celsius to Fahrenheit\n";
    cout<<"2.temperature Fahrenheit to Celsius \n";
    cout<<"3.Find the root \n";
    cout<<"4.compute BMI\n";
    cout<<"5.sum number\n";
    cout<<"0 for exit \n";
    int n;
    cout<<"Choose number : ";
    cin>>n;
    switch (n)
    {
    case 1:
        converttoF();
        break;
    case  2:
        converttoC();
        break;
    case 3 :
        root();
        break;
    case 4 :
        bmi();
        break;
    case 5 :
        sum();
        break;
    case 0 :
        return 0;
        break;
    default:
        cout<<"Invalid number \n";
        break;
    }
    }
}