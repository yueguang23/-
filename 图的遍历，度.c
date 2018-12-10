#define MAXVEX 20
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct {
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
} AdjMatrix;
//创建图 
void create(AdjMatrix *G) {
	int i, j, k, v1, v2;
	char vex1, vex2;
	scanf("%d %d", &G->vexnum, &G->arcnum);
	
	for(i = 0;i < G->vexnum;i++) {
		for(j = 0;j < G->vexnum;j++) {
			G->arcs[i][j] = 0;
		}
	}
	fflush(stdin);
	for(i = 0;i < G->vexnum;i++) {
		scanf("%c",&G->vex[i]);
	}
	/*
	for(i = 0;i < G->vexnum;i++) {
		printf("%c",G->vex[i]);
	}
	*/
	for(k = 0;k < G->arcnum;k++) {
		fflush(stdin);
		scanf("%c%c", &vex1, &vex2);
		
		for(i = 0;i < G->vexnum;i++) {
			if(G->vex[i] == vex1) {
				v1 = i;
			    break;
			}
		}
		
		
		for (i = 0;i < G->vexnum;i++) {
			if(G->vex[i] == vex2) {
				v2 = i;
				break;
			}
		}
		
		G->arcs[v1][v2] = 1;	
	}
/*	
	for(i = 0;i < G->vexnum;i++) {
		for( j = 0;j < G->vexnum;j++) {
			printf("%d",G->arcs[i][j]);
		}
		printf("\n");
	}
	*/
	
}

//求这个点的出度 
int chu(AdjMatrix *G,char b1) {
	int i, k;
	int chu = 0;
	for(i = 0;i < G->vexnum;i++) {
		if(G->vex[i] == b1) {
			k = i;
			break;
		} 
	}
	for (i = 0;i < G->vexnum;i++) {
		if(G->arcs[k][i]) {
			chu++;
		}
	}
	return chu;
}

//求这个点的入度 
int ru(AdjMatrix *G,char b1) {
	int i, k;
	int ru = 0;
	for(i = 0;i <G->vexnum;i++) {
		if(G->vex[i] == b1) {
			k = i;
			break;
		}
	}
	for(i = 0;i <G->vexnum;i++) {
		if(G->arcs[i][k]) {
			ru++;
		}
	}
	return ru;
}

//深度优先遍历   遍历子图 
int visited[MAXVEX];
void DFS(AdjMatrix *G,int vi) {
	int vj;
	printf("%c",G->vex[vi]);
	visited[vi] = TRUE;
	for(vj = 0;vj < G->vexnum;vj++) {
		if(!visited[vj]&&G->arcs[vi][vj] == 1) {
			DFS(G,vj);
		}
	}
}

//遍历图 
/*
void TraverseG(AdjMatrix *G) {
	int i;
	for(i = 0;i < G->vexnum;i++) {
		visited[i] = FALSE;
	}
	for(i = 0;i < G->vexnum;i++) {
		if(!visited[i]) {
			DFS(G,i);
		}
	}
}
*/

void BFSTraverse(AdjMatrix *G) {
	int i, j;
	int in, out;
	int queue[MAXVEX];
	in = -1;
	out = -1;
	
	for(i = 0;i < G->vexnum;i++) {
		visited[i] = FALSE;
	}
	
	for(i = 0;i <G->vexnum;i++) {
		if(!visited[i]) {
			visited[i] = TRUE;
			printf("%c", G->vex[i]);
			in++;
			queue[in] = i;	
			
			while(in!=out) {
				out++;
				for(j = 0;j < G->vexnum;j++) {
					if(!visited[j]&&G->arcs[i][j]==1) {
						visited[j] = TRUE;
						printf("%c", G->vex[j]);
						in++;
						queue[in] = j;
					}
				}
			}
		}
	}
} 

void main() {
	int i;
	AdjMatrix *G;
	G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	create(G);
	for (i = 0;i < G->vexnum;i++) {
		printf("%c %d %d %d",G->vex[i], chu(G,G->vex[i]), ru(G,G->vex[i]),chu(G,G->vex[i])+ru(G,G->vex[i]));
		printf("\n");
	}
	
	DFS(G,0);
	printf("\n");
	BFSTraverse(G);
}
