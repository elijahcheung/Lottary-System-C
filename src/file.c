/*模块功能：	文件功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "head.h"
#include "struct.h"
#include "declaration.h"

/*	函数功能：加载结构体
 *	形参：		*head
 *	返回值：	ret
 */
int LoadFile(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//	lot_t *p = head->next;
	FILE *fp = fopen("lottary.dat","r+");
	int ret = 0;

	char c = '\0';
	int line = 0;

	while(c != EOF)
	{
		c = fgetc(fp);
		if(c == '\n')
		{
			line++;
		}//end of if
	}//end of while

	rewind(fp);
	while(line>0)
	{	
		lot_t *p = (lot_t *)malloc(sizeof(lot_t));
		memset(p,0,sizeof(lot_t));

		fscanf( fp,"%s %s %lf\n",p->username,p->pwd,&p->money);

		InsertNode(head,p->username,p->pwd,p->money);
		line--;
	}//end of while
	
	fclose(fp);

	return ret;
}

/*	函数功能：写入结构体
 *	形参：		*head
 *	返回值：	
 */

int WriteFile(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	lot_t *p = head->next;
	FILE *fp = NULL;

	if( head->next == NULL )
	{
		printf("LinkList has no data");
		exit(-1);
	}//end of if

	fp = fopen("lottary.dat","a+");

	if(fp == NULL)
	{
		printf("FP FOPEN ERROR\n");
		exit(-1);
	}//end of if

	fprintf(fp,"%s %s %.2f\n",p->username,p->pwd,p->money);

	if(fclose(fp))
	{
		printf("FP FCLOSE ERROR\n");
		exit(-1);
	}//end of if
	return 0;
}

/*	函数功能：重新完整写入结构体
 *	形参：		*head
 *	返回值：	
 */

int WriteAllFile(lot_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	lot_t *p = head->next;
	FILE *fp = NULL;

	if( head->next == NULL )
	{
		printf("LinkList has no data");
		exit(-1);
	}//end of if

	fp = fopen("lottary.dat","w+");

	if(fp == NULL)
	{
		printf("FP FOPEN ERROR\n");
		exit(-1);
	}//end of if

	while(p != NULL)
	{
		fprintf(fp,"%s %s %.2f\n",p->username,p->pwd,p->money);

		p = p->next;
	}//end of while

	if(fclose(fp))
	{
		printf("FP FCLOSE ERROR\n");
		exit(-1);
	}//end of if
	return 0;
}

/*	函数功能：写入结构体
 *	形参：		*head
 *	返回值：	
 */

int WritePubFile(lot_pub_t *head)
{	
	if(head == NULL)
	{
		return 0;
	}//end of if

	lot_pub_t *p = head->next;
	FILE *fp = NULL;

	if( head->next == NULL )
	{
		printf("LinkList has no data");
		exit(-1);
	}//end of if

	fp = fopen("lottary_pub.dat","a+");

	if(fp == NULL)
	{
		printf("FP FOPEN ERROR\n");
		exit(-1);
	}//end of if

	fprintf(fp,"%d %lf %d %d %d %lf\n",p->num->issue\
																		,p->single_injection_amount\
																		,p->open_status\
																		,p->prize_number\
																		,p->sell_number\
																		,p->sell_money);

	if(fclose(fp))
	{
		printf("FP FCLOSE ERROR\n");
		exit(-1);
	}//end of if
	return 0;
}

/*	函数功能：重新写入结构体
 *	形参：		*head
 *	返回值：	
 */

int WritePubAllFile(lot_pub_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	lot_pub_t *p = head->next;
	FILE *fp = NULL;

	if( head->next == NULL )
	{
		printf("LinkList has no data");
		exit(-1);
	}//end of if

	fp = fopen("lottary_pub.dat","w+");

	if(fp == NULL)
	{
		printf("FP FOPEN ERROR\n");
		exit(-1);
	}//end of if

	while(p != NULL)
	{

		fprintf(fp,"%d %lf %d %d %d %lf\n",p->num->issue\
																			,p->single_injection_amount\
																			,p->open_status\
																			,p->prize_number\
																			,p->sell_number\
																			,p->sell_money);

		p = p->next;
	}//end of while
	if(fclose(fp))
	{
		printf("FP FCLOSE ERROR\n");
		exit(-1);
	}//end of if
	return 0;
}

/*	函数功能：加载结构体
 *	形参：		*head
 *	返回值：	ret
 */

