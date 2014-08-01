/*
 *项目名称:				简易彩票管理系统
 *作者:						章俊杰
 *日期:						2014年7月28日
 *版本:						1.0
 */

#include "struct.h"
#include "head.h"
#include "declaration.h"

/*	函数功能：主函数
 *	形参：		argc,*argv[]
 *	返回值：	
 */
int main(int argv,char *argc[])
{

	int input = 0;
	lot_t *lot_head = CreateHeadNode();//创建lot_t结构体头节点
	lot_pub_t *lot_pub_head = CreatePubHeadNode();//创建lot_pub_t结构体头节点
	//创建lot_inform_t结构体头节点
	lot_inform_t *lot_inform_head = CreateInformHeadNode();

	memset(lot_head,0,sizeof(lot_t));
	memset(lot_pub_head,0,sizeof(lot_pub_t));
	memset(lot_inform_head,0,sizeof(lot_inform_t));

	int iRet = LoadFile(lot_head);
	if( iRet < 0 )
	{
		printf("lot_head is null\n");
	}
	int iPub = LoadPubFile(lot_pub_head);
	if(iPub <0)
	{
		printf("lot_iPub is null\n");
	}
	int iInform = LoadInformFile(lot_inform_head);
	if(iInform <0)
	{
		printf("lot_iInform is null\n");
	}

	printf("************************\n");
	printf(" 欢迎使用彩票管理系统\n");

	while(1)
	{
		ShowMainMenu();//读取主菜单

		printf("\n");
		printf("请输入选项:");
//		while((input=getchar())!='\n' && input != EOF );//清空输入缓存
		fflush(stdin);
		scanf("%d",&input);

		switch(input)
		{
			case 0:
				return 0;
				break;
			case 1:
				RegUser(lot_head);//注册用户
				break;
			case 2:
				LoginUser(lot_head,lot_pub_head,lot_inform_head);//登入用户
				break;
			default:
				printf("您输入有误，请重新输入。\n");
				break;
		}//end of switch

	}//end of while

	FreeAllNode(lot_head,lot_pub_head,lot_inform_head);

	return 0;
}

