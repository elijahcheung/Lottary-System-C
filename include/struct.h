#ifndef _STRUCT_H_
#define _STRUCT_H_
#define PWD_NUM	30//用户密码长度
#define USER_NUM 30//用户帐户长度
#define PRIZE_NUM 6
#define NUM_LEN 1//设置用户购买彩票长度
#define OPEN_NUM_LEN 10//设置开奖号码长度

struct lottary
{
	int issue;//期号
};

/*	彩票结构体	*/
typedef struct lottary_inform_node
{
	int unique_id;//彩票ID
	int lot_prize;//选中号码
	char buyer[USER_NUM];//购买者
	int number;//注数
	int status;//得奖状态
	double get_money;//中奖金额
	struct lottary *num;
	struct lottary_inform_node *next;
}lot_inform_t;

/*	开奖结构体	*/
typedef struct lottary_publish_node
{
	double single_injection_amount;//单价
	int open_status;//开奖状态
	int prize_number;//中奖号码
	int sell_number;//售出总数
	double sell_money;//奖池总额
	struct lottary *num;
	struct lottary_publish_node *next;
}lot_pub_t;


/*	登录结构体	*/
typedef struct lottary_node
{
	//	int id;
	char username[USER_NUM];//用户名
	char pwd[PWD_NUM];//密码
	double money;//金额
	struct lottary_node *next;//尾指针
	struct lottary_node *prep;//头指针
}lot_t;

#endif

