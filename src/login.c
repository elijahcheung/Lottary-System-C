/*模块功能：	登录功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "head.h"
#include "struct.h"
#include "declaration.h"


/*	函数功能：用户登录函数
 *	形参：		*head,*lot_pub,*lot_inform
 *	返回值：	
 */
int LoginUser(lot_t *head,lot_pub_t *lot_pub,lot_inform_t *lot_inform)
{
	if(head == NULL || lot_pub == NULL || lot_inform == NULL)
	{
		return -1;
	}

	//初始化
	lot_t *p = head;
	char user[USER_NUM] = {};
	char *pwd = NULL;
	char pwdtemp[PWD_NUM] = {};
	char *pwd_confirm = NULL;
	int flag = 3;//三次输错标志
	int len = 0;

	while(flag > 0)
	{
		printf("请输入用户名:");
		scanf("%s",user);
		pwd = getpass("请输入密码:");//隐藏密码
		strcpy(pwdtemp,pwd);
		pwd_confirm = getpass("请再次输入密码:");
		
		len = strlen(pwdtemp);
		
		/*	判断用户名和密码长度	*/
		if(strlen(user) > USER_NUM-1 || strlen(pwd) > PWD_NUM-1)
		{
			printf("用户名或密码长度非法。请减少长度。\n");
			return 0;
		}

		if(strcmp(pwdtemp,pwd_confirm) == 0)
		{
			if(CompareNode(p,user,EncryptPwd(pwdtemp,len)) ==2)//搜索节点
			{
				printf("您是管理员，登入成功，进入管理员界面。\n");
				AdminMenu(p,lot_pub,user,pwdtemp);
				return 1;
			}//end of if
			else if(CompareNode(p,user,pwdtemp) ==3)
			{
				printf("您是第三方用户，登入成功，进入第三方用户界面。\n");
				ThirdMenu(p,lot_pub,lot_inform,user,pwdtemp);
				return 1;
			}//end of else if
			else if(CompareNode(p,user,pwdtemp) ==1)
			{
				printf("您是普通用户，登入成功，进入普通界面。\n");
				UserMenu(p,lot_pub,lot_inform,user,pwdtemp);//用户界面功能实现

				return 1;
			}//end of else if
			printf("登入失败。您还有 %d 次机会尝试。\n",flag-1);
			flag--;

			if(flag ==0)
			{
				printf("您已经输错三次。返回主界面。\n");
				return 0;
			}//end of if
		}
		else
		{
			printf("两次密码输入不一致，请重新输入。\n");

		}
	}//end of while

	return 0;
}

