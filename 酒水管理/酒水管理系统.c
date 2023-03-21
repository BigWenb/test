#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<conio.h>



//定义宏常量
#define MAX_ID 11
#define MAX_PWD 20
#define MAX_NAME 15
#define MAX_SEX 5
#define MAX_PHONE 12

//商品定义
typedef struct Shop{
  char name[100];
  int price;

  struct Shop*next;
}shop;


//创建用户的结构体

typedef struct Users
{
	char id[MAX_ID];//id 即登录的账号
	char pwd[MAX_PWD];//密码
	char name[MAX_NAME];//姓名
	char sex[MAX_SEX];//性别
	char phone[MAX_PHONE];//电话
}Users;






shop list;//链表

//函数声明
void addinfo();//增加函数
void deleinfo(shop*L);//删除函数
void meau();//主菜单函数
void fixinfo(shop*L);//修改函数
void searchinfo(shop*L);//查找函数
void printinfo(shop*L);//输出函数
void tuichu();//退出函数
void insertshopinfo(shop*L,shop e);//插入函数
int savefile(shop*L);//保存函数
shop*searchshop(char name[],shop*L);
int readfile(shop*L);//读取文件
void dele(shop*p);
//打印菜单
void menu();

//用户注册
void Register();

//登录
void Login();

//找回密码
void Reback();

//定位光标
void gotoxy();

//获取x的位置
int posx();

//获取y的位置
int posy();

//密码输入（含掩盖功能）
void Getpwd(char* pwd);

void guanliyuan();
void yonghu();
void main_meau();















int main()
{
    printf("******欢迎来到酒水管理系统********\n");
    printf("       请输入您的登录方式\n");
    printf("         1 :管理员登录\n");
    printf("         2 :用户登录\n");
    int choice1=0;

while(true)
{
    printf("*********");
    scanf("%d",&choice1);
    switch(choice1)
    {
      case 1:
         guanliyuan();
        break;
      case 2:
         yonghu();
        break;
      case 0:
        tuichu();
       break;

      default:
        printf("输入有错，请重新输入\n");
        system("pause");
        system("cls");
        break;
    }
}
}
//登录后的主菜单




void main_meau()
{
    int choice=0;
    int m;
    m=readfile(&list);
    printf("%d",m);
    system("pause");

while(true)
{
    meau();
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
         addinfo();//增加商品
        break;
      case 2:
         deleinfo(&list);
        break;
      case 3:
          fixinfo(&list);
        break;
      case 4:
        searchinfo(&list);
        break;
      case 5:
         printinfo(&list);//输出全部商品
        break;
      case 6:
          //vieworder();   //查看用户订单
        break;
      case 0:
         tuichu();
        break;
      default:
        printf("输入有错，请重新输入\n");
        system("pause");
        system("cls");
        break;
    }
    printf("是否需要继续操作？(yes : 1/no : 0) :");
    scanf("%d",&choice);
    if(choice==0){
        break;
    }
}
 return ;
}
void meau()
{
    system("cls");
    printf("***********************");
    printf("**   酒水管理系统  **\n");
    printf("** 1 增加商品信息  **\n");
    printf("** 2 删除商品信息  **\n");
    printf("** 3 修改商品信息  **\n");
    printf("** 4 查询商品信息  **\n");
    printf("** 5 输出商品信息  **\n");
    printf("** 6 查看用户订单  **\n");

    printf("** 0 退出管理系统  **\n");

    printf("**  请输入对应的功能键:  **\n");

}



int readfile(shop*L)
{
    FILE*fpr=fopen("shopinfo.txt","r");
    shop st;
    shop*s;
    shop*t=L;
    if(fpr==NULL)
    {
        return 0;
    }
    else
    {
        while(fscanf(fpr,"%s %d",st.name,&st.price)!=EOF)
        {

           s=(shop*)malloc(sizeof(shop));
           *s=st;
           t->next=s;
           t=s;
           t->next=NULL;


        }
    }
}

