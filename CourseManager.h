#ifndef _COURSEMANAGER_H_
#define _COURSEMANAGER_H_

#include <vector>
#include "Course.h"

using namespace std;

//课程管理类
class CourseManager{
public:
  //默认构造函数
  CourseManager() = default;

  //构造函数基于给定的课程列表
  CourseManager(const vector<Course> &courseVect);

  //获取课程列表长度
  inline int GetCourseNum(){return courseList.size();};

  //添加新的课程
  void AddCourse(const Course &course);
  void AddCourse(const string &courseName);

  //删除最后一个课程
  void RemoveLast();

  //删除指定名称额课程
  void RemovebyName(const string &name);

  //删除指定ID的课程
  void RemovebyId(int id);

  //打印课程列表信息
  void PrintAllCourse();

  //根据课程名打印指定课程信息
  void PrintCourse(const string &name);

  //根据课程id打印指定课程信息
  void PrintCourse(int id);

  //打印名称最长的课程
  void PrintLongestNameCourse();

private:
  vector<Course> courseList;

  //根据课程名称查找课程，如果没有则返回-1
  int FindCourse(const string& name);

  //根据课程id查找课程，如果没有返回-1
  int FindCourse(int id);
};

#endif
