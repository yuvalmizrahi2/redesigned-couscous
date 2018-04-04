#pragma once
#include <map>
#include <iterator>
using namespace std;
#include <iostream>

class Member{
private:
	static int counter; // num of the all members
public:
	map <int,Member*> Followers; // map that contain pointers to the followers
	map <int,Member*> Following; // map that contain pointers to the following
	int id; // the id of the member
    Member(); // default constructor
	void follow(Member &name); // function to follow after a member
	void unfollow(Member &name); // function to unfollow after a member
	int numFollowers(); // return the num of the followers members 
	int numFollowing(); // return the num of the following members
	static int count(); // eturn the num of the total members
  	~Member(); // destractou
};

		 

