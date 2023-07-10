//DFA that accepts strings with substring 001 over {0,1}
#include<stdio.h>
enum states{q0, q1, q2, qf};
enum states check(enum states, char);
int main()
{
	char string[20];
	enum states curr_state = q0;
	int i = 0;
	printf("Enter the binary string\t");
	gets(string);
	char ch = string[i];
	while (ch!= '\0')
	{
		curr_state=check(curr_state, ch);
		ch = string[++i];
	}
	if (curr_state ==qf)
	{
		printf("The string is accepted");
	}
	else
	{
		printf("The string is rejected");
	}
	return 0;
}
enum states check(states s, char ch)
{
	enum states curr_state;
	switch(s)
	{
		case q0:
			if(ch=='0')
			curr_state = q1;
			else 
			curr_state = q0;
			break;
		case q1:
			if(ch =='0')
			curr_state = q2;
			else 
			curr_state = q0;
			break;
		case q2:
			if(ch =='0')
			curr_state = q2;
			else
			curr_state = qf;
			break;
		case qf:
			if(ch == '0' || ch == '1')
			curr_state = qf;
			break;
	}
	return curr_state;
}

