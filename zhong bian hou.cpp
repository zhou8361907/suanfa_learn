#include<iostream>
using namespace std;
#include<stack>
#include<string>
/*
�沨���㷨_��׺���ʽת��׺���ʽ

1.��ʼ��һ��ջ������ŷ��ţ���������ֱ�����ַ���+=��
2.��������ʱ����ջ��Ϊ��ֱ�����롣
3.�ж����ַ�����ջ�����ŵ����ȼ���ϵ��������ߣ����������ȼ�С�ڻ����ջ�����ţ���һֱ��ջ�������

���� �� �������ŵ�������ʱ��û�� ����
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