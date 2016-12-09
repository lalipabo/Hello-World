#define CRTDBG_MAP_ALLOC 
#include<iostream>
#include<string>
#include<memory>
#include<crtdbg.h>

using namespace std;

class Iuser
{
public:
	virtual void getUser() = 0;
	virtual void insertUser() = 0;
};

class IDepartment
{
public:
	virtual void getDepartment() = 0;
	virtual void insertDepartment() = 0;
};

class accessUser :public Iuser
{
public:
	virtual void getUser()
	{
		std::cout << "Get Access User" << std::endl;
	}

	virtual void insertUser()
	{
		std::cout << "Insert Access User" << std::endl;
	}
};

class accessDepartment :public IDepartment
{
public:
	virtual void getDepartment()
	{
		std::cout << "Get AccessDepartment" << std::endl;
	}

	virtual void insertDepartment()
	{
		std::cout << "Insert AccessDepartment" << std::endl;
	}
};

class IFactory
{
public:
	virtual shared_ptr<Iuser> createIuser() = 0;
	virtual shared_ptr<IDepartment> createIDepartment() = 0;
};

class AccessFactory :public IFactory
{
public:
	virtual shared_ptr<Iuser> createIuser()
	{
		return shared_ptr<Iuser>(new accessUser());
	}

	virtual shared_ptr<IDepartment> createIDepartment()
	{
		return shared_ptr<IDepartment>(new accessDepartment());
	}
};

int main()
{
	
	shared_ptr<IFactory> factory(new AccessFactory());
	shared_ptr<Iuser>user = factory->createIuser();
	shared_ptr<IDepartment> department = factory->createIDepartment();
	user->getUser();
	user->insertUser();
	
	
	return 0;
	_CrtDumpMemoryLeaks();
}