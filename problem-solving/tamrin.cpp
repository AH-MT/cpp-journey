#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isOperator(string check){
    if(check == "+" || check == "-" || check == "*" || check == "/" || check == "^"){
        return true;
    }
    return false;
}
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
        if(isOperator(check[i])) count -= 2;
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
int countOccurrences(vector <string> &check, string value){
    int count = 0;
    for(string i : check){
        if (i == value){
            count++;
        }
    }
    return count;
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
    else if(countOccurrences(expression,"(") != countOccurrences(expression,")")){
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
        if(isOperator(check[i])) count -= 2;
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


    //detecting




    return 0;
}
