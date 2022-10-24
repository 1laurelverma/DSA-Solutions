using namespace std;
int priority(char ch) {
	if (ch == '^')
	return 3;
	else if (ch == '/' || ch == '*')
	return 2;
	else if (ch == '+' || ch == '-')
	return 1;
	else
	return -1;
}
string inToPost(string s) {
	stack<char> st; 
	string post="";
	for (int i=0;i<s.length();i++) 
	{
		char ch = s[i];
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			post=post+ch;   
		else if (ch == '(')
			st.push('(');
		else if (ch == ')') {
			while (st.top() !='(')
			{
				post=post+st.top();    
				st.pop();
			}
			st.pop();
		}
		else 
		{
			while (!st.empty()&&priority(s[i])<=priority(st.top())) 
			{
				post+= st.top();
				st.pop();
			}
			st.push(ch);             
		}
	}
	while (!st.empty()) 
	{
		post=post+st.top();
		st.pop();
	}
	return post;
}
int main() {
	string s;
    cout<<"Enter the Expression"<<endl;
	cin>>s;
	cout <<"Result is:"<<inToPost(s);
	return 0;
}
