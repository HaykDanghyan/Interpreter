#include <iostream>
#include <fstream>
#include <string>
#include "interpretator.h"

Var var_definition (std::string str)
{
       Var obj;
       std::string string ;
       std::string name;

       std::string value;
       for ( int i = 4 ; i < str.length() ; i++)
       {
           if ( str[i] != ' ')
           {
               name = name + str[i] ;
           }
           else { break ;}
       }
       obj.name = name ;
       for ( int i = 5 + name.length() ; i < str.length() ; i++ )
       {
            if ( str[i] != ' ' )
            value = value + str[i] ;
       }
       obj.value = stoi(value) ;
       
        return obj;
}



Str str_definition(std::string str)
{
       Str obj;
       std::string name;
       std::string value;
       for ( int i = 4 ; i < str.length() ; i++) 
       {
           if ( str[i] != ' ')
           {
               name = name + str[i] ;
           }
           else { break ;}
       }
       obj.name = name ;

       for ( int i = 5 + name.length() ; i < str.length() ; i++ )
       {
            if ( str[i] != ' ' )
            value = value + str[i] ;
       }
       obj.value = value ;
       return obj;
}

Alg alg_definition(std::string str)
{
       Alg obj;
       std::string name;
       for ( int i = 4 ; i < str.length() ; i++)
       {
           if ( str[i] != ' ')
           {
               name = name + str[i] ;
           }
           else { break ;}
       }
       obj.name = name ;
       if(str[5 + name.length()] == '0')
       { 
       obj.value = 0 ;
       }
       else 
       {
           obj.value = 1;
       }
       return obj;
         
}
int math_operation (Var numbers[] , std::string name_test, std::string str) {
 std::string a , b ;
 int right = 0 , left = 0 ;
 char operation ;
 for (int i = name_test.length() + 1 ; i < str.length() ; i++ )
 {
        if ( str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != '>' && str[i] != '<' && str[i] != '=')
        {
            a = a + str[i] ; 
        }
        else { break ;}
 } 
 operation = str[name_test.length() + 1 + a.length()] ;
 for ( int i = name_test.length() + a.length() + 2 ; i < str.length() ; i++ )
 {
        if ( str[i] != ' ')
        {
            b = b + str[i] ; 
        }
        else { break ;}
 } 
 if ( a[0] >= '0' && a[0] <= '9')
 {
     left = stoi(a);
 } 
 if( b[0] >= '0' && b[0] <= '9')
 {
     right = stoi(b);
 }
 for ( int i = 0 ; i < 5 ; i++)
 {
    if (a == numbers[i].name)
    {
        left  = numbers[i].value ;
    } 
    if ( b == numbers[i].name)
    {
        right = numbers[i].value;
    }

}
 
switch(operation)
{
    case '+': return right + left;
    case '-': return left - right;
    case '*': return right * left;
    case '/': return left / right;
    case '>': return left > right;
    case '<': return left < right;
    case '=': return left == right;
    default: return left; 
}
    
}

std::string string_operation(Str strs[] , std::string name_test , std::string str){
      	std::string a , b ;
    	std::string right , left ;
 char operation ;
 for ( int i = name_test.length() + 1 ; i < str.length() ; i++ ){
        if ( str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*'){
            a = a + str[i] ; 
        }
        else { break ;}
 } 
 operation = str[name_test.length() + 1 + a.length()] ;
 for ( int i = name_test.length() + a.length() + 2 ; i < str.length() ; i++ ){
        if ( str[i] != ' '){
            b = b + str[i] ; 
        }
        else { break ;}
 } 
 for ( int i = 0 ; i < 5 ; i++){
    if (a == strs[i].name){
        left  = strs[i].value ;
    } 
    if ( b == strs[i].name){
        right = strs[i].value;
    }
 }
 return left+right;
}

void data_output(std::string str, Var numbers[] , Str strs[] , Alg algs[]){
    std::string print;
    for(int i = 4 ; i < str.length() ; i++){
        print = print + str[i] ;
    }    
    for ( int i = 0 ; i < 5 ; i++ ){
        if(numbers[i].name == print){
            std::cout << numbers[i].value <<std::endl;
            break;
        }
        else if(strs[i].name == print){
            std::cout << strs[i].value << std::endl ;
            break;
        }
        else if(algs[i].name == print){
            std::cout << algs[i].value << std::endl ;
            break;
        }
    }
}
bool if_statement( std::string str , Var numbers[] ){
    return math_operation (numbers , "end" , str );
}
int main() {
    bool test_for = false;
    bool check = true;
    std::string str = "";
    int ever_line = 0;
    Var numbers[5];
    int incrementNum = 0;
    Str strs[5];
    int incrementStr = 0;
    int incrementBul = 0;
    Alg algs[5];
    std::ifstream fin;
    fin.open ( "code.txt" );
    int linecount = 0;
    while (!fin.eof())
    {
     getline ( fin , str ) ;
     linecount++;
     if(str.substr(0,6) == "end" && !test_for){
         check = true ;
     }
     else if (test_for && str.substr(0,6) == "end"){
         linecount = ever_line;
         fin.close();
         fin.open("code.txt");
         std::string str1 = "";
         for ( int i = 0 ; i < ever_line ; i++){
             getline(fin,str1);
         }
         str = str1;
     }
     
      if(check == true){  
      if ( str.substr ( 0 , 3 ) == "var" ){
          Var num ;
          numbers[incrementNum] = var_definition(str);
          incrementNum++ ;
      }
        if ( str.substr ( 0 , 3 ) == "str" ){
          strs[incrementStr] = str_definition(str);
          incrementStr++;
          }
        else if(str.substr (0 , 3) == "alg"){
            algs[incrementBul] = alg_definition(str);
            incrementBul++;
        }
        else if( str.substr (0,3) == "out"){
            data_output(str, numbers , strs, algs);
        }  
        else if( str.substr(0,3) == "ete" ){
           check = if_statement( str , numbers );
        }
        else if( str.substr(0,3) == "rep" ){
          ever_line = linecount;
          test_for = if_statement(str,numbers);
          check = test_for;  
        }
        if ( str.substr(0,3) != "out" &&  str.substr(0 , 3) != "var" && str.substr(0 , 3) != "str" &&  str.substr(0 , 2) != "ete" && str.substr(0,3) != "rep" && str.substr( 0 , 3 ) != "alg" ){
            std::string name_test = {} ;
            for ( int i = 0 ; str[i] != '=' ; i++ ){
                    name_test.push_back(str[i]);
            }
            for ( int i = 0 ; i < 5 ; i++ ) {
                if ( name_test == numbers[i].name ){ 
                    numbers[i].value = math_operation( numbers , name_test , str);
                }
                else if ( name_test == strs[i].name ){
                    strs[i].value = string_operation(strs,name_test,str);
                }
            }
        }
      }   
    } 
}


