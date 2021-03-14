#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 20 //��󶥵���Ϊ100
#define MaxInt 32767 //��ʾ�����������ʾ �� 

typedef char VertexType; //����ṹ

typedef struct//ͼ�ṹ���ڽӾ��� ��
{
	VertexType vertex[MaxVertexNum];
	int AdjMatrix[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}Graph;

typedef struct
{
	VertexType adjvex;
	int lowcost;
}ShortEdge;

int LocateVex(Graph *G,VertexType v)
{
	int i;
	
	for(i=0;i<G->vexnum;i++)
	{
		if(v==G->vertex[i])
		{
			return i; 
		} 
	 } 
	 
	 printf("No Such Vertex!\n");
	 return -1;
}

void CreateUDN(Graph *G)//������������Undirected Network��
{
	int i,j;
	//1.���붥�����ͱ���
	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d",&G->vexnum);
	printf("��  �� e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	printf("\n");
	
	//2.���붥��Ԫ�� 
	printf("���붥��Ԫ��(����ո����)��");
	scanf("%s",G->vertex);
	printf("\n");
	//3.�����ʼ��
	for(i=0;i<G->vexnum;i++) 
	 for(j=0;j<G->vexnum;j++)
	    {
	    	G->AdjMatrix[i][j]=MaxInt;
		}
	
	 //4.�����ڽӾ���
	 int n,m;
	 VertexType v1,v2;
	 int w;//v1->v2��Ȩֵ 
	 
	 printf("������ߵ���Ϣ��Ȩֵ(����AB,15)��\n");
	 for(i=0;i<G->arcnum;i++)
	 {
	 	printf("�����%d������Ϣ��Ȩֵ��",i+1);
	 	scanf(" %c%c,%d",&v1,&v2,&w);
	 	n=LocateVex(G,v1); 
	 	m=LocateVex(G,v2); 
	 	
	 	if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		  } 
	
	   G->AdjMatrix[n][m]=w;
	   G->AdjMatrix[m][n]=w;//���������˴���ͬ 
     } 
}

void print(Graph G)
{
	int i,j;
	printf("\n-------------------------------");
	printf("\n �ڽӾ���\n\n"); 	
	
		printf("\t ");
		for(i=0;i<G.vexnum;i++)
		printf("\t%c",G.vertex[i]);
		printf("\n");
		 
		for(i=0;i<G.vexnum;i++)
	   {
	   	  printf("\t%c",G.vertex[i]);
	   	  
		  for(j=0;j<G.vexnum;j++)
	    {
	    	
	    	if(G.AdjMatrix[i][j]==MaxInt)
	 	    printf("\t��");
	 	    else printf("\t%d",G.AdjMatrix[i][j]);
	    }
	      printf("\n");
	   }

	 
}

int minimal(Graph *G,ShortEdge *shortedge)
{
	int i,j;
	int min,loc;
	
	min=MaxInt;
	for(i=1;i<G->vexnum;i++)
	{
		if(min>shortedge[i].lowcost&&shortedge[i].lowcost!=0)
		{
			min=shortedge[i].lowcost;
			loc=i;
		}
	}
	return loc;
}
 
void MiniSpanTree_Prim(Graph *G,VertexType start)
{ 
	int i,j,k;
	ShortEdge shortedge[MaxVertexNum];
	
	//1.������ʼ��start 
	k=LocateVex(G,start);
	for(i=0;i<G->vexnum;i++)
	{
		shortedge[i].adjvex=start;
		shortedge[i].lowcost=G->AdjMatrix[k][i];
	}
	shortedge[k].lowcost=0;//lowcostΪ0��ʾ�ö�������U���� 
	
	//2.���������� 
	for(i=0;i<G->vexnum-1;i++)
	{
		k=minimal(G,shortedge);
	
	    printf("%c->%c,%d\n",shortedge[k].adjvex,G->vertex[k],shortedge[k].lowcost);
	    shortedge[k].lowcost=0;
	    
	    for(j=0;j<G->vexnum;j++)
	    {
	    	if(G->AdjMatrix[k][j]<shortedge[j].lowcost)
	    	{
	    		shortedge[j].lowcost=G->AdjMatrix[k][j];
	    		shortedge[j].adjvex=G->vertex[k];
			}
		}
	    
	 } 
}


int main() 
{
	VertexType start;
	 
	Graph G;
	CreateUDN(&G);
	print(G); 
	
	printf("��������ʼ�㣺");
	scanf(" %c",&start);//%cǰ���пո� 
	MiniSpanTree_Prim(&G,start);
	 
	return 0;
}
