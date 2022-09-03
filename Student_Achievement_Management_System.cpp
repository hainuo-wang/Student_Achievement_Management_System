#include"cstdio"
#include"cstring"
#include<iostream>
using namespace std;
typedef struct Node
{
    char name[8];
    char ID[11];
    float FOX;
    float C;
    float ENGLISH;
    float COUNT;
    struct Node* next;
}Node, * CLLinkList;
#define len sizeof(Node)
void InitCLLinkList(CLLinkList* head)//初始化循环链表
{
    *head = (CLLinkList)malloc(len);
    if (*head)//解决内存泄漏警告问题
    {
        (*head)->next = *head;
    }
}
void SearchCLLinkList1(CLLinkList head, char ID[])//查找学号
{
    int j = 0,flag=0; //置初值
    Node* p;
    p = head->next;//置初值
    while (p != head)
    {
        j++;
        if (strcmp(p->ID, ID) == 0)
        {
            flag = 1;
            cout << "************************" << endl;
            cout << "这位学生的信息如下：" << endl;
            cout << "他在表中的位置为：" << j << endl;
            cout << "姓名：" << p->name << endl;
            cout << "学号：" << p->ID << endl;
            cout << "FOX成绩：" << p->FOX << endl;
            cout << "C成绩：" << p->C << endl;
            cout << "ENGLISH成绩：" << p->ENGLISH << endl;
            cout << "总分为：" << p->COUNT << endl;
            cout << "************************" << endl;
        }
        p = p->next;
    }
    if (flag != 1)
    {
        cout << "************************" << endl;
        cout << "该学号不在系统中！" << endl;
        cout << "************************" << endl;
    }
}
int SearchCLLinkList2(CLLinkList head, char name[])//查找姓名
{
    int j = 0; //置初值
    Node* p;
    p = head->next;//置初值
    while (p != head)
    {
        j++;
        if (strcmp(p->name, name) == 0)
            return(j);
        p = p->next;
    }
    return(0);
}
void CreatCLLinkList(CLLinkList head)//循环链表的创建
{
    Node* rear, * s;
    char n1[8];
    char u1[11];
    float FOX;
    float C;
    float ENGLISH;
    int flag = 1;
    int a, b, n;
    rear = head;//rear指针动态指向当前表尾，其初始值指向头结点   
    cout << "请输入需要录入的学生的数量:\n";
    cin >> n;
    while (flag)
    {
        for (b = 0; b < n; b++)
        {
            cout << "请输入需要添加的学生的姓名:" << "\n";
            cin >> n1;
            s = (Node*)malloc(len);
        A:
            while (1)
            {
                cout << "请输入需要添加的学生的10位学号:" << "\n";
                cin >> u1;
                if (strlen(u1) == 10)
                {
                    for (a = 0; a < 11; a++)
                    {
                        if ((u1[a] >= '0') && (u1[a] <= '9'))
                        {
                            if (s)//解决内存泄漏警告问题
                            {
                                strcpy_s(s->ID, u1);
                                goto B;
                            }

                        }
                        else
                        {
                            cout << "输入错误，";
                            strcpy_s(u1, "");//清空数组，解决内存溢出问题
                            goto A;
                        }
                    }
                }
                else
                {
                    cout << "输入错误，";
                    strcpy_s(u1, "");//清空数组，解决内存溢出问题
                    goto A;
                }
            }
        B:
            cout << "FOX成绩：";
            cin >> FOX;
            cout << "C成绩：";
            cin >> C;
            cout << "ENGLISH成绩：";
            cin >> ENGLISH;
            cout << "--------------------------" << endl;
            strcpy_s(s->name, n1);
            strcpy_s(s->ID, u1);
            s->FOX=FOX;
            s->C=C;
            s->ENGLISH=ENGLISH;
            rear->next = s;
            rear = s;
        }
        flag = 0;
        rear->next = head;//最后一个节点的next域指向头结点
    }
}
void InCLLinkList(CLLinkList head, int i)//添加
{
    Node* p, * s;
    int a, k = 0;
    int flag = 1;
    char n1[8], u1[11];
    float FOX;
    float C;
    float ENGLISH;
    p = head;
    if (i <= 0)
    {
        cout << "插入的位置不合法:" << "\n";
        return;
    }
    while (p->next != head && k < i - 1)
    {
        k++;
        p = p->next;
    }
    s = (Node*)malloc(len);
    cout << "请输入需要添加的学生的姓名" << "\n";
    cin >> n1;
A:
    while (1)
    {
        cout << "请输入需要添加的学生的10位学号:" << "\n";
        cin >> u1;
        if (strlen(u1) == 10)
        {
            for (a = 0; a < 11; a++)
            {
                if ((u1[a] >= '0') && (u1[a] <= '9'))
                {
                    if (s)//解决内存泄漏警告问题
                    {
                        strcpy_s(s->ID, u1);
                        goto B;
                    }

                }
                else
                {
                    cout << "输入错误，";
                    strcpy_s(u1, "");//清空数组，解决内存溢出问题
                    goto A;
                }
            }
        }
        else
        {
            cout << "输入错误，";
            strcpy_s(u1, "");//清空数组，解决内存溢出问题
            goto A;
        }
    }
B:
    cout << "FOX成绩：";
    cin >> FOX;
    cout << "C成绩：";
    cin >> C;
    cout << "ENGLISH成绩：";
    cin >> ENGLISH;
    cout << "--------------------------" << endl;
    strcpy_s(s->name, n1);
    strcpy_s(s->ID, u1);
    s->FOX = FOX;
    s->C = C;
    s->ENGLISH = ENGLISH;
    s->next = p->next;
    p->next = s;
    cout << "插入成功，";
}
void Count_CLLinkList(CLLinkList head)//计算总分
{
    Node* p;
    p = head->next;
    float COUNT=0;
    for (; p != head; p = p->next)
    {
        COUNT = p->FOX + p->C + p->ENGLISH;
        p->COUNT = COUNT;
        COUNT = 0;
    }
}
void Print_CLLinkList(CLLinkList head)//输出
{
    Node* p;
    int i;
    p = head->next;
    cout << "*****学生成绩管理系统*****" << endl;
    for (i=1; p != head; p = p->next,i++)
    {
        cout << "---第" << i << "个学生的成绩信息---" << endl;
        cout << "姓名：" << p->name << endl;
        cout << "学号：" << p->ID << endl;
        cout << "FOX成绩：" << p->FOX << endl;
        cout << "C成绩：" << p->C << endl;
        cout << "ENGLISH成绩：" << p->ENGLISH << endl;
        cout << "总分为：" << p->COUNT << endl;
        cout << "--------------------------" << endl;
    }
}
void DeleCLLinkList(CLLinkList head, char u1[])//删除
{
    Node* p, * r;
    p = head;
    while (p->next != head && strcmp((p->next)->ID, u1) != 0)
    {
        p = p->next;
    }
    if (p->next == head)
    {
        cout << "需要删除的学号不存在!";
        return;
    }
    r = p->next;
    p->next = r->next;
    free(r);
}
void BubleSort1(CLLinkList head)//总分排序
{
    Node* p,*q,*temp;
    p = head;
    q = head->next;
    if (p->next!=head) 
    {
        while (q->next!=head)
        {  
            if (q->COUNT > (q->next)->COUNT) 
            {   
                temp = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = temp;
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
        q = p->next;
    }
    p = head->next;
}
void BubleSort2(CLLinkList head)//学号排序
{
    Node* p, * q, * temp;
    p = head;
    q = head->next;
    if (p->next != head)
    {
        while (q->next != head)
        {  
            if (strcmp(q->ID,(q->next)->ID)>0)
            {   
                temp = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = temp;
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
        q = p->next;
    }
    p = head->next;
}
int LengthCLLinkList(CLLinkList head)//求循环链表的长度
{
    int i = 0;
    Node* p;
    p = head->next;
    while (p != head)
    {
        i++;
        p = p->next;
    }
    return i;
}
int main()
{
    int i;
    char n1[8];
    char u1[11];
    int select = 1;
    CLLinkList head;
    InitCLLinkList(&head);
    while (select != 0)
    {
        cout << "**学生成绩管理系统**\n"
            "  #请输入操作选择#\n"
            "   1-初始录入信息\n"
            "   2-查找学生信息\n"
            "   3-任意位置插入\n"
            "   4-删除学生信息\n"
            "   5-计算各科总分\n"
            "   6-按照总分排名\n"
            "   7-按照学号排名\n"
            "   8-显示全部信息\n"
            "   0-结束本次服务\n";
        cin >> select;
        switch (select)
        {
        case 1:
            CreatCLLinkList(head);
            Count_CLLinkList(head);
            Print_CLLinkList(head);
            break;
        case 2:
            cout << "\n请输入需要查找的学号:\n";
            cin >> u1;
            SearchCLLinkList1(head, u1);
            break;
        case 3:
            cout << "\n请输入需要插入哪位同学（姓名）的前面:\n";
            cin >> n1;
            i = SearchCLLinkList2(head, n1);
            if (i == 0)
            {
                cout << "\n这位同学不在系统中！\n\n";
            }
            else
            {
                InCLLinkList(head, i);
            }
            Count_CLLinkList(head);
            cout << "插入后的学生名册为:\n";
            Print_CLLinkList(head);
            break;
        case 4:
            cout << "\n请输入需要删除学生的学号:\n";
            cin >> u1;
            DeleCLLinkList(head, u1);
            cout << "\n删除后的学生名册为:\n";
            Print_CLLinkList(head);
            break;
        case 5:
            Print_CLLinkList(head);
            break;
        case 6:
            BubleSort1(head);
            Print_CLLinkList(head);
            break;
        case 7:
            BubleSort2(head);
            Print_CLLinkList(head);
            break;
        case 8:
            Print_CLLinkList(head);
            break;
        case 0:
            break;
        default:
            cout << "\n输入错误！\n\n";
        }
    }
    cout << "\n";
    return 0;
}