#ifndef _COURSE_H_
#define _COURSE_H_

#include <string>

using namespace std;

class Course{

  //友元函数，读取输入创建新的课程
  friend void read(istream &inputStream,Course &course);
public:
  //无参数构造函数
  Course();

  //根据课程名称创建课程对象
  Course(const string& cName):Course(){
    name = cName;
  };

  //拷贝构造函数
  Course(const Course& course);

  //打印课程信息
  virtual void PrintInfo() const;

  //返回课程名称
  inline string GetName() const{return name;};

  //设置课程名称
  inline void SetName(const string& newName){name = newName;};

  //返回课程id
  inline const int GetId() const{return id;};

  //重载<<操作符，用来输出课程信息
  friend ostream& operator<<(ostream& out,const Course& course);

protected:
  //课程id
  int id;
  //课程名称
  string name;
  //设置静态变量来分配id
  static int currentId;
};

class ProjectCourse: public Course{
public:
  //设置标签
  inline void SetTag(const string& newTag){tag = newTag;};

  //返回标签
  inline string GetTag() const {return tag;};

  //打印课程信息
  virtual void PrintInfo() const override;
private:
  string tag;
};

class JudgeCourse: public Course{
public:
  //设置限时
  inline void SetTime(int newTime) {time = newTime;};

  //返回限时
  inline int GetTime() {return time;};

  //打印课程信息
  virtual void PrintInfo() const override;
private:
  int time; //有时限
};

#endif
