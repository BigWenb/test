#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<conio.h>



//����곣��
#define MAX_ID 11
#define MAX_PWD 20
#define MAX_NAME 15
#define MAX_SEX 5
#define MAX_PHONE 12

//��Ʒ����
typedef struct Shop{
  char name[100];
  int price;

  struct Shop*next;
}shop;


//�����û��Ľṹ��

typedef struct Users
{
	char id[MAX_ID];//id ����¼���˺�
	char pwd[MAX_PWD];//����
	char name[MAX_NAME];//����
	char sex[MAX_SEX];//�Ա�
	char phone[MAX_PHONE];//�绰
}Users;






shop list;//����

//��������
void addinfo();//���Ӻ���
void deleinfo(shop*L);//ɾ������
void meau();//���˵�����
void fixinfo(shop*L);//�޸ĺ���
void searchinfo(shop*L);//���Һ���
void printinfo(shop*L);//�������
void tuichu();//�˳�����
void insertshopinfo(shop*L,shop e);//���뺯��
int savefile(shop*L);//���溯��
shop*searchshop(char name[],shop*L);
int readfile(shop*L);//��ȡ�ļ�
void dele(shop*p);
//��ӡ�˵�
void menu();

//�û�ע��
void Register();

//��¼
void Login();

//�һ�����
void Reback();

//��λ���
void gotoxy();

//��ȡx��λ��
int posx();

//��ȡy��λ��
int posy();

//�������루���ڸǹ��ܣ�
void Getpwd(char* pwd);

void guanliyuan();
void yonghu();
void main_meau();















