#include<stdio.h>
#include<stdlib.h>
#define MaxVetexNum 100

//����ṹ
typedef char VertexType;

//�߽ṹ
typedef struct{
    VertexType beginVex;
	VertexType endVex;
	int weight;
}Edge;

//ͼ�ṹ
typedef struct{

	int vexnum;//������
	int edgenum;//����
	VertexType vertex[MaxVetexNum];//��������
	Edge edge[MaxVetexNum];//������

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


//ͨ�����������ʼ������ͼ
void CreatGraph(Graph *g)
{   
	printf("��������������ͼ�Ķ������ͱ�����");
	scanf("%d %d",&g->vexnum,&g->edgenum);
	getchar();
	printf("����������ÿ������(�س�����)\n");
	for(int i= 0;i<g->vexnum;i++){
		
		printf("��%d�����㣺",i+1);
		scanf("%c",&g->vertex[i]);
		getchar();
	}
	printf("����������ÿ���ߵ��������㼰�ߵ�Ȩ��(��ʽ���磺a,c,3)��\n");
	for (int j=0;j<g->edgenum;j++){
		
		printf("��%d���ߣ�",j+1);
		scanf("%c,%c,%d",&g->edge[j].beginVex,&g->edge[j].endVex,&g->edge[j].weight);	
		getchar();
	}
}




//���ߵ�Ȩֵ��������
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


//Ѱ��ÿ������ĸ��ڵ�
int  Root(int parent[],int r){
    
	while(parent[r]>-1){
		r = parent[r];
	}
	return r;
}




//Ѱ�Ҷ�����±�
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
	
	printf("��С����������:\n");
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






