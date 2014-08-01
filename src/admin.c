/*模块功能：	管理员功能实现
 *作者：			章俊杰
 *版本：			1.0
 */

#include "head.h"
#include "struct.h"
#include "declaration.h"

/*	函数功能：管理员菜单函数
 *	形参：		*p,*lot_pub,*user,*pwd
 *	返回值：	
 */

int AdminMenu(lot_t *p,lot_pub_t *lot_pub,char *user,char *pwd)
{	
	if(p == NULL)
	{
		return 0;
	}//end of if

	int input = 0;

	while(1)
	{
		ShowAdminMenu();//读取管理员菜单界面

		printf("请输入选项：");
		while((input=getchar())!='\n' && input != EOF );//清空输入缓存
		scanf("%d",&input);

		switch(input)
		{
			case 0:
				return 0;
				break;
			case 1:
				PubLottary(lot_pub);//发行彩票
				break;
			case 2:
				ShowUserInform(p);
				break;
			case 3:
				Sort(p);
				break;
			default:
				printf("您输入有误，请重新输入。\n");
				break;
		}//end of switch
	}//end of while
	return 0;
}

/*	函数功能：发行彩票函数
 *	形参：		*head
 *	返回值：	
 */

int PubLottary(lot_pub_t *head)
{
	if(head == NULL)
	{
		printf("PubLottary is NULL");
		return 0;
	}//end of if

	//初始化
	lot_pub_t *p = NULL;

	if(head->next == NULL)
	{
		p = (lot_pub_t *)malloc(sizeof(lot_pub_t));
		memset(p,0,sizeof(lot_pub_t));
	}//end of if
	else
	{
		p = head->next;
	}//end of else
	
	//初始化
	int issue = 0;
	double single_injection_amount = 0.0;
	int open_status = 0;
	int prize_number = 0;
	int sell_number = 0;
	double sell_money = 0.0;

	/*	判断彩票开奖状态，已开奖才可以发布新的彩票	*/
	if(p->open_status == 1 || GetPubSize("lottary_pub.dat") == 0)
	{		
		issue = GetPubNodeLen(head)+1;//Get issue number
		printf("请输入单注金额:");
		scanf("%lf",&single_injection_amount);
		printf("请输入奖池金额:");
		scanf("%lf",&sell_money);
		open_status = 2;
		InsertPubNode(head,issue,single_injection_amount\
									,open_status,prize_number\
									,sell_number,sell_money);//插入节点

		WritePubFile(head);

	}//end of if
	else
	{
		printf("请等待开奖。\n");
	}//end of else

	PrintPubNode(head);
	return 0;
}

/*	函数功能：显示用户信息函数
 *	形参：		*p
 *	返回值：	
 */

int ShowUserInform(lot_t *p)
{
	if(p == NULL)
	{
		return 0;
	}//end of if

	//初始化
	int input = 0;

	while(1)
	{
		ShowUserInformMenu();//读取用户信息菜单

		printf("请输入选项：");
		while((input=getchar())!='\n' && input != EOF );//清空输入缓存
		scanf("%d",&input);

		switch(input)
		{
			case 0:
				return 0;
				break;
			case 1:
				ShowByUsername(p);//按用户名排序
				break;
			case 2:
				ShowByMoney(p);//按余额排序
				break;
			default:
				printf("您输入选项错误，请重新输入.\n");
				break;
		}//end of switch
	}//end of while
	return 0;
}

/*	函数功能：排序功能函数
 *	形参：		*p
 *	返回值：	
 */

int Sort(lot_t *p)
{	
	if(p == NULL)
	{
		return 0;
	}//end of if

	//初始化
	int input = 0;

	while(1)
	{
		ShowSortMenu();//读取排序菜单

		printf("请输入选项：");
		while((input=getchar())!='\n' && input != EOF );//清空输入缓存
		scanf("%d",&input);

		switch(input)
		{
			case 0:
				return 0;
				break;
			case 1:
				SortByUsername(p);//按用户名排序
				break;
			case 2:
				SortByMoney(p);//按余额排序
				break;
			default:
				printf("您输入选项错误，请重新输入.\n");
				break;
		}//end of switch
	}//end of while
	return 0;
}


/*	函数功能：按用户名关键字显示函数
 *	形参：		*head
 *	返回值：	
 */

int ShowByUsername(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//初始化
	char key[USER_NUM] = {};
	lot_t *p = head->next;
	char *s = NULL;

	printf("请输入关键字:");
	scanf("%s",key);

	printf("用户名\t余额\n");

	while(p != NULL)
	{
		s = p->username;

		for(;*s != '\0';s++)//搜索字符串
		{
			if(strncmp(s,key,strlen(key)) == 0)
			{
				printf("%s\t%.2lf\n",p->username,p->money);

			}//end of if
		}//end of for
		p=p->next;
	}//end of while
	return 0;
}

/*	函数功能：按余额区间显示函数
 *	形参：		*head
 *	返回值：	
 */

int ShowByMoney(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//初始化
	double min = 0.0;
	double max = 0.0;
	lot_t *p = head->next;

	printf("请输入最小余额:");
	scanf("%lf",&min);
	printf("请输入最大余额:");
	scanf("%lf",&max);

	printf("用户名\t余额\n");

	while(p != NULL)
	{
		if(p->money >=min && p->money <=max)
		{
			printf("%s\t%.2lf\n",p->username,p->money);

		}//end of if
		p=p->next;
	}//end of while
	return 0;
}

/*	函数功能：按用户名排序
 *	形参：		*head
 *	返回值：	
 */

int SortByUsername(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//初始化
	lot_t *p = head->next;
	lot_t *high = NULL;
	char temp[USER_NUM] = {};

	/*	冒泡排序	*/
	for(;p != NULL;p = p->next)
	{
		for(high = p->next;high != NULL;high = high->next)
		{
			if(strcmp(p->username,high->username)>0)
			{
				strcpy(temp,high->username);
				strcpy(high->username,p->username);
				strcpy(p->username,temp);
			}//end of if
		}//end of for
	}//end of for

	PrintNode(head);
	return 0;
}

/*	函数功能：按余额排序
 *	形参：		*head
 *	返回值：	
 */

int SortByMoney(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//初始化
	lot_t *p = head->next;
	lot_t *high = NULL;
	double money = 0.0;

	/*	冒泡排序	*/
	for(;p != NULL;p = p->next)
	{
		for(high = p->next;high != NULL;high = high->next)
		{
			if(p->money	>	high->money)
			{
				money = high->money;
				high->money = p->money;
				p->money = money;
			}//end of if
		}//end of for
	}//end of for

	PrintNode(head);
	return 0;
}

