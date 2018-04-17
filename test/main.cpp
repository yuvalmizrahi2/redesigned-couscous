#include <cassert>
#include "Member.hpp"
#include <iostream>
Member yuval , aviv , inon;
void test1()
{
    assert(Member::count() == 3);
}
void test2()
{
    yuval.follow(inon);
    assert(yuval.numFollowing() == 1 && yuval.numFollowers() == 0);
    yuval.unfollow(inon);
    assert(yuval.numFollowing() == 0 && yuval.numFollowers() == 0);
}
void test3()
{
    aviv.follow(inon);
    assert(inon.numFollowing() == 0 && inon.numFollowers() == 1 && aviv.numFollowing() == 1);
    aviv.unfollow(inon);
    assert(aviv.numFollowing() == 0);
}
void test4()
{
    aviv.unfollow(yuval);
    assert(yuval.numFollowing() == 0 && aviv.numFollowers() == 0);
}
void test5()
{
    yuval.follow(yuval);
    assert(yuval.numFollowers() == 0 && yuval.numFollowing() == 0);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    std::cout <<  "the testing are done"  << std::endl;
}
