#include <iostream>
#include "Course.h"

using namespace std;

//Course类

//初始化课程id，默认1开始
int Course::currentId = 1;

//构造函数
Course::Course(){
  //分配一个id并把currentid+1
  id = currentId++;
  //默认名称为空
  name = "";
}

//拷贝构造函数
Course::Course(const Course& course){
  id = course.id;
  name = course.name;
}

//打印课程信息
void Course::PrintInfo() const{
  cout<<"Course: "<<id<<" : "<<name<<endl;
}

//友元函数，读取输入创建新的课程
void read(istream &inputStream,Course &course){
  inputStream >> course.name;
}

//重载<<操作符，用来输出课程信息
ostream& operator<<(ostream& out,const Course& course){
  out<<"Course: "<<course.id<<" : "<<course.name;
  return out;
}

//ProjectCourse类

//打印课程信息
void ProjectCourse::PrintInfo() const{
  cout<<"Course: "<< id <<" : "<< name <<" : "<< tag <<endl;
}

//JudgeCourse类
//打印课程信息
void JudgeCourse::PrintInfo() const{
  cout<<"Course: "<< id <<" : "<< name <<" : "<<time<<endl;
}
