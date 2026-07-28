/*
 * Project: Mathematical Expression Evaluator (Prefix, Infix, Postfix)
 * Author: [َAH_MT]
 * Date: 2026-07-29
 * 
 * --- Problem Description ---
 * This program validates and evaluates mathematical expressions in three formats:
 * 1. Prefix (e.g., + 2 2)
 * 2. Infix (e.g., 2 + 2)
 * 3. Postfix (e.g., 2 2 +)
 * 
 * The system checks formatting errors (bracket balance, token adjacency),
 * converts valid expressions to Postfix if needed, and evaluates the final result.
 * If the input is invalid, it prints "Invalid Input".
 */
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//mohasebe
bool isOperator(string check){
    if(check == "+" || check == "-" || check == "*" || check == "/" ){
        return true;
    }
    return false;
}
double applyOp(double a, double b, string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}
void mohasebe(vector <string> expression){
    stack <string> value;
    for(string i : expression){
        if(!isOperator(i)){
            value.push(i);
        }
        else{
            double a = stod(value.top()); value.pop();
            double b = stod(value.top()); value.pop();
            value.push(to_string(applyOp(b,a,i)));
        }
    }
    cout<<value.top();
}

//detection
bool find(vector <string> &check, string value){
    for(int i=0; i < check.size(); i++){
        if (check[i] == value){
            return true;
        }
    }
    return false;
}
bool isValidPrefix(vector <string> &check){
    int count = 0;
    for(int i = check.size()-1; i>=0; i--){
        if(isOperator(check[i])) count--;
        else count++;

        if(count < 0 ) return false;
    }
    if(count == 1){
        return true;
    }
    return false;
}
bool detectPrefix(vector <string> &expression){

    if (expression.empty()){
        return false;
    }
    else if(!isOperator(expression[0])){
        return  false;
    }
    else if(find(expression,"(") || find(expression,")")){
        return false;
    }
    else if(!isValidPrefix(expression)){
        return false;
    }
    return true;
}
bool checkBraket(vector <string> &check){
    int count = 0;
    for(string i : check){
        if (i == "("){
            count++;
        }
        else if(i == ")"){
            count--;
        }
    if (count<0){
        return false;
    }
    }
    return true;
}
bool isValidInfix(vector <string> &check){
    //0 => openP  1=> closeP  2=>num  3=>Op
    int preType = -1, currentType=-1;
    if(check[0] == "("){
        preType= 0;
    }
    else{
        preType = 2;
    }
    for(int i = 1; i<check.size(); i++){
        if(check[i] == "(") currentType = 0;
        else if(check[i] == ")") currentType = 1;
        else if(isOperator(check[i])) currentType = 3;
        else currentType = 2;

        if((preType == 0 && currentType == 3) || (preType == 0 && currentType == 1)){
            return false;
        }
        else if((preType == 1 && currentType == 2) || (preType == 1 && currentType == 0)){
            return false;
        }
        else if((preType == 3 && currentType == 3) || (preType == 3 && currentType == 1)){
            return false;
        }
        else if((preType ==2 && currentType == 2) || (preType == 2 && currentType == 0)){
            return false;
        }
        preType = currentType;
    }

    return true;
}
bool detectInfix(vector <string> &expression){
    if (expression.empty()) {
        return false;
    }
    else if(!checkBraket(expression)){
        return false;
    }
    else if(isOperator(expression[0]) || isOperator(expression[expression.size()-1])){
        return false;
    }
    else if(!isValidInfix(expression)){
        return false;
    }

    return true;
}
bool isValidPostfix(vector <string> &check){
    int count = 0;
    for(int i = 0; i<check.size(); i++){
        if(isOperator(check[i])) count--;
        else count++;

        if(count < 0 ) return false;
    }
    if(count == 1){
        return true;
    }
    return false;
}
bool detectPostfix(vector <string> &expression){
    if (expression.empty()){
        return false;
    }
    else if(!isOperator(expression[expression.size()-1])){
        return  false;
    }
    else if(find(expression,"(") || find(expression,")")){
        return false;
    }
    else if(!isValidPostfix(expression)){
        return false;
    }

    return true;  
}
//change to postfix
void preToPos(vector <string> &expression){
    vector<string> postfixExpr;
    for (int i = expression.size() - 1; i >= 0; --i) {
        string token = expression[i];

        if (isOperator(token)) {
            string op1 = postfixExpr.back(); postfixExpr.pop_back();
            string op2 = postfixExpr.back(); postfixExpr.pop_back();

            string temp = op1 + " " + op2 + " " + token;
            postfixExpr.push_back(temp);
        } 
        else {
            postfixExpr.push_back(token);
        }
    }

    vector<string> finalTokens;
    if (!postfixExpr.empty()) {
        stringstream ss(postfixExpr.back());
        string word;
        while (ss >> word) {
            finalTokens.push_back(word);
        }
    }

    mohasebe(finalTokens);
}
int precedence(string op) {
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}
void inToPos(vector <string> &expression){
    vector <string> line;
    stack <string> temp;
    
    for(int k = 0; k < expression.size(); k++){
        string token = expression[k];
        if(token != "(" && token != ")" && !isOperator(token)){
            line.push_back(token);
        }
        else if(token == "("){
            temp.push(token);
        }
        else if(token == ")"){
            while(!temp.empty() && temp.top() != "("){
                line.push_back(temp.top());
                temp.pop();                
            }
            if(!temp.empty()) temp.pop();
        }
        else if(isOperator(token)){
            while(!temp.empty() && temp.top() != "(" && precedence(temp.top()) >= precedence(token)){
                line.push_back(temp.top());
                temp.pop();
            }
            temp.push(token);
        }
    }
    while(!temp.empty()){
        line.push_back(temp.top());
        temp.pop();                
    }
    mohasebe(line);
}

//controlling detection
void Control(vector <string> &expression){
    if(detectPrefix(expression)){
        preToPos(expression);
    }
    else if(detectInfix(expression)){
        inToPos(expression);
    }
    else if(detectPostfix(expression)){
        mohasebe(expression);
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
}
int main(){
    // getting input making token
    string line;
    getline(cin, line);
    stringstream a(line);
    vector <string> expression;
    string temp;
    while(a>>temp){
        expression.push_back(temp);
    }

    //detecting && changing to postfix && mohasebe
    Control(expression);
    return 0;
}
