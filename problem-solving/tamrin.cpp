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
    // val = 0 => number    ,    val = 1 => operator
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
    if(!isOperator(expression[0])){
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
