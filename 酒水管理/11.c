#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef struct Order{
  char name[20];
  char phone[20];
  char shopname[20];
  int num;
  struct Order*next;
}order;
order list1;
void addinfo1();//增加函数
void deleinfo1(order*L);//删除函数
void meau1();//主菜单函数
void fixinfo1(order*L);//修改函数
void searchinfo1(order*L);//查找函数
void printinfo1(order*L);//输出函数
void tuichu1();//退出函数
void insertorder1(order*L,order e);//插入函数
int savefile1(order*L);//保存函数
order*searchorder1(char name[],order*L);
int readfile1(order*L);//读取文件
void dele1(order*p);
//打印菜单
void menu1();

int main()
{
    readfile1(&list1);


    int choice=9;
    while(true)
    {
        meau1();
        scanf("%d",&choice);
        switch(choice)
    {
      case 1:
         addinfo1();//订购货物
        break;
      case 2:
         deleinfo1(&list1);//删除订单
        break;
      case 3:
          fixinfo1(&list1);//修改订单
        break;
      case 4:
        searchinfo1(&list1);//查询订单信息
        break;
      case 5:
         printinfo1(&list1);//输出全部订单
        break;
      case 6:
          //vieworder();   //查看用户订单
        break;
      case 0:
         tuichu1();//推出系统
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
}


















void meau1()
{
    system("cls");
    printf("***********************");
    printf("**   酒水管理系统  **\n");
    printf("** 1 增加订单  **\n");
    printf("** 2 删除订单  **\n");
    printf("** 3 修改订单  **\n");
    printf("** 4 查询商品信息  **\n");
    printf("** 5 输出全部订单  **\n");
    printf("** 6 查看用户订单  **\n");

    printf("** 0 退出管理系统  **\n");

    printf("**  请输入对应的功能键:  **\n");

}



int readfile1(order*L)
{
    FILE*fpr=fopen("order.txt","r");
    order st;
    order*s;
    order*t=L;
    if(fpr==NULL)
    {
        return 0;
    }
    else
    {
        while(fscanf(fpr,"%s %s %s %d",st.name,st.phone,st.shopname,&st.num)!=EOF)
        {

           s=(order*)malloc(sizeof(order));
           *s=st;
           t->next=s;
           t=s;
           t->next=NULL;


        }
    }

}

void printinfo1(order*L)
{
    system("cls");
   order*p=L->next;
   printf("**************************\n");

   if(p!=NULL)
   {
       while(p!=NULL)
       {
           printf(" %s %s %s %d\n",p->name,p->phone,p->shopname,p->num);
           p=p->next;
       }

    printf("************************\n");
   }
}
//增加商品
void addinfo1()
{

    order st;
    printf("请输入购买人姓名:");
    scanf("%s",st.name);

    printf("请输入购买人手机号:");
    scanf("%s",st.phone);

    printf("请输入购买商品名称:");
    scanf("%s",st.shopname);


    printf("请输入购买数量:");
    scanf("%d",&st.num);

    insertorder1(&list1,st);
    printf("购买成功");

        system("pause");
}
//插入商品
void insertorder1(order*L,order e)
{
   order*h=L;
   order*s=(order*)malloc(sizeof(order));
   *s=e;
   s->next=h->next;
   h->next=s;
   savefile1(L);
   printf("保存成功");
        system("pause");
}
//保存文件
int savefile1(order*L)
{
    FILE*fpw=fopen("order.txt","w");
    if(fpw==NULL)
    {
        return 0;
    }

    order*p=L->next;
    while(p!=NULL)
    {
        fprintf(fpw,"%s %s %s %d",p->name,p->phone,p->shopname,p->num);
        p=p->next;
        printf("保存成功");
        system("pause");
    }

    return 1;
}
//查找商品1
void searchinfo1(order *L)
{
    system("cls");
    order*st;
    printf("请输入查询的订购人姓名");
    char name[50];
    scanf("%s",name);
    st=searchorder1(name,L);
    if(st->next==NULL)
    {
        printf("没有查询到此人的订单！");
    }
    else
    {
     printf(" %s %s %s  %d\n",st->next->name,st->next->phone,st->next->shopname,st->next->num);
    }


}
//查找商品2
order*searchorder1(char name[],order*L)
{
    order*p=L;
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
void tuichu1()
{
    system("cls");
    printf("欢迎下次使用");
    exit(0);
}
//修改商品信息
void fixinfo1(order*L)
{
    int flag=1;
    system("cls");
    char name[20];
    while(1)
    {
       printf("请输入要修改的订购人名称");
       scanf("%s",name);
       order*st=searchorder1(name,L);


         printf("修改订购人名称为：");
         scanf("%s",st->next->name);

          printf("修改订购人手机号为：");
         scanf("%s",st->next->phone);

          printf("修改订购货物名称为：");
         scanf("%s",st->next->shopname);

         printf("修改购买商品数量为：");

         scanf("%d",&st->next->num);
         printf("修改成功");
         printf("是否继续进行修改\n1:是  0：否");
        scanf("%d",&flag);
        if(flag==0)
        {
            break;
        }
    }
    savefile1(L);
}

//删除商品信息1
void deleinfo1(order*L)
{
    system("cls");
    char name[30];
    order*p;
    printf("请输入要删除订单的订购人姓名：");
    scanf("%s",name);
    order *st=searchorder1(name,L);
    p=st;
    if(st==NULL)
    {
        printf("没有查询到该商品信息");
         return ;
    }
     printf(" %s %s %s  %d\n",st->next->name,st->next->phone,st->next->shopname,st->next->num);
     dele1(p);
     savefile1(L);
     printf("删除成功");

}
//删除商品信息2
void dele1(order*p)
{
    order*s=p->next;
    p->next=s->next;
    s->next=NULL;
    free(s);
}