int LoadPubFile(lot_pub_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//	lot_pub_t *p = head->next;
	FILE *fp = fopen("lottary_pub.dat","r+");

	if(fp == NULL)
	{
		return 0;
	}
	int ret = 0;
	char c = ' ';
	int line = 0;

	while(c != EOF)
	{
		c = fgetc(fp);
		if(c == '\n')
		{
			line++;
		}//end of if
	}//end of while

	rewind(fp);
	while(line>0)
	{	
		lot_pub_t *p = (lot_pub_t *)malloc(sizeof(lot_pub_t));
		p->num = (struct lottary *)malloc(sizeof(struct lottary));
		memset(p->num,0,sizeof(struct lottary));

		fscanf( fp,"%d %lf %d %d %d %lf\n",&p->num->issue\
																			,&p->single_injection_amount\
																			,&p->open_status\
																			,&p->prize_number\
																			,&p->sell_number\
																			,&p->sell_money);

		InsertPubNode(head,p->num->issue,p->single_injection_amount\
									,p->open_status,p->prize_number,p->sell_number\
									,p->sell_money);

		line--;
	}//end of while

	fclose(fp);

	return ret;
}

/*	函数功能：获取结构体长度
 *	形参：		*filename
 *	返回值：	val
 */
int GetPubSize(char *filename)
{
	if(filename == NULL)
	{
		return 0;
	}//end of if

	FILE *fp = NULL;
	int val = 0;
	fp = fopen(filename,"r");
	if(fp == NULL)
	{
		return -1;
	}//end of if

	fseek(fp,0,SEEK_END);

	val = ftell(fp);
	return val;
}

/*	函数功能：写入结构体
 *	形参：		*head_inform
 *	返回值：	
 */
int WriteInformFile(lot_inform_t *head_inform)
{
	if(head_inform == NULL)
	{
		return 0;
	}//end of if

	lot_inform_t *p = head_inform->next;
	FILE *fp = NULL;

	if( head_inform->next == NULL )
	{
		printf("LinkList has no data");
		exit(-1);
	}//end of if

	fp = fopen("lottary_inform.dat","a+");

	if(fp == NULL)
	{
		printf("FP FOPEN ERROR\n");
		exit(-1);
	}//end of if

	fprintf(fp,"%d %d %d %s %d %d %lf\n",p->num->issue\
																			,p->unique_id\
																			,p->lot_prize\
																			,p->buyer\
																			,p->number\
																			,p->status\
																			,p->get_money);

	if(fclose(fp))
	{
		printf("FP FCLOSE ERROR\n");
		exit(-1);
	}//end of if
	return 0;
}

/*	函数功能：重新完全写入结构体
 *	形参：		*head_inform
 *	返回值：	
 */

int WriteAllInformFile(lot_inform_t *head_inform)
{
	if(head_inform == NULL)
	{
		return 0;
	}//end of if

	lot_inform_t *p = head_inform->next;
	FILE *fp = NULL;

	if( head_inform->next == NULL )
	{
		printf("LinkList has no data");
		exit(-1);
	}//end of if

	fp = fopen("lottary_inform.dat","w+");

	if(fp == NULL)
	{
		printf("FP FOPEN ERROR\n");
		exit(-1);
	}//end of if

	while(p != NULL)
	{
		fprintf(fp,"%d %d %d %s %d %d %lf\n",p->num->issue\
																				,p->unique_id\
																				,p->lot_prize\
																				,p->buyer\
																				,p->number\
																				,p->status\
																				,p->get_money);
		p = p->next;
	}//end of while

	if(fclose(fp))
	{
		printf("FP FCLOSE ERROR\n");
		exit(-1);
	}//end of if
	return 0;
}

/*	函数功能：加载结构体
 *	形参：		*head
 *	返回值：	ret
 */
int LoadInformFile(lot_inform_t *head)
{
	if(head == NULL)
	{
		return 0;
	}//end of if

	//	lot_pub_t *p = head->next;
	FILE *fp = fopen("lottary_inform.dat","r+");
	int ret = 0;

	if(fp == NULL)
	{
		return 0;
	}

	char c = ' ';
	int line = 0;

	while(c != EOF)
	{
		c = fgetc(fp);
		if(c == '\n')
		{
			line++;
		}//end of if
	}//end of while

	rewind(fp);
	while(line>0)
	{	
		lot_inform_t *p = (lot_inform_t *)malloc(sizeof(lot_inform_t));
		p->num = (struct lottary *)malloc(sizeof(struct lottary));
		memset(p->num,0,sizeof(struct lottary));

		fscanf( fp,"%d %d %d %s %d %d %lf\n",&p->num->issue\
																				,&p->unique_id\
																				,&p->lot_prize\
																				,p->buyer\
																				,&p->number\
																				,&p->status\
																				,&p->get_money);
		InsertInformNode(head,p->num->issue,p->unique_id,p->lot_prize\
											,p->buyer,p->number,p->status,p->get_money);
		line--;
	}//end of while

	fclose(fp);

	return ret;
}