int main()
{
    printf("******��ӭ������ˮ����ϵͳ********\n");
    printf("       ���������ĵ�¼��ʽ\n");
    printf("         1 :����Ա��¼\n");
    printf("         2 :�û���¼\n");
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
        printf("�����д�����������\n");
        system("pause");
        system("cls");
        break;
    }
}
}
//��¼������˵�




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
         addinfo();//������Ʒ
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
         printinfo(&list);//���ȫ����Ʒ
        break;
      case 6:
          //vieworder();   //�鿴�û�����
        break;
      case 0:
         tuichu();
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
 return ;
}
void meau()
{
    system("cls");
    printf("***********************");
    printf("**   ��ˮ����ϵͳ  **\n");
    printf("** 1 ������Ʒ��Ϣ  **\n");
    printf("** 2 ɾ����Ʒ��Ϣ  **\n");
    printf("** 3 �޸���Ʒ��Ϣ  **\n");
    printf("** 4 ��ѯ��Ʒ��Ϣ  **\n");
    printf("** 5 �����Ʒ��Ϣ  **\n");
    printf("** 6 �鿴�û�����  **\n");

    printf("** 0 �˳�����ϵͳ  **\n");

    printf("**  �������Ӧ�Ĺ��ܼ�:  **\n");

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
   printf("|��Ʒ���� \t|�۸�\t|\n");
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
//������Ʒ
void addinfo()
{
    system("cls");
    shop st;
    printf("������������Ʒ����:");
    scanf("%s",st.name);
    printf("%s",st.name);

    printf("������������Ʒ�۸�:");
    scanf("%d",&st.price);

    insertshopinfo(&list,st);
}
//������Ʒ
void insertshopinfo(shop*L,shop e)
{
   shop*h=L;
   shop*s=(shop*)malloc(sizeof(shop));
   *s=e;
   s->next=h->next;
   h->next=s;
   savefile(L);
}
//�����ļ�
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
//������Ʒ1
void searchinfo(shop *L)
{
    system("cls");
    shop*st;
    printf("�������ѯ����Ʒ����");
    char name[50];
    scanf("%s",name);
    st=searchshop(name,L);
    if(st->next==NULL)
    {
        printf("û�в�ѯ���˻��");
    }
    else
    {
     printf(" %s   %d\n",st->next->name,st->next->price);
    }


}
//������Ʒ2
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
//�˳�����
void tuichu()
{
    system("cls");
    printf("��ӭ�´�ʹ��");
    exit(0);
}
//�޸���Ʒ��Ϣ
void fixinfo(shop*L)
{
    int flag=1;
    system("cls");
    char name[20];
    while(1)
    {
       printf("������Ҫ�޸ĵ���Ʒ����");
       scanf("%s",name);
       shop*st=searchshop( name,L);


         printf("�޸���Ʒ����Ϊ��");
         scanf("%s",st->next->name);
         printf("�޸���Ʒ�۸�Ϊ��");
         scanf("%d",&st->next->price);
         printf("�޸ĳɹ�");
         printf("�Ƿ���������޸�\n1:��  0����");
        scanf("%d",&flag);
        if(flag==0)
        {
            break;
        }
    }
    savefile(L);
}

//ɾ����Ʒ��Ϣ1
void deleinfo(shop*L)
{
    system("cls");
    char name[30];
    shop*p;
    printf("������Ҫɾ������Ʒ���ƣ�");
    scanf("%s",name);
    shop *st=searchshop(name,L);
    p=st;
    if(st==NULL)
    {
        printf("û�в�ѯ������Ʒ��Ϣ");
         return ;
    }
     printf(" %s   %d\n",st->next->name,st->next->price);
     dele(p);
     savefile(L);
     printf("ɾ���ɹ�");

}
//ɾ����Ʒ��Ϣ2
void dele(shop*p)
{
    shop*s=p->next;
    p->next=s->next;
    s->next=NULL;
    free(s);
}



//��¼ ����
//��ӡ�˵�
 void menu()
{
	printf("************************************\n");
    printf("**********��ӭ������¼ϵͳ**********\n");
	printf("************************************\n");
	printf("*****1.ע���˺�         2.��¼******\n");
	printf("*****3.�һ�����         0.�˳� *****\n");
	printf("************************************\n");
	printf("************************************\n");
}

//ע��ϵͳ
void Register()
{
	Users a, b;//�����û��ṹ����ʱ������a�����������û�����ģ�b���������ļ��ж�ȡ�ģ�����a���Ƚ�

	char tmp[20]="";//���������жϵ�

	printf("��ӭ����ע�����!\n");
	FILE* pf = fopen("users.dat", "rb");//"rb"���Զ�����ֻ����ʽ���ļ�����˼
	fread(&b, sizeof(Users), 1, pf);//�����ݶ���b��
	if (!pf)//�����ʧ��
	{
		printf("���ļ�ʧ��");
		return;
	}


	printf("�����������˺�>>");
	scanf("%s", a.id);
	while (1)
	{
		if (strcmp(a.id, b.id))//�����û��������
		{
			if (!feof(pf))//û�����ļ�ĩβ
			{
				fread(&b, sizeof(Users), 1, pf);//������ȡ�ļ��е��û���b��
			}
			else//�����ļ�ĩβ�ˣ�ȷ��û���ظ���id
			{
				break;
			}
		}
		else//�������û������
		{
			printf("���û����Ѵ�����,����������!\n");
			Sleep(1000);
			fclose(pf);//�ر��ļ�
			pf = NULL;//pf�ÿգ�����Ұָ��
			return;
		}
	}
	printf("��������������>>");
	scanf("%s", a.name);
	printf("�����������Ա�>>");
	scanf("%s", a.sex);
	printf("���������ĵ绰����>>");
	scanf("%s", a.phone);
	printf("��������������>>");
	Getpwd(a.pwd);//��������ĺ��������ڸǹ��ܣ���������
	printf("\n���ٴ�ȷ����������>>");
	Getpwd(tmp);
	do
	{
		if (!strcmp(a.pwd, tmp))//�����������
		{
			pf = fopen("users.dat", "ab");
			fwrite(&a, sizeof(Users), 1, pf);
			printf("\n�˺�ע��ɹ�,���¼!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("\n�������벻ƥ��!����������>>");
			Getpwd(a.pwd);
			printf("\n���ٴ�ȷ��>>");
			Getpwd(tmp);
		}
	} while (1);
}

//��¼ϵͳ
void Login()
{
	Users a, b;

	FILE* pf = fopen("users.dat", "rb");//��ֻ���ķ�ʽ���ļ�
	if (!pf)//�����ȡʧ��
	{
		printf("���ļ�ʧ��");
		return;
	}
	printf("��ӭ������¼����!\n");
	Sleep(1000);

	fread(&b, sizeof(Users), 1, pf);//�ȴ��ļ��ж�ȡһ���û�����ˮ

	printf("�������˺�>>");
	scanf("%s", a.id);

	while (1)
	{
		if (!strcmp(a.id, b.id))//���ļ����ҵ������û�������ͬ��id
		{
			break;
		}
		else
		{
			if (!feof(pf))//û�����ļ�ĩβ��������ȡ�ļ��е�id��b��
			{
				fread(&b, sizeof(Users), 1, pf);//�������ļ��ж�ȡ�û���Ϣ��b��ֱ�����ļ����ҵ�һ����a����Ϣ��ͬ��
			}
			else//�����ļ�ĩβ�ˣ�û���ҵ����û�������ͬ���˺�
			{
				printf("���˺Ų�����!����������!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				return;
			}
		}
	}
	do
	{
		printf("����������>>");
		Getpwd(a.pwd);//��ȡ���룬������ὲ
		if (!strcmp(a.pwd, b.pwd))//������������ļ��е���ͬ
		{
			printf("\n��¼�ɹ�!��ӭʹ��!\n");
			Sleep(500);
			fclose(pf);//���굱ȻҪ���ļ�����
			pf = NULL;//�ÿգ�����Ұָ��
			main_meau();
		}
		else
		{
			printf("\n�����������,����������\n");
		}
	} while (strcmp(a.pwd, b.pwd));
}

//�һ�����
void Reback()
{
	char tmp[20] = "";//����ƥ���õ�
	Users a, b;

	FILE* pf = fopen("users.dat", "rb+");//"rb+"��Ϊ�˶���д�Զ����ƴ��ļ�����˼

	if (!pf)//�����ӣ����ж��ܲ���˳����
	{
		printf("���ļ�ʧ��");
		return;
	}

	fread(&b, sizeof(Users), 1, pf);

	printf("�����������˺�>>");
	Sleep(800);

	scanf("%s", a.id);

	while (1)//���ļ����ҵ����û�������ͬ��id
	{
		if (!strcmp(a.id, b.id))//�����ȡ������ͬ��id�����ļ����ҵ��˺��û�����һ���ģ�
		{
			break;
		}
		else
		{
			if (!feof(pf))//û�����ļ�β��������
			{
				fread(&b, sizeof(Users), 1, pf);
			}
			else
			{
				printf("��������˺Ų�����!����������!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				break;
			}
		}
	}

	//��������Ϣƥ����֤
	do//ƥ������
	{
		printf("��������������>>");
		scanf("%s", a.name);
		if (!strcmp(a.name, b.name))
		{
			break;
		}
		else
		{
			printf("�������,����������!\n");
		}
	} while (strcmp(a.name, b.name));

	do//ƥ���Ա�
	{
		printf("�����������Ա�>>");
		scanf("%s", a.sex);
		if (!strcmp(a.sex, b.sex))
		{
			break;
		}
		else
		{
			printf("�������,����������!\n");
		}
	} while (strcmp(a.sex, b.sex));
	do//ƥ��绰����
	{
		printf("���������ĵ绰����>>");
		scanf("%s", a.phone);
		if (!strcmp(a.phone, b.phone))
		{
			break;
		}
		else
		{
			printf("�������,����������!\n");
		}
	} while (strcmp(a.phone, b.phone));

	//��������
	printf("��֤�ɹ�!���޸���������!\n");
	printf("��������������>>");
	Getpwd(a.id);
	printf("���ٴ�ȷ����������>>");
	Getpwd(tmp);
	if (!pf)
	{
		printf("���ļ�ʧ��");
		return;
	}
    //��ԭ�������븲�ǵ�
	do
	{
		if (!strcmp(a.pwd, tmp))//�����������
		{
			fseek(pf,-((int)(sizeof(Users)-MAX_ID)), SEEK_CUR);//���ļ������ص�Ҫ�޸ĵ������λ��
			fprintf(pf, "%s", a.pwd);//����ԭ��������
			printf("�����޸ĳɹ�,���¼!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("�������벻ƥ��!����������>>");
			scanf("%s", a.pwd);
			printf("���ٴ�ȷ��>>");
			scanf("%s", tmp);
		}
	} while (1);
}

//��λ���
void gotoxy(int x, int y)
{
	//���¹��λ��
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}
//��ȡ���x����
int posx()
{
	CONSOLE_SCREEN_BUFFER_INFO ptr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ptr);
	return (ptr.dwCursorPosition.X);
}
//��ȡ���y����
int posy()
{
	CONSOLE_SCREEN_BUFFER_INFO ptr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ptr);
	return (ptr.dwCursorPosition.Y);
}

//��������
void Getpwd(char* pwd)
{
	int i = 0;
	int x, y;
	while (1)
	{
		pwd[i] = _getch();//��ȡ�������루�ַ���
		if (pwd[i] == VK_BACK && i >= 0)//���������ǻ��˼���VK_BACK�Ǽ��̵ļ�ֵ��ASCII��ֵΪ8
		{
			if (i > 0)//i>0˵�������붫���ˣ������ǰһ��
			{
				i--;
				x = posx() - 1;//��λx������һ��
				y = posy();//��λy
				gotoxy(x, y);//��λ���
				printf(" ");//��*�ÿո��ڸ�
				x = posx() - 1;//�ٴλ��ˣ��´�����ʱ���Ż���ʾ����ȷ��λ��
				y = posy();//��λy
				gotoxy(x, y);
				continue;//Ȼ�������˴�ѭ��
			}
			else if (i == 0)//i==0˵��û���붫����ֱ�������˴�ѭ������
			{
				continue;
			}
		}
		if (i >= 0 && pwd[i] != VK_RETURN && pwd[i] != VK_BACK)//���붫����
		{
			x = posx();
			y = posy();
			gotoxy(x, y);
			printf("*");
		}
		if (i == 0 && pwd[i] == VK_RETURN)//���û���붫��ֱ�Ӱ��س���ֱ�������˴�ѭ�����������ѻس���������
		{
			continue;
		}
		if (pwd[i] == VK_RETURN||i==MAX_PWD-2)//����س��˻��ߵ�������
		{
			i++;
			pwd[i] = '\0';//��β��'\0'
			break;
		}
		i++;
	}
}
//����Ա����
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
			printf("�˳��ɹ�!\n");
			tuichu();
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}
}
}

//�û�����
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
			printf("�˳��ɹ�!\n");
			tuichu();
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}
}

}





