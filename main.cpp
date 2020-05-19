#include <iostream>

#include "CmdManager.h"

using namespace std;

int main(){
  int cmd;

  CmdManager cmdManager;
  cmdManager.Init();

  cmdManager.PrintAllHelp();

  cout<<"New command:";

  while(cin>>cmd){
    //检查输入是否合规
    if(cin.good()){
      bool status = cmdManager.HandleCmd((CourseCmd)cmd);
      if(!status) return 0;
    }

    cout<<"----------------------------"<<endl;
    cout<<"New Command:";

    cin.clear();//将错误状态改为有效状态
    cin.ignore();//忽略缓冲区的所有字符
  }

  return 0；
}