void printinfo(shop*L)
{
    system("cls");
   shop*p=L->next;
   printf("**************************\n");
   printf("|商品名称 \t|价格\t|\n");
   if(p!=NULL)
   {
       while(p!=NULL)
       {
           printf(" %s \t%d\n",p->name,p->price);
           p=p->next;
       }
    printf("************************\n");
   }
}
//增加商品
void addinfo()
{
    system("cls");
    shop st;
    printf("请输入新增商品名称:");
    scanf("%s",st.name);
    printf("%s",st.name);

    printf("请输入新增商品价格:");
    scanf("%d",&st.price);

    insertshopinfo(&list,st);
}
//插入商品
void insertshopinfo(shop*L,shop e)
{
   shop*h=L;
   shop*s=(shop*)malloc(sizeof(shop));
   *s=e;
   s->next=h->next;
   h->next=s;
   savefile(L);
}
//保存文件
int savefile(shop*L)
{
    FILE*fpw=fopen("shopinfo.txt","w");
    if(fpw==NULL)
    {
        return 0;
    }

    shop*p=L->next;
    while(p!=NULL)
    {
        fprintf(fpw,"%s %d",p->name,p->price);
        p=p->next;
    }
    return 1;
}
//查找商品1
void searchinfo(shop *L)
{
    system("cls");
    shop*st;
    printf("请输入查询的商品名称");
    char name[50];
    scanf("%s",name);
    st=searchshop(name,L);
    if(st->next==NULL)
    {
        printf("没有查询到此货物！");
    }
    else
    {
     printf(" %s   %d\n",st->next->name,st->next->price);
    }


}
//查找商品2
shop*searchshop(char name[],shop*L)
{
    shop*p=L;
    while(p->next!=NULL)
    {
        if(strcmp(name,p->next->name)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
//退出界面
void tuichu()
{
    system("cls");
    printf("欢迎下次使用");
    exit(0);
}
//修改商品信息
void fixinfo(shop*L)
{
    int flag=1;
    system("cls");
    char name[20];
    while(1)
    {
       printf("请输入要修改的商品名称");
       scanf("%s",name);
       shop*st=searchshop( name,L);


         printf("修改商品名称为：");
         scanf("%s",st->next->name);
         printf("修改商品价格为：");
         scanf("%d",&st->next->price);
         printf("修改成功");
         printf("是否继续进行修改\n1:是  0：否");
        scanf("%d",&flag);
        if(flag==0)
        {
            break;
        }
    }
    savefile(L);
}

//删除商品信息1
void deleinfo(shop*L)
{
    system("cls");
    char name[30];
    shop*p;
    printf("请输入要删除的商品名称：");
    scanf("%s",name);
    shop *st=searchshop(name,L);
    p=st;
    if(st==NULL)
    {
        printf("没有查询到该商品信息");
         return ;
    }
     printf(" %s   %d\n",st->next->name,st->next->price);
     dele(p);
     savefile(L);
     printf("删除成功");

}
//删除商品信息2
void dele(shop*p)
{
    shop*s=p->next;
    p->next=s->next;
    s->next=NULL;
    free(s);
}



//登录 函数
//打印菜单
 void menu()
{
	printf("************************************\n");
    printf("**********欢迎来到登录系统**********\n");
	printf("************************************\n");
	printf("*****1.注册账号         2.登录******\n");
	printf("*****3.找回密码         0.退出 *****\n");
	printf("************************************\n");
	printf("************************************\n");
}

//注册系统
void Register()
{
	Users a, b;//创建用户结构体临时变量，a是用来接收用户输入的，b是用来从文件中读取的，来和a作比较

	char tmp[20]="";//用着下面判断的

	printf("欢迎来到注册界面!\n");
	FILE* pf = fopen("users.dat", "rb");//"rb"是以二进制只读方式打开文件的意思
	fread(&b, sizeof(Users), 1, pf);//将数据读入b中
	if (!pf)//如果打开失败
	{
		printf("打开文件失败");
		return;
	}


	printf("请输入您的账号>>");
	scanf("%s", a.id);
	while (1)
	{
		if (strcmp(a.id, b.id))//两个用户名不相等
		{
			if (!feof(pf))//没读到文件末尾
			{
				fread(&b, sizeof(Users), 1, pf);//继续读取文件中的用户到b中
			}
			else//读到文件末尾了，确认没有重复的id
			{
				break;
			}
		}
		else//有两个用户名相等
		{
			printf("此用户名已存在在,请重新输入!\n");
			Sleep(1000);
			fclose(pf);//关闭文件
			pf = NULL;//pf置空，避免野指针
			return;
		}
	}
	printf("请输入您的姓名>>");
	scanf("%s", a.name);
	printf("请输入您的性别>>");
	scanf("%s", a.sex);
	printf("请输入您的电话号码>>");
	scanf("%s", a.phone);
	printf("请输入您的密码>>");
	Getpwd(a.pwd);//输入密码的函数，有掩盖功能，下面会介绍
	printf("\n请再次确认您的密码>>");
	Getpwd(tmp);
	do
	{
		if (!strcmp(a.pwd, tmp))//两次密码相等
		{
			pf = fopen("users.dat", "ab");
			fwrite(&a, sizeof(Users), 1, pf);
			printf("\n账号注册成功,请登录!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("\n两次密码不匹配!请重新输入>>");
			Getpwd(a.pwd);
			printf("\n请再次确认>>");
			Getpwd(tmp);
		}
	} while (1);
}

//登录系统
void Login()
{
	Users a, b;

	FILE* pf = fopen("users.dat", "rb");//以只读的方式打开文件
	if (!pf)//如果读取失败
	{
		printf("打开文件失败");
		return;
	}
	printf("欢迎来到登录界面!\n");
	Sleep(1000);

	fread(&b, sizeof(Users), 1, pf);//先从文件中读取一个用户试试水

	printf("请输入账号>>");
	scanf("%s", a.id);

	while (1)
	{
		if (!strcmp(a.id, b.id))//在文件中找到了与用户输入相同的id
		{
			break;
		}
		else
		{
			if (!feof(pf))//没读到文件末尾，继续读取文件中的id到b中
			{
				fread(&b, sizeof(Users), 1, pf);//继续从文件中读取用户信息进b，直到在文件中找到一个和a的信息相同的
			}
			else//读到文件末尾了，没有找到与用户输入相同的账号
			{
				printf("此账号不存在!请重新输入!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				return;
			}
		}
	}
	do
	{
		printf("请输入密码>>");
		Getpwd(a.pwd);//获取密码，在下面会讲
		if (!strcmp(a.pwd, b.pwd))//输入的密码与文件中的相同
		{
			printf("\n登录成功!欢迎使用!\n");
			Sleep(500);
			fclose(pf);//用完当然要把文件关啦
			pf = NULL;//置空，避免野指针
			main_meau();
		}
		else
		{
			printf("\n密码输入错误,请重新输入\n");
		}
	} while (strcmp(a.pwd, b.pwd));
}

//找回密码
void Reback()
{
	char tmp[20] = "";//密码匹配用的
	Users a, b;

	FILE* pf = fopen("users.dat", "rb+");//"rb+"是为了读和写以二进制打开文件的意思

	if (!pf)//老样子，先判断能不能顺利打开
	{
		printf("打开文件失败");
		return;
	}

	fread(&b, sizeof(Users), 1, pf);

	printf("请输入您的账号>>");
	Sleep(800);

	scanf("%s", a.id);

	while (1)//在文件中找到与用户输入相同的id
	{
		if (!strcmp(a.id, b.id))//如果读取到了相同的id（在文件中找到了和用户输入一样的）
		{
			break;
		}
		else
		{
			if (!feof(pf))//没读到文件尾，继续读
			{
				fread(&b, sizeof(Users), 1, pf);
			}
			else
			{
				printf("您输入的账号不存在!请重新输入!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				break;
			}
		}
	}

	//下面是信息匹配验证
	do//匹配姓名
	{
		printf("请输入您的姓名>>");
		scanf("%s", a.name);
		if (!strcmp(a.name, b.name))
		{
			break;
		}
		else
		{
			printf("输入错误,请重新输入!\n");
		}
	} while (strcmp(a.name, b.name));

	do//匹配性别
	{
		printf("请输入您的性别>>");
		scanf("%s", a.sex);
		if (!strcmp(a.sex, b.sex))
		{
			break;
		}
		else
		{
			printf("输入错误,请重新输入!\n");
		}
	} while (strcmp(a.sex, b.sex));
	do//匹配电话号码
	{
		printf("请输入您的电话号码>>");
		scanf("%s", a.phone);
		if (!strcmp(a.phone, b.phone))
		{
			break;
		}
		else
		{
			printf("输入错误,请重新输入!\n");
		}
	} while (strcmp(a.phone, b.phone));

	//更改密码
	printf("验证成功!请修改您的密码!\n");
	printf("请输入您的密码>>");
	Getpwd(a.id);
	printf("请再次确认您的密码>>");
	Getpwd(tmp);
	if (!pf)
	{
		printf("打开文件失败");
		return;
	}
    //将原来的密码覆盖掉
	do
	{
		if (!strcmp(a.pwd, tmp))//两次密码相等
		{
			fseek(pf,-((int)(sizeof(Users)-MAX_ID)), SEEK_CUR);//将文件流调回到要修改的密码的位置
			fprintf(pf, "%s", a.pwd);//覆盖原来的密码
			printf("密码修改成功,请登录!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("两次密码不匹配!请重新输入>>");
			scanf("%s", a.pwd);
			printf("请再次确认>>");
			scanf("%s", tmp);
		}
	} while (1);
}

//定位光标
void gotoxy(int x, int y)
{
	//更新光标位置
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}
//获取光标x坐标
int posx()
{
	CONSOLE_SCREEN_BUFFER_INFO ptr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ptr);
	return (ptr.dwCursorPosition.X);
}
//获取光标y坐标
int posy()
{
	CONSOLE_SCREEN_BUFFER_INFO ptr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ptr);
	return (ptr.dwCursorPosition.Y);
}

//输入密码
void Getpwd(char* pwd)
{
	int i = 0;
	int x, y;
	while (1)
	{
		pwd[i] = _getch();//获取单个密码（字符）
		if (pwd[i] == VK_BACK && i >= 0)//如果输入的是回退键，VK_BACK是键盘的键值，ASCII码值为8
		{
			if (i > 0)//i>0说明有输入东西了，则回退前一格
			{
				i--;
				x = posx() - 1;//定位x并回退一格
				y = posy();//定位y
				gotoxy(x, y);//定位光标
				printf(" ");//将*用空格掩盖
				x = posx() - 1;//再次回退，下次输入时光标才会显示在正确的位置
				y = posy();//定位y
				gotoxy(x, y);
				continue;//然后跳过此次循环
			}
			else if (i == 0)//i==0说明没输入东西，直接跳过此次循环即可
			{
				continue;
			}
		}
		if (i >= 0 && pwd[i] != VK_RETURN && pwd[i] != VK_BACK)//输入东西了
		{
			x = posx();
			y = posy();
			gotoxy(x, y);
			printf("*");
		}
		if (i == 0 && pwd[i] == VK_RETURN)//如果没输入东西直接按回车，直接跳过此次循环，避免程序把回车当密码了
		{
			continue;
		}
		if (pwd[i] == VK_RETURN||i==MAX_PWD-2)//输入回车了或者到上限了
		{
			i++;
			pwd[i] = '\0';//结尾放'\0'
			break;
		}
		i++;
	}
}
//管理员界面
void guanliyuan()
{
    system("cls");
    int input=0;
    menu();

while(true)
{
    scanf("%d",&input);
    switch (input)
		{
		case 1:
			Register();
			break;
		case 2:
			Login();
			break;
		case 3:
			Reback();
			break;
		case 0:
			printf("退出成功!\n");
			tuichu();
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
}
}

//用户界面
void yonghu()
{
    system("cls");
    int input=0;
    menu();

while(true)
{

    scanf("%d",&input);
    switch (input)
		{
		case 1:
			Register();
			break;
		case 2:
			Login();
			break;
		case 3:
			Reback();
			break;
		case 0:
			printf("退出成功!\n");
			tuichu();
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
}

}





