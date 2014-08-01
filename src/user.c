/*模块功能：	用户功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "struct.h"
#include "head.h"
#include "declaration.h"
#include <time.h>

/*	函数功能：用户菜单函数
 *	形参：		*lot,*lot_pub,*lot_inform,*user,*pwd
 *	返回值：	
 */
int UserMenu(lot_t *lot,lot_pub_t *lot_pub,lot_inform_t *lot_inform,char *user,char *pwd)
{
	if(lot == NULL || lot_pub == NULL || lot_inform == NULL || user == NULL || pwd == NULL)
	{
		return 0;
	}//end of if

	int input = 0;

	while(1)
	{
		ShowUserMenu();//读取用户菜单

		printf("请输入选项：");
		while((input=getchar())!='\n' && input != EOF );//清空输入缓存
		scanf("%d",&input);

		switch(input)
		{
			case 0:
				return 0;
				break;
			case 1:
				ShowPersonMessage(lot,user);
				break;
			case 2:
				ChangePwd(lot,user);
				break;
			case 3:
				AddMoney(lot,user);
				break;
			case 4:
				Bet(lot,lot_pub,lot_inform,user);
				break;
			case 5:
				ShowHistory(lot,lot_inform,user);
				break;
			case 6:
				if(DelUser(lot,user) ==1)
				{
					return 0;
				}
				else
				{
					break;
				}
			default:
				printf("您输入有误，请重新输入。\n");
				break;
		}//end of switch
	}//end of while	

	return 0;
}

/*	函数功能：显示个人信息
 *	形参：		*head,*user
 *	返回值：	
 */
int ShowPersonMessage(lot_t *head,char *user)
{
	if(head == NULL || user == NULL)
	{
		printf("User is not existed.\n");
		return 0;
	}//end of if

	lot_t *p = SearchNode(head,user);//搜索用户

	printf("用户名\t余额\n");
	printf("%s\t%.2lf\n",p->username,p->money);

	return 0;
}

/*	函数功能：修改密码
 *	形参：		*head,*user
 *	返回值：	
 */
int ChangePwd(lot_t *head,char *user)
{
	if(head == NULL || user == NULL)
	{
		printf("用户名不存在.\n");
		return 0;
	}//end of if

	char *passwd;
	char newpasswd[PWD_NUM] = {};
	char *passwd_confirm;
	int len = 0;
	lot_t *p = SearchNode(head,user);//搜索用户

	passwd = getpass("请输入旧密码:");//隐藏密码

	len = strlen(passwd);

	if(strcmp(p->pwd,EncryptPwd(passwd,len)) == 0)
	{
		passwd = getpass("请输入新密码:");
		strcpy(newpasswd,passwd);
		passwd_confirm = getpass("请重复输入新密码:");
		if(strcmp(passwd_confirm,newpasswd) == 0)
		{
			len =strlen(newpasswd);

			strcpy(p->pwd,newpasswd);
			WriteAllFile(head);//写入文件
			printf("密码修改成功。\n");
		}
		else
		{
			printf("两次密码不正确，请重新输入。\n");
		}
	}
	else
	{
		printf("您的密码不正确，请确认您的密码\n");
	}
	return 0;
}

/*	函数功能：充值
 *	形参：		*head,*user
 *	返回值：	
 */
int AddMoney(lot_t *head,char *user)
{
	if(head == NULL || user == NULL)
	{
		printf("用户名不存在.\n");
		return 0;
	}//end of if

	double money = 0.0;
	lot_t *p = SearchNode(head,user);//搜索用户

	printf("请输入充值金额:");
	scanf("%lf",&money);

	if(money < 0.0)
	{
		printf("充值失败。请输入正确数字\n");
		return 0;
	}//end of if

	p->money += money;
	printf("用户名\t余额\n");
	printf("%s\t%.2lf\n",p->username,p->money);
	printf("充值成功.\n");
	WriteAllFile(head);//写入文件
	return 0;
}

/*	函数功能:下注
 *	形参：		*head,*head_pub,*head_inform,*user
 *	返回值：	
 */
