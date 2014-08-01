#ifndef _DECLARATION_H_
#define _DECLARATION_H_


/*									函数声明											*/

/*************************************************
							Declaration:admin.c
 *************************************************/

//管理员界面
int AdminMenu(lot_t *p,lot_pub_t *lot_pub,char *user,char *pwd);

//发行彩票
int PubLottary(lot_pub_t *lot_pub);

//显示用户信息
int ShowUserInform(lot_t *p);

int Sort(lot_t *p);

int ShowByUsername(lot_t *head);

int ShowByMoney(lot_t *head);

int SortByMoney(lot_t *head);

int SortByUsername(lot_t *head);

//快速排序
lot_t *SortMethodMoney(lot_t *head,lot_t *low,lot_t *high);

//递归快速排序
int QuickSort(lot_t *head,lot_t *low,lot_t *high,int flag);

/*************************************************
							Declaration:node.c
 *************************************************/

//创建lot_inform_t头节点
lot_inform_t *CreateInformHeadNode();

//创建lot_infrom_t节点
lot_inform_t *CreateInformNode(int issue,int unique_id,int lot_prize\
															,char *buyer,int number,int statu
															,double get_money);

//创建lot_pub_t头节点
lot_pub_t *CreatePubHeadNode();

//创建lot_pub_t节点
lot_pub_t *CreatePubNode(int issue,double single_injection_amount\
												,int open_status,int prize_number\
												,int sell_number,double sell_money);

//插入lot_pub_t节点
lot_pub_t *InsertPubNode(lot_pub_t *lot_pub,int issue,double single_injection_amount\
												,int open_status,int prize_number,int sell_number,double sell_money);

//创建lot_t头节点
lot_t *CreateHeadNode();

//创建lot_t节点
lot_t *CreateNode(char *user,char *pwd);

//搜索lot_t节点
lot_t *SearchNode(lot_t *head,char *user);

//插入lot_t节点
lot_t *InsertNode(lot_t *head,char *user,char *pwd,double money);

//比较用户名和密码
int CompareNode(lot_t *head,char *user,char *pwd);

//删除lot_t节点
lot_t *DeleteNode(lot_t *head,char *user);

//获取节点长度
int GetNodeLen(lot_t *head);

//打印lot_pub_t节点
int PrintPubNode(lot_pub_t *head);

//打印lot_inform_t节点
int PrintInformNode(lot_inform_t *head);

//打印lot_t节点
int PrintNode(lot_t *p);

//插入lot_inform_t节点
lot_inform_t *InsertInformNode(lot_inform_t *head,int issue,int unique_id\
															,int lot_prize,char *buyer,int number\
															,int status,double get_money);

//获取lot_pub_t节点数
int GetPubNodeLen(lot_pub_t *head);

int FreeAllNode(lot_t *head,lot_pub_t *head_pub,lot_inform_t *head_inform);

/*************************************************
						Declaration:third.c
 *************************************************/

//第三方用户菜单
int ThirdMenu(lot_t *lot_head,lot_pub_t *lot_pub_head,lot_inform_t *lot_inform_head\
							,char *user,char *pwd);

//开奖
int OpenLottary(lot_t *lot_head,lot_pub_t *lot_pub_head,lot_inform_t *lot_inform_head);

//显示彩票信息
int ShowLotInform(lot_inform_t *lot_inform_head);

/*************************************************
						Declaration:user.c
 *************************************************/

int UserMenu(lot_t *lot,lot_pub_t *lot_pub,lot_inform_t *lot_inform,char *user,char *pwd);

int ShowPersonMessage(lot_t *head,char *user);

int ChangePwd(lot_t *head,char *user);

int AddMoney(lot_t *head,char *user);

int Bet(lot_t *head,lot_pub_t *head_pub,lot_inform_t *head_inform,char *user);

int ShowHistory(lot_t *head,lot_inform_t *head_inform,char *user);

int DelUser(lot_t *head,char *user);

/*************************************************
						Declaration:login.c
 *************************************************/

int LoginUser(lot_t *head,lot_pub_t *lot_pub,lot_inform_t *lot_inform);

/*************************************************
						Declaration:register.c
 *************************************************/

int RegUser(lot_t *head);

/*************************************************
						Declaration:file.c
 *************************************************/

//加载lot_t结构体文件
int LoadFile(lot_t *head);

//写入lot_t结构体文件
int WriteFile(lot_t *head);

//重新写入lot_t结构体文件
int WriteAllFile(lot_t *head);

//重新写入lot_pub_t结构体文件
int WritePubAllFile(lot_pub_t *head);

//写入lot_pub_t结构体文件
int WritePubFile(lot_pub_t *head);

//加载lot_pub_t结构体文件
int LoadPubFile(lot_pub_t *head);

//写入lot_inform_t结构体文件
int WriteInformFile(lot_inform_t *head_inform);

int GetPubSize(char *filename);

//重新写入lot_infrorm_t结构体文件
int WriteAllInformFile(lot_inform_t *head_inform);

//加载lot_inform_t结构体文件
int LoadInformFile(lot_inform_t *head);

/*************************************************
						Declaration:file.c
 *************************************************/

void ShowMainMenu();

void ShowUserMenu();

void ShowAdminMenu();

void ShowThirdMenu();

void ShowUserInformMenu();

void ShowSortMenu();

void ShowSortMethod();

/*************************************************
						Declaration:secret.c
 *************************************************/

char	*EncryptPwd(char *pwd,int n);

char	*DecryptPwd(char *pwd,int n);

#endif

