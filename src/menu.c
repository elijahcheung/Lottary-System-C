/*模块功能：	菜单功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "head.h"
#include "struct.h"
#include "declaration.h"

/*	函数功能：登录界面菜单
 *	形参：		
 *	返回值：	
 */
void ShowMainMenu(void)
{
	printf("************************\n");
	printf("\t1.注册\n");
	printf("\t2.登录\n");
	printf("\t0.退出\n");
	printf("************************\n");
}

/*	函数功能：用户界面菜单
 *	形参：		
 *	返回值：	
 */
void ShowUserMenu(void)
{
	printf("************************\n");
	printf("\t用户界面\n");
	printf("************************\n");
	printf("\n");
	printf("\t1.显示个人信息\n");
	printf("\t2.修改密码\n");
	printf("\t3.充值\n");
	printf("\t4.下注\n");
	printf("\t5.显示历史记录\n");
	printf("\t6.删除帐号\n");
	printf("\t0.退出\n");
	printf("************************\n");
}

/*	函数功能：管理员界面菜单
 *	形参：		
 *	返回值：	
 */
void ShowAdminMenu(void)
{
	printf("************************\n");
	printf("\t管理员界面\n");
	printf("************************\n");
	printf("\n");
	printf("\t1.发布彩票\n");
	printf("\t2.显示用户信息\n");
	printf("\t3.排序\n");
	printf("\t0.退出\n");
	printf("************************\n");
}

/*	函数功能：第三方界面菜单
 *	形参：		
 *	返回值：	
 */
void ShowThirdMenu(void)
{
	printf("************************\n");
	printf("\t第三方界面\n");
	printf("************************\n");
	printf("\n");
	printf("\t1.开奖\n");
	printf("\t2.显示彩票信息\n");
	printf("\t0.退出\n");
	printf("************************\n");
}

/*	函数功能：显示功能界面
 *	形参：		
 *	返回值：	
 */
void ShowUserInformMenu(void)
{
	printf("************************\n");
	printf("\n");
	printf("\t1.按用户名显示\n");
	printf("\t2.按余额显示\n");
	printf("\t0.退出\n");
	printf("************************\n");
}

/*	函数功能：排序功能界面
 *	形参：		
 *	返回值：	
 */
void ShowSortMenu(void)
{	
	printf("************************\n");
	printf("\n");
	printf("\t1.按用户名排序\n");
	printf("\t2.按余额排序\n");
	printf("\t0.退出\n");
	printf("************************\n");
}
