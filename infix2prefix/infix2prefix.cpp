// Chris Grimes
// cs23001
// lab assignment
// compile clang++ infix2prefix.cpp ../string/string.cpp

#include<iostream>
#include<fstream>
#include<cstdlib>
#include "../string/string.hpp"
#include "../assembler/stack.hpp"

void  infix2prefix(std::istream& file){
  stack<String> result;
  while(!file.eof()){
    String test;
    file>>test;
    while((test!=";")&&(!file.eof())){
      if(test== ")"){
        String right= result.pop();
        String oper= result.pop();
        String left = result.pop();
        result.push(oper+left+right);
      }
      else if(test!="("){
        result.push(test);
        test="";
      }
      file>>test;
    }
    while(result.empty()==0){
      std::cout<<result.top();
      result.pop();
    }
    std::cout<<std::endl;
  }
}

int main(){
  std::ifstream file("data3-1.txt");
  if(!file.is_open()){
    std::cout<<"Could not open said file"<<std::endl;
    exit(1);
  }
  else
    std::cout<<"The file is open, success!!"<<std::endl;
  infix2prefix(file);
  file.close();
}
