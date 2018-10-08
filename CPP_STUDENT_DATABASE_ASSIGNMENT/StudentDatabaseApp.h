// StudentDatabaseApp.h: interface for the CStudentDatabaseApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTDATABASEAPP_H__D205FE4E_DE63_488F_887B_C07FA60CD03F__INCLUDED_)
#define AFX_STUDENTDATABASEAPP_H__D205FE4E_DE63_488F_887B_C07FA60CD03F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SD_ADD_STUDENT		1
#define SD_DEL_STUDENT		2
#define SD_SHOW_ALL_STUDENT	3
#define SD_SHOW_A_STUDENT   4
#define SD_SAVE_ALL_STUDENT	5
#define SD_LOAD_ALL_STUDENT 6
#define SD_EXIT				7


class CStudent
{
public:
	CString m_strName;
	CString m_strAddress;
	int m_iAge,m_iStudentID;
	


	CStudent()//Constructor initialize all variables here
	{
		m_strName="";
		m_strAddress="";
		m_iAge=-1;
		m_iStudentID=-1;
	}
	~CStudent()//Destructor
	{

	}
};


class CStudentDatabaseApp  
{
private:
	CArray<CStudent,CStudent> m_StudentArray;//CArray is doubly linked list internaly
public:
	bool DeleteAStudent(int iStudentID);
	bool LoadAllStudents();
	bool SaveAllStudents();
	bool DisplayAllStudents();
	bool DisplayStudentDetails(int iStudentID);
	bool AddAStudent();

	int DisplayMenu();
	CStudentDatabaseApp();
	virtual ~CStudentDatabaseApp();

};

#endif // !defined(AFX_STUDENTDATABASEAPP_H__D205FE4E_DE63_488F_887B_C07FA60CD03F__INCLUDED_)
