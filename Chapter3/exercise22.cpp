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

string postfixToInfix(string input){
  string output = "";
  string testString = "";
  /*for(unsigned i=0; i<input.length(); i++){
    output += " ";
  }
*/
  stack<int> stk;

  for(unsigned i = 0; i < input.length(); i++){
    cout << input[i] << endl;
    if(input[i] == '*' || input[i] == '+' || input[i] == '/' || input[i] == '-'){
      cout << "operator found" << endl;
      if(stk.size() == 1){
          output += input[i];
          output += stk.top();
          stk.pop();
      } else {
        for(unsigned j = 0; j<2; j++){
          if(j==1){
            output += input[i];
          }
          output += stk.top();
          stk.pop();
          cout << output << endl;
        }
      }
    } else {
      stk.push(input[i]);
      cout << stk.size() << endl;
    }
  }

  return output;

}

int main(void){
  string testString = "abc*+de*f+g*+";

  cout << testString << endl;

  testString = postfixToInfix(testString);

  cout << testString << endl;
  return 0;
}
