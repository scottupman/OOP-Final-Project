#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Account.h"

class FileManager
{
public:
	// Searches through the file for the username and password when they're trying to login
	static bool search_account(ifstream& infile, string username, string password)
	{
		string read_username, read_password;
		string read_line;
		stringstream whole_line;
		bool exists = false;
		while (getline(infile, read_line))
		{
			whole_line.str(read_line);
			whole_line.clear();
			whole_line >> read_username >> read_password;	// stringstream reads in the username and password from the line that is read from the file
			
			if (read_username == username)
			{
				if (read_password == password)
				{
					exists = true;	// When the username and password from the user match with the username and password read from the file
					break;
				}
			}
		}
		infile.clear();
		return exists;
	}
	// Function searches for username in the file to see if the username is taken when the user wants to create an account
	static bool search_username(ifstream& infile, string username)
	{
		string read_line;
		string read_user;
		stringstream whole_line;
		bool taken = false;
		while (getline(infile, read_line))
		{
			whole_line.str(read_line);
			whole_line.clear();
			whole_line >> read_user;
			if (read_user == username) 
			{
				taken = true;	// When the user inputf or the username and the username from the file match
				break;
			}				
		}
		infile.clear();
		return taken;
	}
	// Sets the stream position to the beginning of the line that contains the 
	static void set_file_position(ifstream& infile, string username)
	{
		string read_line;
		string read_user;
		stringstream whole_line;
		bool found = false;
		int position;	// position will store the position of the streampos in the file
		while (getline(infile, read_line))
		{
			whole_line.str(read_line);
			whole_line.clear();
			whole_line >> read_user;
			if (read_user == username)
			{
				found = true;
				break;
			}
		}
		position = infile.tellg();	//	Gets the streampos
		int length = read_line.length();
		position -= read_line.length() + 1; //  Sets streampos back to the beginning of the read line within the input file
		infile.seekg(position);		// Set the streampos
	}
};
#endif

