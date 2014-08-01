/*模块功能：	注册功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "struct.h"
#include "head.h"
#include "declaration.h"

/*	函数功能：用户注册函数	
 *	形参：		*head
 *	返回值：	
 */
int RegUser(lot_t *head)
{
	if(head == NULL)
	{
		return -1;
	}//end of if

	char user[USER_NUM] = {};
	char pwd[PWD_NUM] = {};
	int len = 0;

	printf("请输入用户名：");
	scanf("%s",user);
	printf("请输入密码：");
	scanf("%s",pwd);
	len = strlen(pwd);
	/*	判断用户名和密码长度	*/
	if(strlen(user) > USER_NUM-1 || strlen(pwd) > PWD_NUM-1)
	{
		printf("用户名或密码长度非法。请减少长度。\n");
		return 0;
	}
	if(SearchNode(head,user) != NULL)//搜索用户节点
	{

		printf("用户名已经存在。请选择其他用户名。\n");
		return 0;

	}//end of if
	else
	{
		InsertNode(head,user,EncryptPwd(pwd,len),0.0);//插入用户节点
		WriteFile(head);//写入文件
		printf("注册成功!\n");
	}//end of else
	return 0;
}

