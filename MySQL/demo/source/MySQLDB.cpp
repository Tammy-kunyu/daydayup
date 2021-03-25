#include "MySQLDB.h"
#include <stdio.h>
MySQLDB::MySQLDB() :handle(NULL)
{
 
}

MySQLDB& MySQLDB::getInstance()
{
    static MySQLDB db;
    return db;
}

MYSQL *MySQLDB::getHandle()
{
    return handle;
}

void MySQLDB::disconnect()
{
	mysql_close(handle);
}

bool MySQLDB::connect(const DBInfo &dbInfo)
{
	this->dbInfo = dbInfo;

    handle = new MYSQL();
    if (handle == NULL)
        return false;

    mysql_init(handle);

    bool failed = (mysql_real_connect(handle, dbInfo.host, dbInfo.userName, dbInfo.passWord, NULL, dbInfo.port, NULL, 0) == NULL);
    if (failed)
    {
        printf("connected database failed, error :%s", mysql_error(handle));
        return false;
    }
    //��ֹ���롣���ú����ݿ�ı���һ�¾Ͳ�������
    mysql_query(handle, "set names gbk");
    return true;
}

bool MySQLDB::createDataBase(const char *name)
{
	S8 sql[1024] = { 0 };
	sprintf(sql, "CREATE DATABASE IF NOT EXISTS %s;", name);
	bool succ = (mysql_real_query(handle, sql, strlen(sql) + 1) == 0);
	if (!succ)
	{
		printf("create database failed, %s\n", mysql_error(handle));
		return false;
	}

	sprintf(sql, "USE %s;", name); 	//�����������������ݿ��������;
	succ = (mysql_real_query(handle, sql, strlen(sql) + 1) == 0);
	if (!succ)
	{
		printf("use database failed, %s\n", mysql_error(handle));
		return false;
	}
	return true;
}

bool MySQLDB::isTableExist(const char *name)
{
	S8 sql[1024] = { 0 };
	sprintf(sql, "SELECT 1 FROM %s.%s", dbInfo.dBName, name);
	bool exist = (mysql_real_query(handle, sql, strlen(sql) + 1) == 0);

	// ���ͷ�Ŀǰmysql���ݿ�query������ռ�õ��ڴ�
	MYSQL_RES* results = mysql_store_result(handle);
	mysql_free_result(results);
	return exist;
}