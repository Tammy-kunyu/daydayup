#ifndef _DBINFO_H_
#define _DBINFO_H_

#include "BaseTypes.h"

#define  MAX_LEN_USER_NAME      64      //����ݿ��û�������
#define  MAX_LEN_PASSWORD       64      //����볤��
#define  MAX_LEN_DB_NAME        64      //����ݿ�������
#define  MAX_LEN_HOST           16      //����ݿ�IP�ַ�������

struct DBInfo
{
    DBInfo();
    void setUserName(const S8 *user);
    void setPassword(const S8 *password);
    void setDBName(const S8 *name);
	void setHost(const S8 *dbHost);
    void setPort(U16 port);

    S8 userName[MAX_LEN_USER_NAME];  // ��½�û���
    S8 passWord[MAX_LEN_PASSWORD];   // ����
    S8 host[MAX_LEN_HOST];           // ���ݿ��������ַ(�ַ���IP)
    U16 port;                        // �˿�
    S8 dBName[MAX_LEN_DB_NAME];      // ���ݿ���
};

#endif