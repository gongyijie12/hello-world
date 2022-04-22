#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
# define MAXV 100

typedef struct ANode{
    int adjvex;
    struct ANode * nextarc;
    int info;                      
}ArcNode;
//�߽ڵ�����


typedef struct Vnode{
    char data;
    ArcNode *firstarc;
}VNode,AdjList[MAXV];
//��ͷ�����Ϣ


typedef struct {
    AdjList adjlist;                       
    int n,e;     //������������
}ALGraph;
//������ͼ�ڽӱ�����

typedef struct{
	int u,v,w;
	int u1,v1;
}fuzhu[20];

void CreateALGraph(ALGraph *G){
    int i,j,k,w;
    ArcNode *p;
    printf("�����붥�����ͱ���\n");
    scanf("%d,%d",&G->n,&G->e);
    for (i=0; i < G->n;i++) {
        printf("�����붥����Ϣ\n");
        scanf("%s",&G->adjlist[i].data);
        G->adjlist[i].firstarc=NULL;
    }

    for (k=0; k<G->e; k++) {
        printf("�����%d���ߵ��������ź�Ȩֵ:",k+1);
        scanf("%d,%d,%d",&i,&j,&w);             //������0��������1�����ߵ�Ȩֵ

        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->info = w;
        p->nextarc=G->adjlist[i].firstarc;
        G->adjlist[i].firstarc=p;

        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=i;
        p->info =w;
        p->nextarc=G->adjlist[j].firstarc;
        G->adjlist[j].firstarc=p;
    }
}
void CreateKruskal(ALGraph *G,ALGraph *E){
	int i=0,j=0;
	fuzhu que[100];
	fuzhu que2[50];
	fuzhu h;
	ArcNode *p;

	for(i=0; i<G->n ;i++){
		for(p=G->adjlist[i].firstarc ;p!=NULL; p=p->nextarc ){
			que[j]->u =i;
			que[j]->v =p->adjvex ;
			que[j]->w =p->info ;
			que[j]->u1 =que[j]->u - 1;
			que[j]->v1 =que[j]->v - 1;
			j++;
		}
	}


	for(i=0;i<2*(G->e);i++){
		for(j=i;j<2*(G->e);j++){
			if(que[i]->w >que[j]->w ){
				h->u =que[i]->u ;h->u1 =que[i]->u1 ;h->v =que[i]->v ;h->v1 =que[i]->v1 ;h->w =que[i]->w ;
				que[i]->u=que[j]->u; que[i]->u1=que[j]->u1;que[i]->v=que[j]->v;que[i]->v1=que[j]->v1;que[i]->w =que[j]->w ;
				 que[j]->u=h->u; que[j]->u1=h->u1 ; que[j]->v=h->v ; que[j]->v1=h->v1 ; que[j]->w=h->w ;
			}
		}
	}

	que2[0]->u=que[0]->u; que2[0]->u1=que[0]->u1;que2[0]->v=que[0]->v;que2[0]->v1=que[0]->v1;que2[0]->w =que[0]->w ;
	j=1;
	for(i=2;i<2*(G->e);i=i+2){
		que2[j]->u=que[i]->u; que2[j]->u1=que[i]->u1;que2[j]->v=que[i]->v;que2[j]->v1=que[i]->v1;que2[j]->w =que[i]->w ;
		j++;
	}

	int t=0;
	for(i=0;i<G->e ;i++)
	{
		if(que2[i]->u1 !=que2[i]->v1 )
		{
			t=que2[i]->v1 ;
			que2[i]->v1 =que2[i]->u1 ;
			for(j=0;j<G->e;j++)
			{
				if(que2[j]->u1 ==t)
				{
					que2[j]->u1 =que2[i]->u1 ;
				}
				if(que2[j]->v1 ==t)
				{
					que2[j]->v1 =que2[i]->u1 ;
				}
			}
		
		}
		else{
			que2[i]->u =-2;que2[i]->u1=-2 ;que2[i]->v=-2 ;que2[i]->v1=-2 ;que2[i]->w=-2 ;
		}
	}

	E->e =G->e ; E->n =G->n ;
	for (i=0; i < E->n;i++) {
        E->adjlist [i].data =G->adjlist[i].data;
        E->adjlist[i].firstarc=NULL;
    }

	int m1,m2,m3;
	for (i=0; i<E->e; i++) 
	{
		if(que2[i]->u !=-2)
		{
			m1=que2[i]->u ; m2=que2[i]->v ;m3=que2[i]->w ;
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=m2 ;
        p->info =m3 ;
        p->nextarc=E->adjlist[m1].firstarc;
        E->adjlist[m1].firstarc=p;

        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=m1;
        p->info =m3;
        p->nextarc=E->adjlist[m2].firstarc;
        E->adjlist[m2].firstarc=p;
		}
    }
}



void DispALGraph(ALGraph *G){
    int i,max=0,max_index=0;
    ArcNode *p;
    printf("ͼ���ڽӱ�����:\n");
    printf("  ���    ����   ���ڱ�ţ�Ȩֵ\n");
    for (i=0; i<G->n; i++) {
        int j=0;
        printf("%4d %8c",i,G->adjlist[i].data);
        for (p=G->adjlist[i].firstarc; p!=NULL; p=p->nextarc) {
            printf(" --> ");
            printf("%d,%d",p->adjvex,p->info);
            j++;
            if (max<j) {
                max=j;
                max_index=i;
            }
        }
        printf("\t�ö�����%d����\n",j);
    }
    printf("    ���%d������\n",max_index);

}

void print(ALGraph *G){
	int i=0;

	int j;
	ArcNode *p;
	cout<<"**********************"<<endl;
	cout<<"ͼ����С����������"<<endl;
	for(i=0;i<G->n ;i++){
		cout<<G->adjlist [i].data ;
		for(p=G->adjlist [i].firstarc ;p!=NULL;p=p->nextarc ){
			 printf(" --> ");
			 j=p->adjvex ;
			 cout<<G->adjlist [j].data<<"ȨֵΪ:"<<p->info  <<endl;
		}
		cout<<endl;
	}
}

int main(){
    ALGraph G;          //��������ͨ��G
    ALGraph E;          //��С������
    CreateALGraph(&G);  //��ÿ��ͷ��������ϱߵ���Ϣ
    DispALGraph(&G);    //��ӡ������
    CreateKruskal(&G,&E);//������С������
    print(&E);//��ӡ��С������
	system("pause");
    return 0;
}