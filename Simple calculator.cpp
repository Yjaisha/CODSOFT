#include<iostream>
using namespace std;
int main()
{
	int number1,number2,add,sub,div,mul;
	char optr;
	cout<<"Enter The First Digit:";
	cin>>number1;
	cout<<"Enter The Operator:+,-,/,* :";
	cin>>optr;
	cout<<"Enter The Second Digit:";
	cin>>number2;
    switch(optr)
    {
    	case '+':
    	{
    		add=number1+number2;
    		//cout<<add<<"="<<number1<<"+"number2<<endl;
    		cout<<"Sum Of Addition:";
    		cout<<add;
    		break;
    	case '-':
		    sub=number1-number2;
			cout<<"Sum Of Subtraction:";
			cout<<sub;
			break;
		case '/':
		    div=number1/number2;
			cout<<"Sum Of Division:";
			cout<<div;
			break;
		case '*':
		    mul=number1*number2;
			cout<<"Sum Of Multication:";
			cout<<mul;
			break;	
		default:
		cout<<"Error! Operator is Not Correct";			
		}
	}
	return 0;
}
