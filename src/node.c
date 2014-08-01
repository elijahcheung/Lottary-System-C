/*模块功能：	节点功能	
 *作者：			章俊杰
 *版本：			1.0
 */

#include "struct.h"
#include "head.h"
#include "declaration.h"

/*	函数功能：创建lot_t头节点
 *	形参：		NULL
 *	返回值：	CreateNode()
 */

lot_t *CreateHeadNode()
{
	return CreateNode("","");
}

/*	函数功能：创建lot_t节点	
 *	形参：		*user,*pwd
 *	返回值：	p
 */

lot_t *CreateNode(char *user,char *pwd)
{
	if(user == NULL && pwd == NULL)
	{
		return NULL;
	}//end of if

	lot_t *p = (lot_t *)malloc(sizeof(lot_t));

	if(p == NULL)
	{
		printf("P is NULL\n");

	}//end of if

	/*	初始化节点	*/
	strcpy(p->username,user);
	strcpy(p->pwd,pwd);
	p->next = NULL;
	p->prep = NULL;
	return p;
}

/*	函数功能：搜索lot_t节点
 *	形参：		*head,*user
 *	返回值：	p
 */

lot_t *SearchNode(lot_t *head,char *user)
{
	if(head == NULL || user == NULL)
	{
		return NULL;
	}//end of if

	lot_t *p = head->next;

	/* 遍历所有节点	*/
	while(p != NULL)
	{
		if(strcmp(p->username,user) !=0)//比较用户名
		{
			p = p->next;
		}//end of if
		else
		{
			return p;
		}//end of else
	}//end of while

	return NULL;
}

/*	函数功能：比较用户节点	
 *	形参：		*head,*user,*pwd
 *	返回值：	0,1,2,3
 */

int CompareNode(lot_t *head,char *user,char *pwd)
{
	if(head == NULL || user == NULL)
	{
		return 0;
	}//end of if

	lot_t *p = head->next;

	/* 遍历所有节点	*/
	while(p != NULL)
	{
		/*	比较用户名和密码	*/
		if(strcmp(p->username,user) ==0 && strcmp(p->pwd,pwd) == 0)
		{
			if(strcmp(p->username,"third") ==0)
			{
				return 3;
			}//end of if
			else if(strcmp(p->username,"admin") ==0)
			{
				return 2;
			}//end of else if
			else
			{
				return 1;
			}//end of else
		}//end of if
		else
		{
			p = p->next;
		}//end of else
	}//end of while

	return 0;
}

/*	函数功能：插入lot_t节点	
 *	形参：		*head,*user,*pwd,money
 *	返回值：	head
 */

lot_t *InsertNode(lot_t *head,char *user,char *pwd,double money)
{
	if(head == NULL || user == NULL || pwd ==NULL)
	{
		return NULL;
	}//end of if

	lot_t *p = (lot_t *)malloc(sizeof(lot_t));

	if(p == NULL)
	{
		printf("P is NULL\n");

	}//end of if

	if(head->next == NULL)//如果只有一个节点
	{
		strcpy(p->username,user);
		strcpy(p->pwd,pwd);
		p->money = money;
		p->next = NULL;
		p->prep = head;
		head->next = p;
		return head;
	}//end of if
	else
	{
		strcpy(p->username,user);
		strcpy(p->pwd,pwd);
		p->money = money;
		p->next = head->next;
		p->prep = head;
		head->next->prep = p;
		head->next = p;
		return head;
	}//end of else	
	return NULL;
}

/*	函数功能：从lot_t删除节点
 *	形参：		*head,*user
 *	返回值：	p
 */

lot_t *DeleteNode(lot_t *head,char *user)
{
	if(head == NULL || user == NULL)
	{
		return NULL;
	}//end of if

	/*	搜索用户名	*/
	lot_t *p = SearchNode(head,user);

	if(p == NULL)
	{
		printf("P is NULL\n");

	}

	if(p->next == NULL)//p是最后一个节点
	{
		p->prep->next = p->next;
		free(p);
		p = NULL;
	}
	else
	{	
		p->prep->next = p->next;
		p->next->prep = p->prep;
		free(p);
		p = NULL;
	}
	return NULL;
}

