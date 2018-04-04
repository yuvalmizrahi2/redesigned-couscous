#include "Member.hpp"
int Member::counter=0;
map<int,Member*>::iterator it;
Member::Member()
{
  Member::counter++;
  id = Member::counter;
};
void Member::follow(Member& name)
{
	if(this->id != name.id && Following.find(name.id)==Following.end())
    {
		Following.insert(pair <int,Member*> (name.id,&name));
		name.Followers.insert(pair<int,Member*> (this->id,this));
	}
}
void Member::unfollow(Member &name)
{
	if((it=Following.find(name.id))!=Following.end())
	{
		Following.erase(it);
		name.Followers.erase(name.Followers.find(this->id));
	}
}
int Member::numFollowers()
{
	return this->Followers.size();
}
int Member::numFollowing()
{
	return this->Following.size();
}
int Member::count()
{
	return Member::counter;
}
Member::~Member(){
	counter--;
	for(it=Followers.begin();it!=Followers.end();it++)
	{
		if(it->second->Following.find(this->id)!=it->second->Following.end())
			it->second->Following.erase(it->second->Following.find(this->id));
	}
	for(it=Following.begin();it!=Following.end();it++)
	{
		if(it->second->Followers.find(this->id)!=it->second->Followers.end())
			it->second->Followers.erase(it->second->Followers.find(this->id));
	}
}