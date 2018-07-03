#pragma once
#include <map>
#include <iterator>
using namespace std;
#include <iostream>

class Member{
private:
	/* variable */ 
	static int counter;
	map <int,Member&> Followers;
	map <int,Member&> Following;
	int id;
public:
	/* constructor */
	Member(); 
	/* destructor */
	~Member();
	/* functions */
	void follow(Member &name);
	void unfollow(Member &name);
	int numFollowers() const; 
	int numFollowing() const;
	/* static functions */
	static int count(); // eturn the num of the total members
  	
};

		 

