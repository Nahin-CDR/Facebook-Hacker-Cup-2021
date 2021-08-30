#include<bits/stdc++.h>
using namespace std;

bool checker(char ch)
{
	char vArray[5] = {'A','E','I','O','U'};
	for(int i=0; i<5; i++)
	{
		if(ch==vArray[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int line = 1;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;map<char,int>vwl;bool V_exist = false;bool C_exist = false;map<char,int>cns;
		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == 'A' or s[i] == 'E')
			{
				++vwl[s[i]];
				V_exist = true;
			}
			else if(s[i] == 'I' or s[i] == 'O')
			{
				++vwl[s[i]];
				V_exist = true;
			}
			else if(s[i] == 'U')
			{
				++vwl[s[i]];
				V_exist = true;
			}
			else
			{
				++cns[s[i]];
				C_exist = true;
			}
		}
		int maxC = -1;
		int maxV = -1;
		
		char vowl;
		for(auto it:vwl)
		{
			if(maxV<it.second)
			{
				maxV = it.second;
				vowl = it.first;
			}
		}
		char constt;
		for(auto it:cns)
		{
			if(maxC<it.second)
			{
				maxC = it.second;
				constt = it.first;
			}
		}
		
		if(V_exist == true and C_exist == false)
		{
			if(vwl.size()==1)
			{
				cout<<"Case #"<<line<<": ";
				cout<<0<<endl;
				line++;
				continue;
			}
			else
			{
		        int counter = 0;
		        for(int i=0; i<s.size(); i++)
		        {
			        if(vowl == s[i])
			        {
				        continue;
			        }
			        else if(checker(s[i]))
			        {
				        counter = counter + 2;
			        }
		        }
		        int len = s.size();
			    int ans = min(len,counter);
			    cout<<"Case #"<<line<<": ";
			    cout<<ans<<endl;
			    line++;
			    continue;
			}
		}
		if(C_exist == true and V_exist == false)
		{
			if(cns.size()==1)
			{
				cout<<"Case #"<<line<<": ";
				cout<<0<<endl;
				line++;
				continue;
			}
			else
			{
				int counter = 0;
				for(int i=0; i<s.size(); i++)
		        {
			        if(constt == s[i])
			        {
				        continue;
			        }
			        else
			        {
				        counter = counter + 2;
			        }
		        }
		        int len = s.size();
		        int ans = min(len,counter);
		        cout<<"Case #"<<line<<": ";
		        cout<<ans<<endl;
		        line++;
		        continue;
			}
		}
		
		
		int consonant_count = 0;
		int limitt = s.size();
		for(int i=0; i<limitt; i++)
		{
			if(checker(s[i]))
			{
				consonant_count++;
			}
			else if(constt == s[i])
			{
				continue;
			}
			else
			{
				consonant_count = consonant_count + 2;
			}
		}
		
		int vowel_count = 0;
		int limit = s.size();
		for(int i=0; i<limit; i++)
		{
			if(vowl == s[i])
			{
				continue;
			}
			else if(checker(s[i]))
			{
				vowel_count = vowel_count + 2;
			}
			else
			{
				vowel_count++;
			}
		}
		int answer = min(vowel_count,consonant_count);
		cout<<"Case #"<<line<<": "<<answer<<endl;
		line++;	
	}
	
	return 0;
}

