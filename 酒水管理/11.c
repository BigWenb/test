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
void addinfo1();//���Ӻ���
void deleinfo1(order*L);//ɾ������
void meau1();//���˵�����
void fixinfo1(order*L);//�޸ĺ���
void searchinfo1(order*L);//���Һ���
void printinfo1(order*L);//�������
void tuichu1();//�˳�����
void insertorder1(order*L,order e);//���뺯��
int savefile1(order*L);//���溯��
order*searchorder1(char name[],order*L);
int readfile1(order*L);//��ȡ�ļ�
void dele1(order*p);
//��ӡ�˵�
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
         addinfo1();//��������
        break;
      case 2:
         deleinfo1(&list1);//ɾ������
        break;
      case 3:
          fixinfo1(&list1);//�޸Ķ���
        break;
      case 4:
        searchinfo1(&list1);//��ѯ������Ϣ
        break;
      case 5:
         printinfo1(&list1);//���ȫ������
        break;
      case 6:
          //vieworder();   //�鿴�û�����
        break;
      case 0:
         tuichu1();//�Ƴ�ϵͳ
        break;
      default:
        printf("�����д�����������\n");
        system("pause");
        system("cls");
        break;
    }

    printf("�Ƿ���Ҫ����������(yes : 1/no : 0) :");
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
    printf("**   ��ˮ����ϵͳ  **\n");
    printf("** 1 ���Ӷ���  **\n");
    printf("** 2 ɾ������  **\n");
    printf("** 3 �޸Ķ���  **\n");
    printf("** 4 ��ѯ��Ʒ��Ϣ  **\n");
    printf("** 5 ���ȫ������  **\n");
    printf("** 6 �鿴�û�����  **\n");

    printf("** 0 �˳�����ϵͳ  **\n");

    printf("**  �������Ӧ�Ĺ��ܼ�:  **\n");

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
//������Ʒ
void addinfo1()
{

    order st;
    printf("�����빺��������:");
    scanf("%s",st.name);

    printf("�����빺�����ֻ���:");
    scanf("%s",st.phone);

    printf("�����빺����Ʒ����:");
    scanf("%s",st.shopname);


    printf("�����빺������:");
    scanf("%d",&st.num);

    insertorder1(&list1,st);
    printf("����ɹ�");

        system("pause");
}
//������Ʒ
void insertorder1(order*L,order e)
{
   order*h=L;
   order*s=(order*)malloc(sizeof(order));
   *s=e;
   s->next=h->next;
   h->next=s;
   savefile1(L);
   printf("����ɹ�");
        system("pause");
}
//�����ļ�
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
        printf("����ɹ�");
        system("pause");
    }

    return 1;
}
//������Ʒ1
void searchinfo1(order *L)
{
    system("cls");
    order*st;
    printf("�������ѯ�Ķ���������");
    char name[50];
    scanf("%s",name);
    st=searchorder1(name,L);
    if(st->next==NULL)
    {
        printf("û�в�ѯ�����˵Ķ�����");
    }
    else
    {
     printf(" %s %s %s  %d\n",st->next->name,st->next->phone,st->next->shopname,st->next->num);
    }


}
//������Ʒ2
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
//�˳�����
void tuichu1()
{
    system("cls");
    printf("��ӭ�´�ʹ��");
    exit(0);
}
//�޸���Ʒ��Ϣ
void fixinfo1(order*L)
{
    int flag=1;
    system("cls");
    char name[20];
    while(1)
    {
       printf("������Ҫ�޸ĵĶ���������");
       scanf("%s",name);
       order*st=searchorder1(name,L);


         printf("�޸Ķ���������Ϊ��");
         scanf("%s",st->next->name);

          printf("�޸Ķ������ֻ���Ϊ��");
         scanf("%s",st->next->phone);

          printf("�޸Ķ�����������Ϊ��");
         scanf("%s",st->next->shopname);

         printf("�޸Ĺ�����Ʒ����Ϊ��");

         scanf("%d",&st->next->num);
         printf("�޸ĳɹ�");
         printf("�Ƿ���������޸�\n1:��  0����");
        scanf("%d",&flag);
        if(flag==0)
        {
            break;
        }
    }
    savefile1(L);
}

//ɾ����Ʒ��Ϣ1
void deleinfo1(order*L)
{
    system("cls");
    char name[30];
    order*p;
    printf("������Ҫɾ�������Ķ�����������");
    scanf("%s",name);
    order *st=searchorder1(name,L);
    p=st;
    if(st==NULL)
    {
        printf("û�в�ѯ������Ʒ��Ϣ");
         return ;
    }
     printf(" %s %s %s  %d\n",st->next->name,st->next->phone,st->next->shopname,st->next->num);
     dele1(p);
     savefile1(L);
     printf("ɾ���ɹ�");

}
//ɾ����Ʒ��Ϣ2
void dele1(order*p)
{
    order*s=p->next;
    p->next=s->next;
    s->next=NULL;
    free(s);
}
