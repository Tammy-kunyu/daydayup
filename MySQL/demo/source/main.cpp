#include <iostream>
#include <winsock.h> //ע��˳��Ҫ����mysql.hǰ
#include <mysql.h>   //����̨��Ŀ��Ҫ��mysql.h֮ǰinclude <winsock.h>
#include "MySQLDB.h"

using namespace std;

int main(int argc, char **argv)
{
    MySQLDB &db = MySQLDB::getInstance();

    DBInfo dbInfo;
    dbInfo.setDBName("test");
    dbInfo.setHost("localhost");
    dbInfo.setPassword("root");
    dbInfo.setPort(3306);
    dbInfo.setUserName("root");
    db.connect(dbInfo);

    db.ROLE(StudentsTable).createTable();

    db.ROLE(StudentsTable).add(student(1, 1, "daniel", 'M', 90));

    db.ROLE(StudentsTable).modify(student(1, 1, "daniel", 'M', 95));

    db.ROLE(StudentsTable).remove(student(1, 1, "daniel", 'M', 95));

    db.ROLE(StudentsTable).destoryTable();
    system("pause");
    return 0;
}