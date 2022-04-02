#include<iostream>
#define MaxVertexNum 10
using namespace std;
typedef int DataType;
typedef int WeightType;

typedef GNode* PtrToGNode;
struct GNode{
	int nv;   //顶点数
	int ne;   //边数
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType data[MaxVertexNum];    //结点存放的数据
};
typedef PtrToGNode MGraph;  //以邻接矩阵存储的图的类型

typedef int Vertex;
MGraph CreateGraph(int VertexNum){
		Vertex V,W;
		MGraph Graph = new GNode();
		Graph->nv = MaxVertexNum;
		Graph->ne = 0;

		for(V = 0;V<Graph->nv;V++){
				for(W = 0;W<Graph->nv;W++){
						Graph->G[V][W] = 0;
		
				}

		}
		return Graph;
}
typedef struct ENode* PtrToENode;
struct ENode{
    Vertex V1,V2;   //有向边
    WeightType Weight;  //权重
};
typedef PtrToENode Edge;


void InserttEdge(MGraph Graph,Edge E){

    //插入<V1,V2>
    Graph->G[E->V1][E->V2] = E->Weight;
    //诺是无向图还需插入插入<V2,V1>
    Graph->G[E->V2][E->V1] = E->Weight;

}
MGraph BuildGraph(){
    int Nv;
    cin>>Nv;
    MGraph Graph = CreateGraph(Nv);
    cin>>Graph->Ne;
    if(Graph->Ne!= 0){
        Edge E = new ENode();
        for(int i = 0;i<Graph->Ne;i++){
            cin>>E->V1>>E->V2>>E->Weight;
            InserttEdge(Graph,E);
        }

    }
    for(int V;V<Graph->Nv;V++){
        cin>>Graph->data[V];
    }
    return Graph;
}










int main(){
    return 0;
}