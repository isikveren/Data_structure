#include<iostream>
#define MaxVertexNum 10
using namespace std;
typedef int DataType;
typedef int Vertex;
typedef int WeightType;

typedef struct AdjNode* PtrToAdjVnode;
struct AdjNode{
    Vertex AdjV;
    WeightType weight;
    PtrToAdjVnode next;

};


typedef struct Vnode{
    PtrToAdjVnode FirstEdge;
    DataType data;
};
typedef Vnode AdjList[MaxVertexNum];

typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv;     //顶点
    int Ne;       //边
    AdjList G;
};
typedef PtrToGNode LGraph;

typedef struct ENode* PtrToENode;
struct ENode{
    Vertex V1,V2;   //有向边
    WeightType Weight;  //权重
};
typedef PtrToENode Edge;

LGraph CreateGraph(int VertexNum){   //邻接链表的初始化
		Vertex V,W;
		LGraph Graph = new GNode();
		Graph->Nv = MaxVertexNum;
		Graph->Ne = 0;

		for(V = 0;V<Graph->Nv;V++){
				Graph->G[V].FirstEdge == NULL;

		}
		return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVnode NewNode = new AdjNode();
    NewNode->AdjV = E->V2;
    NewNode->weight = E->Weight;
    NewNode->next =  Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    PtrToAdjVnode NewNode = new AdjNode();
    NewNode->AdjV = E->V1;
    NewNode->weight = E->Weight;
    NewNode->next =  Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

int main(){

    return 0;
}