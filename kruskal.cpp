#include<stdio.h>
#include<stdlib.h>
#define MaxVetexNum 100

//顶点结构
typedef char VertexType;

//边结构
typedef struct{
    VertexType beginVex;
	VertexType endVex;
	int weight;
}Edge;

//图结构
typedef struct{

	int vexnum;//顶点数
	int edgenum;//边数
	VertexType vertex[MaxVetexNum];//顶点数组
	Edge edge[MaxVetexNum];//边数组

}Graph;
void CreatGraph(Graph *g);
void SortWeight(Graph *g);
int LocationOfVex(Graph *g,VertexType vex);
int  Root(int parent[],int currentNode);
void Kruskal(Graph *g);


int main(){
	Graph g;
	CreatGraph(&g);
	
	Kruskal(&g);
	return 0;
}


//通过键盘输入初始化无向图
void CreatGraph(Graph *g)
{   
	printf("请依次输入无向图的顶点数和边数：");
	scanf("%d %d",&g->vexnum,&g->edgenum);
	getchar();
	printf("请依次输入每个顶点(回车结束)\n");
	for(int i= 0;i<g->vexnum;i++){
		
		printf("第%d个顶点：",i+1);
		scanf("%c",&g->vertex[i]);
		getchar();
	}
	printf("请依次输入每条边的两个顶点及边的权重(格式例如：a,c,3)：\n");
	for (int j=0;j<g->edgenum;j++){
		
		printf("第%d条边：",j+1);
		scanf("%c,%c,%d",&g->edge[j].beginVex,&g->edge[j].endVex,&g->edge[j].weight);	
		getchar();
	}
}




//按边的权值给边排序
void SortWeight(Graph *g){
	int i;
	int j;	
	int mark;
	int min;
	Edge temp;
	for(i=0;i<g->edgenum-1;i++)
	{   
		min = g->edge[i].weight;
	    mark = i;
		for(j=i+1;j<g->edgenum;j++){
		    if(g->edge[j].weight<min){
			    min = g->edge[j].weight;
			    mark = j;
	     	}
		}
		temp =  g->edge[i];
		g->edge[i]=g->edge[mark];
		g->edge[mark] = temp;
	}
	
}


//寻找每个顶点的根节点
int  Root(int parent[],int r){
    
	while(parent[r]>-1){
		r = parent[r];
	}
	return r;
}




//寻找顶点的下标
int LocationOfVex(Graph *g,VertexType vex){

	
	for(int i=0;i<g->vexnum;i++){
		if(g->vertex[i]==vex){
			return i;
		}

	}
	return -1;


}


void Kruskal(Graph *g)
{
	int i;
	int count;
	int parent[MaxVetexNum];
	int rootOfBenginVex,rootOfEndVex; 
	int locationOfBeginVex,locationOfEndVex; 
	
	SortWeight(g);
	
	for(i=0;i<g->vexnum;i++)
	{
		parent[i]=-1;
	}
	
	printf("最小生成树如下:\n");
	//3.
	for(count=0,i=0;i<g->edgenum;i++)
	{
		locationOfBeginVex=LocationOfVex(g,g->edge[i].beginVex);
		locationOfEndVex=LocationOfVex(g,g->edge[i].endVex);

		rootOfBenginVex=Root(parent,locationOfBeginVex);
		rootOfEndVex=Root(parent,locationOfEndVex);
	
		
		if(rootOfBenginVex!=rootOfEndVex)
		{
			printf("<%c,%c> weight=%d\n",g->edge[i].beginVex,g->edge[i].endVex,g->edge[i].weight);
			parent[rootOfEndVex]=rootOfBenginVex;
			count++;
			
			if(count==g->vexnum-1)
			{
				return;
			}
		} 
	}
	
}