/*	函数功能：获取节点长度
 *	形参：		*head
 *	返回值：	len
 */

int GetNodeLen(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}

	int len = 0;
	lot_t *p = head->next;

	while(p != NULL)
	{
		len++;
		p = p->next;

	}
	return len;
}

/*	函数功能：打印节点	
 *	形参：		*head
 *	返回值：	0
 */

int PrintNode(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	lot_t *p = head->next;

	while(p != NULL)
	{
		printf("%s\t%.2lf\n",p->username,p->money);
		p = p->next;
	}//end of while
	return 0;
}

/************************************************/
/*							STUCT LOTTARY_INFORM					  */
/************************************************/

/*	函数功能：创建lot_inform头节点	
 *	形参：		NULL
 *	返回值：	CreateInformNode()
 */

lot_inform_t *CreateInformHeadNode()
{
	return CreateInformNode(-1,-1,-1,"",-1,-1,-1.0);
}

/*	函数功能：创建lot_inform节点
 *	形参：		issue,unique_id,lot_prize,*buyer,number,status,get_money
 *	返回值：	p
 */

lot_inform_t *CreateInformNode(int issue,int unique_id,int lot_prize\
		,char *buyer,int number,int status,double get_money)
{

	lot_inform_t *p = (lot_inform_t *)malloc(sizeof(lot_inform_t));
	p->num = (struct lottary *)malloc(sizeof(struct lottary));
	memset(p->num,0,sizeof(struct lottary));

	p->num->issue = issue;
	p->unique_id = unique_id;
	p->lot_prize = lot_prize;
	strcpy(p->buyer,buyer);
	p->number = number;
	p->status = status;
	p->get_money = get_money;
	p->next = NULL;
	return p;
}

/*	函数功能：插入lot_inform节点
 *	形参：		*head,issue,unique_id,lot_prize,*buyer,number,status,get_money
 *	返回值：	head
 */

lot_inform_t *InsertInformNode(lot_inform_t *head,int issue,int unique_id\
		,int lot_prize,char *buyer,int number,int status,double get_money)
{
	if(head == NULL)
	{
		return NULL;
	}//end of if

	lot_inform_t *p = (lot_inform_t *)malloc(sizeof(lot_inform_t));
	p->num = (struct lottary *)malloc(sizeof(struct lottary));
	memset(p->num,0,sizeof(struct lottary));

	if(p == NULL)
	{
		printf("P is NULL\n");

	}//end of if

	p->num->issue = issue;
	p->unique_id = unique_id;
	p->lot_prize = lot_prize;
	strcpy(p->buyer,buyer);
	p->number = number;
	p->status = status;
	p->get_money = get_money;
	p->next = head->next;
	head->next = p;
	return head;
}

/*	函数功能：打印节点函数
 *	形参：		*head
 *	返回值：	0
 */

int PrintInformNode(lot_inform_t *head)
{
	if(head == NULL)
	{
		return 0;
	}

	lot_inform_t *p = head->next;

	printf("期号\t彩票ID\t选中号码\t购买者\t注数\t中奖状态\t得奖金额\n");
	while(p != NULL)
	{
		printf("%d\t%d\t%d\t\t%s\t%d\t%d\t\t%.2lf\n",p->num->issue\
				,p->unique_id\
				,p->lot_prize\
				,p->buyer\
				,p->number\
				,p->status\
				,p->get_money);
		p = p->next;

	}//end of while
	printf("中奖状态说明：1.中奖\t0.未中奖\n");

	return 0;
}


/***********************************************************/
/*							STUCT LOTTARY_PUB												   */
/***********************************************************/



/*	函数功能：创建lot_pub头节点
 *	形参：		NULL
 *	返回值：	CreatePubNode()
 */

