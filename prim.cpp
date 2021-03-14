#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 20 //最大顶点数为100
#define MaxInt 32767 //表示最大整数，表示 ∞ 

typedef char VertexType; //顶点结构

typedef struct//图结构（邻接矩阵 ）
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

void CreateUDN(Graph *G)//构建无向网（Undirected Network）
{
	int i,j;
	//1.输入顶点数和边数
	printf("输入顶点个数和边数：\n");
	printf("顶点数 n="); 
	scanf("%d",&G->vexnum);
	printf("边  数 e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	printf("\n");
	
	//2.输入顶点元素 
	printf("输入顶点元素(无需空格隔开)：");
	scanf("%s",G->vertex);
	printf("\n");
	//3.矩阵初始化
	for(i=0;i<G->vexnum;i++) 
	 for(j=0;j<G->vexnum;j++)
	    {
	    	G->AdjMatrix[i][j]=MaxInt;
		}
	
	 //4.构建邻接矩阵
	 int n,m;
	 VertexType v1,v2;
	 int w;//v1->v2的权值 
	 
	 printf("请输入边的信息和权值(例：AB,15)：\n");
	 for(i=0;i<G->arcnum;i++)
	 {
	 	printf("输入第%d条边信息及权值：",i+1);
	 	scanf(" %c%c,%d",&v1,&v2,&w);
	 	n=LocateVex(G,v1); 
	 	m=LocateVex(G,v2); 
	 	
	 	if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		  } 
	
	   G->AdjMatrix[n][m]=w;
	   G->AdjMatrix[m][n]=w;//无向网仅此处不同 
     } 
}

void print(Graph G)
{
	int i,j;
	printf("\n-------------------------------");
	printf("\n 邻接矩阵：\n\n"); 	
	
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
	 	    printf("\t∞");
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
	
	//1.处理起始点start 
	k=LocateVex(G,start);
	for(i=0;i<G->vexnum;i++)
	{
		shortedge[i].adjvex=start;
		shortedge[i].lowcost=G->AdjMatrix[k][i];
	}
	shortedge[k].lowcost=0;//lowcost为0表示该顶点属于U集合 
	
	//2.处理后续结点 
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
	
	printf("请输入起始点：");
	scanf(" %c",&start);//%c前面有空格 
	MiniSpanTree_Prim(&G,start);
	 
	return 0;
}
