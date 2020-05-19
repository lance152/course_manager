#include <stdexcept>
#include <iostream>

#include "CmdManager.h"

using namespace std;

//初始化函数
void CmdManager::Init(){
  manager.AddCourse("Linux");
  manager.AddCourse("NodeJs");
  manager.AddCourse("C++");
  manager.AddCourse("Python");
  manager.AddCourse("Spark");
  manager.AddCourse("Hadoop");
  manager.AddCourse("Ruby");
  manager.AddCourse("Java");

  cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintHelp,"Help Info"));
  cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintCourse,"Course List"));
  cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintCourseNum,"Course Number"));
  cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintLongestName,"Longest Course Name"));
  cmdMap.insert(pair<CourseCmd,string>(Cmd_RemoveLastCourse,"Remove Lase Course"));
  cmdMap.insert(pair<CourseCmd,string>(Cmd_Exit,"Exit"));

}

//打印帮助信息
void CmdManager::PrintAllHelp() const{
  cout<<"Cmd List:"<<endl;
  for(auto iter = cmdMap.begin();iter!=cmdMap.end();iter++){
    cout<<iter->first<<" : "<<iter->second<<endl;
  }
}

//根据命令查询帮助信息
void CmdManager::PrintCmdHelp(const CourseCmd cmd) const{
  auto iter = cmdMap.find(cmd);

  if(iter!=cmdMap.end()){
    cout<<iter->first<<" : "<<iter->second<<endl;
  }else{
    cout<<"NOT FOUND"<<endl;
  }
}

//处理操作命令
bool CmdManager::HandleCmd(const CourseCmd cmd){
  //在字典中查询命令
  auto iter = cmdMap.find(cmd);

  //如果没找到，则提示
  if(iter==cmdMap.end()){
    cout<<"NOT FOUND"<<endl;
    return true;
  }

  switch(cmd){
    case Cmd_PrintHelp: PrintAllHelp();break;
    case Cmd_PrintCourse: manager.PrintAllCourse();break;
    case Cmd_PrintCourseNum: cout<<manager.GetCourseNum()<<endl;break;
    case Cmd_PrintLongestName: manager.PrintLongestNameCourse();break;
    case Cmd_RemoveLastCourse: manager.RemoveLast();break;
    case Cmd_Exit: return false;
    default: break;
  }

  return true;
}
