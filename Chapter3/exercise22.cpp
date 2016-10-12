/*
//  Created by: Jacob Cassady
//  Date Created: 10/9/2016
//  Last Updated: 10/11/2016
*/

/* Problem Statement
Write a program to evaluate a postfix expression
*/

#include <string>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int charToInt(char input){
  int output;
  output = input - '0';
  return output;
}

void displayStack(stack<int> stk){
	cout << "stack = ";
	for(unsigned i = 0; i<=stk.size(); i++){
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
}


int evaluatePostfix(string input){
  int output = 0;
  string testString = "";
  int num1=0,num2=0;

  stack<int> stk;
  int total = 0;

  for(unsigned i = 0; i < input.length(); i++){
  	if(input[i] == '*' || input[i] == '+' || input[i] == '/' || input[i] == '-'){
	  	cout << input[i] << endl;
  		displayStack(stk);
  		num1 = stk.top();
    	stk.pop();
    	num2 = stk.top();
    	stk.pop();
    	
    	cout << "num1: " << num1 << endl;
    	cout << "num2: " << num2 << endl;
    	
	    if(input[i] == '*'){
	    	total = num1 * num2;
	    }
	    if(input[i] == '+'){
	    	total = num1 + num2;
	    }
	    if(input[i] == '-'){
	    	total = num2 - num1;
	    }
	    if(input[i] == '/'){
	    	total = num2 / num1;
	    }
	    stk.push(total);
		cout << "total: " << total << endl;
    } else if (input[i] == ' '){
  	} else {
      	cout << input[i] << endl;
		stk.push(charToInt(input[i]));
	}
  }
  return total;
}


int main (void) {
	string testString = "5 6 7 * + 3 - 4 * 3 + 4 * ";
	int testint = 0;
	
	testint = evaluatePostfix(testString);
	cout << testint << endl;

	cout << testint << endl;
	
	return 0;
}
