// StudentDatabaseApp.cpp: implementation of the CStudentDatabaseApp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StudentDatabaseApp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudentDatabaseApp::CStudentDatabaseApp()
{

}

CStudentDatabaseApp::~CStudentDatabaseApp()
{

}

int CStudentDatabaseApp::DisplayMenu()
{
	int iOption=-1;
	
	cout<<"\n\n\t\t*************Student Register***************\n";
	cout<<"\n\n\t\tAdd a student"<<setw(17)<<SD_ADD_STUDENT<<"\n";
	cout<<"\n\n\t\tDelete a student"<<setw(14)<<SD_DEL_STUDENT<<"\n";
	cout<<"\n\n\t\tShow all students details"<<setw(5)<<SD_SHOW_ALL_STUDENT<<"\n";
	cout<<"\n\n\t\tShow a students details"<<setw(7)<<SD_SHOW_A_STUDENT<<"\n";
	cout<<"\n\n\t\tSave all students details"<<setw(5)<<SD_SAVE_ALL_STUDENT<<"\n";
	cout<<"\n\n\t\tLoad all students details"<<setw(5)<<SD_LOAD_ALL_STUDENT<<"\n";
	cout<<"\n\n\t\tExit"<<setw(26)<<SD_EXIT<<"\n";
	cout<<"\n\n\t\tEnter your Option->";

	cin>>iOption;

	return iOption;
}
//This routine is to add  a student details
bool CStudentDatabaseApp::AddAStudent()
{   
	CStudent Student;
	
	int iSize;
	char name[10];
	char address[10];
	cout<<"\n\n\t\tAdd a student details here"<<setw(17)<<"\n";
	cout<<"\nenter number of students:\n";
	cin>>iSize;
	for(int i=0;i<iSize;i++)
	{
		cout<<"enter student name:\n";
		cin>>name;
		Student.m_strName=name;
		cout<<"enter student address:\n";
		cin>>address;
		Student.m_strAddress=address;
		cout<<"enter student id:\n";
		cin>>Student.m_iStudentID;
		cout<<"enter student age:\n";
		cin>>Student.m_iAge;
		m_StudentArray.Add(Student);
		
	}
	return true;
}
//This routine displays the student details
bool CStudentDatabaseApp::DisplayStudentDetails(int iStudentID)
{   
	cout<<"\n\n\t\tDisplay a student details here"<<setw(17)<<"\n";
	for(int i=0;i<m_StudentArray.GetSize();i++)
	{
		if(m_StudentArray[i].m_iStudentID==iStudentID)
		{
			cout<<"\nname:\t"<<m_StudentArray[i].m_strName;
			cout<<"\nage:\t"<<m_StudentArray[i].m_iAge;
			cout<<"\naddress:\t"<<m_StudentArray[i].m_strAddress;
			
		}
	}
		
	return true;
}
//This routine displays all students details
bool CStudentDatabaseApp::DisplayAllStudents()
{
	cout<<"\n\n\t\tDisplay al student details here"<<setw(17)<<"\n";
    
	for(int i=0;i<m_StudentArray.GetSize();i++)
	{
		cout<<"\nStudent name is:\t"<<m_StudentArray[i].m_strName;
		cout<<"\nStudent address is:\t"<<m_StudentArray[i].m_strAddress;
		cout<<"\nStudent id is:\t"<<m_StudentArray[i].m_iStudentID;
		cout<<"\nStudent age is:\t"<<m_StudentArray[i].m_iAge;
		
	}


	return true;
}
//This routine load all students details
bool CStudentDatabaseApp::LoadAllStudents()
{
	try
	{
		char buffer[100];
		char strFilename[20];
		cout<<"\n\n\t\tLoad all student details here"<<setw(17)<<"\n";
		cout<<"enter file name:\n";
		cin>>strFilename;
		CStdioFile StudentFile;
		StudentFile.Open(strFilename,CFile::modeRead|CFile::shareExclusive);
		cout<<"\t\t***STUDENT DETAILS***\n";
		for(int i=0;i<m_StudentArray.GetSize();i++)
		{
			CString strDataToReadToFile;
			StudentFile.ReadString(buffer,99);
			cout<<"\n"<<buffer;
		}
		StudentFile.Close();
	}
	catch(...)
	{
		cout<<"file not found";
	}
	return true;
}
//This routine is to save all student details
bool CStudentDatabaseApp::SaveAllStudents()
{
	char strFilename[20];
	cout<<"\n\n\t\tSave all student details here"<<setw(17)<<"\n";
	cout<<"enter file name\n:";
	cin>>strFilename;
	CStdioFile StudentFile;
    StudentFile.Open(strFilename,CFile::modeWrite|CFile::shareExclusive|CFile::modeCreate);
	for(int i=0;i<m_StudentArray.GetSize();i++)
	{
		CString strDataToWriteToFile;
		strDataToWriteToFile.Format("name:%s\taddress:%s\tid:%d\tage:%d\n",m_StudentArray[i].m_strName,m_StudentArray[i].m_strAddress,m_StudentArray[i].m_iStudentID,m_StudentArray[i].m_iAge);
		StudentFile.WriteString(strDataToWriteToFile);
		

	}
	StudentFile.Close();
	return true;
}
//This routine delete a student details
bool CStudentDatabaseApp::DeleteAStudent(int iStudentID)
{
	cout<<"\n\n\t\tDelete a student"<<setw(17)<<"\n";
	for(int i=0;i<m_StudentArray.GetSize();i++)
	{
		if(m_StudentArray[i].m_iStudentID==iStudentID)
		{
			for(int j=i;j<(m_StudentArray.GetSize()-1);j++)
			{
				m_StudentArray[j]=m_StudentArray[j+1];
			}
		}
	}
	return true;
}