lot_pub_t *CreatePubHeadNode()
{
	return CreatePubNode(-1,0.0,-1,-1,-1,0.0);
}

/*	函数功能：创建lot_pub节点
 *	形参：		issue,single_injection_amount,open_status,prize_number,sell_number,sell_money
 *	返回值：	p
 */

lot_pub_t *CreatePubNode(int issue,double single_injection_amount\
		,int open_status,int prize_number,int sell_number,double sell_money)
{

	lot_pub_t *p = (lot_pub_t *)malloc(sizeof(lot_pub_t));
	p->num = (struct lottary *)malloc(sizeof(struct lottary));
	memset(p->num,0,sizeof(struct lottary));

	p->num->issue = issue;
	p->single_injection_amount = single_injection_amount;
	p->open_status = open_status;
	p->prize_number = prize_number;
	p->sell_number = sell_number;
	p->sell_money = sell_money;
	p->next = NULL;
	return p;
}


/*	函数功能：插入lot_pub节点
 *	形参：		*head,issue,single_injection_amount,open_status,prize_number,sell_number,sell_money
 *	返回值：	head
 */

lot_pub_t *InsertPubNode(lot_pub_t *head,int issue,double single_injection_amount	\
		,int open_status,int prize_number,int sell_number,double sell_money)
{
	if(head == NULL)
	{
		return NULL;
	}//end of if

	lot_pub_t *p = (lot_pub_t *)malloc(sizeof(lot_pub_t));
	p->num = (struct lottary *)malloc(sizeof(struct lottary));
	memset(p->num,0,sizeof(struct lottary));

	if(p == NULL)
	{
		printf("P is NULL\n");

	}//end of if

	p->num->issue = issue;
	p->single_injection_amount = single_injection_amount;
	p->open_status = open_status;
	p->prize_number = prize_number;
	p->sell_number = sell_number;
	p->sell_money = sell_money;
	p->next = head->next;
	head->next = p;
	return head;
}

/*	函数功能：打印lot_pub节点
 *	形参：		*head
 *	返回值：	0
 */

int PrintPubNode(lot_pub_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	lot_pub_t *p = head->next;

	printf("期号\t单注\t开奖状态\t开奖号码\t售出总数\t奖池额度\n");
	while(p != NULL)
	{
		printf("%d\t%.2lf\t\t%d\t%d\t\t%d\t\t%.2lf\n",p->num->issue\
				,p->single_injection_amount\
				,p->open_status\
				,p->prize_number\
				,p->sell_number\
				,p->sell_money);
		p = p->next;

	}
	printf("开奖状态说明：1.已经开奖\t2.等待开奖\n");
	return 0;
}

/*	函数功能：获取lot_pub长度
 *	形参：		*head
 *	返回值：	len
 */
int GetPubNodeLen(lot_pub_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	int len = 0;
	lot_pub_t *p = head->next;

	while(p != NULL)
	{
		len++;
		p = p->next;

	}//end of while
	return len;
}

/*	函数功能：释放所有节点
 *	形参：		*head,*head_pub,*head_inform
 *	返回值：	
 */

int FreeAllNode(lot_t *head,lot_pub_t *head_pub,lot_inform_t *head_inform)
{
	if(head == NULL || head_pub == NULL || head_inform == NULL)
	{
		return 0;
	}

	lot_t *p = head->next;
	lot_inform_t *p_inform = head_inform->next;
	lot_pub_t *p_pub = head_pub->next;

	while(p != NULL)
	{
		p->next->prep = p->prep;
		p->prep->next = p->next;
		free(p);
		p = NULL;
	}
	while(p_pub != NULL)
	{
		free(p_pub);
		p_pub = p_pub->next;
		p = NULL;
	}
	while(p_inform != NULL)
	{
		free(p_inform);
		p_inform = p_inform->next;
		p = NULL;
	}
	return 0;
}
