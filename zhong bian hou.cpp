#include<iostream>
using namespace std;
#include<stack>
#include<string>
/*
逆波兰算法_中缀表达式转后缀表达式

1.初始化一个栈用来存放符号，关于数字直接在字符串+=；
2.遇到符号时，若栈内为空直接填入。
3.判断所持符号与栈顶符号的优先级关系“（”最高，若所持优先级小于或等于栈顶符号，则一直出栈并输出。

问题 ： 关于括号的问题暂时还没有 处理
*/

stack<char> a;
int youxian(char a_s, char b_zhan)
{
	if ((a_s == '*' || a_s == '/') && (b_zhan == '+' || b_zhan == '-'))
		return 1;
	if ((a_s == '+' || a_s == '-') && (b_zhan == '*' || b_zhan == '/'))
		return 0;
	if ((a_s == '+' || a_s == '-') && (b_zhan == '+' || b_zhan == '-'))
		return 0;
	if ((a_s == '*' || a_s == '/') && (b_zhan == '*' || b_zhan == '/'))
		return 0;
	if ((a_s == '*' || a_s == '/') && (b_zhan == '('))
		return 1;
	if ((a_s == '+' || a_s == '-') && (b_zhan == '('))
		return 1;
}
int j = 0;

void zhuanhuan(string s)
{

	int n = s.length();
	//char* b = new char[100];
	string b;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			b += s[i];
			while ('0' <= s[i + 1] && s[i + 1] <= '9')
			{
				i++;
				b += s[i];
				
			}
			j++;
			b += " ";
		
		}
		else{
			if (a.empty()){
				a.push(s[i]);
				
			}
			else{
				if ((a.top() == '+' || a.top() == '-') && (s[i] == '*' || s[i] == '/')&&(s[i]=='(')&&(a.top()=='(')){

					a.push(s[i]);
				}
				else{
					if (s[i] == ')')
					{
						while (!(a.top() == '('))
						{
							b+= a.top();
							a.pop();
							j++;
							b += " ";
						}
						if (a.top() == '('){
							a.pop();
						}
					}
					else
					{
						while (youxian(s[i], a.top())==0)
						{
							b+= a.top();
							j++;
							a.pop();
							b += " ";
							if (a.empty())
							{
								a.push(s[i]);
								break;
							}
						}
						if (youxian(s[i], a.top()) == 1){
							a.push(s[i]);
						}
					}


				}
			}
		}
	}
	while (!a.empty())
	{
		b += a.top();
		a.pop();
		b += " ";
	}
	cout << b;
}


int main()
{
	string m;

	cin >> m;
	zhuanhuan(m);
	//for (int i = 0; i < m.length(); i++){
	//	cout << m[i];
	//}
}