int Bet(lot_t *head,lot_pub_t *head_pub,lot_inform_t *head_inform,char *user)
{
	if(head == NULL || head_pub == NULL || head_inform == NULL)
	{
		printf("Pointer is NULL\n");
		return 0;
	}

	lot_pub_t *p_pub = NULL;
	lot_inform_t *p_inform = NULL;

	if(head_pub->next == NULL)//只有头节点
	{
		p_pub = (lot_pub_t *)malloc(sizeof(lot_pub_t));
		p_pub->num = (struct lottary *)malloc(sizeof(struct lottary));
		memset(p_pub->num,0,sizeof(struct lottary));
	}//end of if
	else
	{
		p_pub = head_pub->next;
	}//end of else

	if(head_inform->next == NULL)//只有头节点
	{
		p_inform = (lot_inform_t *)malloc(sizeof(lot_inform_t));
		p_inform->num = (struct lottary *)malloc(sizeof(struct lottary));
		memset(p_inform->num,0,sizeof(struct lottary));
	}//end of if
	else
	{
		p_inform = head_inform->next;
	}//end of else

	lot_t *p = SearchNode(head,user);//搜索用户

	int lot_num = 0;
	int lot = 0;
	int temp = 0;
	char s[20]= {};//用于整型转字符串

	printf("期号\t单注\t状态\n");

	if(p_pub->open_status == 2)//彩票为等待开奖时可以下注
	{
		printf("%d\t%.2lf\t%d\n",p_pub->num->issue\
														,p_pub->single_injection_amount\
														,p_pub->open_status);

		printf("请输入注数:");
		scanf("%d",&lot_num);
		printf("请输入您想购买的号码(长度为%d位):",NUM_LEN);
		scanf("%d",&lot);//用户购买的号码

		sprintf(s,"%d",lot);
		temp = strlen(s);

		if(temp != NUM_LEN ||	lot < 0)
		{
			printf("您购买的号码非法，请重新输入.\n");
			return 0;
		}//end of if

		if(p->money - lot_num*(p_pub->single_injection_amount) <0)
		{
			printf("余额不足，请先充值!\n");
			return 0;
		}//end of if
		else
		{
			p->money = p->money - lot_num*(p_pub->single_injection_amount);
			printf("下注成功。您帐户余额减少了%.2lf\n",lot_num*(p_pub->single_injection_amount));
			WriteAllFile(head);//写入文件

			p_pub->sell_number = p_pub->sell_number + lot_num;

			WritePubAllFile(head_pub);
			
			/*	生成随机数	*/
			srand((unsigned)time(NULL));
			int unique_id = rand()%10000;

			/*	确认彩票ID唯一性	*/
			while(p_inform != NULL)
			{
				if(head_inform->next == NULL)
				{
					break;
				}
				if(unique_id == p_inform->unique_id)
				{
					srand((unsigned)time(NULL));
					unique_id = rand()%10000;
				}//end of if
				p_inform = p_inform->next;
			}//end of while
			
			//插入节点
			InsertInformNode(head_inform,p_pub->num->issue,unique_id,lot,p->username,lot_num,0,0.0);

			WriteInformFile(head_inform);//写入文件
			return 0;			
		}//end of else
	}//end of if
	else
	{
		printf("请等待管理员发布彩票。\n");
	}
	return 0;
}

/*	函数功能：显示购买历史记录
 *	形参：		*head,*head_inform,*user
 *	返回值：	
 */
int ShowHistory(lot_t *head,lot_inform_t *head_inform,char *user)
{
	if(head == NULL || head_inform == NULL || user == NULL)
	{
		return 0;
	}//end of if

	printf("用户名\t彩票ID\t注数\t得奖状态\t得奖金额\n");
	printf("\n");
	lot_t *p = SearchNode(head,user);//search user
	lot_inform_t *p_inform = head_inform->next;

	while(p_inform != NULL)
	{
		if(strcmp(p_inform->buyer,p->username) == 0)
		{
			printf("%s\t%d\t%d\t%d\t\t%.2lf\n",p_inform->buyer\
																			,p_inform->unique_id\
																			,p_inform->number\
																			,p_inform->status\
																			,p_inform->get_money);

		}//end ofi if

		p_inform = p_inform->next;
	}//end of while
	return 0;
}

/*	函数功能：删除用户
 *	形参：		*head,*user
 *	返回值：	
 */
int DelUser(lot_t *head,char *user)
{
	if(head == NULL || user == NULL)
	{
		printf("用户名不存在.\n");
		return 0;
	}//end of if

	char confirm = ' ';

	printf("您确认删除您的帐户吗?\n");
	printf("如果您不想取消，按任意键返回。如果您确认删除，请按 \"Y\":");
	scanf(" %c",&confirm);

	if(confirm == 'y' ||confirm == 'Y')
	{
		DeleteNode(head,user);//删除用户节点
		WriteAllFile(head);//写入文件
		printf("帐户删除成功.\n");
		return 1;
	}//end of if

	return 0;
}
