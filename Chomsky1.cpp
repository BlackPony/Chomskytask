#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
using namespace std;

typedef struct 
{
		string left;
		string right;
} rule;



int Compare(string strterm, string str) 
{
		int i, j, n=0;
		for(i=0; i<strterm.length(); i++) 
        {
				for(j=0; j<str.length(); j++) 
                {
						if (strterm[i] == str[j]) 
                        {n++;break;}
				}
		}
		return n;
}

void Znacheniya(string left, int *n, string s1, string s2, rule tr[100], int P) 
{
	
	if ((*n) == 10)return;
	string str=left;
	str.replace(str.find(s1), s1.length(), s2);
	string s=str;
	
	if (Compare(tr[0].left, s) == 0)
    {
		cout  << s << endl;
		(*n)++;
		return;
	}
	
    for (int i=2; i<=P; i++) 
    {
		if (Compare(tr[0].left,tr[i].right) == 0)
			Znacheniya(s, n, tr[i].left, tr[i].right, tr, P);
	}
	for (int i=2; i<=P; i++) 
   {		
		if (Compare(tr[0].left,tr[i].right) != 0)
			 Znacheniya(s, n, tr[i].left, tr[i].right, tr,P);
	}
}

int main()
{
	rule t_rule[100];
	int P, n=0, nrule;
	string init;
	cout<<"Chomsky grammar generator "<<endl;
    cout << "\n\nWrite nonterminals: ";
	cin >> t_rule[0].left;	
	cout << "Write terminals: ";
	cin >> t_rule[0].right;		
	cout << "Write initial symbol: ";
	cin >> init;
	cout << "Write the number of rules: ";
	cin >> P;
	for (int i=1; i<=P; i++)
    {
		cout<<"\nWrite left part of "<<i<<" rule: ";
		cin>> t_rule[i].left;
		cout << "\nWrite right part of "<<i<<" rule: ";
		cin >> t_rule[i].right;
		
		if (t_rule[i].right == "e")
			t_rule[i].right="";	
	}

	Znacheniya(init, &n, t_rule[1].left, t_rule[1].right, t_rule,P);
	getch();
	return 0;
}
