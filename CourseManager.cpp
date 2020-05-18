#include <iostream>
#include "CourseManager.h"
#include <stdexcept>

using namespace std;

CourseManager::CourseManager(const vector<Course> &courseVect){
  for(auto curs = courseVect.begin();curs!=courseVect.end();curs++){
    courseList.push_back(*curs);
  }
}

void CourseManager::AddCourse(const Course &course){
  courseList.push_back(course);
}

void CourseManager::AddCourse(const string &courseName){
  Course course(courseName);
  courseList.push_back(course);
}

void CourseManager::RemoveLast(){
  try{
    if(!courseList.empty()){
      courseList.pop_back();

      cout<<"Delete successfully!"<<endl;
    }else{
      throw runtime_error("Delete error, there is no course!");
    }
    }
    catch(runtime_error err){
      cout<<err.what()<<endl;
    }
}


void CourseManager::RemovebyName(const string &name){
  int index = FindCourse(name);
  if(index!=-1){
    courseList.erase(courseList.begin()+index);
  }else{
    cout<<"NOT FOUND"<<endl;
  }
}

void CourseManager::RemovebyId(int id){
  int index = FindCourse(id);
  if(index!=-1) courseList.erase(courseList.begin()+index);
  else cout<<"NOT FOUND"<<endl;
}

void CourseManager::PrintAllCourse(){
  for(auto curs = courseList.begin();curs!=courseList.end();curs++){
    cout<<*curs<<endl;
  }
}

void CourseManager::PrintCourse(const string &name){
  int index = FindCourse(name);
  if(index!=-1){
    cout<<courseList[index]<<endl;
  }else{
    cout<<"NOT FOUND"<<endl;
  }
}

void CourseManager::PrintCourse(int id){
  int index = FindCourse(id);
  if(index!=-1){
    cout<<courseList[index]<<endl;
  }else{
    cout<<"NOT FOUND"<<endl;
  }
}

void CourseManager::PrintLongestNameCourse(){
  if(courseList.empty()){
    cout<<"No course in the list!"<<endl;
    return;
  }
  int maxLen = 0;
  string longest= "";

  for(auto curs = courseList.begin();curs!=courseList.end();curs++){
    int currentLen = curs->GetName().length();
    if(currentLen>maxLen){
      maxLen = currentLen;
      longest = curs->GetName();
    }
  }
  cout<<longest<<endl;
}

int CourseManager::FindCourse(const string& name){
  int i=0;
  for(;i<courseList.size();i++){
    if(courseList[i].GetName() == name) return i;
  }
  return -1;
}

int CourseManager::FindCourse(int id){
  int i=0;
  for(;i<courseList.size();i++){
    if(courseList[i].GetId() == id) return i;
  }
  return -1;
}
