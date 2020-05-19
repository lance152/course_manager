#ifndef _CMDMANAGER_H_
#define _CMDMANAGER_H_

#include <map>
#include <istream>

#include "CourseManager.h"
#include "Cmd.h"

class CmdManager{
public:

  //构造函数
  CmdManager() = default;

  //初始化函数
  void Init();

  //打印帮助信息
  void PrintAllHelp() const;

  //根据命令查询帮助信息
  void PrintCmdHelp(const CourseCmd cmd) const;

  //处理操作命令
  bool HandleCmd(const CourseCmd cmd);

  //返回课程管理对象
  inline CourseManager& GetCourseManager(){return manager;};
private:
  CourseManager manager;

  map<CourseCmd,string> cmdMap;
};

#endif
