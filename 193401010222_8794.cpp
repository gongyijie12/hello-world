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
//边节点类型


typedef struct Vnode{
    char data;
    ArcNode *firstarc;
}VNode,AdjList[MAXV];
//表头结点信息


typedef struct {
    AdjList adjlist;                       
    int n,e;     //顶点数，边数
}ALGraph;
//完整的图邻接表类型

typedef struct{
	int u,v,w;
	int u1,v1;
}fuzhu[20];

void CreateALGraph(ALGraph *G){
    int i,j,k,w;
    ArcNode *p;
    printf("请输入顶点数和边数\n");
    scanf("%d,%d",&G->n,&G->e);
    for (i=0; i < G->n;i++) {
        printf("请输入顶点信息\n");
        scanf("%s",&G->adjlist[i].data);
        G->adjlist[i].firstarc=NULL;
    }

    for (k=0; k<G->e; k++) {
        printf("输入第%d条边的两顶点编号和权值:",k+1);
        scanf("%d,%d,%d",&i,&j,&w);             //顶点编号0，顶点编号1，两者的权值

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
    printf("图的邻接表如下:\n");
    printf("  编号    顶点   相邻编号，权值\n");
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
        printf("\t该顶点有%d个边\n",j);
    }
    printf("    编号%d有最多度\n",max_index);

}

void print(ALGraph *G){
	int i=0;

	int j;
	ArcNode *p;
	cout<<"**********************"<<endl;
	cout<<"图的最小生成树如下"<<endl;
	for(i=0;i<G->n ;i++){
		cout<<G->adjlist [i].data ;
		for(p=G->adjlist [i].firstarc ;p!=NULL;p=p->nextarc ){
			 printf(" --> ");
			 j=p->adjvex ;
			 cout<<G->adjlist [j].data<<"权值为:"<<p->info  <<endl;
		}
		cout<<endl;
	}
}

int main(){
    ALGraph G;          //无向网连通网G
    ALGraph E;          //最小生成树
    CreateALGraph(&G);  //在每个头结点后面加上边的信息
    DispALGraph(&G);    //打印无向网
    CreateKruskal(&G,&E);//创建最小生成树
    print(&E);//打印最小生成树
	system("pause");
    return 0;
}