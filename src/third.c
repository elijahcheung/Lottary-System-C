/*模块功能：	第三方功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "head.h"
#include "struct.h"
#include "declaration.h"
#include <time.h>

/*	函数功能：第三方用户函数
 *	形参：		*lot_head,*lot_pub_head,*lot_inform_head,*user,*pwd
 *	返回值：	
 */
int ThirdMenu(lot_t *lot_head,lot_pub_t *lot_pub_head\
							,lot_inform_t *lot_inform_head,char *user,char *pwd)
{	
	if(lot_head == NULL || lot_pub_head == NULL || lot_inform_head == NULL || user == NULL || pwd == NULL)
	{
		return 0;
	}//end of if

	int input = 0;

	while(1)
	{
		ShowThirdMenu();//读取第三方用户菜单

		printf("请输入选项：");
		while((input=getchar())!='\n' && input != EOF );//清空输入缓存
		scanf("%d",&input);

		switch(input)
		{
			case 0:
				return 0;
				break;
			case 1:
				OpenLottary(lot_head,lot_pub_head,lot_inform_head);
				break;
			case 2:
				ShowLotInform(lot_inform_head);
				break;
			default:
				printf("您输入有误，请重新输入。\n");
				break;
		}//end of switch
	}//end of while
	return 0;
}

/*	函数功能：开奖
 *	形参：		*lot_head,*lot_pub_head,*lot_inform_head
 *	返回值：	
 */
int OpenLottary(lot_t *lot_head,lot_pub_t *lot_pub_head,lot_inform_t *lot_inform_head)
{
	if(lot_head == NULL)
	{
		return 0;
	}//end of if

	char confirm = '\0';

	lot_pub_t *p_pub = NULL;
	lot_t *p = lot_head->next;
	lot_inform_t *p_inform = NULL;

	if(lot_pub_head->next == NULL)//只有头节点
	{
		p_pub = (lot_pub_t *)malloc(sizeof(lot_pub_t));
		p_pub->num = (struct lottary *)malloc(sizeof(struct lottary));

		memset(p_pub->num,0,sizeof(struct lottary));
	}//end of if
	else
	{
		p_pub = lot_pub_head->next;
	}//end of else

	if(lot_inform_head->next == NULL)//只有头节点
	{
		p_inform = (lot_inform_t *)malloc(sizeof(lot_inform_t));
		p_inform->num = (struct lottary *)malloc(sizeof(struct lottary));

		memset(p_inform->num,0,sizeof(struct lottary));
	}//end of if
	else
	{
		p_inform = lot_inform_head->next;
	}//end of else

	printf("你确认开奖吗?\n");
	printf("按\'Y\'确认，按其他任意键退出:");
	scanf(" %c",&confirm);

	printf("下列用户获奖:\n");
	printf("期号\t用户名\t注数\t得奖金额\n");

	if(confirm == 'y' ||confirm == 'Y')
	{
//		if(p_pub->num->issue == p_inform->num->issue)
//		{
			if(p_pub->open_status == 2)
			{
				srand((unsigned)time(NULL));
				int prize = rand()%OPEN_NUM_LEN;//彩票位数

				p_pub->prize_number = prize;//中奖号码加入p_pub链表

				if(lot_inform_head->next == NULL)//彩票为空
				{
					p_pub->open_status = 1;
					printf("没有用户购买彩票。\n");
					printf("\n开奖号码:\t%d\n",prize);
					printf("\n");
					return 0;
				}
				

				while(p_inform->next != NULL)//遍历彩票
				{
					if(p_inform->lot_prize == prize)//比较彩票号码
					{
						if(p_pub->num->issue == p_inform->num->issue)//比较期号
						{
							p_inform->status = 1;
							p = SearchNode(lot_head,p_inform->buyer);//搜索用户节点

							if(p_pub->sell_money >= (p_inform->number*100))//判断中奖金额是否超过奖池金额
							{
								p->money = p->money+p_inform->number*100;
								p_inform->get_money = p_inform->number*100;
							}//end of if
							else
							{
								p->money = p->money + p_pub->sell_money;
								p_inform->get_money = p_pub->sell_money;
							}//end of else

							printf("%d\t%s\t%d\t%.2lf\n",p_inform->num->issue\
																					,p_inform->buyer\
																					,p_inform->number\
																					,p_inform->get_money);
						}
					}//end of if

					p_inform = p_inform->next;
				}//end of while
				printf("\n开奖号码:\t%d\n",prize);
				printf("\n");
				printf("售出总额:\t%d\n",p_pub->sell_number);
				printf("奖池额度:\t%.2lf\n",p_pub->sell_money);
			}//end of if
			else
			{
				printf("请先发布彩票。\n");
				return 0;
			}//end of else

			p_pub->open_status = 1;
			WritePubAllFile(lot_pub_head);
			WriteAllFile(lot_head);
			WriteAllInformFile(lot_inform_head);
//		}//end of if
	}//end of if
	else
	{
		printf("您输入有误，请重新输入。\n");
		return 0;
	}//end of else

	return 0;
}
/*	函数功能：显示彩票信息
 *	形参：		*lot_inform_head
 *	返回值：	
 */
int ShowLotInform(lot_inform_t *lot_inform_head)
{
	if(lot_inform_head == NULL)
	{
		return 0;
	}
	PrintInformNode(lot_inform_head);
	return 0;
}
