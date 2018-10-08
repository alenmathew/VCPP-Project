// StudentDatabase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"StudentDatabaseApp.h"

int main(int argc, char* argv[])
{
	CStudentDatabaseApp StudentDatabaseApp;
	int iOption=-1;
	do
	{
		iOption=StudentDatabaseApp.DisplayMenu();
		switch(iOption)
		{
		case SD_ADD_STUDENT:
			StudentDatabaseApp.AddAStudent();
			break;
		case SD_DEL_STUDENT:
			int id;
			cout<<"enter student id:\n";
			cin>>id;
			StudentDatabaseApp.DeleteAStudent(id);

			break;
        case SD_SHOW_A_STUDENT:
			
			cout<<"enter student id:\n";
	        cin>>id;
			StudentDatabaseApp.DisplayStudentDetails(id);
			break;
		case SD_SHOW_ALL_STUDENT:
			StudentDatabaseApp.DisplayAllStudents(); 
			break;
		case SD_SAVE_ALL_STUDENT:
			StudentDatabaseApp.SaveAllStudents() ; 
			break;
        case SD_LOAD_ALL_STUDENT:
			StudentDatabaseApp.LoadAllStudents();

			break;
		}

	}while(iOption<SD_EXIT);
	return 0;
}

