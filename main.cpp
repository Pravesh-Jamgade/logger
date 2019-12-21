#include<iostream>
#include<stack>
#include"logger.h"

using namespace std;

logger l(true);

int order(char s){
	if(s == '^') return 3;
	else if(s == '*' || s == '/') return 2;
	else if(s == '+' || s == '-') return 1;
	return 0;
}
string infixToPostfix(string s){
	string xpr = "";
	stack<char> stack;
	for(int i=0; i< s.size(); i++){

		l.log("character at", i, s[i], '\n');

		if(s[i] >= 'a' and s[i] <= 'z'){
			l.log("to xpr ", s[i],'\n');
			xpr += s[i];
		}else if(s[i] == '('){
			l.log("push to stack ", '(','\n');
			stack.push('(');
		}else if(s[i] == ')'){
			l.log("end found, pop stack ", ')','\n');
			while(!stack.empty()){
				l.log("pop ", stack.top(), '\n');
				if(stack.top()!='(') xpr+=stack.top();
				stack.pop();
			}
		}
		else{
			while(!stack.empty() and order(stack.top()) >= order(s[i])){
				l.log("order(top) > order(s[i])","-",stack.top()," > ", s[i]);
				xpr+=stack.top(); stack.pop();
			}
			l.log("push ", s[i], '\n');
			stack.push(s[i]);
		}
	}
	l.log("pop remaining: ", '\n');
	while(!stack.empty()){
		l.log("pop ",stack.top(),'\n');
		xpr+=stack.top();stack.pop();
	}
	return xpr;
}

void process(string s){

	string sx = infixToPostfix(s);
	l.log("first done, posfix notation: ");
	cout<<sx;
}

int main(){

    string s = "(a+b)*c";
    l.log("inital, going for infixToPostfix: ",s,'\n');
    process(s);
    return 0;
}



