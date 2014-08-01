/*模块功能：	加解密功能实现
 *作者：			章俊杰
 *版本：			1.0
 */
#include "head.h"
#include "struct.h"
#include "declaration.h"

/*	函数功能：加密功能
 *	形参：		*pwd,n
 *	返回值： pwd
 */
char	*EncryptPwd(char *pwd,int n)
{
	if(pwd == NULL)
	{
		return 0;
	}

	int i = 0;

	for(i = 0;i < n;i++)
	{
		*(pwd + i) = *(pwd + i) + i*i + i + 1;
	}
	return pwd;
}

/*	函数功能：解密功能
 *	形参：		*pwd,n
 *	返回值：pwd
 */
char	*DecryptPwd(char *pwd,int n)
{
	if(pwd == NULL)
	{
		return 0;
	}

	int i = 0;

	for(i = 0;i < n;i++)
	{
		*(pwd + i) = *(pwd + i) - i*i - i - 1;
	}
	return pwd;
}
